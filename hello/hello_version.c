// SPDX-License-Identifier: GPL-2.0
#include <linux/init.h>
#include <linux/module.h>
#include <linux/utsname.h>

static char *who = "World";
module_param(who, charp, 0644);

static time64_t tstamp_start;

static int __init hello_init(void)
{
	tstamp_start = ktime_get_seconds();
	pr_alert("Hello %s. You are currently using Linux %s.\n", who, utsname()->release);
	return 0;
}

static void __exit hello_exit(void)
{
	time64_t tstamp_end = ktime_get_seconds();

	pr_alert("Goodbye %lld!\n", tstamp_end - tstamp_start);
}

module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");
