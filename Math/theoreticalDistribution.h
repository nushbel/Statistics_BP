#ifndef BINDISTRMODBP_THEORETICALDISTRIBUTION_H
#define BINDISTRMODBP_THEORETICALDISTRIBUTION_H


///hello
class theoreticalDistribution {
protected:
    /**
     * distribution parameter m
     */
    int m;
    /**
     * distribution parameter p
     */
     double p;
public:
    double * theorFreq;

    theoreticalDistribution(int _m, double _p);

    /*
     * Getters and setters
     * @return
     */
    int getM() const;

    void setM(int m);

    double getP() const;

    void setP(double p);

    /** method to compute factorial
     * @param n
     * @return n!
     */
    double factorial(double n);

    /*
     * Destructor
     */
    ~theoreticalDistribution() = default;

    /** method to compute probability P(x = k)
     * @param k
     */
    double probCoef(int k);

    /** method to create an array of theoretical frequencies
     * @param sampleSize - size of a sample
     * @param theorFreq - array of theoretical frequencies
     */
    void createTheorFreq(int sampleSize);
};


#endif //BINDISTRMODBP_THEORETICALDISTRIBUTION_H
