#include "CurrentMeasurementRange.h"

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int DetectContinuousRanges(int currentsamplesarray[],int arraysize)
{
  int diff = 0,consecutive=0,startvalue=currentsamplesarray[0],endvalue=currentsamplesarray[0],rangecount=0;
  qsort(currentsamplesarray, arraysize, sizeof(int), cmpfunc);
  for( int n = 0 ; n < arraysize; n++ ) 
  {   
      diff = currentsamplesarray[n+1] - currentsamplesarray[n];
      if(diff==0 || diff==1)
      {
       consecutive++;
      }
     else
     {
        endvalue = currentsamplesarray[n];
        rangecount++;
     }
   }
  printf("Consecutive count %d\n",consecutive);
  printf("Rangecount count %d\n",rangecount);   
  return 0;
  //TDD Step2 : Just added function to make code compile
  //end of step2 as expected test failed since actual code implementation not yet done : Assertion `DetectContinuousRanges(currentsamplesarray) == 2' failed.
}
