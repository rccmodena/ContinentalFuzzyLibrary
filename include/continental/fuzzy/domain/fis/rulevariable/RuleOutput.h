#ifndef CONTINENTAFUZZY_DOMAIN_FIS_RULEVARIABLE_RULEOUTPUT_H
#define CONTINENTAFUZZY_DOMAIN_FIS_RULEVARIABLE_RULEOUTPUT_H

#include "continental/fuzzy/export.h"
#include "continental/fuzzy/export.h"
#include <QString>

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace rulevariable {

class CONTINENTALFUZZY_EXPORT_DECL RuleOutput
{

public:
    /// Construtor.
    RuleOutput();

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
