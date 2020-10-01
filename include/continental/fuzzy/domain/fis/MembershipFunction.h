#ifndef CONTINENTAFUZZY_DOMAIN_FIS_MEMBERSHIPFUNCTION_H
#define CONTINENTAFUZZY_DOMAIN_FIS_MEMBERSHIPFUNCTION_H

#include "continental/fuzzy/export.h"
#include "continental/fuzzy/domain/fis/definition/Functions.h"
#include <QString>
#include <list>
namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {

class CONTINENTALFUZZY_EXPORT_DECL MembershipFunction
{

public:
    /// Construtor.
    MembershipFunction();

    QString getName() const;
    void setName(const QString &name);

    continental::fuzzy::domain::fis::definition::Functions getFunction() const;
    void setFunction(const continental::fuzzy::domain::fis::definition::Functions &function);

private:
    QString m_name;
    continental::fuzzy::domain::fis::definition::Functions m_function;
};

}
}
}
}

#endif // CONTINENTAFUZZY_SERVICE_FUZZY_FUZZYSERVICE_H
