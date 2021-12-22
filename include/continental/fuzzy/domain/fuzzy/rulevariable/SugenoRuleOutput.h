#ifndef CONTINENTAFUZZY_DOMAIN_FUZZY_RULEVARIABLE_SUGENORULEOUTPUT_H
#define CONTINENTAFUZZY_DOMAIN_FUZZY_RULEVARIABLE_SUGENORULEOUTPUT_H

#include "continental/fuzzy/export.h"
#include "continental/fuzzy/domain/fuzzy/SugenoRuleVariable.h"
#include <QString>

namespace continental {
namespace fuzzy {
namespace domain {
namespace fuzzy {
namespace rulevariable {

class CONTINENTALFUZZY_EXPORT_DECL SugenoRuleOutput : public SugenoRuleVariable
{

public:
    /// Construtor.
    SugenoRuleOutput();

    QString getInputName() const;
    void setInputName(const QString &inputName);

    QString getInputMf() const;
    void setInputMf(const QString &inputMf);

private:
    QString m_inputName;
    QString m_inputMf;
};

}
}
}
}
}

#endif // CONTINENTAFUZZY_SERVICE_FUZZY_FUZZYSERVICE_H
