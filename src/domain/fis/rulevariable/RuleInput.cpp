#include "continental/fuzzy/domain/fis/rulevariable/RuleInput.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace rulevariable {

RuleInput::RuleInput()
{

}

QString RuleInput::getInputName() const
{
    return m_inputName;
}

void RuleInput::setInputName(const QString &inputName)
{
    m_inputName = inputName;
}

QString RuleInput::getInputMf() const
{
    return m_inputMf;
}

void RuleInput::setInputMf(const QString &inputMf)
{
    m_inputMf = inputMf;
}

bool RuleInput::getInputVarNot() const
{
    return m_inputVarNot;
}

void RuleInput::setInputVarNot(bool inputVarNot)
{
    m_inputVarNot = inputVarNot;
}

}
}
}
}
}
