#include <string.h>
#include <stdlib.h>
#include <stdio.h>

const unsigned int MAX_LENGTH = 1 * 1024 * 1024;  
const unsigned int CHUNK_SIZE = 128;             

struct Table{
    char byteFromFile;
    int freq;
};

struct Table* analysFileByts(FILE* F) {
    struct Table* table;
    char* buf;
    while (fread(buf, sizeof(char), 1, F) == 1) {
        analysByte(buf, &table);
    }
    if (feof(F)) {
        return table;
    }
    else printf("File read error.");
}
// ------TODO  ������������� ��������� ������� � ����� ����� 
void analysByte(char inputByte, struct Table** table) {
    static unsigned int len = 128, endTable = 0;
    static int init = 0;
    static struct Table* box;

    if (init == 0) {
        box = (struct Table*)malloc(sizeof(struct Table) * len);
        *table = box;// ��������� �� ������� � ������ �������
        init = 1;
    }

    for (unsigned int i = 0; i < endTable; i++) {
        if (inputByte == box[i].byteFromFile) {
            box[i].freq++;
            goto further;
        }
    }
    if (len > MAX_LENGTH) {
        free(box);
        err(EXIT_FAILURE, "������� ����� ������� ������!\n");
    }
    if (endTable >= len) {
        len += 128;
        box = (struct Table*)realloc(box, sizeof(struct Table) * len);
        *table = box;// ��������� �� ������� � ������ �������
    }
    box[endTable].byteFromFile = inputByte;
    box[endTable].freq = 1;
    endTable++;
    further:;
}
