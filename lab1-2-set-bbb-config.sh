#!/bin/bash

set -eux

BOOTLIN_KERNEL_DIR="$HOME/trainings/bootlin-kernel"
KERNEL_DIR="$BOOTLIN_KERNEL_DIR/linux"

cd "$KERNEL_DIR"
if [ -f .config ]; then
	rm .config
fi
ln -s "$BOOTLIN_KERNEL_DIR"/bootlin-kernel-labs/.config .
