#include <assert.h>
#include "CurrentMeasurementRange.h"
#include "AnalogToDigitalConversion.h"

int main()
{
int *ptr;
int rangeinfo[100][4];
  
printf("Test case 1");
int samplesarray[] = {4,5};
int arraysize = sizeof(samplesarray) / sizeof(samplesarray[0]);
ptr = detectAndPrintRangeDetails(samplesarray,arraysize);
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
ptr = detectAndPrintRangeDetails(samplesarray1,arraysize1);
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
ptr = detectAndPrintRangeDetails(samplesarray2,arraysize2);
//Test case to check number of range detected
assert(*(ptr+3) == 0); 
  
printf("\n\nTest case 4");
int samplesarray3[] = {-3, -30, -5, -7, -10, -11, -12, 20, -6};
int arraysize3 = sizeof(samplesarray3) / sizeof(samplesarray3[0]);
ptr = detectAndPrintRangeDetails(samplesarray3,arraysize3); 
//Test case to check start of range
assert(*(ptr+4) == -12);
assert(*(ptr+8) == -7);
//Test case to check end of range
assert(*(ptr+5) == -10);
assert(*(ptr+9) == -5);
//Test case to check number of readings in the range
assert(*(ptr+6) == 3);
assert(*(ptr+10) == 3);
//Test case to check number of range detected
assert(*(ptr+11) == 2); 

  
printf("\n\nTest case 5");
int samplesarray4[] = {-2,-1,0,1,2,3,4,5};
int arraysize4 = sizeof(samplesarray4) / sizeof(samplesarray4[0]);
ptr = detectAndPrintRangeDetails(samplesarray4,arraysize4);
//Test case to check start of range
assert(*(ptr+4) == -2);
//Test case to check end of range
assert(*(ptr+5) == 5);
//Test case to check number of readings in the range
assert(*(ptr+6) == 8);
//Test case to check number of range detected
assert(*(ptr+7) == 1);  
  
printf("\n\nTest case 6");
int samplesarray5[] = {};
int arraysize5 = sizeof(samplesarray5) / sizeof(samplesarray5[0]);
ptr = detectAndPrintRangeDetails(samplesarray5,arraysize5);
//Test case to check number of range detected
assert(*(ptr+3) == 0); 
  
//Testcase to check isConsecutive fucntion
assert(isConsecutive(0) == 1);
assert(isConsecutive(1) == 1);  
assert(isConsecutive(5) == 0);
  
//Test case for conversion check
assert(convertA2DToAmpere(10,1146,12) == 3);
assert(convertA2DToAmpere(10,4095,12) == -1);
assert(convertA2DToAmpere(10,4094,12) == 10);
  
//Test case for ampere value range check
printf("\n\nTest case 7");
int A2Dvaluearray[] = {1146,4094};
int A2Darraysize = sizeof(A2Dvaluearray) / sizeof(A2Dvaluearray[0]);  
int Amperearray[] = {};
convertA2DToAmpereRange(A2Dvaluearray,A2Darraysize,Amperearray,10,12);
ptr = detectAndPrintRangeDetails(Amperearray,A2Darraysize);
//Test case to check number of range detected
assert(*(ptr+3) == 0);   
  
//Test case for ampere value range check
printf("\n\nTest case 8");
int A2Dvaluearray1[] = {1146,1600,4094};
int A2Darraysize1 = sizeof(A2Dvaluearray1) / sizeof(A2Dvaluearray1[0]);  
int Amperearray1[] = {};
convertA2DToAmpereRange(A2Dvaluearray1,A2Darraysize1,Amperearray1,10,12);
ptr = detectAndPrintRangeDetails(Amperearray1,A2Darraysize1);
//Test case to check start of range
assert(*(ptr+4) == 3);
//Test case to check end of range
assert(*(ptr+5) == 4);
//Test case to check number of readings in the range
assert(*(ptr+6) == 2);
//Test case to check number of range detected
assert(*(ptr+7) == 1);    
  
//Test case for ampere value range check
printf("\n\nTest case 9");
int A2Dvaluearray2[] = {-1000,-1146,-4094};
int A2Darraysize2 = sizeof(A2Dvaluearray2) / sizeof(A2Dvaluearray2[0]);  
int Amperearray2[] = {};
convertA2DToAmpereRange(A2Dvaluearray2,A2Darraysize2,Amperearray2,10,12);
ptr = detectAndPrintRangeDetails(Amperearray2,A2Darraysize2);
//Test case to check start of range
assert(*(ptr+4) == 2);
//Test case to check end of range
assert(*(ptr+5) == 3);
//Test case to check number of readings in the range
assert(*(ptr+6) == 2);
//Test case to check number of range detected
assert(*(ptr+7) == 1);
  
printf("\n\nTest case 10");
int A2Dvaluearray3[] = {4095};
int A2Darraysize3 = sizeof(A2Dvaluearray3) / sizeof(A2Dvaluearray3[0]);  
int Amperearray3[] = {};
convertA2DToAmpereRange(A2Dvaluearray3,A2Darraysize3,Amperearray3,10,12);
ptr = detectAndPrintRangeDetails(Amperearray3,A2Darraysize3);
//Test case to check number of range detected
assert(*(ptr+3) == 0); 
  
return 0;
}
