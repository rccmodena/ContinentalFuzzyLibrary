#include "continental/fuzzy/domain/fis/RuleVariable.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {

RuleVariable::RuleVariable()
{
}

QString RuleVariable::getName() const
{
    return m_name;
}

void RuleVariable::setName(const QString &name)
{
    m_name = name;
}

QString RuleVariable::getMf() const
{
    return m_mf;
}

void RuleVariable::setMf(const QString &mf)
{
    m_mf = mf;
}

}
}
}
}
