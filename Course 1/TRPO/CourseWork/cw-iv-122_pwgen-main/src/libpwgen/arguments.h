#pragma once

#include <getopt.h>

int getopt_long(
        int argc,
        char* const argv[],
        const char* optstring,
        const struct option* longopts,
        int* longindex);
extern char* optarg;
extern int optind, opterr, optopt;

/* /arguments.c */
typedef struct {
    const char* name;
    int sname;
    char* helpstr;
    char* manstr;
    char* description;
} ARG_KEYS;
extern ARG_KEYS ArgKeys[];