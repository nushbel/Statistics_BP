#ifndef BINDISTRMODBP_CHISQUARE_H
#define BINDISTRMODBP_CHISQUARE_H
#include "Sample.h"


class ChiSquare {
public:
    double* empiricalFreq = nullptr;
    double* theorFreq = nullptr;
    double* theorFreq_g = nullptr;
    double* empiricalFreq_g = nullptr;
    int df = 0, n = 0;
    double pvalue = 0;
    double ChiSq_statistics = 0;


    ChiSquare(theoreticalDistribution& d, Sample& s);
    ChiSquare(ChiSquare& chi);
    ChiSquare();
    void calculateChisq();
    void mergeSample();
    ~ChiSquare();

    ChiSquare& operator = (ChiSquare&& s) noexcept;


};


#endif //BINDISTRMODBP_CHISQUARE_H
