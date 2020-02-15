#ifndef _CLASS_SYSTEM_H
#define _CLASS_SYSTEM_H

#include "types.h"
#include "gClassCPU.h"

struct gClassSystem{
    char *unk_0x00[0x10];
    gClassCPU_t *cpu;
};

extern gClassSystem_t  *gSystem;

#endif