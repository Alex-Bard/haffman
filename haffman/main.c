#include "Header.h";

int main() {
    FILE* file;
    unsigned long n;
    file = fopen("f.txt", "r");
    if (file == NULL) {
        printf("hhhhh");
    }
    else {
        struct Table* table = analysFileByts(file, &n);
    }

}
