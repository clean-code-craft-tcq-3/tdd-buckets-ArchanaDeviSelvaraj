#include <assert.h>
#include "CurrentMeasurementRange.h"

int main()
{
//TDD Step 1: Write test code
int samplesarray[] = {3, 3, 5, 4, 10, 11, 12};
int arraysize = sizeof(samplesarray) / sizeof(samplesarray[0]);
printf("Size of the array is: %d\n", arraysize);
assert(DetectContinuousRanges(samplesarray,arraysize) == 2);
 //DetectContinuousRanges(samplesarray,arraysize);
//End of step 1 error observed as expected : error: ‘DetectContinuousRanges’ was not declared in this scope
samplesarray[] = {3, 8, 5, 7, 10, 15, 12, 20};
arraysize = sizeof(samplesarray) / sizeof(samplesarray[0]);
printf("Size of the array is: %d\n", arraysize);
assert(DetectContinuousRanges(samplesarray,arraysize) == 0);
return 0;
}
