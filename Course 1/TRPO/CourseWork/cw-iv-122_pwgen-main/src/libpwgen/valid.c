/* valid.c */

#include <libpwgen/valid.h>

int isNumber(char number[])
{
    int i = 0;
    //проверяем на отрицательные числа
    if (number[0] == '-')
        i = 1;

    for (; number[i] != 0; i++) {
        if (!isdigit(number[i]))
            return 0;
    }
    return 1;
}