#ifndef BINDISTRMODBP_SAMPLEINVERSETRANSFORM_H
#define BINDISTRMODBP_SAMPLEINVERSETRANSFORM_H

#include "Sample.h"
#include "theoreticalDistribution.h"
//std::random_device rd;
//extern std::mt19937 generator;
class SampleInverseTransform : public Sample {
public:
    SampleInverseTransform(theoreticalDistribution& d) : Sample(d) {};
    SampleInverseTransform(int _m, double _p) : Sample(_m, _p) {};
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
    ~SampleInverseTransform() override;
};



#endif //BINDISTRMODBP_SAMPLEINVERSETRANSFORM_H
