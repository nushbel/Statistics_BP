#include "SampleBernoulli.h"
//#include <random>
#include <iostream>

using namespace std;

/**
     * Create implementation of a random variable
     * @return
     */
int SampleBernoulli::randomValue()
{
    uniform_real_distribution<> dis(0, 1.0);
    int k = 0;
    for (int i = 0; i < m; ++i)
    {
        double a = dis(generator);
        int j = (int)(a + p);
        k += j;
    }
    return k;
}

/**
 * Create an array of empirical frequencies by using randomValue()
 * @param sampleSize - size of a sample
 */
void SampleBernoulli::createEmpiricalFreq(int sampleSize)
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
SampleBernoulli::~SampleBernoulli()
{
    delete [] empiricalFreq;
    empiricalFreq = nullptr;
    p = 0;
    m = 0;
}
