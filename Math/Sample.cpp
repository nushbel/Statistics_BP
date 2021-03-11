#include "Sample.h"
std::mt19937 generator;

Sample::Sample(theoreticalDistribution &d):m(d.getM()), p(d.getP())
{
    empiricalFreq = new double[m + 1] {0};
}
Sample::Sample(int _m, double _p): m(_m), p(_p)
{
    empiricalFreq = new double [m + 1];
    for (int i = 0; i < m + 1; ++i)
    {
        empiricalFreq[i] = 0;
    }
}

/**
     * Create implementation of a random variable
     * @return
     */
int Sample::randomValue()
{
    return 0;
}
/**
 * Create an array of empirical frequencies by using randomValue()
 * @param sampleSize - size of a sample
*/
void Sample::createEmpiricalFreq(int )
{
    return;
}
/*
* Destructor
*/
Sample::~Sample()
{
    delete [] empiricalFreq;
    empiricalFreq = nullptr;
    p = 0;
    m = 0;
}

/*
 * Getters and setters
 */
int Sample::getM() const
{
    return m;
}
void Sample::setM(int m)
{
    Sample::m = m;
}
double Sample::getP() const
{
    return p;
}
void Sample::setP(double p)
{
    Sample::p = p;
}
