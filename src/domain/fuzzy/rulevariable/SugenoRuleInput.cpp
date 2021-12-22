#include "continental/fuzzy/domain/fuzzy/rulevariable/SugenoRuleInput.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fuzzy {
namespace rulevariable {

SugenoRuleInput::SugenoRuleInput()
{
    setType("antecedent");
}

QString SugenoRuleInput::getInputName() const
{
    return m_inputName;
}

void SugenoRuleInput::setInputName(const QString &inputName)
{
    m_inputName = inputName;
}

QString SugenoRuleInput::getInputMf() const
{
    return m_inputMf;
}

void SugenoRuleInput::setInputMf(const QString &inputMf)
{
    m_inputMf = inputMf;
}

bool SugenoRuleInput::getInputVarNot() const
{
    return m_inputVarNot;
}

void SugenoRuleInput::setInputVarNot(bool inputVarNot)
{
    m_inputVarNot = inputVarNot;
}

}
}
}
}
}
