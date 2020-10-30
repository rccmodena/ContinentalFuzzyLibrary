#include <gtest/gtest.h>
#include <continental/fuzzy/service/fis/FisService.h>
#include <continental/fuzzy/domain/fis/definition/AggMethods.h>
#include <continental/fuzzy/domain/shared/Raster.h>
#include <continental/fuzzy/util/RasterFileUtil.h>
#include <continental/fuzzy/domain/fis/definition/AndMethods.h>
#include <continental/fuzzy/domain/fis/definition/ControllerType.h>
#include <continental/fuzzy/domain/fis/definition/DefuzzMethods.h>
#include <continental/fuzzy/domain/fis/definition/ImpMethods.h>
#include <continental/fuzzy/domain/fis/definition/OrMethods.h>
#include <continental/fuzzy/domain/fis/definition/InputFunctions.h>
#include <continental/fuzzy/service/fuzzy/membershipfunction/GaussMembershipFunctionService.h>
#include <continental/fuzzy/service/fuzzy/membershipfunction/GaussTwoMembershipFunctionService.h>
#include <continental/fuzzy/service/fuzzy/membershipfunction/TriangularMembershipFunctionService.h>
#include <continental/fuzzy/service/fuzzy/membershipfunction/TrapezoidalMembershipFunctionService.h>
#include <continental/fuzzy/service/fuzzy/membershipfunction/LinearMembershipFunctionService.h>
#include <continental/fuzzy/service/fuzzy/operators/MaxOrMethod.h>
#include <continental/fuzzy/service/fuzzy/operators/MinAndMethod.h>
#include <continental/fuzzy/service/fuzzy/operators/NotMethod.h>
#include <continental/fuzzy/service/fuzzy/operators/MinAndMethod.h>
#include <continental/fuzzy/service/fuzzy/operators/ProborOrMethod.h>
#include <continental/fuzzy/service/fuzzy/operators/ProdAndMethod.h>
#include <continental/fuzzy/service/fuzzy/SugenoControllerService.h>
#include <QString>

using namespace continental::fuzzy::service::fis;
using namespace continental::fuzzy::util;
using namespace continental::fuzzy::service::fuzzy;
using namespace continental::fuzzy::domain::fis::definition;
using namespace continental::fuzzy::domain::shared;
using namespace continental::fuzzy::service::fuzzy::membershipfunction;
using namespace continental::fuzzy::service::fuzzy::operators;


