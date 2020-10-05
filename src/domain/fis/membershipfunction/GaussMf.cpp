#include "continental/fuzzy/domain/fis/membershipfunction/GaussMF.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace membershipfunction {

GaussMF::GaussMF()
{

}

GaussMF::~GaussMF()
{

}

double GaussMF::getSigma() const
{
    return m_sigma;
}

void GaussMF::setSigma(double sigma)
{
    m_sigma = sigma;
}

double GaussMF::getMean() const
{
    return m_mean;
}

void GaussMF::setMean(double mean)
{
    m_mean = mean;
}

}
}
}
}
}
