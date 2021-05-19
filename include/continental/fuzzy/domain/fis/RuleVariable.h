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
    int  getIndex() const;
    void setIndex(const int index);

    bool getInputVarNot() const;
    void setInputVarNot(bool inputVarNot);   

    float getValueFromOrigFis() const;
    void setValueFromOrigFis(float valueFromOrigFis);

private:
    int m_index = 0;
    bool m_inputVarNot = false;
    float m_valueFromOrigFis = 0;
};

}
}
}
}

#endif // CONTINENTAFUZZY_SERVICE_FUZZY_FUZZYSERVICE_H
