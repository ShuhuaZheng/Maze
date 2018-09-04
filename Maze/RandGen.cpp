#include "RandGen.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>



int RandGen::ourInitialized = 0;

void RandGen::SetSeed(int seed)
{
    srand(seed);
}

RandGen::RandGen()
{
    if (0 == ourInitialized)
    {   ourInitialized = 1;          // only call srand once
        srand(unsigned(time(0)));    // randomize
    }
}

int RandGen::RandInt(int max)
{
    return int(RandReal() * max);
}

int RandGen::RandInt(int low, int max)
{
    return low + RandInt(max-low+1);
}

double RandGen::RandReal()
{
    return rand() / (double(RAND_MAX) + 1);
}

double RandGen::RandReal(double low, double high)
{
    double width = fabs(high-low);
    double thelow = low < high ? low : high;
    return RandReal()*width + thelow;
}

bool RandGen::RandBool()
{
   int coin =  RandInt(0,1);
   return (coin == 0) ? true : false;

}

int RandGen::RandSign()
{
    return RandInt(0,1) *2 - 1;
}