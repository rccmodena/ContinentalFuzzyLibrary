#ifndef CONTINENTAFUZZY_DOMAIN_FIS_RULE_H
#define CONTINENTAFUZZY_DOMAIN_FIS_RULE_H

#include "continental/fuzzy/export.h"
#include "continental/fuzzy/domain/fis/definition/Connections.h"
#include "continental/fuzzy/domain/fis/RuleVariable.h"
#include <QString>
#include <map>
namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {



class CONTINENTALFUZZY_EXPORT_DECL Rule
{

public:
    /// Construtor.
    Rule();

    double getWeight() const;
    void setWeight(double weight);

    definition::Connections getConnection() const;
    void setConnection(const definition::Connections &connection);

    std::map<int, continental::fuzzy::domain::fis::RuleVariable> getInputs() const;
    void setInputs(const std::map<int, continental::fuzzy::domain::fis::RuleVariable> &ruleInputs);

    std::map<int, continental::fuzzy::domain::fis::RuleVariable> getOutputs() const;
    void setOutputs(const std::map<int, continental::fuzzy::domain::fis::RuleVariable> &ruleOutputs);

private:
    double m_weight;
    definition::Connections m_connection;
    std::map<int, continental::fuzzy::domain::fis::RuleVariable> m_ruleInputs;
    std::map<int, continental::fuzzy::domain::fis::RuleVariable> m_ruleOutputs;
};

}
}
}
}

#endif // CONTINENTAFUZZY_SERVICE_FUZZY_FUZZYSERVICE_H
