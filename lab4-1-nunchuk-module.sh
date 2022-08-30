#!/bin/bash

set -eux

BOOTLIN_KERNEL_DIR="$HOME/trainings/bootlin-kernel"

cd "$BOOTLIN_KERNEL_DIR/linux-kernel-labs-data/modules/nfsroot/root/nunchuk"
if [ -f "nunchuk.c" ]; then
	rm nunchuk.c
fi

if [ ! -L "nunchuk.c" ]; then
	ln -s "$BOOTLIN_KERNEL_DIR/bootlin-kernel-labs/nunchuk/nunchuk.c" .
fi

if [ -f "Makefile" ]; then
	rm Makefile
fi

if [ ! -L "Makefile" ]; then
	ln -s "$BOOTLIN_KERNEL_DIR/bootlin-kernel-labs/nunchuk/Makefile" .
fi
