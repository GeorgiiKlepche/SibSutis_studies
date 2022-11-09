/* main.c */

#include <libpwgen/arguments.h>
#include <libpwgen/passgen.h>
#include <libpwgen/print.h>
#include <libpwgen/reading.h>
#include <libpwgen/valid.h>

int main(int argc, char* argv[])
{
    int flag_correct_argc;

    srand((unsigned)time(NULL) * getpid());

    textdomain(PACKAGE_NAME);

    flag_correct_argc = reading(argc, argv);

    if (flag_correct_argc)
        exit(EXIT_FAILURE);

    exit(EXIT_SUCCESS);
}
