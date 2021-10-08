#include"stdlib.h"

static int sb = 0;
int bar(int c, int d)
{
    int e = c + d;
    return e;
}
int foo(int a, int b)
{
    return bar(a, b);
}
int main1(void)
{
    foo(2, 5);
    return 0;
}