TEST(ContinentalFuzzyTest, TestImportFisFile)
{
    FisService import;
    auto mySystem = import.importFile("C:/genesis/ContinentalCarbonatePluginMock/Fuzzy/Australia/Ramp_Arid.fis", true);

    // Testes do Bloco System
    ASSERT_EQ(1, (mySystem.getName() == "Ramp_Arid"));
    ASSERT_EQ(1, (mySystem.getFilename() == "C:/genesis/ContinentalCarbonatePluginMock/Fuzzy/Australia/Ramp_Arid.fis"));
    ASSERT_EQ(1, (mySystem.getType() == ControllerType::sugeno));
    ASSERT_EQ(1, (mySystem.getVersion() == "2.0"));
    ASSERT_EQ(2, mySystem.getNumInputs());
    ASSERT_EQ(1, mySystem.getNumOutputs());
    ASSERT_EQ(9, mySystem.getNumRules());
    ASSERT_EQ(1, (mySystem.getAndMethod() == AndMethods::min));
    ASSERT_EQ(1, (mySystem.getOrMethod() == OrMethods::max));
    ASSERT_EQ(1, (mySystem.getImpMethod() == ImpMethods::prod));
    ASSERT_EQ(1, (mySystem.getAggMethod() == AggMethods::sum));
    ASSERT_EQ(1, (mySystem.getDefuzzMethod() == DefuzzMethods::wtaver));

    // Testes do Bloco Inputs

    // Teste Input1
    auto myInputs = mySystem.getInputs();
    ASSERT_EQ(1, (myInputs[1].getName() == "Depth"));
    ASSERT_DOUBLE_EQ(0.0, myInputs[1].getRange().first);
    ASSERT_DOUBLE_EQ(3000.0, myInputs[1].getRange().second);
    ASSERT_EQ(3, myInputs[1].getNumMfs());

    // Teste Input1 - MF1
    ASSERT_EQ(1, (myInputs[1].getInputMfs().at(1).getName() == "Shallow"));
    ASSERT_EQ(1, (myInputs[1].getInputMfs().at(1).getFunction() == InputFunctions::gauss2mf));
    ASSERT_DOUBLE_EQ(10.3, myInputs[1].getInputMfs().at(1).getGauss2mf().getSigma1());
    ASSERT_DOUBLE_EQ(-56.35, myInputs[1].getInputMfs().at(1).getGauss2mf().getMean1());
    ASSERT_DOUBLE_EQ(6.65, myInputs[1].getInputMfs().at(1).getGauss2mf().getSigma2());
    ASSERT_DOUBLE_EQ(2.384, myInputs[1].getInputMfs().at(1).getGauss2mf().getMean2());

    // Teste Input1 - MF2
    ASSERT_EQ(1, (myInputs[1].getInputMfs().at(2).getName() == "Intermediary"));
    ASSERT_EQ(1, (myInputs[1].getInputMfs().at(2).getFunction() == InputFunctions::gauss2mf));
    ASSERT_DOUBLE_EQ(18.6, myInputs[1].getInputMfs().at(2).getGauss2mf().getSigma1());
    ASSERT_DOUBLE_EQ(62.2, myInputs[1].getInputMfs().at(2).getGauss2mf().getMean1());
    ASSERT_DOUBLE_EQ(17.81, myInputs[1].getInputMfs().at(2).getGauss2mf().getSigma2());
    ASSERT_DOUBLE_EQ(84.92, myInputs[1].getInputMfs().at(2).getGauss2mf().getMean2());

    // Teste Input1 - MF3
    ASSERT_EQ(1, (myInputs[1].getInputMfs().at(3).getName() == "Deep"));
    ASSERT_EQ(1, (myInputs[1].getInputMfs().at(3).getFunction() == InputFunctions::gauss2mf));
    ASSERT_DOUBLE_EQ(50.0, myInputs[1].getInputMfs().at(3).getGauss2mf().getSigma1());
    ASSERT_DOUBLE_EQ(260.0, myInputs[1].getInputMfs().at(3).getGauss2mf().getMean1());
    ASSERT_DOUBLE_EQ(28.3, myInputs[1].getInputMfs().at(3).getGauss2mf().getSigma2());
    ASSERT_DOUBLE_EQ(9999.0, myInputs[1].getInputMfs().at(3).getGauss2mf().getMean2());

    // Teste Input2
    ASSERT_EQ(1, (myInputs[2].getName() == "EnergyDissipation"));
    ASSERT_DOUBLE_EQ(0, myInputs[2].getRange().first);
    ASSERT_DOUBLE_EQ(1, myInputs[2].getRange().second);
    ASSERT_EQ(3, myInputs[2].getNumMfs());

    // Teste Input2 - MF1
    ASSERT_EQ(1, (myInputs[2].getInputMfs().at(1).getName() == "Low"));
    ASSERT_EQ(1, (myInputs[2].getInputMfs().at(1).getFunction() == InputFunctions::gaussmf));
    ASSERT_DOUBLE_EQ(0.15, myInputs[2].getInputMfs().at(1).getGaussmf().getSigma());
    ASSERT_DOUBLE_EQ(0.0, myInputs[2].getInputMfs().at(1).getGaussmf().getMean());

    // Teste Input2 - MF2
    ASSERT_EQ(1, (myInputs[2].getInputMfs().at(2).getName() == "Moderate"));
    ASSERT_EQ(1, (myInputs[2].getInputMfs().at(2).getFunction() == InputFunctions::gaussmf));
    ASSERT_DOUBLE_EQ(0.15, myInputs[2].getInputMfs().at(2).getGaussmf().getSigma());
    ASSERT_DOUBLE_EQ(0.5, myInputs[2].getInputMfs().at(2).getGaussmf().getMean());

    // Teste Input2 - MF3
    ASSERT_EQ(1, (myInputs[2].getInputMfs().at(3).getName() == "High"));
    ASSERT_EQ(1, (myInputs[2].getInputMfs().at(3).getFunction() == InputFunctions::gaussmf));
    ASSERT_DOUBLE_EQ(0.15, myInputs[2].getInputMfs().at(3).getGaussmf().getSigma());
    ASSERT_DOUBLE_EQ(1.0, myInputs[2].getInputMfs().at(3).getGaussmf().getMean());


    // Testes do Bloco Outputs
    // Teste Output1
    auto myOutputs = mySystem.getOutputs();
    ASSERT_EQ(1, (myOutputs.at(1).getName() == "FaciesAssociation"));
    ASSERT_DOUBLE_EQ(0.0, myOutputs.at(1).getRange().first);
    ASSERT_DOUBLE_EQ(5.0, myOutputs.at(1).getRange().second);
    ASSERT_EQ(6, myOutputs.at(1).getNumMfs());

    // Teste Output1 - MF1
    ASSERT_EQ(1, (myOutputs.at(1).getOutputMfs().at(1).getName() == "Cape"));
    ASSERT_EQ(1, (myOutputs.at(1).getOutputMfs().at(1).getFunction() == OutputFunctions::constant));
    ASSERT_DOUBLE_EQ(0.0, myOutputs.at(1).getOutputMfs().at(1).getConstantmf().getValue());

    // Teste Output1 - MF2
    ASSERT_EQ(1, (myOutputs.at(1).getOutputMfs().at(2).getName() == "HighEnergyIntraclastic"));
    ASSERT_EQ(1, (myOutputs.at(1).getOutputMfs().at(2).getFunction() == OutputFunctions::constant));
    ASSERT_DOUBLE_EQ(1.0, myOutputs.at(1).getOutputMfs().at(2).getConstantmf().getValue());

    // Teste Output1 - MF3
    ASSERT_EQ(1, (myOutputs.at(1).getOutputMfs().at(3).getName() == "ModerateEnergyIntraclastic"));
    ASSERT_EQ(1, (myOutputs.at(1).getOutputMfs().at(3).getFunction() == OutputFunctions::constant));
    ASSERT_DOUBLE_EQ(2.0, myOutputs.at(1).getOutputMfs().at(3).getConstantmf().getValue());

    // Teste Output1 - MF4
    ASSERT_EQ(1, (myOutputs.at(1).getOutputMfs().at(4).getName() == "LaminiteRamp"));
    ASSERT_EQ(1, (myOutputs.at(1).getOutputMfs().at(4).getFunction() == OutputFunctions::constant));
    ASSERT_DOUBLE_EQ(3.0, myOutputs.at(1).getOutputMfs().at(4).getConstantmf().getValue());

    // Teste Output1 - MF5
    ASSERT_EQ(1, (myOutputs.at(1).getOutputMfs().at(5).getName() == "SubCoastal"));
    ASSERT_EQ(1, (myOutputs.at(1).getOutputMfs().at(5).getFunction() == OutputFunctions::constant));
    ASSERT_DOUBLE_EQ(4.0, myOutputs.at(1).getOutputMfs().at(5).getConstantmf().getValue());

    // Teste Output1 - MF6
    ASSERT_EQ(1, (myOutputs.at(1).getOutputMfs().at(6).getName() == "Undefined"));
    ASSERT_EQ(1, (myOutputs.at(1).getOutputMfs().at(6).getFunction() == OutputFunctions::constant));
    ASSERT_DOUBLE_EQ(5.0, myOutputs.at(1).getOutputMfs().at(6).getConstantmf().getValue());

    // Testes do Bloco Rules
    // Teste Rule 1
    auto myRules = mySystem.getRules();
    ASSERT_EQ(1, myRules.at(1).getInputs().at(1).getIndex());
    ASSERT_EQ(1, myRules.at(1).getInputs().at(2).getIndex());
    ASSERT_EQ(4, myRules.at(1).getOutputs().at(1).getIndex());
    ASSERT_DOUBLE_EQ(1.0, myRules.at(1).getWeight());
    ASSERT_EQ(1, (myRules.at(1).getConnection() == Connections::AND));

    // Teste Rule 2
    ASSERT_EQ(1, myRules[2].getInputs().at(1).getIndex());
    ASSERT_EQ(2, myRules[2].getInputs().at(2).getIndex());
    ASSERT_EQ(3, myRules[2].getOutputs().at(1).getIndex());
    ASSERT_DOUBLE_EQ(1.0, myRules[2].getWeight());
    ASSERT_EQ(1, (myRules[2].getConnection() == Connections::AND));

    // Teste Rule 3
    ASSERT_EQ(1, myRules[3].getInputs().at(1).getIndex());
    ASSERT_EQ(3, myRules[3].getInputs().at(2).getIndex());
    ASSERT_EQ(1, myRules[3].getOutputs().at(1).getIndex());
    ASSERT_DOUBLE_EQ(1.0, myRules[3].getWeight());
    ASSERT_EQ(1, (myRules[3].getConnection() == Connections::AND));

    // Teste Rule 4
    ASSERT_EQ(2, myRules[4].getInputs().at(1).getIndex());
    ASSERT_EQ(1, myRules[4].getInputs().at(2).getIndex());
    ASSERT_EQ(4, myRules[4].getOutputs().at(1).getIndex());
    ASSERT_DOUBLE_EQ(1.0, myRules[4].getWeight());
    ASSERT_EQ(1, (myRules[4].getConnection() == Connections::AND));

    // Teste Rule 5
    ASSERT_EQ(2, myRules[5].getInputs().at(1).getIndex());
    ASSERT_EQ(2, myRules[5].getInputs().at(2).getIndex());
    ASSERT_EQ(4, myRules[5].getOutputs().at(1).getIndex());
    ASSERT_DOUBLE_EQ(1.0, myRules[5].getWeight());
    ASSERT_EQ(1, (myRules[5].getConnection() == Connections::AND));

    // Teste Rule 6
    ASSERT_EQ(2, myRules[6].getInputs().at(1).getIndex());
    ASSERT_EQ(3, myRules[6].getInputs().at(2).getIndex());
    ASSERT_EQ(2, myRules[6].getOutputs().at(1).getIndex());
    ASSERT_DOUBLE_EQ(1.0, myRules[6].getWeight());
    ASSERT_EQ(1, (myRules[6].getConnection() == Connections::AND));

    // Teste Rule 7
    ASSERT_EQ(3, myRules[7].getInputs().at(1).getIndex());
    ASSERT_EQ(1, myRules[7].getInputs().at(2).getIndex());
    ASSERT_EQ(5, myRules[7].getOutputs().at(1).getIndex());
    ASSERT_DOUBLE_EQ(1.0, myRules[7].getWeight());
    ASSERT_EQ(1, (myRules[7].getConnection() == Connections::AND));

    // Teste Rule 8
    ASSERT_EQ(3, myRules[8].getInputs().at(1).getIndex());
    ASSERT_EQ(2, myRules[8].getInputs().at(2).getIndex());
    ASSERT_EQ(6, myRules[8].getOutputs().at(1).getIndex());
    ASSERT_DOUBLE_EQ(1.0, myRules[8].getWeight());
    ASSERT_EQ(1, (myRules[8].getConnection() == Connections::AND));

    // Teste Rule 9
    ASSERT_EQ(3, myRules[9].getInputs().at(1).getIndex());
    ASSERT_EQ(3, myRules[9].getInputs().at(2).getIndex());
    ASSERT_EQ(6, myRules[9].getOutputs().at(1).getIndex());
    ASSERT_DOUBLE_EQ(1.0, myRules[9].getWeight());
    ASSERT_EQ(1, (myRules[9].getConnection() == Connections::AND));

    //Teste conversão associação de fácies
    auto myFaciesAssociation = mySystem.getFaciesAssociationConversion();

    // (1):Cape -> (0):Cape
    ASSERT_EQ(0,  myFaciesAssociation[0]);

    // (2):HighEnergyIntraclastic -> (8):HighEnergyIntraclastic
    ASSERT_EQ(8,  myFaciesAssociation[1]);

    // (3):ModerateEnergyIntraclastic -> (7):ModerateEnergyIntraclastic
    ASSERT_EQ(7,  myFaciesAssociation[2]);

    // (4):LaminiteRamp -> (6):LaminiteRamp
    ASSERT_EQ(6,  myFaciesAssociation[3]);

    // (5):SubCoastal -> (9):SubCoastal
    ASSERT_EQ(9,  myFaciesAssociation[4]);

    // (6):Undefined -> (12):Undefined
    ASSERT_EQ(12,  myFaciesAssociation[5]);
}

