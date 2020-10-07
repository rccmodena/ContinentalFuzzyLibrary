#include "continental/fuzzy/service/fuzzy/membershipfunction/TrapezoidalMembershipFunctionService.h"

using namespace continental::fuzzy::service::fuzzy::membershipfunction;

namespace continental {
namespace fuzzy {
namespace service {
namespace fuzzy {
namespace membershipfunction {

TrapezoidalMembershipFunctionService::TrapezoidalMembershipFunctionService()
{

}

TrapezoidalMembershipFunctionService::~TrapezoidalMembershipFunctionService()
{

}

double TrapezoidalMembershipFunctionService::calculeTrapezoidalMf(double xValue,
                                                                  double pointA,
                                                                  double pointB,
                                                                  double pointC,
                                                                  double pointD)
{
    if ((pointA == pointB) && (pointB == pointC) && (pointC == pointD) && (pointD == xValue))
    {
        return 1.0;
    }
    else if ((xValue >= pointB) && (xValue <= pointC))
    {
        return 1.0;
    }
    else if ((xValue > pointA) && (xValue < pointB))
    {
        return TriangularMembershipFunctionService::calculeTriangularMf(xValue, pointA, pointB, pointC);
    }
    else if ((xValue > pointC) && (xValue < pointD))
    {
        return TriangularMembershipFunctionService::calculeTriangularMf(xValue, pointB, pointC, pointD);
    }
    else
    {
        return 0.0;
    }
}

}
}
}
}
}
