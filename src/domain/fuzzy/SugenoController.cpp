#include "continental/fuzzy/domain/fuzzy/SugenoController.h"
#include "continental/fuzzy/domain/fuzzy/SugenoRule.h"
#include "continental/fuzzy/domain/fis/System.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fuzzy {

SugenoController::SugenoController()
{
}

continental::fuzzy::domain::fis::System SugenoController::getSugenoFisSystem() const
{
    return m_sugenoFisSystem;
}

void SugenoController::setSugenoFisSystem(const continental::fuzzy::domain::fis::System &sugenoFisSystem)
{
    m_sugenoFisSystem = sugenoFisSystem;
}

std::map<QString, fuzzy::variable::SugenoInput> SugenoController::getSugenoInputs() const
{
    return m_sugenoInputs;
}

void SugenoController::setSugenoInputs(const std::map<QString, fuzzy::variable::SugenoInput> &sugenoInputs)
{
    m_sugenoInputs = sugenoInputs;
}

std::map<QString, fuzzy::variable::SugenoOutput> SugenoController::getSugenoOutputs() const
{
    return m_sugenoOutputs;
}

void SugenoController::setSugenoOutputs(const std::map<QString, fuzzy::variable::SugenoOutput> &sugenoOutputs)
{
    m_sugenoOutputs = sugenoOutputs;
}

std::map<QString, SugenoRule> SugenoController::getSugenoRules() const
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