TEST(ContinentalFuzzyTest, TestMembershipFunctions)
{
    // Teste da função gaussiana
    ASSERT_NEAR(0.44829, GaussMembershipFunctionService::calculeGaussMf(4.9, 3.0, 1.5), 0.0001);

    // Teste da função combinação de duas curvas gaussianas
    ASSERT_NEAR(0.89683, GaussTwoMembershipFunctionService::calculeTwoGaussMf(2.3, 3.0, 1.5, 8.0, 2.7), 0.0001);
    ASSERT_NEAR(0.92035, GaussTwoMembershipFunctionService::calculeTwoGaussMf(9.1, 3.0, 1.5, 8.0, 2.7), 0.0001);
    ASSERT_NEAR(1.0, GaussTwoMembershipFunctionService::calculeTwoGaussMf(5.0, 3.0, 1.5, 8.0, 2.7), 0.0001);
    ASSERT_NEAR(0.19691, GaussTwoMembershipFunctionService::calculeTwoGaussMf(5.0, 8.0, 2, 4.0, 1.0), 0.0001);

    // Teste da função triangular
    ASSERT_NEAR(0.3, TriangularMembershipFunctionService::calculeTriangularMf(2.7, 1.0, 2.0, 3.0), 0.0001);
    ASSERT_NEAR(0.5, TriangularMembershipFunctionService::calculeTriangularMf(1.5, 1.0, 2.0, 3.0), 0.0001);
    ASSERT_NEAR(1.0, TriangularMembershipFunctionService::calculeTriangularMf(2.0, 1.0, 2.0, 3.0), 0.0001);
    ASSERT_NEAR(1.0, TriangularMembershipFunctionService::calculeTriangularMf(2.0, 1.0, 2.0, 3.0), 0.0001);
    ASSERT_NEAR(0.0, TriangularMembershipFunctionService::calculeTriangularMf(7.0, 1.0, 2.0, 3.0), 0.0001);

    // Teste da função trapezoidal
    ASSERT_NEAR(0.0, TrapezoidalMembershipFunctionService::calculeTrapezoidalMf(0.0, 1.0, 2.0, 3.0, 4.0), 0.0001);
    ASSERT_NEAR(0.7, TrapezoidalMembershipFunctionService::calculeTrapezoidalMf(1.7, 1.0, 2.0, 3.0, 4.0), 0.0001);
    ASSERT_NEAR(1.0, TrapezoidalMembershipFunctionService::calculeTrapezoidalMf(2.7, 1.0, 2.0, 3.0, 4.0), 0.0001);
    ASSERT_NEAR(0.9, TrapezoidalMembershipFunctionService::calculeTrapezoidalMf(3.1, 1.0, 2.0, 3.0, 4.0), 0.0001);
    ASSERT_NEAR(1.0, TrapezoidalMembershipFunctionService::calculeTrapezoidalMf(2.0, 1.0, 2.0, 3.0, 4.0), 0.0001);

    // Teste da função linear
    std::vector<double> inputsVector = {1.0, 2.0, 3.0};
    std::vector<double> parametersVector = {4.0, 3.0, 2.0, 1.0};

    ASSERT_NEAR(17.0, LinearMembershipFunctionService::calculeLinearMembershipFunctionService(parametersVector, inputsVector), 0.0001);
}

