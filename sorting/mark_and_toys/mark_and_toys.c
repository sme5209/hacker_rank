#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

/*
 * Complete the 'maximumToys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY prices
 *  2. INTEGER k
 */
 
bool find_index(int* best_indexes, int size, int index) {
    printf("Current size = %d\n", size);
    bool found = false;
    for (int i = 0; i < size; i++) {
        printf("Index %d with best index = %d\n", i, best_indexes[i]);
        if (best_indexes[i] == index) {
            found = true;
        }
    }
    return found;
}

int maximumToys(int prices_count, int* prices, int k) {
    // Best fit algorithm on unsorted data - O(N^2) time
    int toys = 0;
    int* best_indexes = calloc(k, sizeof(int));
    int best_index_curr_size = 0;
    int total_spent = 0;
    for (int i = 0; i < prices_count; i++) {
        int min_idx = 0;
        while (find_index(best_indexes, best_index_curr_size, min_idx)) {
            min_idx++;
        }
        printf("Price %d = %d\n", i, prices[i]);     
        for (int j = 0; j < prices_count; j++) {
            if (!find_index(best_indexes, best_index_curr_size, j)) {
                if (prices[j] < prices[min_idx]) {
                    min_idx = j;
                    break;
                }
            }
        }
        if (total_spent + prices[min_idx] > k) {
            break;
        }
        best_indexes[best_index_curr_size] = min_idx;
        best_index_curr_size++;
        toys++;
        total_spent += prices[min_idx];
        printf("Min index = %d\nMin price = %d\nTotal spent = %d\n", min_idx, prices[min_idx], total_spent);     
    }
    free(best_indexes);
    return toys;
}

void sort(int* prices) {
    return;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** first_multiple_input = split_string(rtrim(readline()));

    int n = parse_int(*(first_multiple_input + 0));

    int k = parse_int(*(first_multiple_input + 1));

    char** prices_temp = split_string(rtrim(readline()));

    int* prices = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int prices_item = parse_int(*(prices_temp + i));

        *(prices + i) = prices_item;
    }

    int result = maximumToys(n, prices, k);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
