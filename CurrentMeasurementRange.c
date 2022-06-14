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


void printRangeDetails(int startvalue,int endvalue,int consecutivecount)
{
   printf("\nRange,Readings\n");
   printf("%d - %d,  %d",startvalue,endvalue,consecutivecount+1);
}

int calculateRangeCount(int consecutivecount,int rangecount,int startvalue,int endvalue)
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
                

Range detectRangeCountAndPrintDetails(int currentsamplesarray[],int arraysize)
{
  Range *Rangeinfo[];
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
        rangecount = calculateRangeCount(consecutivecount,rangecount,startvalue,endvalue);
        Rangeinfo[rangecount]->startvalue = startvalue;
        Rangeinfo[rangecount]->endvalue = endvalue;
        startvalue = currentsamplesarray[index+1];
        endvalue = currentsamplesarray[index];
        consecutivecount=0;
     }
  }
  Rangeinfo[rangecount]->rangecount = rangecount;
  printNoRangeFound(Rangeinfo[rangecount]->rangecount);
  return &Rangeinfo;
}
