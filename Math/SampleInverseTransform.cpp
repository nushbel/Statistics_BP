#include "SampleInverseTransform.h"
//#include <random>
#include <iostream>

using namespace std;

/**
     * Create implementation of a random variable
     * @return
     */
int SampleInverseTransform::randomValue()
{
    //random_device rd;  //Will be used to obtain a seed for the random number engine
    //mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_real_distribution<> dis(0, 1.0);
    for (int  i = 0; i < m; ++i)
    {
        double q = 0;
        if (p > 0.5)
        {
            q = 1 - p;
        }
        else
        {
            q = p;
        }
        double k = 0;
        double s = pow(1 - q, m);
        double t = s;
        double l = q / (1 - q);
        double a = dis(generator);
        //double a = dis(gen);
        while (a >= s)
        {
            t = t * (m - k) * l / (k + 1);
            ++k;
            s += t;
        }
        if (p > 0.5)
        {
            return m - k;
        }
        return k;
    }
    return 0;
}

/**
 * Create an array of empirical frequencies by using randomValue()
 * @param sampleSize - size of a sample
 */
void SampleInverseTransform::createEmpiricalFreq(int sampleSize)
{
    for (int i = 0; i < m + 1; ++i)
    {
        empiricalFreq[i] = 0;
    }
    for(int i = 0; i < sampleSize; ++i)
    {
        empiricalFreq[randomValue()]++;
    }
}

/*
* Destructor
*/
SampleInverseTransform::~SampleInverseTransform()
{
    delete [] empiricalFreq;
    empiricalFreq = nullptr;
    p = 0;
    m = 0;
}
