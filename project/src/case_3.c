#include "case_3.h"
#include <stdio.h>

void Special_printf_of_num(int num) {
    for (int i = 2; i < num; ++i) {
        if (num % i == 0) {
            printf("%d\n", 0);
            break;
        }
    }
    if (num <= 1)
        printf("%d\n", 0);
    else
        printf("%d\n", 1);
}