TEST(ContinentalFuzzyTest, TestOperators)
{
    std::vector<double> testValues = {0.3, 0.1, 0.7, 0.5, 0.4};

    // Teste da método Or (Max)
    ASSERT_NEAR(0.7, MaxOrMethod::calculeMaxOrMethod(testValues), 0.0001);

    // Teste da método And (Min)
    ASSERT_NEAR(0.1, MinAndMethod::calculeMinAndMethod(testValues), 0.0001);

    // Teste da método Not
    ASSERT_NEAR(0.3, NotMethod::calculeNotMethod(0.7), 0.0001);

    // Teste da método Or (Probor)
    ASSERT_NEAR(0.9433, ProborOrMethod::calculeProborOrMethod(testValues), 0.0001);

    // Teste da método And (Prod)
    ASSERT_NEAR(0.0042, ProdAndMethod::calculeProdAndMethod(testValues), 0.0001);
}

TEST(ContinentalFuzzyTest, TestSugeno)
{
    FisService import;
    auto mySystem = import.importFile("C:/genesis/ContinentalCarbonatePluginMock/Fuzzy/Australia/Ramp_Arid.fis", true);

    SugenoControllerService sugenoControllerService;
    sugenoControllerService.createFromFisSystem(mySystem);

    std::vector<double> listInputs = {120.0, 0.7};
    int resultFuzzy = static_cast<int>(sugenoControllerService.calcSingleValue(listInputs, true));

    ASSERT_EQ(7, resultFuzzy);
}

