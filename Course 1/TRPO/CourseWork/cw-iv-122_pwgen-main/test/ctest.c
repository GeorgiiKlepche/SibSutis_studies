#include <ctest.h>
#include <libpwgen/print.h>
#include <libpwgen/reading.h>
#include <libpwgen/valid.h>

#include <stdio.h>

CTEST(valid, correctly_valid)
{
    char arr[] = {'1', '2', '3'};
    int flag = isNumber(arr);
    int exp_flag = 1;
    ASSERT_EQUAL(flag, exp_flag);
}
CTEST(valid, correctly_valid1)
{
    char arr[] = {'.', '/', ','};
    int flag = isNumber(arr);
    int exp_flag = 0;
    ASSERT_EQUAL(flag, exp_flag);
}
CTEST(valid, correctly_valid2)
{
    char arr[] = {'-', '`', '+'};
    int flag = isNumber(arr);
    int exp_flag = 0;
    ASSERT_EQUAL(flag, exp_flag);
}
CTEST(valid, correctly_valid3)
{
    char arr[] = {'q', 'w', 'e', 'r', 't', 'y'};
    int flag = isNumber(arr);
    int exp_flag = 0;
    ASSERT_EQUAL(flag, exp_flag);
}
CTEST(valid, correctly_valid4)
{
    char arr[] = {"-1, -2, -3"};
    int flag = isNumber(arr);
    int exp_flag = 0;
    ASSERT_EQUAL(flag, exp_flag);
}

CTEST(argc, corrct_argc)
{
    char* arr[] = {"-P", "-u", "-d", "-n", "-s"};

    freopen("OUTPUT", "w+", stdout);
    int flag = reading(5, arr);
    int exp_flag = 0;
    freopen("/dev/tty", "w+", stdout);
    remove("OUTPUT");

    ASSERT_EQUAL(flag, exp_flag);
}

/*CTEST(argc, corrct_argc2)
{
    char* arr[] = {"-.", "-/", "+", "=", "'"};

    freopen("OUTPUT", "w+", stdout);
    freopen("OUTPUT", "w+", stderr);
    int flag = reading(5, arr);
    int exp_flag = 0;
    // freopen("/dev/tty", "w+", stdout);

    remove("OUTPUT");

    ASSERT_EQUAL(flag, exp_flag);
}*/
