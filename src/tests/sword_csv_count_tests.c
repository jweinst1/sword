#include "sword_csv_count.h"
#include <stdio.h>

static unsigned _failures = 0;


#define CHECK(cond) if(!(cond) && ++_failures) \
    fprintf(stderr, "FAILURE: expression '%s', line %u\n", #cond, (unsigned)__LINE__)
    
    
static void test_sword_csv_count_rows(void)
{
    long result = 0;
    static const char* TEST_STR = "r,a,c\n\n a,b\n";
    result = sword_csv_count_rows(TEST_STR);
    CHECK(result == 2);
}

static void test_sword_csv_count_cols(void)
{
    long result = 0;
    static const char* TEST_STR = "r,ab,c\n\n a,b,5\n";
    result = sword_csv_count_cols(TEST_STR);
    CHECK(result == 3);
}

int main(int argc, char const* argv[])
{
    test_sword_csv_count_rows();
    test_sword_csv_count_cols();
    return _failures == 0 ? 0 : 3;
}