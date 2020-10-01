#include "continental/fuzzy/domain/fuzzy/SugenoRule.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fuzzy {

float SugenoRule::getWeight() const
{
    return m_weight;
}

void SugenoRule::setWeight(float weight)
{
    m_weight = weight;
}

std::list<rulevariable::SugenoRuleInput> SugenoRule::getInputs() const
{
    return m_inputs;
}

void SugenoRule::setInputs(const std::list<rulevariable::SugenoRuleInput> &inputs)
{
    m_inputs = inputs;
}

std::list<rulevariable::SugenoRuleOutput> SugenoRule::getOutputs() const
{
    return m_outputs;
}

void SugenoRule::setOutputs(const std::list<rulevariable::SugenoRuleOutput> &outputs)
{
    m_outputs = outputs;
}

fis::definition::Connections SugenoRule::getConnection() const
{
    return m_connection;
}

void SugenoRule::setConnection(const fis::definition::Connections &connection)
{
    m_connection = connection;
}


}
}
}
}
