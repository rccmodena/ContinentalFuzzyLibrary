#ifndef CONTINENTAFUZZY_DOMAIN_FUZZY_RULEVARIABLE_SUGENORULEINPUT_H
#define CONTINENTAFUZZY_DOMAIN_FUZZY_RULEVARIABLE_SUGENORULEINPUT_H

#include "continental/fuzzy/export.h"
#include "continental/fuzzy/domain/fuzzy/SugenoRuleVariable.h"
#include <QString>

namespace continental {
namespace fuzzy {
namespace domain {
namespace fuzzy {
namespace rulevariable {

class CONTINENTALFUZZY_EXPORT_DECL SugenoRuleInput : public SugenoRuleVariable
{

public:
    /// Construtor.
    SugenoRuleInput();

    QString getInputName() const;
    void setInputName(const QString &inputName);

    QString getInputMf() const;
    void setInputMf(const QString &inputMf);

    bool getInputVarNot() const;
    void setInputVarNot(bool inputVarNot);

private:
    QString m_inputName;
    QString m_inputMf;
    bool m_inputVarNot;
};

}
}
}
}
}

#endif // CONTINENTAFUZZY_DOMAIN_FUZZY_RULEVARIABLE_SUGENORULEINPUT_H
