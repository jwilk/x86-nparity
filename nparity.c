/* Copyright © 2005-2023 Jakub Wilk <jwilk@jwilk.net>
 * SPDX-License-Identifier: MIT
 */

#include <stdio.h>

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
    for (i = 0; i < 64; i++)
        printf("%cparity(%02d)\n", nparity(i) ? 'n' : ' ', i);
}

// vim:set ts=4 sts=4 sw=4 et:
