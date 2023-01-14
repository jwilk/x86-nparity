/* Copyright © 2005-2023 Jakub Wilk <jwilk@jwilk.net>
 * SPDX-License-Identifier: MIT
 */

#include <assert.h>

static inline unsigned int nparity(unsigned char x)
{
    register unsigned int xi = x;
    register unsigned int v;
    __asm__(
        "or %1, %1\n"
        "mov $0, %0\n"
        "setnp %b0\n"
        : "=r" (v)
        : "r" (xi)
        : "cc"
    );
    return v;
}

int main(void)
{
    unsigned int i;
    for (i = 0; i <= 0xFF; i++) {
        int v = 0;
        for (int b = 0; b < 8; b++)
            v ^= !!(i & (1U << b));
        assert(v == nparity(i));
    }
}

// vim:set ts=4 sts=4 sw=4 et:
