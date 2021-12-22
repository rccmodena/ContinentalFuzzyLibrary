#include "continental/fuzzy/domain/fuzzy/SugenoRuleVariable.h"
#include "continental/fuzzy/domain/fuzzy/rulevariable/SugenoRuleInput.h"
#include "continental/fuzzy/domain/fuzzy/rulevariable/SugenoRuleOutput.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fuzzy {

QString SugenoRuleVariable::getName() const
{
    return m_name;
}

void SugenoRuleVariable::setName(const QString &name)
{
    m_name = name;
}

QString SugenoRuleVariable::getType() const
{
    return m_type;
}

void SugenoRuleVariable::setType(const QString &type)
{
    m_type = type;
}

}
}
}
}