TEST(ContinentalFuzzyTest, TestTipOneCompareMatlab)
{
    QString filenameTipFood = "C:/genesis/ContinentalCarbonatePluginMock/Fuzzy/Tip/food.asc";
    auto rasterTipFood = std::make_shared<Raster<double>>(RasterFileUtil<double>::read(filenameTipFood));

    QString filenameTipService = "C:/genesis/ContinentalCarbonatePluginMock/Fuzzy/Tip/service.asc";
    auto rasterTipService = std::make_shared<Raster<double>>(RasterFileUtil<double>::read(filenameTipService));

    QString filenameTipFuzzyliteOneResultMatlab = "C:/genesis/ContinentalCarbonatePluginMock/Fuzzy/Tip/Tip_fuzzylite_1_Result_Matlab.asc";
    auto fuzzyMatlabResult = std::make_shared<Raster<double>>(RasterFileUtil<double>::read(filenameTipFuzzyliteOneResultMatlab));

    FisService import;
    auto mySystem = import.importFile("C:/genesis/ContinentalCarbonatePluginMock/Fuzzy/Tip/Tip_fuzzylite_1.fis", false);

    SugenoControllerService sugenoControllerService;
    sugenoControllerService.createFromFisSystem(mySystem);

    // Informações do Raster
    const size_t rasterRows = rasterTipFood->getRows();
    const size_t rasterCols = rasterTipFood->getCols();

    for (size_t j = 0; j < rasterCols; ++j)
    {
        for (size_t i = 0; i < rasterRows; ++i)
        {
            std::vector<double> listInputs = {rasterTipService->getData(i, j), rasterTipFood->getData(i, j)};
            double resultFuzzy = sugenoControllerService.calcSingleValue(listInputs, false);

            ASSERT_NEAR(fuzzyMatlabResult->getData(i, j), resultFuzzy, 0.001);
        }
    }
}

