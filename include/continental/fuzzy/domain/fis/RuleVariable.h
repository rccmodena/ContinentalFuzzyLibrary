#ifndef CONTINENTAFUZZY_DOMAIN_FIS_RULEVARIABLE_H
#define CONTINENTAFUZZY_DOMAIN_FIS_RULEVARIABLE_H

#include "continental/fuzzy/export.h"
#include "continental/fuzzy/export.h"
#include <QString>

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {

class CONTINENTALFUZZY_EXPORT_DECL RuleVariable
{

public:
    /// Construtor.
    RuleVariable();

    QString getName() const;
    void setName(const QString &name);

    QString getMf() const;
    void setMf(const QString &mf);

private:
    QString m_name;
    QString m_mf;
};

}
}
}
}

#endif // CONTINENTAFUZZY_SERVICE_FUZZY_FUZZYSERVICE_H
