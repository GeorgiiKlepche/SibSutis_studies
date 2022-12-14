#include <libpwgen/reading.h>

int reading(int argc, char* argv[])
{
    int length = DEFAULT_PASSWORD_LENGTH;
    int count = 1;
    int useCount = 0;
    int usePattern = 0;
    char* password;
    char* source = malloc(MAX_PATTERN_LENGTH + 1);
    *source = '\0';
    int iargs = 0;
    int option_index;

    const char* short_options = "hvl:c:P:udnse";
    const struct option long_options[]
            = {{ArgKeys[0].name, optional_argument, NULL, ArgKeys[0].sname},
               {ArgKeys[1].name, optional_argument, NULL, ArgKeys[1].sname},
               {ArgKeys[2].name, required_argument, NULL, ArgKeys[2].sname},
               {ArgKeys[3].name, required_argument, NULL, ArgKeys[3].sname},
               {ArgKeys[4].name, required_argument, NULL, ArgKeys[4].sname},
               {ArgKeys[5].name, optional_argument, NULL, ArgKeys[5].sname},
               {ArgKeys[6].name, optional_argument, NULL, ArgKeys[6].sname},
               {ArgKeys[7].name, optional_argument, NULL, ArgKeys[7].sname},
               {ArgKeys[8].name, optional_argument, NULL, ArgKeys[8].sname},
               {ArgKeys[9].name, optional_argument, NULL, ArgKeys[9].sname},
               {NULL, 0, NULL, 0}};

    while ((iargs = getopt_long(
                    argc, argv, short_options, long_options, &option_index))
           != -1) {
        switch (iargs) {
        case 'h':
            Print.help();
            break;
        case 'v':
            Print.version();
            break;
        case 'l':
            if (isNumber(optarg) == 1) {
                // Пресекаем попытку ввести слишком большую длину пароля
                if (atoi(optarg) > MAX_PASSWORD_LENGTH) {
                    Print.error(
                            "%s: %d",
                            _("Max password length"),
                            MAX_PASSWORD_LENGTH);
                }
                // Если указана нулевая длина, то будет запрошен ввод с клавиату
                if (atoi(optarg) > 0) {
                    useCount = 1;
                }
                sscanf(optarg, "%d", &length);
            } else {
                Print.error(
                        _("Option %s must be a number!"), ArgKeys[2].manstr);
            }
            break;
        case 'c':
            if (isNumber(optarg) == 1) {
                // Пресекаем попытку ввести слишком большое количество итераций

                if (atoi(optarg) > MAX_PASSWORD_COUNT) {
                    Print.error(
                            "%s: %d",
                            _("Max password count"),
                            MAX_PASSWORD_COUNT);
                }
                sscanf(optarg, "%d", &count);
            } else {
                Print.error(
                        _("Option %s must be a number!"), ArgKeys[3].manstr);
            }
            break;
        case 'P':
            usePattern = 1;

            // Пресекаем попытку ввести слишком длинный шаблон
            if (strlen(optarg) > MAX_PATTERN_LENGTH) {
                Print.error(
                        "%s: %d", _("Max pattern length"), MAX_PATTERN_LENGTH);
            }
            sscanf(optarg, "%s", source);
            break;
        case 'u':
            if (usePattern != 1) {
                strcat(source, PATTERN_UP);
            }
            break;
        case 'd':
            if (usePattern != 1) {
                strcat(source, PATTERN_DOWN);
            }
            break;
        case 'n':
            if (usePattern != 1) {
                strcat(source, PATTERN_NUMBER);
            }
            break;
        case 's':
            if (usePattern != 1) {
                strcat(source, PATTERN_SYMBOL);
            }
            break;
        case 'e':
            // * Пресекаем попытку ввести слишком длинный шаблон
            if ((strlen(source) + 1) > MAX_PATTERN_LENGTH) {
                char __e__[ERROR_MSG_BUFFER_LENGTH];
                sprintf(__e__,
                        _("No use key %s with long pattern"),
                        ArgKeys[9].manstr);
                Print.error(
                        "%s: %d (%s)",
                        _("Max pattern length"),
                        MAX_PATTERN_LENGTH,
                        __e__);
            }
            strcat(source, " ");
            break;
        case '?':
            exit(EXIT_FAILURE);
            break;
        default:
            break;
        };
    };
    if (strlen(source) > 0) {
        if (useCount > 0) {
            while (count >= 1) {
                password = PassGen.getPassword(source, length);
                printf("%s\n", password);
                free(password);
                count--;
            }
        } else {
            password = PassGen.getPassword(source, length);
            printf("%s\n", password);
            free(password);
        }
    } else {
        char __s__[ERROR_MSG_BUFFER_LENGTH];
        sprintf(__s__,
                "%s, %s, %s, %s, %s",
                ArgKeys[4].manstr,
                ArgKeys[5].manstr,
                ArgKeys[6].manstr,
                ArgKeys[7].manstr,
                ArgKeys[8].manstr);
        Print.error(_("One of the arguments %s is mandatory"), __s__);
        return 1;
    }

    free(source);
    return 0;
}