TEST(ContinentalFuzzyTest, TestTipTwoCompareMatlab)
{
    QString filenameTipFood = "C:/genesis/ContinentalCarbonatePluginMock/Fuzzy/Tip/food.asc";
    auto rasterTipFood = std::make_shared<Raster<double>>(RasterFileUtil<double>::read(filenameTipFood));

    QString filenameTipService = "C:/genesis/ContinentalCarbonatePluginMock/Fuzzy/Tip/service.asc";
    auto rasterTipService = std::make_shared<Raster<double>>(RasterFileUtil<double>::read(filenameTipService));

    QString filenameTipFuzzyliteTwoResultMatlab = "C:/genesis/ContinentalCarbonatePluginMock/Fuzzy/Tip/Tip_fuzzylite_2_Result_Matlab.asc";
    auto fuzzyMatlabResult = std::make_shared<Raster<double>>(RasterFileUtil<double>::read(filenameTipFuzzyliteTwoResultMatlab));

    FisService import;
    auto mySystem = import.importFile("C:/genesis/ContinentalCarbonatePluginMock/Fuzzy/Tip/Tip_fuzzylite_2.fis", false);

    SugenoControllerService sugenoControllerService;
    sugenoControllerService.createFromFisSystem(mySystem);

    // Informações do Raster
    const size_t rasterRows = rasterTipFood->getRows();
    const size_t rasterCols = rasterTipFood->getCols();

    for (size_t j = 0; j < rasterCols; ++j)
    {
        for (size_t i = 0; i < rasterRows; ++i)
        {
            std::vector<double> listInputs = {rasterTipService->getData(i, j), rasterTipFood->getData(i, j)};
            double resultFuzzy = sugenoControllerService.calcSingleValue(listInputs, false);

            ASSERT_NEAR(fuzzyMatlabResult->getData(i, j), resultFuzzy, 0.001);
        }
    }

}

