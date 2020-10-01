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

QString Rule::getName() const
{
    return m_name;
}

void Rule::setName(const QString &name)
{
    m_name = name;
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

std::list<RuleInput> Rule::getInputs() const
{
    return m_inputs;
}

void Rule::setInputs(const std::list<RuleInput> &inputs)
{
    m_inputs = inputs;
}

std::list<RuleOutput> Rule::getOutputs() const
{
    return m_outputs;
}

void Rule::setOutputs(const std::list<RuleOutput> &outputs)
{
    m_outputs = outputs;
}



}
}
}
}
