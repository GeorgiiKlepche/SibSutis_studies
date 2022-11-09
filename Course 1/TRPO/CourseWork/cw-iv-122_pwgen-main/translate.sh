#!/bin/bash


KEY_EXTRACT=0
KEY_GENERATE=0




if [ "$#" -eq 0 ]; then
	err_exit ${ERR_NOT_ARGS} "Requires at least one argument!";
fi

parse_args;

while true; do
	case "$1" in
		-h | --help )       print_help;
							exit 0;
					;;
		-e | --extract )    KEY_EXTRACT=1;
							shift;
					;;
		-g | --generate )   KEY_GENERATE=1;
							shift;
					;;
		-- )                print_help;
							exit 0;
					;;
		* )                 break;
					;;
	esac
done


if [ ${KEY_EXTRACT} -eq 1 ]; then
	extract_phrases;
fi

if [ ${KEY_GENERATE} -eq 1 ]; then
	generate_mo;
fi
