#include "continental/fuzzy/service/fuzzy/SugenoControllerService.h"
#include "continental/fuzzy/domain/fis/Rule.h"
#include "continental/fuzzy/domain/fis/definition/Connections.h"
#include "continental/fuzzy/domain/fis/definition/AndMethods.h"
#include "continental/fuzzy/domain/fis/definition/OrMethods.h"

using namespace  continental::fuzzy::domain::fuzzy;
using namespace  continental::fuzzy::domain::fis::definition;

namespace continental {
namespace fuzzy {
namespace service {
namespace fuzzy {

SugenoControllerService::SugenoControllerService()
{

}

SugenoController SugenoControllerService::getSugenoController() const
{
    return m_sugenoController;
}

void SugenoControllerService::getConnection(domain::fis::Rule p_rule)
{
    if(p_rule.getConnection() ==  Connections::AND)
    {
        if(m_sugenoController.getSugenoFisSystem().getAndMethod() == AndMethods::min)
        {
            //return MinAndMethod.calculate_min_and
        }
        else
        {
            if(m_sugenoController.getSugenoFisSystem().getAndMethod() == AndMethods::prod)
            {
                //return ProdAndMethod.calculate_prod_and
            }
        }
    }
    else
    {
        if(p_rule.getConnection() ==  continental::fuzzy::domain::fis::definition::Connections::OR)
        {
            if(m_sugenoController.getSugenoFisSystem().getOrMethod() == OrMethods::max)
            {
                // return MaxOrMethod.calculate_max_or
            }
            else
            {
                if(m_sugenoController.getSugenoFisSystem().getOrMethod() == OrMethods::probor)
                {
                    //return ProdAndMethod.calculate_prod_and
                }
            }

        }
    }
}



}
}
}
}