TEST(ContinentalFuzzyTest, TestTipThreeCompareMatlab)
{
    QString filenameTipFood = "C:/genesis/ContinentalCarbonatePluginMock/Fuzzy/Tip/food.asc";
    auto rasterTipFood = std::make_shared<Raster<double>>(RasterFileUtil<double>::read(filenameTipFood));

    QString filenameTipService = "C:/genesis/ContinentalCarbonatePluginMock/Fuzzy/Tip/service.asc";
    auto rasterTipService = std::make_shared<Raster<double>>(RasterFileUtil<double>::read(filenameTipService));

    QString filenameTipFuzzyliteThreeResultMatlab = "C:/genesis/ContinentalCarbonatePluginMock/Fuzzy/Tip/Tip_fuzzylite_3_Result_Matlab.asc";
    auto fuzzyMatlabResult = std::make_shared<Raster<double>>(RasterFileUtil<double>::read(filenameTipFuzzyliteThreeResultMatlab));

    FisService import;
    auto mySystem = import.importFile("C:/genesis/ContinentalCarbonatePluginMock/Fuzzy/Tip/Tip_fuzzylite_3.fis", false);

    SugenoControllerService sugenoControllerService;
    sugenoControllerService.createFromFisSystem(mySystem);

    // Informações do Raster
    const size_t rasterRows = rasterTipFood->getRows();
    const size_t rasterCols = rasterTipFood->getCols();

    for (size_t j = 0; j < rasterCols; ++j)
    {
        for (size_t i = 0; i < rasterRows; ++i)
        {
            std::vector<double> listInputs = {rasterTipService->getData(i, j), rasterTipFood->getData(i, j)};
            double resultFuzzy = sugenoControllerService.calcSingleValue(listInputs, false);

            ASSERT_NEAR(fuzzyMatlabResult->getData(i, j), resultFuzzy, 0.001);
        }
    }
}

TEST(ContinentalFuzzyTest, TestAustraliaRampAridCompareMatlab)
{
    QString filenameDepth = "C:/genesis/ContinentalCarbonatePluginMock/Fuzzy/Australia/depth.asc";
    auto rasterDepth = std::make_shared<Raster<double>>(RasterFileUtil<double>::read(filenameDepth));

    QString filenameNormD = "C:/genesis/ContinentalCarbonatePluginMock/Fuzzy/Australia/normD.asc";
    auto rasterNormD = std::make_shared<Raster<double>>(RasterFileUtil<double>::read(filenameNormD));

    QString filenameRampAridResultMatlab = "C:/genesis/ContinentalCarbonatePluginMock/Fuzzy/Australia/fuzzy_Ramp_Arid_Result_Matlab.asc";
    auto fuzzyMatlabResult = std::make_shared<Raster<double>>(RasterFileUtil<double>::read(filenameRampAridResultMatlab));

    FisService import;
    auto mySystem = import.importFile("C:/genesis/ContinentalCarbonatePluginMock/Fuzzy/Australia/Ramp_Arid.fis", false);

    SugenoControllerService sugenoControllerService;
    sugenoControllerService.createFromFisSystem(mySystem);

    // Informações do Raster
    const size_t rasterRows = rasterDepth->getRows();
    const size_t rasterCols = rasterDepth->getCols();

    for (size_t j = 0; j < rasterCols; ++j)
    {
        for (size_t i = 0; i < rasterRows; ++i)
        {
            if (rasterDepth->getData(i, j) >= 0)
            {
                std::vector<double> listInputs = {rasterDepth->getData(i, j), rasterNormD->getData(i, j)};
                double resultFuzzy = sugenoControllerService.calcSingleValue(listInputs, false);

                ASSERT_NEAR(fuzzyMatlabResult->getData(i, j), resultFuzzy, 0.01);
            }
        }
    }

}

TEST(ContinentalFuzzyTest, TestAustraliaRampHumidCompareMatlab)
{
    QString filenameDepth = "C:/genesis/ContinentalCarbonatePluginMock/Fuzzy/Australia/depth.asc";
    auto rasterDepth = std::make_shared<Raster<double>>(RasterFileUtil<double>::read(filenameDepth));

    QString filenameNormD = "C:/genesis/ContinentalCarbonatePluginMock/Fuzzy/Australia/normD.asc";
    auto rasterNormD = std::make_shared<Raster<double>>(RasterFileUtil<double>::read(filenameNormD));

    QString filenameRampAridResultMatlab = "C:/genesis/ContinentalCarbonatePluginMock/Fuzzy/Australia/fuzzy_Ramp_Humid_Result_Matlab.asc";
    auto fuzzyMatlabResult = std::make_shared<Raster<double>>(RasterFileUtil<double>::read(filenameRampAridResultMatlab));

    FisService import;
    auto mySystem = import.importFile("C:/genesis/ContinentalCarbonatePluginMock/Fuzzy/Australia/Ramp_Humid.fis", false);

    SugenoControllerService sugenoControllerService;
    sugenoControllerService.createFromFisSystem(mySystem);

    // Informações do Raster
    const size_t rasterRows = rasterDepth->getRows();
    const size_t rasterCols = rasterDepth->getCols();

    for (size_t j = 0; j < rasterCols; ++j)
    {
        for (size_t i = 0; i < rasterRows; ++i)
        {
            if (rasterDepth->getData(i, j) >= 0)
            {
                std::vector<double> listInputs = {rasterDepth->getData(i, j), rasterNormD->getData(i, j)};
                double resultFuzzy = sugenoControllerService.calcSingleValue(listInputs, false);

                ASSERT_NEAR(fuzzyMatlabResult->getData(i, j), resultFuzzy, 0.01);
            }
        }
    }

}

