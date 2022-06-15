#include <assert.h>
#include "CurrentMeasurementRange.h"

int main()
{
int *ptr;
int rangeinfo[100][4];
printf("Test case 1");
int samplesarray[] = {4,5};
int arraysize = sizeof(samplesarray) / sizeof(samplesarray[0]);
printf("\n Size : %d",arraysize);
ptr = detectRangeCountAndPrintDetails(samplesarray,arraysize);
//Test case to check start of range
assert(*(ptr+4) == 4);
//Test case to check end of range
assert(*(ptr+5) == 5);
//Test case to check number of readings in the range
assert(*(ptr+6) == 2);
//Test case to check number of range detected
assert(*(ptr+7) == 1);  
printf("\n\nTest case 2");
int samplesarray1[] = {3, 3, 5, 4, 10, 11, 12};
int arraysize1 = sizeof(samplesarray1) / sizeof(samplesarray1[0]);
ptr = detectRangeCountAndPrintDetails(samplesarray1,arraysize1);
//Test case to check start of range
assert(*(ptr+4) == 3);
assert(*(ptr+8) == 10);
//Test case to check end of range
assert(*(ptr+5) == 5);
assert(*(ptr+9) == 12);
//Test case to check number of readings in the range
assert(*(ptr+6) == 4);
assert(*(ptr+10) == 3);
//Test case to check number of range detected
assert(*(ptr+11) == 2);  
printf("\n\nTest case 3");
int samplesarray2[] = {3, 30, 5, 7, 10, 15, 12, 20};
int arraysize2 = sizeof(samplesarray2) / sizeof(samplesarray2[0]);
ptr = detectRangeCountAndPrintDetails(samplesarray2,arraysize2);
//Test case to check number of range detected
assert(*(ptr+3) == 0); 
printf("\n\nTest case 4");
int samplesarray3[] = {-3, -30, -5, -7, -10, -11, -12, 20, -6};
int arraysize3 = sizeof(samplesarray3) / sizeof(samplesarray3[0]);
ptr = detectRangeCountAndPrintDetails(samplesarray3,arraysize3); 
printf("\n\nTest case 5");
int samplesarray4[] = {-2,-1,0,1,2,3,4,5};
int arraysize4 = sizeof(samplesarray4) / sizeof(samplesarray4[0]);
//assert(detectRangeCountAndPrintDetails(samplesarray4,arraysize4) == 1);
printf("\n\nTest case 6");
int samplesarray5[] = {};
int arraysize5 = sizeof(samplesarray5) / sizeof(samplesarray5[0]);
//assert(detectRangeCountAndPrintDetails(samplesarray5,arraysize5) == 0);
  
//Testcase to check isConsecutive fucntion
assert(isConsecutive(0) == 1);
assert(isConsecutive(1) == 1);  
assert(isConsecutive(5) == 0);
return 0;
}
