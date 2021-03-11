#ifndef MODELING_H
#define MODELING_H
#include "ChiSquare.h"

class Modeling
{
public:
    int k;
    double p;
    int sampleSize;
    int alt_k = k;
    double alt_p = p;

    Modeling(int _k, double _p, int _sampleSize,int alt_k, double alt_p);
    ChiSquare modelingDist(int type);
};



#endif // MODELING_H
