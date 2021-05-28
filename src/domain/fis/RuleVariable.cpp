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

int RuleVariable::getIndexOfInput() const
{
    return m_indexOfInput;
}

void RuleVariable::setIndexOfInput(int indexOfInput)
{
    m_indexOfInput = indexOfInput;
}



}
}
}
}
