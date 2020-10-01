#ifndef CONTINENTAFUZZY_DOMAIN_FIS_RULE_H
#define CONTINENTAFUZZY_DOMAIN_FIS_RULE_H

#include "continental/fuzzy/export.h"
#include "continental/fuzzy/domain/fis/definition/Connections.h"
#include "continental/fuzzy/domain/fis/rulevariable/RuleInput.h"
#include "continental/fuzzy/domain/fis/rulevariable/RuleOutput.h"
#include <QString>
#include <list>
namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {



class CONTINENTALFUZZY_EXPORT_DECL Rule
{

public:
    /// Construtor.
    Rule();

    QString getName() const;
    void setName(const QString &name);

    float getWeight() const;
    void setWeight(float weight);

    definition::Connections getConnection() const;
    void setConnection(const definition::Connections &connection);

    std::list<continental::fuzzy::domain::fis::rulevariable::RuleInput> getInputs() const;
    void setInputs(const std::list<continental::fuzzy::domain::fis::rulevariable::RuleInput> &inputs);

    std::list<continental::fuzzy::domain::fis::rulevariable::RuleOutput> getOutputs() const;
    void setOutputs(const std::list<continental::fuzzy::domain::fis::rulevariable::RuleOutput> &outputs);

private:
    QString m_name;
    float m_weight;
    definition::Connections m_connection;
    std::list<continental::fuzzy::domain::fis::rulevariable::RuleInput> m_inputs;
    std::list<continental::fuzzy::domain::fis::rulevariable::RuleOutput> m_outputs;
};

}
}
}
}

#endif // CONTINENTAFUZZY_SERVICE_FUZZY_FUZZYSERVICE_H
