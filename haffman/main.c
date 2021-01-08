#include "Header.h";

int main() {
    FILE* file;
    unsigned long n;
    file = fopen("f.txt", "rb");
    if (file == NULL) {
        printf("hhhhh");
    }
    else {
        struct Table* table = analysFileByts(file, &n);
    }

}
