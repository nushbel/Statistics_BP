#ifndef BINDISTRMODBP_SAMPLEBERNOULLI_H
#define BINDISTRMODBP_SAMPLEBERNOULLI_H

#include "Sample.h"
#include "theoreticalDistribution.h"
//std::random_device rd;
//extern std::mt19937 generator;
class SampleBernoulli : public Sample {
public:
    SampleBernoulli(theoreticalDistribution& d) : Sample(d) {};
    SampleBernoulli(int _m, double _p) : Sample(_m, _p) {};

    /**
     * Create implementation of a random variable
     * @return
     */
    int randomValue() override;
    /**
     * Create an array of empirical frequencies by using randomValue()
     * @param sampleSize - size of a sample
     */
    void createEmpiricalFreq(int sampleSize) override;
    ~SampleBernoulli() override;
};


#endif //BINDISTRMODBP_SAMPLEBERNOULLI_H
