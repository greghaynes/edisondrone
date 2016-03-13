#ifndef WAVE_GENERATOR_H
#define WAVE_GENERATOR_H

#include <functional>

class WaveGenerator {

    public:
        WaveGenerator(std::function<double(double)> gen,
                      double step=.01,
                      double start=0);

        double operator()();

    private:
        std::function<double(double)> m_gen;
        double m_step;
        double m_seq_ndx;
};

class SinWaveGenerator : public WaveGenerator {

    public:
        SinWaveGenerator(double step=.01,
                         double start=0,
                         double amplitude=1);

    private:
        double m_amplitude;

};

#endif
