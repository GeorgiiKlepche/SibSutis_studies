/* print.c */

#include <libpwgen/print.h>

void help()
{
    printf("%s\n", _("Console password generator"));
    printf("\n");
    printf("%s:\n", _("Default values"));
    printf("\t%-s: %-8d\n",
           _("Default password length"),
           DEFAULT_PASSWORD_LENGTH);
    printf("\t%-s: %-8d\n", _("Max password length"), MAX_PASSWORD_LENGTH);
    printf("\t%-s: %-8d\n", _("Max password count"), MAX_PASSWORD_COUNT);
    printf("\t%-s: %-8d\n", _("Max pattern length"), MAX_PATTERN_LENGTH);
    printf("\n");
    printf("%s:\n", _("Usage keys"));
    printf("\t%s                       %s\n",
           ArgKeys[0].helpstr,
           _("Help information"));
    printf("\n");
    printf("\t%s              %s\n",
           ArgKeys[2].helpstr,
           _("Password length. If not specified,"));
    printf("\t                                 %s\n",
           _("it will be set to default value. If set to 0,"));
    printf("\t                                 %s\n",
           _("the program will ask for input from the keyboard."));
    printf("\t%s                %s\n",
           ArgKeys[3].helpstr,
           _("The amount for one time passwords."));
    printf("\t                                 %s\n",
           _("It is useful when you need to create"));
    printf("\t                                 %s\n",
           _("a file with a unique string."));
    printf("\t%s            %s\n",
           ArgKeys[4].helpstr,
           _("A string containing the possible"));
    printf("\t                                 %s\n",
           _("characters in the password."));
    printf("\t                                 %s\n",
           _("If the key is specified, the keys"));
    printf("\t                                 -u, -d, -n, -s %s\n",
           _("will be ignored."));
    printf("\t%s                  %s\n",
           ArgKeys[5].helpstr,
           _("Use uppercase letters in the password"));
    printf("\t%s                %s\n",
           ArgKeys[6].helpstr,
           _("Use lowercase letters in the password"));
    printf("\t%s                     %s\n",
           ArgKeys[7].helpstr,
           _("Use the numbers in the password"));
    printf("\t%s                     %s\n",
           ArgKeys[8].helpstr,
           _("Use punctuation to the password"));
    printf("\t%s               %s\n",
           ArgKeys[9].helpstr,
           _("Add space to the password pattern"));
    printf("\n");
    printf("%s:\n", _("Example"));
    printf("\t%s -l0 -u                 # %s\n",
           PACKAGE_NAME,
           _("Input length from the keyboard and use uppercase letters only"));
    printf("\t%s -l25 -d                # %s\n",
           PACKAGE_NAME,
           _("Use the lowercase letters only"));
    printf("\t%s -l25 -s                # %s\n",
           PACKAGE_NAME,
           _("Use punctuation marks only"));
    printf("\t%s -l25 -dn               # %s\n",
           PACKAGE_NAME,
           _("Use lowercase letters and numbers only"));
    printf("\t%s -l25 -du               # %s\n",
           PACKAGE_NAME,
           _("Use lowercase and uppercase letters only"));
    printf("\t%s -l25 -P123abc          # %s\n",
           PACKAGE_NAME,
           _("Use symbols '123abc' only"));
    printf("\t%s -l25 -P123abc -e       # %s\n",
           PACKAGE_NAME,
           _("Use symbols '123abc' with space"));
    printf("\t%s -l25 -c5               # %s\n",
           PACKAGE_NAME,
           _("List of the 5 passwords, one per line"));
    printf("\n");
    exit(EXIT_SUCCESS);
}

void echo(char* const msg, ...)
{
    va_list arguments;
    va_start(arguments, msg);
    vfprintf(stdout, msg, arguments);
    fprintf(stdout, "\n");
    va_end(arguments);
}

void error(char* const msg, ...)
{
    va_list arguments;
    va_start(arguments, msg);
    vfprintf(stderr, msg, arguments);
    fprintf(stderr, "\n");
    va_end(arguments);
    exit(EXIT_FAILURE);
}

const struct print Print = {.help = help, .echo = echo, .error = error};
