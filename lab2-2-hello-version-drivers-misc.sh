#!/bin/bash

set -eux

BOOTLIN_KERNEL_DIR="$HOME/trainings/bootlin-kernel"
KERNEL_DIR="$BOOTLIN_KERNEL_DIR/linux"

cd "$KERNEL_DIR"/drivers/misc || exit 1
if [ ! -L Makefile ]; then
	rm Makefile
	ln -s "$BOOTLIN_KERNEL_DIR/bootlin-kernel-labs/drivers/misc/Makefile" .
fi

if [ ! -L Kconfig ]; then
	rm Kconfig
	ln -s "$BOOTLIN_KERNEL_DIR/bootlin-kernel-labs/drivers/misc/Kconfig" .
fi

if [ ! -L hello_version.c ]; then
	ln -s "$BOOTLIN_KERNEL_DIR/bootlin-kernel-labs/drivers/misc/hello_version.c" .
fi
