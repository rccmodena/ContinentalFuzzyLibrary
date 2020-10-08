#ifndef CONTINENTAFUZZY_DOMAIN_FUZZY_VARIABLE_SUGENOINPUT_H
#define CONTINENTAFUZZY_DOMAIN_FUZZY_VARIABLE_SUGENOINPUT_H

#include "continental/fuzzy/export.h"
#include "continental/fuzzy/domain/fuzzy/SugenoVariable.h"
#include "continental/fuzzy/domain/fis/MembershipFunction.h"
#include <QString>
#include <list>
#include <map>

namespace continental {
namespace fuzzy {
namespace domain {

namespace fuzzy {
namespace variable {

class CONTINENTALFUZZY_EXPORT_DECL SugenoInput :  public SugenoVariable
{

public:
    /// Construtor.
    SugenoInput();

    int getNumMfs() const;
    void setNumMfs(int numMfs);

    std::pair<double, double> getRange() const;
    void setRange(const std::pair<double, double> &range);

private:
    std::pair<double, double> m_range = std::pair<double, double>(0.0, 0.0);
    int m_numMfs;
    std::map<std::string, continental::fuzzy::domain::fis::MembershipFunction> m_mfs;
};

}
}
}
}
}

#endif // CONTINENTAFUZZY_DOMAIN_FUZZY_RULEVARIABLE_SUGENORULEINPUT_H
