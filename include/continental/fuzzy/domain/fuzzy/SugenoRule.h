#ifndef CONTINENTAFUZZY_DOMAIN_FUZZY_SUGENORULE_H
#define CONTINENTAFUZZY_DOMAIN_FUZZY_SUGENORULE_H

#include "continental/fuzzy/export.h"
#include "continental/fuzzy/domain/fis/definition/Connections.h"
#include "continental/fuzzy/domain/fuzzy/rulevariable/SugenoRuleInput.h"
#include "continental/fuzzy/domain/fuzzy/rulevariable/SugenoRuleOutput.h"
#include <QString>
#include <list>

namespace continental {
namespace fuzzy {
namespace domain {
namespace fuzzy
{
class CONTINENTALFUZZY_EXPORT_DECL SugenoRule
{

public:
    QString getName() const;
    void setName(const QString &name);

    float getWeight() const;
    void setWeight(float weight);

    std::list<rulevariable::SugenoRuleInput> getInputs() const;
    void setInputs(const std::list<rulevariable::SugenoRuleInput> &inputs);

    std::list<rulevariable::SugenoRuleOutput> getOutputs() const;
    void setOutputs(const std::list<rulevariable::SugenoRuleOutput> &outputs);

    fis::definition::Connections getConnection() const;
    void setConnection(const fis::definition::Connections &connection);

private:
    QString m_name;
    float m_weight = 0.0f;
    fis::definition::Connections m_connection;
    std::list<rulevariable::SugenoRuleInput> m_inputs;
    std::list<rulevariable::SugenoRuleOutput> m_outputs;
};


}
}
}
}

#endif // CONTINENTAFUZZY_DOMAIN_FUZZY_SUGENORULEVARIABLE_H
