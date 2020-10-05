#include "continental/fuzzy/domain/fis/Rule.h"
#include "continental/fuzzy/domain/fis/rulevariable/RuleInput.h"
#include "continental/fuzzy/domain/fis/rulevariable/RuleOutput.h"

using namespace continental::fuzzy::domain::fis::rulevariable;
using namespace continental::fuzzy::domain::fis::definition;

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {

Rule::Rule()
{
}

float Rule::getWeight() const
{
    return m_weight;
}

void Rule::setWeight(float weight)
{
    m_weight = weight;
}

Connections Rule::getConnection() const
{
    return m_connection;
}

void Rule::setConnection(const Connections &connection)
{
    m_connection = connection;
}

std::map<int, RuleInput> Rule::getInputs() const
{
    return m_ruleInputs;
}

void Rule::setInputs(const std::map<int, RuleInput> &ruleInputs)
{
    m_ruleInputs = ruleInputs;
}

std::map<int, RuleOutput> Rule::getOutputs() const
{
    return m_ruleOutputs;
}

void Rule::setOutputs(const std::map<int, RuleOutput> &ruleOutputs)
{
    m_ruleOutputs = ruleOutputs;
}



}
}
}
}
