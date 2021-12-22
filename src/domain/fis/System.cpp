#include "continental/fuzzy/domain/fis/System.h"
#include "continental/fuzzy/domain/fis/Rule.h"

using namespace continental::fuzzy::domain;

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {

System::System()
{
}

System::~System()
{

}

QString System::getName() const
{
    return m_name;
}

void System::setName(const QString &name)
{
    m_name = name;
}

QString System::getFilename() const
{
    return m_filename;
}

void System::setFilename(const QString &filename)
{
    m_filename = filename;
}

definition::ControllerType System::getType() const
{
    return m_type;
}

void System::setType(const definition::ControllerType &type)
{
    m_type = type;
}

QString System::getVersion() const
{
    return m_version;
}

void System::setVersion(const QString &version)
{
    m_version = version;
}

int System::getNumInputs() const
{
    return m_numInputs;
}

void System::setNumInputs(int numInputs)
{
    m_numInputs = numInputs;
}

int System::getNumOutputs() const
{
    return m_numOutputs;
}

void System::setNumOutputs(int numOutputs)
{
    m_numOutputs = numOutputs;
}

int System::getNumRules() const
{
    return m_numRules;
}

void System::setNumRules(int numRules)
{
    m_numRules = numRules;
}

definition::AndMethods System::getAndMethod() const
{
    return m_andMethod;
}

void System::setAndMethod(const definition::AndMethods &andMethod)
{
    m_andMethod = andMethod;
}

definition::OrMethods System::getOrMethod() const
{
    return m_orMethod;
}

void System::setOrMethod(const definition::OrMethods &orMethod)
{
    m_orMethod = orMethod;
}

definition::ImpMethods System::getImpMethod() const
{
    return m_impMethod;
}

void System::setImpMethod(const definition::ImpMethods &impMethod)
{
    m_impMethod = impMethod;
}

definition::AggMethods System::getAggMethod() const
{
    return m_aggMethod;
}

void System::setAggMethod(const definition::AggMethods &aggMethod)
{
    m_aggMethod = aggMethod;
}

definition::DefuzzMethods System::getDefuzzMethod() const
{
    return m_defuzzMethod;
}

void System::setDefuzzMethod(const definition::DefuzzMethods &defuzzMethod)
{
    m_defuzzMethod = defuzzMethod;
}

const std::vector<variable::Input> &System::getInputs() const
{
    return m_inputs;
}

std::vector<variable::Input>& System::getInputs()
{
    return m_inputs;
}

void System::setInputs(const std::vector<variable::Input> &inputs)
{
    m_inputs = inputs;
}

void System::addInput(const variable::Input &input)
{
    m_inputs.push_back(input);
}

const std::vector<variable::Output>& System::getOutputs() const
{
    return m_outputs;
}

void System::setOutputs(const std::vector<variable::Output> &outputs)
{
    m_outputs = outputs;
}

void System::addOutput(const variable::Output &output)
{
    m_outputs.push_back(output);
}

const std::vector<Rule>& System::getRules() const
{
    return m_rules;
}

void System::setRules(const std::vector<Rule> &rules)
{
    m_rules = rules;
}

void System::addRule(const Rule &rule)
{
    m_rules.push_back(rule);
}

}
}
}
}
