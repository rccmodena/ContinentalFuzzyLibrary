#ifndef CONTINENTAFUZZY_DOMAIN_FIS_RULE_H
#define CONTINENTAFUZZY_DOMAIN_FIS_RULE_H

#include "continental/fuzzy/export.h"
#include "continental/fuzzy/domain/fis/definition/Connections.h"
#include "continental/fuzzy/domain/fis/rulevariable/RuleInput.h"
#include "continental/fuzzy/domain/fis/rulevariable/RuleOutput.h"
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

    float getWeight() const;
    void setWeight(float weight);

    definition::Connections getConnection() const;
    void setConnection(const definition::Connections &connection);

    std::map<int, continental::fuzzy::domain::fis::rulevariable::RuleInput> getInputs() const;
    void setInputs(const std::map<int, continental::fuzzy::domain::fis::rulevariable::RuleInput> &ruleInputs);

    std::map<int, continental::fuzzy::domain::fis::rulevariable::RuleOutput> getOutputs() const;
    void setOutputs(const std::map<int, continental::fuzzy::domain::fis::rulevariable::RuleOutput> &ruleOutputs);

private:
    float m_weight;
    definition::Connections m_connection;
    std::map<int, continental::fuzzy::domain::fis::rulevariable::RuleInput> m_ruleInputs;
    std::map<int, continental::fuzzy::domain::fis::rulevariable::RuleOutput> m_ruleOutputs;
};

}
}
}
}

#endif // CONTINENTAFUZZY_SERVICE_FUZZY_FUZZYSERVICE_H
