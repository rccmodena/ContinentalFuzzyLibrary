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
        //auto mySystem = import.importFile("C:/genesis/ContinentalCarbonatePluginMock/Fuzzy/Tip/Tip_fuzzylite_3.fis");
        auto mySystem = import.importFile("C:/Users/ADM_LOCAL/Desktop/teste_plugin/sem_ttulo/sem_ttulo_continentalcarbonate/fuzzy/Ramp_Arid.fis");


        SugenoControllerService sugenoControllerService;
        sugenoControllerService.createFromFisSystem(mySystem);

        std::vector<double> listInputs = {20,20000};
        double resultFuzzy = sugenoControllerService.calcSingleValue(listInputs);
        std::cout << resultFuzzy << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "***************** FIM - TESTE FUZZY *****************" << std::endl;

    return 0;

/*
    std::cout << "***************** INICIO - TESTE EXPORT FIS *****************" << std::endl;

    FisService export_;
    //auto mySystem = export_.importFile("C:/genesis/ContinentalCarbonatePluginMock/Fuzzy/Tip/Tip_fuzzylite_3.fis", false);
    //export_.exportFile("C:/genesis/ContinentalCarbonatePluginMock/Fuzzy/Tip/Tip_fuzzylite_TESTE.fis", mySystem);


    //auto mySystem = export_.importFile("C:/genesis/ContinentalCarbonatePluginMock/Fuzzy/Tip/Tip_fuzzylite_2.fis", false);
    //export_.exportFile("C:/genesis/ContinentalCarbonatePluginMock/Fuzzy/Tip/Tip_fuzzylite_TESTE_2.fis", mySystem);


    auto mySystem = export_.importFile("C:/genesis/ContinentalCarbonatePluginMock/Fuzzy/Tip/Tip_fuzzylite_4.fis");
    export_.exportFile("C:/genesis/ContinentalCarbonatePluginMock/Fuzzy/Tip/Tip_fuzzylite_TESTE_4.fis", mySystem);


    //auto mySystem = export_.importFile("C:/Git/ContinentalFuzzyLibrary/ContinentalFuzzyLibrary/mock/tipper.fis", false);
    //export_.exportFile("C:/Git/ContinentalFuzzyLibrary/ContinentalFuzzyLibrary/mock/tipper_TESTE.fis", mySystem);

    //auto mySystem = export_.importFile("C:/Git/ContinentalFuzzyLibrary/ContinentalFuzzyLibrary/mock/tipper_sugeno_linear.fis", false);
    //export_.exportFile("C:/Git/ContinentalFuzzyLibrary/ContinentalFuzzyLibrary/mock/tipper_sugeno_linear_TESTE.fis", mySystem);



    std::cout << "***************** FIM - TESTE FUZZY *****************" << std::endl;

    return 0;
*/
}
