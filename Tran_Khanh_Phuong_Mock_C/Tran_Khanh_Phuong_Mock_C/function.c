#define _CRT_SECURE_NO_DEPRECATE    
/*******************************************************************************
* Includes
*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "function.h"

/*******************************************************************************
* Function
*******************************************************************************/
void help() {
    printf("How to use: gcc -o srecord_parser main.c function.c\n");
    printf("Step1: Open Terminal");
    printf("Step2: gcc -o srecord_parser main.c function.c");
    printf("Step3: srecord_parser <path_to_srecord_file>");
    printf("Parses an S-record file and checks for errors.\n");
    printf("Outputs a file 'Output.txt' with the parsed records.\n");
}

uint8_t HexCharToValue(char c) { // ten bien co y nghia
    uint8_t result = 0;

    if ((c >= '0') && (c <= '9')) {
        result = c - '0';
    }
    else if ((c >= 'A') && (c <= 'F')) {
        result = c - 'A' + 10;
    }
    else if ((c >= 'a') && (c <= 'f')) {
        result = c - 'a' + 10;
    }

    return result;
}

uint8_t HexStringToByte(const char* hexStr) {
    uint8_t value = (HexCharToValue(hexStr[0]) << 4) | HexCharToValue(hexStr[1]);
    return value;
}

bool Check_type(const char* line) {
    bool checkVal = false;
    if ((line[0] == 'S') && (line[1] >= '0') &&
        (line[1] <= '9') && (line[1] != '4')) {
        checkVal = true;
    }
    else
    {
        checkVal = false;
    }
    return checkVal;
}

bool isHexChar(char c) { //bien co y nghia
    bool checkVal = false;
    if ((c >= '0' && c <= '9') ||
        (c >= 'A' && c <= 'F') ||
        (c >= 'a' && c <= 'f')) {
        checkVal = true;
    }
    else
    {
        checkVal = false;
    }
    return checkVal;
}

bool Check_hexa(const char* line) {
    bool isHex = true;
    line++;

    while (*line) {
        if (!isHexChar(*line)) {
            isHex = false;
            break;
        }
        line++;
    }

    return isHex;
}

bool Check_length(const char* line) {
    bool checkVal = false;
    uint8_t size_rc = strlen(line);
    if (line == NULL) {
        checkVal = false;
    }
    else if (size_rc < 10) {
        checkVal = false;
    }
    else
    {
        checkVal = true;
    }
    return checkVal;
}

bool check_count(const char* line) {
    bool checkVal = false;
    if (!Check_length(line)) {
        checkVal = false;
    }

    uint8_t count = HexStringToByte(&line[2]);

    uint32_t size_rc = (uint32_t)strlen(line);

    uint32_t dataLength = size_rc - BYTE_COUNT - BYTE_TYPE;

    if (count == (dataLength / HEX_BYTE_LENGTH)) {
        checkVal = true;
    }
    else
    {
        checkVal = false;
    }

    return checkVal;
}

bool Check_Sum(const char* hexStr) {
    bool checkVal = false;
    uint8_t size_rc = (uint8_t)strlen(hexStr);
    uint8_t checksum = HexStringToByte(&hexStr[size_rc - 2]);

    uint8_t sum = 0;
    for (int i = 2; i < size_rc - 2; i += 2) { //index
        uint8_t count = HexStringToByte(&hexStr[i]);
        sum += count;
    }

    sum = 0xFF - (sum & 0xFF);

    if (sum == checksum) {
        checkVal = true;
    }
    else {
        checkVal = false;
    }

    return checkVal;
}

bool parse_record(const char* line) {
    bool checkVal = false;
    if (!Check_type(line)) {
        checkVal = false;
    }
    else if (!check_count(line)) {
        checkVal = false;
    }
    else if (!Check_hexa(line)) {
        checkVal = false;
    }
    else if (!Check_length(line)) {
        checkVal = false;
    }
    else if (!Check_Sum(line)) {
        checkVal = false;
    }
    else {
        checkVal = true;
    }
    return checkVal;
}

void print_srecord(const char* line, const char* outputName) {
    char type = line[1];
    char address[9] = { 0 };
    char data[256] = { 0 };
    uint8_t dataLength = 0;
    uint8_t address_length = 0;

    switch (type) {
    case '0':
        address_length = 4;
        break;
    case '1':
        address_length = 4;
        break;
    case '9':
    case '5':
        address_length = 4;
        dataLength = 0;
        break;
    case '2':
        address_length = 6;
        break;
    case '8':
    case '6':
        address_length = 6;
        dataLength = 0;
        break;
    case '3':
        address_length = 8;
        break;
    case '7':
        address_length = 8;
        dataLength = 0;
        break;
    default:
        printf("Unsupported S-record type: %c\n", type);
        break;
    }

    // Extract the address
    strncpy(address, &line[4], address_length);

    // Calculate the data length
    dataLength = strlen(line) - 2 - (address_length)-HEX_BYTE_LENGTH * 2; // Excluding type, address, and checksum

    // Extract the data
    if (dataLength > 0) {
        strncpy(data, &line[4 + address_length], dataLength);
        data[dataLength] = '\0';
        fprintf(outputName, "  %-10s|| %s\n", address, data);
    }
    else {
        fprintf(outputName, "  %-10s|| 0\n", address);
    }
}

bool Check_MOT_Format(const char* filename) {
    FILE* file = fopen(filename, "r");

    char line[256];
    int s0_count = 0, s1_count = 0, s2_count = 0, s3_count = 0;
    int s5_count = 0, s7_count = 0, s8_count = 0, s9_count = 0;

    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "S0", 2) == 0) {
            s0_count++;
        }
        else if (strncmp(line, "S1", 2) == 0) {
            s1_count++;
        }
        else if (strncmp(line, "S2", 2) == 0) {
            s2_count++;
        }
        else if (strncmp(line, "S3", 2) == 0) {
            s3_count++;
        }
        else if (strncmp(line, "S5", 2) == 0) {
            s5_count++;
        }
        else if (strncmp(line, "S7", 2) == 0) {
            s7_count++;
        }
        else if (strncmp(line, "S8", 2) == 0) {
            s8_count++;
        }
        else if (strncmp(line, "S9", 2) == 0) {
            s9_count++;
        }
    }
    fclose(file);

    bool result = true;

    if (s0_count != 1) {
        result = false;
    }
    if (s5_count != 1) {
        result = false;
    }

    if ((s1_count > 0 && s9_count == 0) || (s1_count == 0 && s9_count > 0)) {
        result = false;
    }
    if ((s2_count > 0 && s8_count == 0) || (s2_count == 0 && s8_count > 0)) {
        result = false;
    }
    if ((s3_count > 0 && s7_count == 0) || (s3_count == 0 && s7_count > 0)) {
        result = false;
    }

    int data_types_count = (s1_count > 0) + (s2_count > 0) + (s3_count > 0);
    if (data_types_count > 1) {
        printf("Data section contains multiple types of records.\n");
        result = false;
    }
    int term_types_count = (s7_count > 0) + (s8_count > 0) + (s9_count > 0);
    if (term_types_count > 1) {
        printf("Termination section contains multiple types of records.\n");
        result = false;
    }

    return result;
}

/*******************************************************************************
* EOF
*******************************************************************************/