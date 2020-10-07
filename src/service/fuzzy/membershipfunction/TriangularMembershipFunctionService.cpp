#include "continental/fuzzy/service/fuzzy/membershipfunction/TriangularMembershipFunctionService.h"

namespace continental {
namespace fuzzy {
namespace service {
namespace fuzzy {
namespace membershipfunction {

TriangularMembershipFunctionService::TriangularMembershipFunctionService()
{

}

TriangularMembershipFunctionService::~TriangularMembershipFunctionService()
{

}

double TriangularMembershipFunctionService::calculeTriangularMf(double xValue, double pointA, double pointB, double pointC)
{
    if ((pointA == pointB) && (pointB == pointC) && (pointC == xValue))
    {
        return 1.0;
    }
    else if ((pointA < xValue) && (xValue <= pointB))
    {
        return (xValue - pointA)/(pointB - pointA);
    }
    else if ((pointB < xValue) && (xValue < pointC))
    {
        return (pointC - xValue)/(pointC - pointB);
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
