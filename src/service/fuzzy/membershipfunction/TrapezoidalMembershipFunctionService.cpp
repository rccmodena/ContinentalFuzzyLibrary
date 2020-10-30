#include "continental/fuzzy/service/fuzzy/membershipfunction/TrapezoidalMembershipFunctionService.h"

using namespace continental::fuzzy::service::fuzzy::membershipfunction;

namespace continental {
namespace fuzzy {
namespace service {
namespace fuzzy {
namespace membershipfunction {

double TrapezoidalMembershipFunctionService::calculeTrapezoidalMf(const double xValue,
                                                                  const double pointA,
                                                                  const double pointB,
                                                                  const double pointC,
                                                                  const double pointD)
{
    if (qFuzzyCompare(pointA, pointB) && qFuzzyCompare(pointB, pointC) && qFuzzyCompare(pointC, pointD) && qFuzzyCompare(pointD, xValue))
    {
        return 1.0;
    }
    else if ((xValue >= pointB || qFuzzyCompare(xValue, pointB)) && (xValue <= pointC || qFuzzyCompare(xValue, pointC)))
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
