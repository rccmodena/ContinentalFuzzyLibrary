#ifndef CONTINENTAFUZZY_DOMAIN_FUZZY_SUGENOCONTROLLER_H
#define CONTINENTAFUZZY_DOMAIN_FUZZY_SUGENOCONTROLLER_H

#include "continental/fuzzy/export.h"
#include "continental/fuzzy/domain/fis/definition/AndMethods.h"
#include "continental/fuzzy/domain/fis/definition/OrMethods.h"
#include "continental/fuzzy/domain/fis/definition/Connections.h"
#include "continental/fuzzy/domain/fis/System.h"
#include "continental/fuzzy/domain/fuzzy/SugenoRule.h"
#include "continental/fuzzy/domain/fuzzy/variable/SugenoInput.h"
#include "continental/fuzzy/domain/fuzzy/variable/SugenoOutput.h"
#include <QString>
#include <list>
#include <map>

namespace continental {
namespace fuzzy {
namespace domain {
namespace fuzzy
{
    namespace variable {
        class SugenoInput;
        class SugenoOutput;
    }

class CONTINENTALFUZZY_EXPORT_DECL SugenoController
{

public:
    const fis::System& getSugenoFisSystem() const;
    void setSugenoFisSystem(const fis::System &sugenoFisSystem);

    const std::map<QString, fuzzy::variable::SugenoInput>& getSugenoInputs() const;
    void setSugenoInputs(const std::map<QString, fuzzy::variable::SugenoInput> &sugenoInputs);

    void addSugenoInput(QString nameInput, fuzzy::variable::SugenoInput &sugenoInputs);

    const std::map<QString, fuzzy::variable::SugenoOutput>& getSugenoOutputs() const;
    void setSugenoOutputs(const std::map<QString, fuzzy::variable::SugenoOutput> &sugenoOutputs);
    void addSugenoOutput(QString nameInput, fuzzy::variable::SugenoOutput &sugenoOutputs);

    const std::map<QString, fuzzy::SugenoRule>& getSugenoRules() const;
    void setSugenoRules(const std::map<QString, fuzzy::SugenoRule> &sugenoRules);

private:
    fis::System m_sugenoFisSystem;
    std::map<QString, fuzzy::variable::SugenoInput> m_sugenoInputs;
    std::map<QString, fuzzy::variable::SugenoOutput> m_sugenoOutputs;
    std::map<QString, fuzzy::SugenoRule> m_sugenoRules;
};

}
}
}
}

#endif // CONTINENTAFUZZY_DOMAIN_FUZZY_SUGENOCONTROLLER_H
