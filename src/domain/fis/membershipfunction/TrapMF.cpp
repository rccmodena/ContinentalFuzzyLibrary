#include "continental/fuzzy/domain/fis/membershipfunction/TrapMF.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace membershipfunction {

TrapMF::TrapMF()
{

}

TrapMF::~TrapMF()
{

}

double TrapMF::getA() const
{
    return m_a;
}

void TrapMF::setA(double a)
{
    m_a = a;
}

double TrapMF::getB() const
{
    return m_b;
}

void TrapMF::setB(double b)
{
    m_b = b;
}

double TrapMF::getC() const
{
    return m_c;
}

void TrapMF::setC(double c)
{
    m_c = c;
}

double TrapMF::getD() const
{
    return m_d;
}

void TrapMF::setD(double d)
{
    m_d = d;
}

}
}
}
}
}
