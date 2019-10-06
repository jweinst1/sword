#ifndef SWORD_CSV_COUNT_H
#define SWORD_CSV_COUNT_H

#include "compiler-info.h"

long sword_csv_count_rows(const char* data);
/**
 * Counts the number of columns in the first row of \c data.
 * Always returns at least 1. An empty row is considered to have one column as an
 * empty string.
 */
long sword_csv_count_cols(const char* data);

#endif // SWORD_CSV_COUNT_H
