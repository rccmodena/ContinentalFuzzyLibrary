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
    /// Construtor.
    Output();

    /// Destrutor.
    ~Output();

    continental::fuzzy::domain::fis::definition::VariableType getVariableType() const;

    std::map<int, continental::fuzzy::domain::fis::membershipfunction::OutputMembershipFunction> getOutputMfs() const;
    void setOutputMfs(const std::map<int, continental::fuzzy::domain::fis::membershipfunction::OutputMembershipFunction> &outputMfs);
    void addOutputMfs(const int mfsNumber, const continental::fuzzy::domain::fis::membershipfunction::OutputMembershipFunction &outputMfs);

private:
    continental::fuzzy::domain::fis::definition::VariableType m_variableType = continental::fuzzy::domain::fis::definition::VariableType::consequent;
    std::map<int, continental::fuzzy::domain::fis::membershipfunction::OutputMembershipFunction> m_outputMfs;

};

}
}
}
}
}

#endif // CONTINENTAFUZZY_DOMAIN_FUZZY_VARIABLE_OUTPUT_H
