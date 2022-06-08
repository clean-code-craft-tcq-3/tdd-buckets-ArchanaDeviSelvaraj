#include "CurrentMeasurementRange.h"

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int DetectContinuousRanges(int currentsamplesarray[])
{
  qsort(currentsamplesarray, sizeof(currentsamplesarray), sizeof(int), cmpfunc);
  return 0;
  //TDD Step2 : Just added function to make code compile
  //end of step2 as expected test failed since actual code implementation not yet done : Assertion `DetectContinuousRanges(currentsamplesarray) == 2' failed.
}
