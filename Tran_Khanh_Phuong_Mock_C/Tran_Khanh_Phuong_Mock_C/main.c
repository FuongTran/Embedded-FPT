/*===Author: Tran Khanh Phuong===*/
#define _CRT_SECURE_NO_DEPRECATE

/*******************************************************************************
* Include
*******************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "function.h"

/*******************************************************************************
* Main Function
*******************************************************************************/
int main(int argc, char* argv[]) {
	char line[256];
	uint16_t countline = 0;
	uint8_t first_line_checked = 0;
	uint8_t last_line_checked = 0;

	FILE* input_file = NULL;
	FILE* output_file = NULL;
	input_file = fopen(argv[1], "r");
	output_file = fopen("Output.txt", "w");

	if (argv[1] == NULL) {
		help();
	}
	else if (!Check_MOT_Format(argv[1]))
	{
		fprintf(output_file, "Wrong format");
	}
	else
	{
		if (input_file == NULL) {
			printf("Error: Unable to open inputfile\n");
			help();
			fclose(input_file);
		}
		else if (output_file == NULL) {
			printf("Error: Unable to open outputfile\n");
			help();
		}
		else {
			fprintf(output_file, "Line ||   Adress   || Data\n");

			while (fgets(line, sizeof(line), input_file)) {
				line[strcspn(line, "\n")] = '\0';

				if (!first_line_checked) {/*check fist line is S0*/
					if (line[1] != '0') {
						printf("Error: First line must be S0 record.\n");
						fclose(input_file);
						fclose(output_file);
					}
					first_line_checked = 1;
				}

				uint8_t len = strlen(line);
				if (len > 0 && line[len - 1] == '\n') {
					line[len - 1] = '\0';
				}
				if (!parse_record(line)) {
					fprintf(output_file, "%-5d||  ERRO RECORD\n", countline);
				}
				else {
					fprintf(output_file, "%-5d||", countline);
					print_srecord(line, output_file);
				}
				countline++;
			}
			if (!last_line_checked) { /*Check last line is S7/S8/S9*/
				if (line[1] != '7' && line[1] != '8' && line[1] != '9') {
					printf("Error: Last line must be S7, S8, or S9 record.\n");
					fclose(input_file);
					fclose(output_file);
				}
			}
		}
	}

}

/*******************************************************************************
* EOF
*******************************************************************************/