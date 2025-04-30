#include <stdio.h>
#include <stdlib.h>

int mygetline(char** line, size_t* lim);
void copy(char* to, char* from);

int main() {
    size_t size = 50;
    int len, max = 0;
    char* line = malloc(size * sizeof(char));
    char* longest = malloc(size * sizeof(char));

    if (!line || !longest) {
        printf("Ошибка выделения памяти!\n");
        free(line);
        free(longest);
        return 1;
    }

    while ((len = mygetline(&line, &size)) > 0) {
        if (len > max) {
            max = len;
            if (size < (size_t)max) {
                char* temp = realloc(longest, max);
                if (!temp) {
                    printf("Ошибка перевыделения памяти!\n");
                    break;
                }
                longest = temp;
            }
            copy(longest, line);
        }
    }

    if (max > 0) printf("%s", longest);

    free(line);
    free(longest);
    return 0;
}

int mygetline(char** s, size_t* lim) {
    int c, i = 0;
    while (i < *lim - 1 && (c = getchar()) != '`' && c != '\n') {
        (*s)[i++] = c;
        if (i >= *lim - 1) {
            *lim *= 2;
            char* temp = realloc(*s, *lim * sizeof(char));
            if (!temp) {
                printf("Ошибка перевыделения памяти!\n");
                return -1;
            }
            *s = temp;
        }
    }
    if (c == '\n') (*s)[i++] = c;
    (*s)[i] = '\0';
    return i;
}

void copy(char* to, char* from) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') i++;
}