#include <math.h>
#include <stdio.h>

#define invalid -1;

int convertA2DToAmpere(int maxAmp,int A2Dvalue,int bitresolution)
{
   int Ampere = invalid;
   int maxA2Dvalue = pow(2,bitresolution) - 2;
   if(A2Dvalue<=maxA2Dvalue)
   {
   float convertedvalue = (float)maxAmp * (float)A2Dvalue/(float)maxA2Dvalue; 
   Ampere = round(convertedvalue);
   }
   return Ampere;
}
