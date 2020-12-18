#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
struct Table {
    char byteFromFile;
    int freq;
};
struct Table* analysFileByts(FILE*, unsigned long*);
void analysByte(char, struct Table**);
