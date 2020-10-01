#include "continental/fuzzy/domain/fis/membershipfunction/TrapMF.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace membershipfunction {

TrapMF::TrapMF()
{
}

QString TrapMF::getName() const
{
    return m_name;
}

std::list<float> TrapMF::getAbcd() const
{
    return m_abcd;
}

void TrapMF::setAbcd(const std::list<float> &abcd)
{
    m_abcd = abcd;
}

}
}
}
}
}
