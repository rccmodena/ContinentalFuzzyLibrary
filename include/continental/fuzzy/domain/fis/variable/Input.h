#ifndef CONTINENTAFUZZY_DOMAIN_FUZZY_VARIABLE_INPUT_H
#define CONTINENTAFUZZY_DOMAIN_FUZZY_VARIABLE_INPUT_H

#include "continental/fuzzy/export.h"
#include "continental/fuzzy/domain/fis/Variable.h"
#include "continental/fuzzy/domain/fis/definition/VariableType.h"
#include "continental/fuzzy/domain/fis/membershipFunction/InputMembershipFunction.h"
#include <memory>
#include <QString>
#include <list>

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace variable {

class CONTINENTALFUZZY_EXPORT_DECL Input : public Variable
{
public:
    definition::VariableType getVariableType() const;

    const std::map<int, membershipfunction::InputMembershipFunction>& getInputMfs() const;
    void setInputMfs(const std::map<int, membershipfunction::InputMembershipFunction> &inputMfs);
    void addInputMfs(const int mfsNumber, const membershipfunction::InputMembershipFunction &inputMfs);

private:
    definition::VariableType m_variableType = definition::VariableType::antecedent;
    std::map<int, membershipfunction::InputMembershipFunction> m_inputMfs;
};

}
}
}
}
}

#endif // CONTINENTAFUZZY_DOMAIN_FUZZY_VARIABLE_INPUT_H
