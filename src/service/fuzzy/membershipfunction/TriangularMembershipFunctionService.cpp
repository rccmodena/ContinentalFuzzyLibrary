#include "continental/fuzzy/service/fuzzy/membershipfunction/TriangularMembershipFunctionService.h"

namespace continental {
namespace fuzzy {
namespace service {
namespace fuzzy {
namespace membershipfunction {

double TriangularMembershipFunctionService::calculeTriangularMf(const double xValue, const double pointA, const double pointB, const double pointC)
{
    if (qFuzzyCompare(pointA, pointB) && qFuzzyCompare(pointB, pointC) && qFuzzyCompare(pointC, xValue))
    {
        return 1.0;
    }
    else if ((pointA < xValue) && (xValue <= pointB || qFuzzyCompare(xValue, pointB)))
    {
        return (xValue - pointA) / (pointB - pointA);
    }
    else if ((pointB < xValue) && (xValue < pointC))
    {
        return (pointC - xValue) / (pointC - pointB);
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
