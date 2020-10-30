#include <iostream>
#include <QString>
#include <QCoreApplication>
#include <continental/fuzzy/service/fis/FisService.h>
#include <continental/fuzzy/service/fuzzy/SugenoControllerService.h>

using namespace continental::fuzzy::domain::fis::definition;
using namespace continental::fuzzy::service::fis;
using namespace continental::fuzzy::service::fuzzy;

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    QStringList args = app.arguments();

    std::cout << "CONSOLE CONTINENTAL FUZZY" << std::endl;

    std::cout << "***************** INICIO - TESTE FUZZY *****************" << std::endl;
    FisService import;
    try
    {
        auto mySystem = import.importFile("C:/genesis/ContinentalCarbonatePluginMock/Fuzzy/Tip/Tip_fuzzylite_3.fis", false);

        SugenoControllerService sugenoControllerService;
        sugenoControllerService.createFromFisSystem(mySystem);

        std::vector<double> listInputs = {5.455, 7.576};
        double resultFuzzy = sugenoControllerService.calcSingleValue(listInputs, false);
        std::cout << resultFuzzy << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "***************** FIM - TESTE FUZZY *****************" << std::endl;

    return 0;
}
