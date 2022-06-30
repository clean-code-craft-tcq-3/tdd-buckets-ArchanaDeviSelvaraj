#include <math.h>
#include <stdio.h>
int convertA2DToAmpere(int maxAmp,int A2Dvalue,int bitresolution)
{
   int maxA2Dvalue = pow(2,bitresolution) - 2;
   float convertedvalue = (float)maxAmp * (float)A2Dvalue/(float)maxA2Dvalue; 
   int Ampere = round(convertedvalue);
   printf("\n Ampere is %d",Ampere);
   return Ampere;
}
