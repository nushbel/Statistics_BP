//using namespace std;
#include "theoreticalDistribution.h"
#include <math.h>
#include <iostream>

theoreticalDistribution::theoreticalDistribution(int _m, double _p): m(_m), p(_p)
{
    theorFreq = new double [m + 1];
    for (int i = 0; i < m + 1; ++i)
    {
        theorFreq[i] = 0;
    }
}

/** method to compute factorial
     * @param n
     * @return n!

double theoreticalDistribution::factorial(double n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}
*/

/** method to compute probability P(x = k)
     * @param k
     */
double theoreticalDistribution::probCoef(int k)
{
    //return pow(p, k) * pow(1 - p, m - k) * factorial(m) / (factorial(m - k) * factorial(k));
    if (k == 0)
    {
        return (pow(1 - p, m));
    }
     return (probCoef(k - 1) * p / (1 - p) * (m - k + 1) / k);
}

/** method to create an array of theoretical frequencies
     * @param sampleSize - size of a sample
     * @param theorFreq - array of theoretical frequencies
     */
void theoreticalDistribution::createTheorFreq(int sampleSize)
{
    double sP = 0;
    for (int i = 0; i < m + 1; ++i)
    {
        theorFreq[i] = sampleSize * probCoef(i);
        sP += probCoef(i);
    }
}

int theoreticalDistribution::getM() const {
    return m;
}

void theoreticalDistribution::setM(int m) {
    theoreticalDistribution::m = m;
}

double theoreticalDistribution::getP() const {
    return p;
}

void theoreticalDistribution::setP(double p) {
    theoreticalDistribution::p = p;
}
