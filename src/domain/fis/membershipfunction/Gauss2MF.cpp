#include "continental/fuzzy/domain/fis/membershipfunction/Gauss2MF.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace membershipfunction {

Gauss2MF::Gauss2MF()
{

}

QString Gauss2MF::getName() const
{
    return m_name;
}

void Gauss2MF::setName(const QString &name)
{
    m_name = name;
}

float Gauss2MF::getSigma1() const
{
    return m_sigma1;
}

void Gauss2MF::setSigma1(float sigma1)
{
    m_sigma1 = sigma1;
}

float Gauss2MF::getMean1() const
{
    return m_mean1;
}

void Gauss2MF::setMean1(float mean1)
{
    m_mean1 = mean1;
}

float Gauss2MF::getSigma2() const
{
    return m_sigma2;
}

void Gauss2MF::setSigma2(float sigma2)
{
    m_sigma2 = sigma2;
}

float Gauss2MF::getMean2() const
{
    return m_mean2;
}

void Gauss2MF::setMean2(float mean2)
{
    m_mean2 = mean2;
}

}
}
}
}
}
