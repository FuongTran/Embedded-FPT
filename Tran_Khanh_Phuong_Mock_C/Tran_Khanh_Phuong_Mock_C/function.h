/*******************************************************************************
* Definitions
*******************************************************************************/

#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdint.h>
#include <stdbool.h>

#define BYTE_COUNT 2
#define BYTE_TYPE 2
#define HEX_BYTE_LENGTH 2

/*******************************************************************************
* Prorotype
*******************************************************************************/
/*
*	@brief: this function help how to use cmd to check SRECORD
*/
void help();

/*
*	@brief: this function convert hex char to dec value, use for hexStringToByte
*	@param[in]: hex char
*/
uint8_t HexCharToValue(char c);

/*
*	@brief: this function convert hexstring to byte dec
*	@param[in]: hex string
*/
uint8_t HexStringToByte(const char* hexStr);

/*
*	@brief: this function check Record format hex
*	@param[in]: record line
*/
bool Check_hexa(const char* line);

/*
*	@brief: this function check record start with S and not S4
*	@param[in]: record line
*/
bool Check_type(const char* line);

/*
*	@brief: this function check record length more than 10
*	@param[in]: record line
*/
bool Check_length(const char* line);

/*
*	@brief: this function check is that correct count_byte
*	@param[in]: record line
*/
bool check_count(const char* line);

/*
*	@brief: this function check is that correct checksum
*	@param[in]: record line
*/
bool Check_Sum(const char* hexStr);

/*
*	@brief: this function combine all exception
*	@param[in]: record line
*/
bool parse_record(const char* line);

/*
*	@brief: this function print answer to outputfile
*	@param[in]: record line
*/
void print_srecord(const char* line, const char* outputName);

/*
*	@brief: this function check format file
*	@param[in]: record line
*/
bool Check_MOT_Format(const char* filename);

#endif // FUNCTION_H
/*******************************************************************************
* EOF
*******************************************************************************/