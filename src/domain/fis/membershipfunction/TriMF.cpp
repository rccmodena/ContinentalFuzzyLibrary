#include "continental/fuzzy/domain/fis/membershipfunction/TriMF.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace membershipfunction {

TriMF::TriMF()
{
}

TriMF::~TriMF()
{

}

double TriMF::getA() const
{
    return m_a;
}

void TriMF::setA(double a)
{
    m_a = a;
}

double TriMF::getB() const
{
    return m_b;
}

void TriMF::setB(double b)
{
    m_b = b;
}

double TriMF::getC() const
{
    return m_c;
}

void TriMF::setC(double c)
{
    m_c = c;
}


}
}
}
}
}
