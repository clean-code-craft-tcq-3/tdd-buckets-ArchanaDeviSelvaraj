#include "CurrentMeasurementRange.h"

int cmpfunc (const void * value1, const void * value2) {
   return ( *(int*)value1 - *(int*)value2 );
}
//TDD Step4:New functions added to refactor code and to reduce CCN value

int isConsecutive(int diff)
{
   if((diff==0) || (diff==1))
     int consecutive=1;
   return consecutive;
}

int DetectContinuousRanges(int currentsamplesarray[],int arraysize)
{
  //TDD Step3:Code Implementation done to make the test pass
  //as expected at end of step3 test case got passed
  int startvalue=currentsamplesarray[0],endvalue=currentsamplesarray[0],rangecount=0,consecutivecount=0;
  qsort(currentsamplesarray, arraysize, sizeof(int), cmpfunc);
  for( int index = 0 ; index < arraysize; index++ ) 
  {   
      int diff = currentsamplesarray[index+1] - currentsamplesarray[index];
      int consecutive=0;
      consecutive = isConsecutive(diff);
     if(consecutive==1)
     {
        consecutivecount++;
        endvalue = currentsamplesarray[index+1];
     }
     else if(consecutivecount!=0)
     {
        rangecount++;
        printf("Range%d : %d-%d\n",rangecount,startvalue,endvalue);
        printf("Number of readings detected in the above range : %d\n",consecutivecount+1);
        startvalue = currentsamplesarray[index+1];
        endvalue = currentsamplesarray[index];
        consecutivecount=0;
     }
  }
  printf("Total number of continuous ranges detected : %d\n",rangecount);   
  return rangecount;
  //TDD Step2 : Just added function to make code compile
  //end of step2 as expected test failed since actual code implementation not yet done : Assertion `DetectContinuousRanges(currentsamplesarray) == 2' failed.
}
