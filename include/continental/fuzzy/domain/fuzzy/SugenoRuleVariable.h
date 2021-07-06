#ifndef CONTINENTAFUZZY_DOMAIN_FUZZY_SUGENORULEVARIABLE_H
#define CONTINENTAFUZZY_DOMAIN_FUZZY_SUGENORULEVARIABLE_H

#include "continental/fuzzy/export.h"
#include <QString>

namespace continental {
namespace fuzzy {
namespace domain {
namespace fuzzy {

class CONTINENTALFUZZY_EXPORT_DECL SugenoRuleVariable
{

public:
    QString getName() const;
    void setName(const QString &name);

    QString getType() const;
    void setType(const QString &type);

protected:
    QString m_type;
private:
    QString m_name;
};

}
}
}
}

#endif // CONTINENTAFUZZY_DOMAIN_FUZZY_SUGENORULEVARIABLE_H
