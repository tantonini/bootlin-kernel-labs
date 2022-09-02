#!/bin/bash

set -eux

BOOTLIN_KERNEL_DIR="$HOME/trainings/bootlin-kernel"

cd "$BOOTLIN_KERNEL_DIR/linux-kernel-labs-data/modules/nfsroot/root/hello" || exit 1
if [ -f hello_version.c ]; then
	rm hello_version.c
fi
ln -sf "$BOOTLIN_KERNEL_DIR/bootlin-kernel-labs/hello/hello_version.c" .

if [ -f Makefile ]; then
	rm Makefile
fi
ln -sf "$BOOTLIN_KERNEL_DIR/bootlin-kernel-labs/hello/Makefile" .

export ARCH=arm
export CROSS_COMPILE=arm-none-linux-gnueabihf-
make
