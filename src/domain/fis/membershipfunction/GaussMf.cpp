#include "continental/fuzzy/domain/fis/membershipfunction/GaussMF.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace membershipfunction {

GaussMF::GaussMF()
{

}

QString GaussMF::getName() const
{
    return m_name;
}

void GaussMF::setName(const QString &name)
{
    m_name = name;
}

float GaussMF::getSigma() const
{
    return m_sigma;
}

void GaussMF::setSigma(float sigma)
{
    m_sigma = sigma;
}

float GaussMF::getMean() const
{
    return m_mean;
}

void GaussMF::setMean(float mean)
{
    m_mean = mean;
}

}
}
}
}
}
