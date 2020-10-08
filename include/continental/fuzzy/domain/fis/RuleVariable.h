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

    ~RuleVariable();

    int  getIndex() const;
    void setIndex(const int index);

    bool getInputVarNot() const;
    void setInputVarNot(bool inputVarNot);

private:
    int m_index;
    bool m_inputVarNot;
};

}
}
}
}

#endif // CONTINENTAFUZZY_SERVICE_FUZZY_FUZZYSERVICE_H
