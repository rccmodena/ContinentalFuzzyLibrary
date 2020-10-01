#include "continental/fuzzy/domain/fuzzy/rulevariable/SugenoRuleOutput.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fuzzy {
namespace rulevariable {

SugenoRuleOutput::SugenoRuleOutput()
{
    setType("consequent");
}

QString SugenoRuleOutput::getInputName() const
{
    return m_inputName;
}

void SugenoRuleOutput::setInputName(const QString &inputName)
{
    m_inputName = inputName;
}

QString SugenoRuleOutput::getInputMf() const
{
    return m_inputMf;
}

void SugenoRuleOutput::setInputMf(const QString &inputMf)
{
    m_inputMf = inputMf;
}




}
}
}
}
}
