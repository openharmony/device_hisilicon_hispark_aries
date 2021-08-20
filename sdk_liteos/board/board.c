/*
 * Copyright (c) 2013-2019 Huawei Technologies Co., Ltd. All rights reserved.
 * Copyright (c) 2020-2021 Huawei Device Co., Ltd. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this list of
 *    conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list
 *    of conditions and the following disclaimer in the documentation and/or other materials
 *    provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors may be used
 *    to endorse or promote products derived from this software without specific prior written
 *    permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "los_config.h"
#include "los_vm_map.h"
#include "los_vm_zone.h"
#include "los_vm_boot.h"
#include "los_mmu_descriptor_v6.h"

#ifdef LOSCFG_KERNEL_MMU
LosArchMmuInitMapping g_archMmuInitMapping[] = {
    {
        .phys = SYS_MEM_BASE,
        .virt = KERNEL_VMM_BASE,
        .size = KERNEL_VMM_SIZE,
        .flags = MMU_DESCRIPTOR_KERNEL_L1_PTE_FLAGS,
        .name = "KernelCached",
    },
    {
        .phys = SYS_MEM_BASE,
        .virt = UNCACHED_VMM_BASE,
        .size = UNCACHED_VMM_SIZE,
        .flags = MMU_INITIAL_MAP_NORMAL_NOCACHE,
        .name = "KernelUncached",
    },
    {
        .phys = PERIPH_PMM_BASE,
        .virt = PERIPH_DEVICE_BASE,
        .size = PERIPH_DEVICE_SIZE,
        .flags = MMU_INITIAL_MAP_DEVICE,
        .name = "PeriphDevice",
    },
    {
        .phys = PERIPH_PMM_BASE,
        .virt = PERIPH_CACHED_BASE,
        .size = PERIPH_CACHED_SIZE,
        .flags = MMU_DESCRIPTOR_KERNEL_L1_PTE_FLAGS,
        .name = "PeriphCached",
    },
    {
        .phys = PERIPH_PMM_BASE,
        .virt = PERIPH_UNCACHED_BASE,
        .size = PERIPH_UNCACHED_SIZE,
        .flags = MMU_INITIAL_MAP_STRONGLY_ORDERED,
        .name = "PeriphStronglyOrdered",
    },
    {0}
};
#endif

