// SPDX-License-Identifier: GPL-2.0
#include <linux/delay.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/i2c.h>

static int nunchuk_i2c_probe(struct i2c_client *client,
		const struct i2c_device_id * device_id)
{
	int ret;
	unsigned char buffer[2];

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
