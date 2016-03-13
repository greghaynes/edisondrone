#include "wave_generator.h"

#include <cmath>

WaveGenerator::WaveGenerator(std::function<double(double)> gen,
                             double step, double start)
    : m_gen(gen)
    , m_step(step)
    , m_seq_ndx(start) {
}

double WaveGenerator::operator()() {
    double ret = m_gen(m_seq_ndx);
    m_seq_ndx += m_step;
    return ret;
}

SinWaveGenerator::SinWaveGenerator(double step, double start, double amplitude)
    : WaveGenerator(sin, step, start)
    , m_amplitude(amplitude) {
}
