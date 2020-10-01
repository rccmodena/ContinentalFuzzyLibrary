#ifndef CONTINENTAFUZZY_DOMAIN_FIS_RULEVARIABLE_RULEINPUT_H
#define CONTINENTAFUZZY_DOMAIN_FIS_RULEVARIABLE_RULEINPUT_H

#include "continental/fuzzy/export.h"
#include "continental/fuzzy/export.h"
#include <QString>

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace rulevariable {

class CONTINENTALFUZZY_EXPORT_DECL RuleInput
{

public:
    /// Construtor.
    RuleInput();

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

#endif // CONTINENTAFUZZY_SERVICE_FUZZY_FUZZYSERVICE_H
