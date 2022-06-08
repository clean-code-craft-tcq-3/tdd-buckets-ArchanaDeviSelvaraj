#include "CurrentMeasurementRange.h"

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int DetectContinuousRanges(int currentsamplesarray[],int arraysize)
{
  //TDD step3: Implementation and refactoring
  int consecutive=0,startvalue=currentsamplesarray[0],endvalue=currentsamplesarray[0],rangecount=0,consecutivecount=0;
  qsort(currentsamplesarray, arraysize, sizeof(int), cmpfunc);
  for( int n = 0 ; n < arraysize; n++ ) 
  {   
      int diff = currentsamplesarray[n+1] - currentsamplesarray[n];
      printf("Diff value %d\n",diff);
      if(diff==0 || diff==1)
      {
       consecutive=1;
      }
     if(consecutive==1)
     {
        consecutivecount++;
        //endvalue = currentsamplesarray[n+1];
     }
     else
     {
        rangecount++;
        //startvalue = currentsamplesarray[n+1]
        //endvalue = currentsamplesarray[n];
     }
   }
  if(consecutivecount==0)
     {
        rangecount=0;
     }
  printf("Consecutive count %d\n",consecutivecount);
  printf("Rangecount count %d\n",rangecount);   
  return rangecount;
  //TDD Step2 : Just added function to make code compile
  //end of step2 as expected test failed since actual code implementation not yet done : Assertion `DetectContinuousRanges(currentsamplesarray) == 2' failed.
}
