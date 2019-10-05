#include "sword_csv.h"
#include <stdio.h>

static unsigned _failures = 0;


#define CHECK(cond) if(!(cond) && ++_failures) \
    fprintf(stderr, "FAILURE: expression '%s', line %u\n", #cond, (unsigned)__LINE__)

int main(int argc, char const* argv[])
{
    return _failures == 0 ? 0 : 3;
}