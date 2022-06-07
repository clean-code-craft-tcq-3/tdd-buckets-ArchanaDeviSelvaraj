#include <assert.h>

int main()
{
//TDD Step 1: Write test code
int currentsamplesarray[7] = {3, 3, 5, 4, 10, 11, 12};
assert(DetectContinuousRanges(currentsamplesarray) == 2);
//End of step 1 error observed as expected : error: ‘DetectContinuousRanges’ was not declared in this scope
return 0;
}
