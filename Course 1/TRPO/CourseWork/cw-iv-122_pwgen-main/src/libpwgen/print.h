#pragma once
/* print.h */

#include <errno.h>
#include <libintl.h>
#include <libpwgen/arguments.h>
#include <libpwgen/config.h>
#include <locale.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define ENABLE_NLS 1
#define _(s) gettext(s)

#define PATTERN_UP "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define PATTERN_DOWN "abcdefghijklmnopqrstuvwxyz"
#define PATTERN_NUMBER "0123456789"
#define PATTERN_SYMBOL "!@#$%^&*()_+=-.,/`\\[]{}|"

#define PACKAGE_DESCRIPTION "Console password generator"
#define PACKAGE_NAME "pwgen"
#define PACKAGE_STRING "passgen"
#define PACKAGE_TARNAME "passgen"

#define DEFAULT_PASSWORD_LENGTH 25
#define MAX_PASSWORD_LENGTH 4096
#define MAX_PASSWORD_COUNT 1000000
#define MAX_PATTERN_LENGTH 200
#define ERROR_MSG_BUFFER_LENGTH 300

/* Source: source/print.c */
struct print {
    /**
     * @namespace Print
     * @name help
     * Функция выводит справочную информацию программы
     */
    void (*help)();
    /**
     * @namespace Print
     * @name version
     * Функция выводит версию релиза
     */
    void (*version)();
    /**
     * @namespace Print
     * @name echo
     * Функция выводит список переданных аргументов
     * в виде форматированной строки в STDOUT.
     * @param {char*} msg Строка в формате sprintf
     * @param {va_list} ... Аргументы для форматирования строки msg
     */
    void (*echo)(char* const, ...);
    /**
     * @namespace Print
     * @name error
     * Функция выводит список переданных аргументов
     * в виде форматированной строки в STDERR и завершает работу
     * программы с ошибкой.
     * @param {char*} msg Строка в формате sprintf
     * @param {va_list} ... Аргументы для форматирования строки msg
     */
    void (*error)(char* const, ...);
};
extern const struct print Print;