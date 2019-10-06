#include "sword_csv_count.h"

long sword_csv_count_rows(const char* data)
{
    long row_count = 0;
    int got_data = 0;
    while(*data) {
        if(got_data) {
            if(*data == '\n') {
                row_count++;
                got_data = 0;
            }
            data++;
        } 
        else {
            switch(*data) {
                case '\n':
                case ' ':
                case '\t':
                    data++;
                    break;
                default:
                    got_data = 1;
                    data++;
            }
        }
    }
    return row_count;
}

long sword_csv_count_cols(const char* data)
{
    long col_count = 1;
    while(*data && *data != '\n') {
        if(*data++ == ',')
            col_count++;
    }
    return col_count;
}