#include "sword_io.h"

void sword_io_file_size(const char* path, size_t* sz)
{
    FILE* fp;
    fp = fopen(path, "r");
    if(fp == NULL) {
        *sz = 0;
        return;
    }
    fseek(fp, 0L, SEEK_END);
    *sz = ftell(fp);
    fclose(fp);
}