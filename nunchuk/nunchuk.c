// SPDX-License-Identifier: GPL-2.0
#include <linux/delay.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/i2c.h>

static int cbyte = 5;
static int zbyte = 5;

static int cmask = 2;
static int zmask = 1;

static bool cpressed;
static bool zpressed;

int nunchuk_read_registers(struct i2c_client *client,
		unsigned char *buffer)
{
	int ret;
	unsigned char buffer_read_trig = 0x00;

	usleep_range(10000, 20000);

	buffer[0] = 0x00;
	ret = i2c_master_send(client, &buffer_read_trig, 1);
	if (ret < 0)
		return ret;

	usleep_range(10000, 20000);

	ret = i2c_master_recv(client, buffer, 6);
	if (ret < 0)
		return ret;

	return 0;
}

static int nunchuk_i2c_probe(struct i2c_client *client,
		const struct i2c_device_id * device_id)
{
	int ret;
	unsigned char buffer[6];

	buffer[0] = 0xf0;
	buffer[1] = 0x55;

	ret = i2c_master_send(client, buffer, 2);
	if (ret < 0)
		return ret;

	udelay(1000);

	buffer[0] = 0xfb;
	buffer[1] = 0x00;

	ret = i2c_master_send(client, buffer, 2);
	if (ret < 0)
		return ret;

	ret = nunchuk_read_registers(client, buffer);
	if (ret < 0)
		return ret;

	ret = nunchuk_read_registers(client, buffer);
	if (ret < 0)
		return ret;

	if (~buffer[cbyte] & cmask)
		cpressed = true;
	else
		cpressed = false;

	if (~buffer[zbyte] & zmask)
		zpressed = true;
	else
		zpressed = false;

	pr_info("C = %d\n", cpressed);
	pr_info("Z = %d\n", zpressed);

	return 0;
}

static int nunchuk_i2c_remove(struct i2c_client *client)
{
	pr_info("Remove\n");

	return 0;
}

static const struct of_device_id nunchuk_of_match[] = {
	{ .compatible = "nintendo,nunchuk" },
	{ }
};

MODULE_DEVICE_TABLE(of, nunchuk_of_match);

static struct i2c_driver nunchuk_i2c_driver = {
	.driver = {
		.name = "nunchuk_i2c",
		.of_match_table = nunchuk_of_match,
	},
	.probe = nunchuk_i2c_probe,
	.remove = nunchuk_i2c_remove,
};

module_i2c_driver(nunchuk_i2c_driver);

MODULE_LICENSE("GPL");
