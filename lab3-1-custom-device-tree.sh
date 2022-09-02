#!/bin/bash

set -eux

BOOTLIN_KERNEL_DIR="$HOME/trainings/bootlin-kernel"
KERNEL_DIR="$BOOTLIN_KERNEL_DIR/linux"

cd "$KERNEL_DIR/arch/arm/boot/dts"
if [ ! -L am335x-customboneblack.dts ]; then
	ln -sf "$BOOTLIN_KERNEL_DIR/bootlin-kernel-labs/arch/arm/boot/dts/am335x-customboneblack.dts" .
fi

if [ ! -L Makefile ]; then
	ln -sf "$BOOTLIN_KERNEL_DIR/bootlin-kernel-labs/arch/arm/boot/dts/Makefile" .
fi
