#include "CurrentMeasurementRange.h"

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int DetectContinuousRanges(int currentsamplesarray[],int arraysize)
{
  //TDD step3: Implementation and refactoring
  int startvalue=currentsamplesarray[0],endvalue=currentsamplesarray[0],rangecount=0;
  qsort(currentsamplesarray, arraysize, sizeof(int), cmpfunc);
  for( int n = 0 ; n < arraysize; n++ ) 
  {   
      int diff = currentsamplesarray[n+1] - currentsamplesarray[n];
      int consecutive=0;
      int consecutivecount=0;
      //printf("Diff value %d\n",diff);
      if((diff==0) || (diff==1))
      {
       consecutive=1;
       //printf("consecutive value %d\n",consecutive);
      }
     if(consecutive==1)
     {
        consecutivecount++;
        //printf("consecutivecount value %d\n",consecutivecount);
        endvalue = currentsamplesarray[n+1];
     }
     else if(consecutivecount!=0)
     {
        rangecount++;
        printf("rangecount value %d\n",rangecount);
        printf("startvalue %d\n",startvalue);
        printf("endvalue %d\n",endvalue);
        printf("Number of readings %d\n",consecutivecount);
        startvalue = currentsamplesarray[n+1];
        endvalue = currentsamplesarray[n];
     }
  }
  //printf("Consecutive count %d\n",consecutivecount);
  printf("Rangecount count %d\n",rangecount);   
  return rangecount;
  //TDD Step2 : Just added function to make code compile
  //end of step2 as expected test failed since actual code implementation not yet done : Assertion `DetectContinuousRanges(currentsamplesarray) == 2' failed.
}
