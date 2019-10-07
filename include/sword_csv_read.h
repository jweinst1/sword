#ifndef SWORD_CSV_READ_H
#define SWORD_CSV_READ_H

#include "compiler-info.h"

/**
 * This controls the amount of stack allocated field slots used before
 * switching to dynamic allocation. Ideally, csv rows shouldn't contain
 * high numbers of fields.
 */
#ifndef SWORD_CSV_READ_STACK_FIELDS
#  define SWORD_CSV_READ_STACK_FIELDS 50
#endif // !SWORD_CSV_READ_STACK_FIELDS

typedef struct {
    const char* field;
    size_t len;
} sword_CsvRead;

typedef struct {
    sword_CsvRead fields[SWORD_CSV_READ_STACK_FIELDS];
    sword_CsvRead* heap_fields;
    size_t fields_len;
} sword_CsvReadRow;


size_t sword_csv_read_row(sword_CsvReadRow* result, const char* data);


#endif // SWORD_CSV_READ_H
