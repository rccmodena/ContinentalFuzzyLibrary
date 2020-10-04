#ifndef CONTINENTAFUZZY_DOMAIN_FUZZY_VARIABLE_INPUT_H
#define CONTINENTAFUZZY_DOMAIN_FUZZY_VARIABLE_INPUT_H

#include "continental/fuzzy/export.h"
#include "continental/fuzzy/domain/fis/Variable.h"
#include "continental/fuzzy/domain/fis/definition/VariableType.h"
#include <memory>
#include <QString>
#include <list>

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace variable {

class CONTINENTALFUZZY_EXPORT_DECL Input : public continental::fuzzy::domain::fis::Variable
{
public:
    /// Construtor.
    Input();

    /// Destrutor.
    ~Input();

    continental::fuzzy::domain::fis::definition::VariableType getVariableType() const;

private:
    //QString m_name = "";
    continental::fuzzy::domain::fis::definition::VariableType m_variableType = continental::fuzzy::domain::fis::definition::VariableType::antecedent;
    //std::shared_ptr<std::pair<float, float>> m_range = std::make_shared<std::pair<float, float>>(0, 0);
    //int m_numMfs = 0;
    //std::map<int, MembershipFunction> m_mfs;
};

}
}
}
}
}

#endif // CONTINENTAFUZZY_DOMAIN_FUZZY_VARIABLE_INPUT_H
