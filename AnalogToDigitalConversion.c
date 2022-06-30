#include <math.h>
#include <stdio.h>
int convertA2DToAmpere(int maxAmp,int A2Dvalue,int bitresolution)
{
   int maxA2Dvalue = pow(2,bitresolution) - 2;
   int Ampere = maxAmp * A2Dvalue/maxA2Dvalue; 
   printf("\n Ampere is %d",Ampere);
   return Ampere;
}
