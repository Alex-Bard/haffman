#include <string.h>
#include <stdlib.h>
#include <stdio.h>

const unsigned int MAX_LENGTH = 1 * 1024 * 1024;  
const unsigned int CHUNK_SIZE = 128;             

struct Table{
    char byteFromFile;
    int freq;
};

// ------TODO  предусмотреть получение события о конце файла
void analysByte(char inputByte, int EndFile) {
    static unsigned int len = 128, endTable = 0;
    static int init = 0;
    static struct Table* box;

    if (init == 0) {
        box = (struct Table*)malloc(sizeof(struct Table) * len);
        init = 1;
    }

    if (EndFile == 1) {
        
    }
    for (unsigned int i = 0; i < endTable; i++) {
        if (inputByte == box[i].byteFromFile) {
            box[i].freq++;
            goto further;
        }
    }
    if (len > MAX_LENGTH) {
        free(box);
        err(EXIT_FAILURE, "Слишком много входных данных!\n");
    }
    if (endTable >= len) {
        len += 128;
        box = (struct Table*)realloc(box, sizeof(struct Table) * len);
    }
    box[endTable].byteFromFile = inputByte;
    box[endTable].freq = 1;
    endTable++;
further:;
}



/*


    int j, i;
    static struct ZACHETKA* box;
    box = (struct ZACHETKA*)malloc(sizeof(struct ZACHETKA) * n);
    struct ZACHETKA tmp;

    for (i = 0; i < n; i++)
    {
        puts("Vvedite Familiy\n");
        scanf("%s", box[i].last_name);

        puts("Vvedite nomer\n");
        scanf("%d", &box[i].no);
        puts("Vvedite ocenki (3)\n");
        scanf("%d %d %d", &box[i].ocenka[0], &box[i].ocenka[1], &box[i].ocenka[2]);
    }

    //- Cортировка по фамилии
    for (i = n - 1; i > 0; i--)
        for (j = 0; j < i; j++)
            if (strcmp(box[j].last_name, box[j + 1].last_name) > 0)
            {
                tmp = box[j];
                box[j] = box[j + 1];
                box[j + 1] = tmp;
            }

    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++) {
            if (box[i].ocenka[j] == 3)
                goto fin; // да, в данном случае это оправдано, это си
        }
        printf("%s\n", box[i].last_name);
        printf("%d\n", box[i].no);
        for (j = 0; j < 3; j++)
            printf("%d ", box[i].ocenka[j]);
        printf("\n");
    fin:;
    }

    free(box);
    return 0;
}

int main() {
    unsigned int str_len = CHUNK_SIZE;
    char* str_ptr = malloc(CHUNK_SIZE);           // Выделяем первый килобайтный блок

    if (str_ptr == NULL)
        err(EXIT_FAILURE, "Не удалось выделить память!\n");

    int c;
    unsigned int i;
    for (i = 0, c = EOF; (c = getchar()) != '\n' && c != EOF; i++) {
        str_ptr[i] = c;

        if (i == MAX_LENGTH) {
            free(str_ptr);
            err(EXIT_FAILURE, "Слишком много входных данных!\n");
        }

        if (i == str_len) {                       // Блок заполнен
            str_len = i + CHUNK_SIZE;
            str_ptr = realloc(str_ptr, str_len);  // Расширяем блок на ещё один килобайт
        }
    }
    str_ptr[i] = '\0';                            // Признак конца строки

    printf("%s\n", str_ptr);

    free(str_ptr);
    str_ptr = NULL;

    return EXIT_SUCCESS;
}

*/
