#include <stdio.h>

static inline unsigned int nparity(unsigned int x)
{
  register unsigned int _v;
  __asm__ ("or %1, %1\n\tmov $0, %0\n\tsetnp %b0" : "=r" (_v) : "r" (x));
  return _v;
}

int main(void)
{
  unsigned int i;
  for (i=0; i<64; i++)
    printf("%cparity(%02d)\n", nparity(i)?'n':' ', i);
}

// vim:set ts=2 sts=2 sw=2 et:
