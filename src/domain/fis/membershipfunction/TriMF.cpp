#include "continental/fuzzy/domain/fis/membershipfunction/TriMF.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace membershipfunction {

TriMF::TriMF()
{
}

QString TriMF::getName() const
{
    return m_name;
}

std::list<float> TriMF::getAbcd() const
{
    return m_abcd;
}

void TriMF::setAbcd(const std::list<float> &abcd)
{
    m_abcd = abcd;
}

}
}
}
}
}
