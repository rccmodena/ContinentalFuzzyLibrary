#ifndef CONTINENTAFUZZY_SERVICE_FUZZY_SUGENOCONTROLLERSERVICE_H
#define CONTINENTAFUZZY_SERVICE_FUZZY_SUGENOCONTROLLERSERVICE_H

#include "continental/fuzzy/export.h"
#include "continental/fuzzy/domain/fuzzy/SugenoController.h"
#include "continental/fuzzy/domain/fis/Rule.h"
namespace continental {
namespace fuzzy {
namespace service {
namespace fuzzy {

class CONTINENTALFUZZY_EXPORT_DECL SugenoControllerService
{

public:
    /// Construtor.
    SugenoControllerService();

    continental::fuzzy::domain::fuzzy::SugenoController getSugenoController() const;

private:
    continental::fuzzy::domain::fuzzy::SugenoController m_sugenoController;

    void getConnection(continental::fuzzy::domain::fis::Rule p_rule);

    void getMFFunction();
};

}
}
}
}

#endif // CONTINENTAFUZZY_SERVICE_FUZZY_SUGENOCONTROLLERSERVICE_H
