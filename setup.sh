#!/bin/bash

set -eux

BOOTLIN_KERNEL_DIR="$HOME/trainings/bootlin-kernel"
KERNEL_SRC="$HOME/sources/linux"
KERNEL_DIR="$BOOTLIN_KERNEL_DIR/linux"

if [ ! -d "$KERNEL_SRC" ]; then
	echo "Linux kernel sources not found"
	exit 1
fi

if [ ! -d "$KERNEL_DIR" ]; then
	pushd "$KERNEL_SRC"
	git worktree add "$KERNEL_DIR" linux-5.18.y
fi
