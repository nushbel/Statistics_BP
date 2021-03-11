#include "modeling.h"
#include "ChiSquare.h"
#include "SampleBernoulli.h"
#include "SampleInverseTransform.h"
#include "theoreticalDistribution.h"
#include "PROBDIST.h"
#include <QMessageBox>

Modeling::Modeling(int _k, double _p, int _sampleSize, int _alt_k, double _alt_p):k(_k), p(_p), sampleSize(_sampleSize), alt_k(_alt_k), alt_p(_alt_p)
{
}

//ChiSquare Modeling::modelingDist(double* empFreq, double* theorFreq, double* pval, int type, int* df)
ChiSquare Modeling::modelingDist(int type)
{

        //theoreticalDistribution d(k, p);
        theoreticalDistribution d(alt_k, alt_p);

        d.createTheorFreq(sampleSize);

        // наверное штука ф-я не нужна
        for (int i = 0; i<k+1; ++i)
        {
            //theorFreq[i] = d.theorFreq[i];
        }


        Sample *sample;
        if (type == 1)
        {
            //sample = new SampleBernoulli(d);
            sample = new SampleBernoulli(k, p);

        }
        else
        {
            //sample = new SampleInverseTransform(d);
            sample = new SampleInverseTransform(k, p);
        }

        sample->createEmpiricalFreq(sampleSize);
        //и вот эта соотвтственно тоже не нужна
        for (int i = 0; i<k+1; ++i)
        {
           // empFreq[i] = sample->empiricalFreq[i];
        }


        ChiSquare ch(d, *sample);
        //ch.mergeSample();
        //ch.calculateChisq();
        //pval и df надо доставать из chisq
        //*pval = 1 - pChi(ch.calculateChisq(), ch.df);
        //*df = ch.df;
        //return ch.calculateChisq();
        return ch;
}
