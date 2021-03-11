#include <iostream>
#include "ChiSquare.h"
#include "PROBDIST.h"

ChiSquare::ChiSquare(theoreticalDistribution& d, Sample& s)
{
    theorFreq = d.theorFreq;
    empiricalFreq = s.empiricalFreq;
    n = d.getM();
    theorFreq_g = new double[n + 1];
    for (int i = 0; i < n + 1; ++i)
    {
        theorFreq_g[i] = d.theorFreq[i];
    }
    empiricalFreq_g = new double[n + 1];
    for (int i = 0; i < n + 1; ++i)
    {
        empiricalFreq_g[i] = s.empiricalFreq[i];
    }
    df = -1;
    pvalue = 0;
    std::cout << pvalue;
    this->mergeSample();
    this->calculateChisq();

}

ChiSquare::ChiSquare(ChiSquare& ch)
{
    theorFreq = ch.theorFreq;
    empiricalFreq = ch.empiricalFreq;
    theorFreq_g = ch.theorFreq_g;
    empiricalFreq_g = ch.empiricalFreq_g;
    n = ch.n;
    df = ch.df;
    pvalue = ch.pvalue;
    ChiSq_statistics = ch.ChiSq_statistics;
}

ChiSquare::ChiSquare()
{
    theorFreq = nullptr;
    empiricalFreq = nullptr;
    theorFreq_g = nullptr;
    empiricalFreq_g = nullptr;
    n = 0;
    df = 0;
    pvalue = 0;
    ChiSq_statistics = 0;
}

void ChiSquare::calculateChisq()
{
    double tChisq = 0;
    for (int i = 0; i < n + 1; ++i)
    {
        if (theorFreq_g[i] != -1)
        {
            tChisq += ((empiricalFreq_g[i] - theorFreq_g[i]) * (empiricalFreq_g[i] - theorFreq_g[i])) / (double)theorFreq_g[i];
            ++df;
        }
    }
    pvalue = 1 - pChi(tChisq, df);
    ChiSq_statistics =  tChisq;
}
void ChiSquare::mergeSample()
{
    int i = 0, j = n;
    bool flag = false;
    while (i < j)
    {
        if (theorFreq_g[i] < 5)
        {
            theorFreq_g[i + 1] += theorFreq_g[i];
            theorFreq_g[i] = -1;
            empiricalFreq_g[i + 1] += empiricalFreq_g[i];
            empiricalFreq_g[i] = -1;
            ++i;
            flag = true;
        }
        if (theorFreq_g[j] < 5)
        {
            theorFreq_g[j - 1] += theorFreq_g[j];
            theorFreq_g[j] = -1;
            empiricalFreq_g[j - 1] += empiricalFreq_g[j];
            empiricalFreq_g[j] = -1;
            --j;
            flag = true;
        }
        if (flag == false)
        {
            if (i == j + 1)
            {
                ++i;
            }
            else
            {
                ++i;
                --j;
            }
        }
        flag = false;
    }
}

ChiSquare& ChiSquare::operator = (ChiSquare&& s) noexcept
{
    n = s.n;
    theorFreq = new double[n + 1];
    for (int i = 0; i < n + 1; ++i)
    {
        theorFreq[i] = s.theorFreq[i];
    }
    empiricalFreq = new double[n + 1];
    for (int i = 0; i < n + 1; ++i)
    {
        empiricalFreq[i] = s.empiricalFreq[i];
    }
    pvalue = s.pvalue;
    df = s.df;
    ChiSq_statistics = s.ChiSq_statistics;
    return *this;
}

ChiSquare::~ChiSquare()
{
    delete [] empiricalFreq;
    delete [] theorFreq;
    empiricalFreq = nullptr;
    theorFreq = nullptr;
    delete [] empiricalFreq_g;
    delete [] theorFreq_g;
    empiricalFreq_g = nullptr;
    theorFreq_g = nullptr;
    n = 0;
    df = 0;
    pvalue = 0;
    ChiSq_statistics = 0;
}
