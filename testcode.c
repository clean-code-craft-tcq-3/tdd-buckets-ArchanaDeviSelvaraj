#include <assert.h>
#include "CurrentMeasurementRange.h"

int main()
{
//TDD Step 1: Write test code
printf("Test case 1");
int samplesarray[] = {4,5};
int arraysize = sizeof(samplesarray) / sizeof(samplesarray[0]);
assert(detectRangeCountAndPrintDetails(samplesarray,arraysize) == 1);
//End of step 1 error observed as expected : error: ‘DetectContinuousRanges’ was not declared in this scope
printf("\nTest case 2");
int samplesarray1[] = {3, 3, 5, 4, 10, 11, 12};
int arraysize1 = sizeof(samplesarray1) / sizeof(samplesarray1[0]);
assert(detectRangeCountAndPrintDetails(samplesarray1,arraysize1) == 2);
printf("\nTest case 3");
int samplesarray2[] = {3, 30, 5, 7, 10, 15, 12, 20};
int arraysize2 = sizeof(samplesarray2) / sizeof(samplesarray2[0]);
assert(detectRangeCountAndPrintDetails(samplesarray2,arraysize2) == 0);
printf("\nTest case 4");
int samplesarray3[] = {-3, -30, -5, -7, -10, -11, -12, 20, -6};
int arraysize3 = sizeof(samplesarray3) / sizeof(samplesarray3[0]);
assert(detectRangeCountAndPrintDetails(samplesarray3,arraysize3) == 2);
printf("\nTest case 5");
int samplesarray4[] = {-2,-1,0,1,2,3,4,5};
int arraysize4 = sizeof(samplesarray4) / sizeof(samplesarray4[0]);
assert(detectRangeCountAndPrintDetails(samplesarray4,arraysize4) == 1);
printf("\nTest case 6");
int samplesarray5[] = {};
int arraysize5 = sizeof(samplesarray5) / sizeof(samplesarray5[0]);
assert(detectRangeCountAndPrintDetails(samplesarray5,arraysize5) == 0);
  
//Testcase to check isConsecutive fucntion
assert(isConsecutive(0) == 1);
assert(isConsecutive(1) == 1);  
assert(isConsecutive(5) == 0);
return 0;
}
