#include "continental/fuzzy/service/fuzzy/MamdaniControllerService.h"
#include "continental/fuzzy/domain/fis/Rule.h"
#include "continental/fuzzy/domain/fis/Variable.h"
#include "continental/fuzzy/domain/fis/variable/Input.h"
#include "continental/fuzzy/domain/fis/variable/Output.h"
#include "continental/fuzzy/domain/fis/MembershipFunction.h"
#include "continental/fuzzy/domain/fis/definition/Connections.h"
#include "continental/fuzzy/domain/fis/definition/AndMethods.h"
#include "continental/fuzzy/domain/fis/definition/OrMethods.h"
#include "continental/fuzzy/domain/fis/definition/InputFunctions.h"
#include "continental/fuzzy/domain/fis/definition/OutputFunctions.h"
#include "continental/fuzzy/service/fuzzy/membershipfunction/GaussMembershipFunctionService.h"
#include "continental/fuzzy/service/fuzzy/membershipfunction/GaussTwoMembershipFunctionService.h"
#include "continental/fuzzy/service/fuzzy/membershipfunction/TrapezoidalMembershipFunctionService.h"
#include "continental/fuzzy/service/fuzzy/membershipfunction/TriangularMembershipFunctionService.h"
#include "continental/fuzzy/service/fuzzy/membershipfunction/LinearMembershipFunctionService.h"
#include "continental/fuzzy/service/fuzzy/operators/NotMethod.h"
#include "continental/fuzzy/service/fuzzy/operators/MaxOrMethod.h"
#include "continental/fuzzy/service/fuzzy/operators/MinAndMethod.h"
#include "continental/fuzzy/service/fuzzy/operators/ProborOrMethod.h"
#include "continental/fuzzy/service/fuzzy/operators/ProdAndMethod.h"
#include <vector>

using namespace  continental::fuzzy::domain::fuzzy;
using namespace  continental::fuzzy::domain::fis;
using namespace  continental::fuzzy::domain::fis::variable;
using namespace  continental::fuzzy::domain::fis::definition;
using namespace  continental::fuzzy::domain::fuzzy::variable;
using namespace  continental::fuzzy::domain::fuzzy::rulevariable;
using namespace  continental::fuzzy::service::fuzzy::membershipfunction;
using namespace  continental::fuzzy::service::fuzzy::operators;

namespace continental {
namespace fuzzy {
namespace service {
namespace fuzzy {

MamdaniControllerService::MamdaniControllerService()
{
    throw "MamdaniControllerService not implemented!";
}

void MamdaniControllerService::createFromFisSystem(System p_system)
{
     throw "MamdaniControllerService not implemented!";
}

double MamdaniControllerService::calcSingleValue(std::vector<double> v_inputs, bool useDictFaciesAssociation)
{
  throw "MamdaniControllerService not implemented!";
  return -1;
}

}
}
}
}
