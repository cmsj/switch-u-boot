/*
 * (C) Copyright 2013-2015
 * NVIDIA Corporation <www.nvidia.com>
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#ifndef _NINTENDO_SWITCH_H
#define _NINTENDO_SWITCH_H

#include <linux/sizes.h>

#include "tegra210-common.h"

#define CONFIG_REMAKE_ELF

/* High-level configuration options */
#define CONFIG_TEGRA_BOARD_STRING	"Nintendo Switch"

/* Board-specific serial config */
#define CONFIG_TEGRA_ENABLE_UARTB

/* I2C */
#define CONFIG_SYS_I2C_TEGRA

/* USB2.0 Host support */
#define CONFIG_USB_EHCI_TEGRA

/* USB networking support */

/* PCI host support */

/* General networking support */

#include "tegra-common-usb-gadget.h"
#include "tegra-common-post.h"

/* Crystal is 38.4MHz. clk_m runs at half that rate */
#define COUNTER_FREQUENCY	19200000

#define CONFIG_SYS_MEM_RESERVE_SECURE (4 * SZ_1M)

#undef CONFIG_EXTRA_ENV_SETTINGS
#define CONFIG_EXTRA_ENV_SETTINGS               \
        "kernel_addr=0x83000000\0"              \
        "dtb_addr=0x8d000000\0"                 \
        "unzip_addr=0x85000000\0"               \
        "mmc_part=1:2\0"
#define CONFIG_BOOTCOMMAND                      \
        "ext4load mmc $mmc_part $kernel_addr; " \
        "ext4load mmc $mmc_part $dtb_addr; "    \
        "unzip $kernel_addr $unzip_addr; "      \
        "setenv bootargs 'root=/dev/mmcblk0p2 rw fbcon=rotate:3 rootwait'; " \
        "usb reset; "                           \
        "booti $unzip_addr - $dtb_addr"

#endif /* _NINTENDO_SWITCH_H */
