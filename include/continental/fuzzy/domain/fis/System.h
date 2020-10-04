#ifndef CONTINENTAFUZZY_DOMAIN_FIS_SYSTEM_H
#define CONTINENTAFUZZY_DOMAIN_FIS_SYSTEM_H

#include "continental/fuzzy/export.h"
#include "continental/fuzzy/domain/fis/definition/AggMethods.h"
#include "continental/fuzzy/domain/fis/definition/AndMethods.h"
#include "continental/fuzzy/domain/fis/definition/Blocks.h"
#include "continental/fuzzy/domain/fis/definition/Connections.h"
#include "continental/fuzzy/domain/fis/definition/ControllerType.h"
#include "continental/fuzzy/domain/fis/definition/DefuzzMethods.h"
#include "continental/fuzzy/domain/fis/definition/Functions.h"
#include "continental/fuzzy/domain/fis/definition/ImpMethods.h"
#include "continental/fuzzy/domain/fis/definition/OrMethods.h"
#include "continental/fuzzy/domain/fis/Rule.h"
#include "continental/fuzzy/domain/fis/variable/Input.h"
#include "continental/fuzzy/domain/fis/variable/Output.h"
#include <QString>
#include <map>
#include <list>

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis
{
class CONTINENTALFUZZY_EXPORT_DECL System
{

public:
    /// Construtor.
    System();

  //  const int MAX_NUM_OUTPUTS = 1;

    //const std::map<std::string, std::string> DICT_CONNECTORS = { std::pair<std::string, std::string> ("1", "AND"), std::pair<std::string, std::string> ("2", "OR")};


    QString getFilename() const;
    void setFilename(const QString &filename);

    definition::ControllerType getType() const;
    void setType(const definition::ControllerType &type);

    QString getVersion() const;
    void setVersion(const QString &version);

    int getNumInputs() const;
    void setNumInputs(int numInputs);

    int getNumOutputs() const;
    void setNumOutputs(int numOutputs);

    int getNumRules() const;
    void setNumRules(int numRules);

    definition::AndMethods getAndMethod() const;
    void setAndMethod(const definition::AndMethods &andMethod);

    definition::OrMethods getOrMethod() const;
    void setOrMethod(const definition::OrMethods &orMethod);

    definition::ImpMethods getImpMethod() const;
    void setImpMethod(const definition::ImpMethods &impMethod);

    definition::AggMethods getAggMethod() const;
    void setAggMethod(const definition::AggMethods &aggMethod);

    definition::DefuzzMethods getDefuzzMethod() const;
    void setDefuzzMethod(const definition::DefuzzMethods &defuzzMethod);

    std::shared_ptr<std::map<int, variable::Input>> getInputs() const;
    void setInputs(const std::shared_ptr<std::map<int, variable::Input>> inputs);
    void addInput(const int inputNumber,const std::shared_ptr<variable::Input> input);

    std::map<int, variable::Output> getOutputs() const;
    void setOutputs(const std::map<int, variable::Output> &outputs);

    std::map<int, Rule> getRules() const;
    void setRules(const std::map<int, Rule> &rules);

    QString getName() const;
    void setName(const QString &name);

private:
    QString m_name = "";
    QString m_filename = "";
    definition::ControllerType m_type = definition::ControllerType::none;
    QString m_version = "";
    int m_numInputs = 0;
    int m_numOutputs = 0;
    int m_numRules = 0;
    definition::AndMethods m_andMethod = definition::AndMethods::none;
    definition::OrMethods m_orMethod = definition::OrMethods::none;
    definition::ImpMethods m_impMethod = definition::ImpMethods::none;
    definition::AggMethods m_aggMethod = definition::AggMethods::none;
    definition::DefuzzMethods m_defuzzMethod = definition::DefuzzMethods::none;
    std::shared_ptr<std::map<int, domain::fis::variable::Input>> m_inputs = std::make_shared<std::map<int, domain::fis::variable::Input>>();
    std::map<int, variable::Output> m_outputs;
    std::map<int, fis::Rule> m_rules;
};

}
}
}
}

#endif // CONTINENTAFUZZY_SERVICE_FUZZY_FUZZYSERVICE_H
