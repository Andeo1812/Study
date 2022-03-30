#pragma once //  NOLINT

#include "blank.h"
#include "list_blanks.h"

#define ERR_OPEN -1

typedef struct node_list_parts {
    list_blanks_t *list_b;

    struct node_list_parts *next;
} node_list_parts_t;

node_list_parts_t *create_part(const size_t number, char *storage, char *responsible);

//  Data entry, structure filling
int input(char const *source, size_t *count_error, node_list_parts_t **first1);

//  Search combination storage and responsible in struct
node_list_parts_t *find_combination(node_list_parts_t *first, const char *storage, const char *responsible);

//  Output functional
int output_parts(char const *target, node_list_parts_t* first, size_t *count_error);

//  Freeing Memory
int free_list_parts(node_list_parts_t* first);



