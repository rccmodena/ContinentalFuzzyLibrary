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



    FisService import = FisService();
    auto mySystem = import.importFile("C:/stratbr-oiv-1.12.5/plugins/visual/ContinentalCarbonatePlugin/Ramp_Arid.fis");

    SugenoControllerService sugenoControllerService = SugenoControllerService();
    sugenoControllerService.createFromFisSystem(mySystem);

    std::vector<double> listInputs = {120.0, 0.7};
    double resultFuzzy = sugenoControllerService.calcSingleValue(listInputs, true);


    std::cout << "***************** INICIO - TESTE IMPORTACAO ARQUIVO .FIS *****************" << std::endl;
//    FisService import;
//    try
//    {
//        auto my_system = import.importFile("C:/stratbr-oiv-1.12.5/plugins/visual/ContinentalCarbonatePlugin/Ramp_Arid.fis", false);
//        std::cout << my_system.getName().toStdString() << std::endl;
//    }
//    catch (const std::exception& e)
//    {
//        std::cout << e.what() << std::endl;
//    }


    std::cout << "***************** FIM - TESTE IMPORTACAO ARQUIVO .FIS *****************" << std::endl;

    return 0;
}
