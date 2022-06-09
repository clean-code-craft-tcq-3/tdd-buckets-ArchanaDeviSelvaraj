#include <assert.h>
#include "CurrentMeasurementRange.h"

int main()
{
//TDD Step 1: Write test code
printf("Test case 1");
int samplesarray[] = {4,5};
int arraysize = sizeof(samplesarray) / sizeof(samplesarray[0]);
assert(DetectandPrintContinuousRanges(samplesarray,arraysize) == 1);
//End of step 1 error observed as expected : error: ‘DetectContinuousRanges’ was not declared in this scope
printf("\nTest case 2");
int samplesarray1[] = {3, 3, 5, 4, 10, 11, 12};
int arraysize1 = sizeof(samplesarray1) / sizeof(samplesarray1[0]);
assert(DetectandPrintContinuousRanges(samplesarray1,arraysize1) == 2);
printf("\nTest case 3");
int samplesarray2[] = {3, 30, 5, 7, 10, 15, 12, 20};
int arraysize2 = sizeof(samplesarray2) / sizeof(samplesarray2[0]);
assert(DetectandPrintContinuousRanges(samplesarray2,arraysize2) == 0);
return 0;
}
