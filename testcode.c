#include <assert.h>
#include "CurrentMeasurementRange.h"

int main()
{
//TDD Step 1: Write test code
int samplesarray1[] = {3, 3, 5, 4, 10, 11, 12};
int arraysize1 = sizeof(samplesarray1) / sizeof(samplesarray1[0]);
printf("Size of the array is: %d\n", arraysize1);
assert(DetectContinuousRanges(samplesarray1,arraysize1) == 2);
 //DetectContinuousRanges(samplesarray,arraysize);
//End of step 1 error observed as expected : error: ‘DetectContinuousRanges’ was not declared in this scope
int samplesarray2[] = {3, 30, 5, 7, 10, 15, 12, 20};
int arraysize2 = sizeof(samplesarray2) / sizeof(samplesarray2[0]);
printf("Size of the array is: %d\n", arraysize2);
//assert(DetectContinuousRanges(samplesarray2,arraysize2) == 0);
 DetectContinuousRanges(samplesarray2,arraysize2);
return 0;
}
