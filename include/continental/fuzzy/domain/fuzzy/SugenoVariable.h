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
    int getNumMfs() const;
    void setNumMfs(int numMfs);

    std::map<std::string, fis::MembershipFunction> getMfs() const;
    void setMfs(const std::map<std::string, fis::MembershipFunction> &mfs);
    void addMfs(std::string name, fis::MembershipFunction &mfs);

    std::string getType() const;
    void setType(const std::string &type);

    std::pair<double, double> getRange() const;
    void setRange(const std::pair<double, double> &range);

protected:
    std::string m_type = "";

private:
    std::pair<double, double> m_range = std::pair<double, double>(0.0, 0.0);
    int m_numMfs;
    std::map<std::string, fis::MembershipFunction> m_mfs;

};


}
}
}
}

#endif // CONTINENTAFUZZY_DOMAIN_FUZZY_SUGENORULEVARIABLE_H
