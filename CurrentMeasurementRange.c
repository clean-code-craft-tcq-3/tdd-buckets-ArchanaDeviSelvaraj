#include "CurrentMeasurementRange.h"

int cmpfunc (const void * value1, const void * value2) 
{
   return ( *(int*)value1 - *(int*)value2 );
}

int isConsecutive(int diff)
{
   int consecutive = 0;
   if((diff==0) || (diff==1))
     consecutive=1;
   return consecutive;
}

int detectStartValue(int currentsamplesarray[],int index)
{
   int startvalue = currentsamplesarray[index+1];
   return startvalue;
}

int detectEndValue(int currentsamplesarray[],int index)
{
   int endvalue = currentsamplesarray[index];
   return endvalue;
}

void printRangeDetails(int startvalue,int endvalue,int consecutivecount)
{
   printf("\nRange,Readings\n");
   printf("%d - %d,  %d",startvalue,endvalue,consecutivecount+1);
}

int calculateRangeCount(int consecutivecount,int rangecount,int startvalue,int endvalue,int index)
{
   if(consecutivecount!=0)
     {
        rangecount++;
        printRangeDetails(startvalue,endvalue,consecutivecount);
      }
   return rangecount;
  }

void printNoRangeFound(int rangecount)
{
   if(rangecount==0)
   printf("\nNo Continuous Range detected");
}
                

int detectRangeCountAndPrintDetails(int currentsamplesarray[],int arraysize)
{
  qsort(currentsamplesarray, arraysize, sizeof(int), cmpfunc);
  int rangecount=0,consecutivecount=0,startvalue=currentsamplesarray[0],endvalue=currentsamplesarray[0],index = 0;
  for( index = 0 ; index < arraysize; index++ ) 
  {   
      int diff = currentsamplesarray[index+1] - currentsamplesarray[index];
      int isconsecutive=0;
      isconsecutive = isConsecutive(diff);
      if(isconsecutive==1)
     {
        consecutivecount++;
        endvalue = currentsamplesarray[index+1];
     }
     else 
     {
        rangecount = calculateRangeCount(consecutivecount,rangecount,startvalue,endvalue,index);
        startvalue = detectStartValue(currentsamplesarray,index);
        endvalue = detectEndValue(currentsamplesarray,index);
        consecutivecount=0;
     }
  }
  printNoRangeFound(rangecount);
  return rangecount;
}
