#ifndef CONTINENTAL_FUZZY_DOMAIN_FIS_DEFINITION_INPUTFUNCTIONS_H
#define CONTINENTAL_FUZZY_DOMAIN_FIS_DEFINITION_INPUTFUNCTIONS_H

#include "continental/fuzzy/export.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace definition {

/**
 * Tipo da curva da varíavel de entrada do Fuzzy
 */
enum class InputFunctions
{
    // Triangular membership function
	trimf = 1,
	
    // Trapezoidal membership function
    trapmf = 2,
	
	// Gaussian membership function
    gaussmf = 3,
	
	//Gaussian combination membership function
    gauss2mf = 4
};

}
}
}
}
}

#endif // CONTINENTAL_FUZZY_DOMAIN_FIS_DEFINITION_INPUTFUNCTIONS_H
