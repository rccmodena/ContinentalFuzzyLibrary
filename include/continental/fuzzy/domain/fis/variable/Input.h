#ifndef CONTINENTAFUZZY_DOMAIN_FUZZY_VARIABLE_INPUT_H
#define CONTINENTAFUZZY_DOMAIN_FUZZY_VARIABLE_INPUT_H

#include "continental/fuzzy/export.h"
#include "continental/fuzzy/domain/fis/Variable.h"
#include "continental/fuzzy/domain/fis/definition/VariableType.h"
#include "continental/fuzzy/domain/fis/membershipFunction/InputMembershipFunction.h"
#include <memory>
#include <QString>
#include <vector>

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace variable {

class CONTINENTALFUZZY_EXPORT_DECL Input : public Variable
{
public:
    definition::VariableType getVariableType() const;

    const std::vector<membershipfunction::InputMembershipFunction>& getInputMfs() const;
    std::vector<membershipfunction::InputMembershipFunction>& getInputMfs();
    void setInputMfs(const std::vector<membershipfunction::InputMembershipFunction> &inputMfs);
    void addInputMfs(const membershipfunction::InputMembershipFunction &inputMfs);

private:
    definition::VariableType m_variableType = definition::VariableType::antecedent;
    std::vector<membershipfunction::InputMembershipFunction> m_inputMfs;
};

}
}
}
}
}

#endif // CONTINENTAFUZZY_DOMAIN_FUZZY_VARIABLE_INPUT_H
