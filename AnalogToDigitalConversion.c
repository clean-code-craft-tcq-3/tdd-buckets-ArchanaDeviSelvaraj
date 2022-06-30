#include <math.h>
int convertA2DToAmpere(int maxAmp,int A2Dvalue,int maxA2Dvalue)
{
   int Ampere = round(maxAmp * A2Dvalue / maxA2Dvalue); 
   return Ampere;
}
