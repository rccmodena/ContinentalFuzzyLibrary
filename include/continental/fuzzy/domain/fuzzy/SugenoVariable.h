#ifndef CONTINENTAFUZZY_DOMAIN_FUZZY_SUGENOVARIABLE_H
#define CONTINENTAFUZZY_DOMAIN_FUZZY_SUGENOVARIABLE_H

#include "continental/fuzzy/export.h"
#include "continental/fuzzy/domain/fis/MembershipFunction.h"
#include <QString>
#include <list>
#include <map>
namespace continental {
namespace fuzzy {
namespace domain {
namespace fuzzy
{
class CONTINENTALFUZZY_EXPORT_DECL SugenoVariable
{

public:
    /// Construtor.
    SugenoVariable();

    std::list<float> getRange() const;
    void setRange(const std::list<float> &range);

    int getNumMfs() const;
    void setNumMfs(int numMfs);

    std::map<std::string, continental::fuzzy::domain::fis::MembershipFunction> getMfs() const;
    void setMfs(const std::map<std::string, continental::fuzzy::domain::fis::MembershipFunction> &mfs);

    std::string getType() const;
    void setType(const std::string &type);

protected:
    std::string m_type = "";

private:
    std::list<float> m_range;
    int m_numMfs;
    std::map<std::string, continental::fuzzy::domain::fis::MembershipFunction> m_mfs;

};


}
}
}
}

#endif // CONTINENTAFUZZY_DOMAIN_FUZZY_SUGENORULEVARIABLE_H
