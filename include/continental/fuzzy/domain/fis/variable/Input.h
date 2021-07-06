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

/**
 * Varíavel de entrada Fuzzy
 */
class CONTINENTALFUZZY_EXPORT_DECL Input : public Variable
{
public:
    /**
     * Retorna o tipo da varíavel
     * @return Tipo da varíavel de entrada
     */
    definition::VariableType getVariableType() const;

    /**
     * Retorna as membership functions da varíavel de entrada
     * @return Membership functions da varíavel de entrada
     */
    const std::vector<membershipfunction::InputMembershipFunction>& getInputMfs() const;
    std::vector<membershipfunction::InputMembershipFunction>& getInputMfs();

    /**
     * Define as membership functions da varíavel de entrada
     * @param inputMfs Varíaveis de entrada
     */
    void setInputMfs(const std::vector<membershipfunction::InputMembershipFunction> &inputMfs);

    /**
     * Adiciona uma membership function na varíavel de entrada
     * @param inputMfs Varíavel de entrada
     */
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
