#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int i = ft_printf("%d\n",123);
    int x = printf("%d\n", 123);
    ft_printf("%d\n", i);
    printf("%d", x);
}