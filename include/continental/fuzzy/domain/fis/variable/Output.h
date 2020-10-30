#ifndef CONTINENTAFUZZY_DOMAIN_FUZZY_VARIABLE_OUTPUT_H
#define CONTINENTAFUZZY_DOMAIN_FUZZY_VARIABLE_OUTPUT_H

#include "continental/fuzzy/export.h"
#include "continental/fuzzy/domain/fis/Variable.h"
#include "continental/fuzzy/domain/fis/definition/VariableType.h"
#include "continental/fuzzy/domain/fis/membershipFunction/OutputMembershipFunction.h"
#include <QString>
#include <list>

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace variable {

class CONTINENTALFUZZY_EXPORT_DECL Output : public Variable
{

public:
    definition::VariableType getVariableType() const;

    const std::vector<membershipfunction::OutputMembershipFunction>& getOutputMfs() const;
    void setOutputMfs(const std::vector<membershipfunction::OutputMembershipFunction> &outputMfs);
    void addOutputMfs(const membershipfunction::OutputMembershipFunction &outputMfs);

private:
    definition::VariableType m_variableType = definition::VariableType::consequent;
    std::vector<membershipfunction::OutputMembershipFunction> m_outputMfs;

};

}
}
}
}
}

#endif // CONTINENTAFUZZY_DOMAIN_FUZZY_VARIABLE_OUTPUT_H