TEST(ContinentalFuzzyTest, TestAustraliaShelfAridCompareMatlab)
{
    QString filenameDepth = "C:/genesis/ContinentalCarbonatePluginMock/Fuzzy/Australia/depth.asc";
    auto rasterDepth = std::make_shared<Raster<double>>(RasterFileUtil<double>::read(filenameDepth));

    QString filenameNormD = "C:/genesis/ContinentalCarbonatePluginMock/Fuzzy/Australia/normD.asc";
    auto rasterNormD = std::make_shared<Raster<double>>(RasterFileUtil<double>::read(filenameNormD));

    QString filenameRampAridResultMatlab = "C:/genesis/ContinentalCarbonatePluginMock/Fuzzy/Australia/fuzzy_Shelf_Arid_Result_Matlab.asc";
    auto fuzzyMatlabResult = std::make_shared<Raster<double>>(RasterFileUtil<double>::read(filenameRampAridResultMatlab));

    FisService import;
    auto mySystem = import.importFile("C:/genesis/ContinentalCarbonatePluginMock/Fuzzy/Australia/Shelf_Arid.fis", false);

    SugenoControllerService sugenoControllerService;
    sugenoControllerService.createFromFisSystem(mySystem);

    // Informações do Raster
    const size_t rasterRows = rasterDepth->getRows();
    const size_t rasterCols = rasterDepth->getCols();

    for (size_t j = 0; j < rasterCols; ++j)
    {
        for (size_t i = 0; i < rasterRows; ++i)
        {
            if (rasterDepth->getData(i, j) >= 0)
            {
                std::vector<double> listInputs = {rasterDepth->getData(i, j), rasterNormD->getData(i, j)};
                double resultFuzzy = sugenoControllerService.calcSingleValue(listInputs, false);

                ASSERT_NEAR(fuzzyMatlabResult->getData(i, j), resultFuzzy, 0.01);
            }
        }
    }

}

TEST(ContinentalFuzzyTest, TestAustraliaShelfHumidCompareMatlab)
{
    QString filenameDepth = "C:/genesis/ContinentalCarbonatePluginMock/Fuzzy/Australia/depth.asc";
    auto rasterDepth = std::make_shared<Raster<double>>(RasterFileUtil<double>::read(filenameDepth));

    QString filenameNormD = "C:/genesis/ContinentalCarbonatePluginMock/Fuzzy/Australia/normD.asc";
    auto rasterNormD = std::make_shared<Raster<double>>(RasterFileUtil<double>::read(filenameNormD));

    QString filenameRampAridResultMatlab = "C:/genesis/ContinentalCarbonatePluginMock/Fuzzy/Australia/fuzzy_Shelf_Humid_Result_Matlab.asc";
    auto fuzzyMatlabResult = std::make_shared<Raster<double>>(RasterFileUtil<double>::read(filenameRampAridResultMatlab));

    FisService import;
    auto mySystem = import.importFile("C:/genesis/ContinentalCarbonatePluginMock/Fuzzy/Australia/Shelf_Humid.fis", false);

    SugenoControllerService sugenoControllerService;
    sugenoControllerService.createFromFisSystem(mySystem);

    // Informações do Raster
    const size_t rasterRows = rasterDepth->getRows();
    const size_t rasterCols = rasterDepth->getCols();

    for (size_t j = 0; j < rasterCols; ++j)
    {
        for (size_t i = 0; i < rasterRows; ++i)
        {
            if (rasterDepth->getData(i, j) >= 0)
            {
                std::vector<double> listInputs = {rasterDepth->getData(i, j), rasterNormD->getData(i, j)};
                double resultFuzzy = sugenoControllerService.calcSingleValue(listInputs, false);

                ASSERT_NEAR(fuzzyMatlabResult->getData(i, j), resultFuzzy, 0.01);
            }
        }
    }

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
