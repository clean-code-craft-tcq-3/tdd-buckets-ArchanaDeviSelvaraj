#include <stdio.h>
#include <stdlib.h>
typedef struct Range 
{
   int startvalue; int endvalue; int rangecount;
}Range;
Range Rangeinfo[50];
Range detectRangeCountAndPrintDetails(int currentsamplesarray[],int arraysize);
int isConsecutive(int diff);
