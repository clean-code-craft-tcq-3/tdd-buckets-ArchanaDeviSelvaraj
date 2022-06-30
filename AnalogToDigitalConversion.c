#include <math.h>
#include <stdio.h>
int convertA2DToAmpere(int maxAmp,int A2Dvalue,int bitresolution)
{
   int maxA2Dvalue = pow(2,bitresolution) - 2;
   float convertedvalue = maxAmp * A2Dvalue/maxA2Dvalue; 
   int Ampere = round(convertedvalue);
   printf("\n Ampere is %d",Ampere);
   return Ampere;
}
