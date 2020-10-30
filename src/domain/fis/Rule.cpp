#include "continental/fuzzy/domain/fis/Rule.h"

using namespace continental::fuzzy::domain;
using namespace continental::fuzzy::domain::fis::definition;

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {

Rule::Rule()
{
}

double Rule::getWeight() const
{
    return m_weight;
}

void Rule::setWeight(double weight)
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

const std::map<int, RuleVariable>& Rule::getInputs() const
{
    return m_ruleInputs;
}

void Rule::setInputs(const std::map<int, RuleVariable> &ruleInputs)
{
    m_ruleInputs = ruleInputs;
}

const std::map<int, RuleVariable>& Rule::getOutputs() const
{
    return m_ruleOutputs;
}

void Rule::setOutputs(const std::map<int, RuleVariable> &ruleOutputs)
{
    m_ruleOutputs = ruleOutputs;
}



}
}
}
}
