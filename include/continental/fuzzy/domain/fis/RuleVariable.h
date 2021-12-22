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


    int getIndexOfInput() const;
    void setIndexOfInput(int indexOfInput);

private:
    int m_index = 0;
    bool m_inputVarNot = false;

    int m_indexOfInput = 0;


};

}
}
}
}

#endif // CONTINENTAFUZZY_SERVICE_FUZZY_FUZZYSERVICE_H
