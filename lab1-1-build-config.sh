#!/bin/bash

set -eux

BOOTLIN_KERNEL_DIR="$HOME/trainings/bootlin-kernel"
KERNEL_DIR="$BOOTLIN_KERNEL_DIR/linux"

export ARCH=arm
export CROSS_COMPILE=arm-none-linux-gnueabihf-
cd "$KERNEL_DIR"
make omap2plus_defconfig
