#include "monty.h"
/***/

int _getline(char **line, size_t *n, FILE *stream) {
    size_t capacity = *n, increment;
    int len = 0;
    int c;

    if (line == NULL || n == NULL || stream == NULL) {
        errno = EINVAL;
        return -1;
    }

    if (*line == NULL) {
        *line = malloc(capacity);
        if (*line == NULL) {
            errno = ENOMEM;
            return -1;
        }
    }

    while ((c = getc(stream)) != EOF) {
        increment = len + 1;
        if ( increment >= capacity) {
            capacity *= 2;
            char *new_line = realloc(*line, capacity);
            if (new_line == NULL) {
                free(*line);
                *line = NULL;
                *n = 0;
                errno = ENOMEM;
                return -1;
            }
            *line = new_line;
            *n = capacity;
        }
        (*line)[len++] = c;
        if (c == '\n') {
            break;
        }
    }

    if (len == 0) {
        return -1;
    }

    (*line)[len] = '\0';
    return len;
}