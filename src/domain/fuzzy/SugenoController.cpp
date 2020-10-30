#include "continental/fuzzy/domain/fuzzy/SugenoController.h"
#include "continental/fuzzy/domain/fuzzy/SugenoRule.h"
#include "continental/fuzzy/domain/fis/System.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fuzzy {

const fis::System& SugenoController::getSugenoFisSystem() const
{
    return m_sugenoFisSystem;
}

void SugenoController::setSugenoFisSystem(const fis::System &sugenoFisSystem)
{
    m_sugenoFisSystem = sugenoFisSystem;
}

const std::map<QString, fuzzy::variable::SugenoInput>& SugenoController::getSugenoInputs() const
{
    return m_sugenoInputs;
}

void SugenoController::setSugenoInputs(const std::map<QString, fuzzy::variable::SugenoInput> &sugenoInputs)
{
    m_sugenoInputs = sugenoInputs;
}

void SugenoController::addSugenoInput(QString nameInput, variable::SugenoInput &sugenoInputs)
{
    m_sugenoInputs.insert(std::pair<QString,variable::SugenoInput>(nameInput, sugenoInputs));
}

const std::map<QString, fuzzy::variable::SugenoOutput>& SugenoController::getSugenoOutputs() const
{
    return m_sugenoOutputs;
}

void SugenoController::setSugenoOutputs(const std::map<QString, fuzzy::variable::SugenoOutput> &sugenoOutputs)
{
    m_sugenoOutputs = sugenoOutputs;
}

void SugenoController::addSugenoOutput(QString nameInput, variable::SugenoOutput &sugenoOutputs)
{
    m_sugenoOutputs.insert(std::pair<QString,variable::SugenoOutput>(nameInput, sugenoOutputs));
}

const std::map<QString, SugenoRule>& SugenoController::getSugenoRules() const
{
    return m_sugenoRules;
}

void SugenoController::setSugenoRules(const std::map<QString, SugenoRule> &sugenoRules)
{
    m_sugenoRules = sugenoRules;
}



}
}
}
}
