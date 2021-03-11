#ifndef BINDISTRMODBP_SAMPLE_H
#define BINDISTRMODBP_SAMPLE_H

#include <random>

#include<chrono>
#include "theoreticalDistribution.h"
extern std::mt19937 generator;
//std::random_device rd;  //Will be used to obtain a seed for the random number engine
//std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
//std::uniform_real_distribution<> dis(0, 1.0);

class Sample {
protected:
    int m;
    double p;
public:
    double* empiricalFreq;
    /*
     * Constructor
     */
    Sample(theoreticalDistribution& d);
    Sample(int _m, double _p);
    /**
     * Create implementation of a random variable
     * @return
     */
    virtual int randomValue();
    /**
     * Create an array of empirical frequencies by using randomValue()
     * @param sampleSize - size of a sample
     */
    virtual void createEmpiricalFreq(int );
    //sampleSize
    /*
     * Destructor
     */
    virtual ~Sample();

    /*
     * Getters and setters
     */
    int getM() const;

    void setM(int m);

    double getP() const;

    void setP(double p);

};


#endif //BINDISTRMODBP_SAMPLE_H
