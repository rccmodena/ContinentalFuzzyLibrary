#include "continental/fuzzy/domain/fis/RuleVariable.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {

int RuleVariable::getIndex() const
{
    return m_index;
}

void RuleVariable::setIndex(const int index)
{
    m_index = index;
}

bool RuleVariable::getInputVarNot() const
{
    return m_inputVarNot;
}

void RuleVariable::setInputVarNot(bool inputVarNot)
{
    m_inputVarNot = inputVarNot;
}

float RuleVariable::getValueFromOrigFis() const
{
    return m_valueFromOrigFis;
}

void RuleVariable::setValueFromOrigFis(float valueFromOrigFis)
{
    m_valueFromOrigFis = valueFromOrigFis;
}

}
}
}
}
