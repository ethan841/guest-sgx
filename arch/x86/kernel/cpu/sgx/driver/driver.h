/* SPDX-License-Identifier: (GPL-2.0 OR BSD-3-Clause) */
#ifndef __ARCH_SGX_DRIVER_H__
#define __ARCH_SGX_DRIVER_H__

#include <crypto/hash.h>
#include <linux/kref.h>
#include <linux/mmu_notifier.h>
#include <linux/radix-tree.h>
#include <linux/rwsem.h>
#include <linux/sched.h>
#include <linux/workqueue.h>
#include <uapi/asm/sgx.h>
#include "../arch.h"
#include "../encl.h"
#include "../encls.h"
#include "../sgx.h"

#define SGX_DRV_NR_DEVICES	2
#define SGX_EINIT_SPIN_COUNT	20
#define SGX_EINIT_SLEEP_COUNT	50
#define SGX_EINIT_SLEEP_TIME	20

extern struct workqueue_struct *sgx_encl_wq;
extern u64 sgx_encl_size_max_32;
extern u64 sgx_encl_size_max_64;
extern u32 sgx_misc_reserved_mask;
extern u64 sgx_attributes_reserved_mask;
extern u64 sgx_xfrm_reserved_mask;
extern u32 sgx_xsave_size_tbl[64];

extern const struct file_operations sgx_provision_fops;

long sgx_ioctl(struct file *filep, unsigned int cmd, unsigned long arg);

#ifdef CONFIG_INTEL_SGX_DRIVER
int sgx_drv_init(void);
#else
static inline int sgx_drv_init(void)
{
	return -ENODEV;
}
#endif

#endif /* __ARCH_X86_SGX_DRIVER_H__ */
