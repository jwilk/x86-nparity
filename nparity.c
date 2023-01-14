#include <stdio.h>

static inline unsigned int nparity(unsigned int x)
{
    register unsigned int _v;
    __asm__(
        "or %1, %1\n"
        "mov $0, %0\n"
        "setnp %b0\n"
        : "=r" (_v)
        : "r" (x)
        : "cc"
    );
    return _v;
}

int main(void)
{
    unsigned int i;
    for (i = 0; i < 64; i++)
        printf("%cparity(%02d)\n", nparity(i) ? 'n' : ' ', i);
}

// vim:set ts=4 sts=4 sw=4 et:
