#include "continental/fuzzy/domain/fis/MembershipFunction.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {

MembershipFunction::MembershipFunction()
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

continental::fuzzy::domain::fis::definition::Functions MembershipFunction::getFunction() const
{
    return m_function;
}

void MembershipFunction::setFunction(const continental::fuzzy::domain::fis::definition::Functions &function)
{
    m_function = function;
}

}
}
}
}
