#include "continental/fuzzy/domain/fis/MembershipFunction.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {

MembershipFunction::MembershipFunction()
{
}

MembershipFunction::~MembershipFunction()
{

}

QString MembershipFunction::getName() const
{
    return m_name;
}

void MembershipFunction::setName(const QString &name)
{
    m_name = name;
}

}
}
}
}
