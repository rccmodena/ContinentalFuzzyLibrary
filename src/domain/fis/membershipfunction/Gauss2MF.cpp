#include "continental/fuzzy/domain/fis/membershipfunction/Gauss2MF.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace membershipfunction {

Gauss2MF::Gauss2MF()
{

}

Gauss2MF::~Gauss2MF()
{

}

double Gauss2MF::getSigma1() const
{
    return m_sigma1;
}

void Gauss2MF::setSigma1(double sigma1)
{
    m_sigma1 = sigma1;
}

double Gauss2MF::getMean1() const
{
    return m_mean1;
}

void Gauss2MF::setMean1(double mean1)
{
    m_mean1 = mean1;
}

double Gauss2MF::getSigma2() const
{
    return m_sigma2;
}

void Gauss2MF::setSigma2(double sigma2)
{
    m_sigma2 = sigma2;
}

double Gauss2MF::getMean2() const
{
    return m_mean2;
}

void Gauss2MF::setMean2(double mean2)
{
    m_mean2 = mean2;
}

}
}
}
}
}
