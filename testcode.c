#include <assert.h>

int main()
{
//Step 1: Write test code
int currentsamplesarray[7] = {3, 3, 5, 4, 10, 11, 12};
assert(DetectContinuousRanges(currentsamplesarray) == 2);
return 0;
}
