#include <iostream>
#include <QString>
#include <QCoreApplication>
#include <continental/fuzzy/service/fis/FisService.h>

using namespace continental::fuzzy::domain::fis::definition;
using namespace continental::fuzzy::service::fis;

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    QStringList args = app.arguments();

    std::cout << "CONSOLE CONTINENTAL FUZZY" << std::endl;

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
