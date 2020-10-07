#include <gtest/gtest.h>
#include <continental/fuzzy/service/fis/FisService.h>
#include <continental/fuzzy/domain/fis/definition/AggMethods.h>
#include <continental/fuzzy/domain/fis/definition/AndMethods.h>
#include <continental/fuzzy/domain/fis/definition/ControllerType.h>
#include <continental/fuzzy/domain/fis/definition/DefuzzMethods.h>
#include <continental/fuzzy/domain/fis/definition/ImpMethods.h>
#include <continental/fuzzy/domain/fis/definition/OrMethods.h>
#include <continental/fuzzy/domain/fis/definition/InputFunctions.h>

#include <QString>

using namespace continental::fuzzy::service::fis;
using namespace continental::fuzzy::domain::fis::definition;

TEST(ContinentalFuzzyTest, TestImportFisFile)
{
    FisService import;
    auto mySystem = import.importFile("C:/stratbr-oiv-1.12.5/plugins/visual/ContinentalCarbonatePlugin/Ramp_Arid.fis");

    // Testes do Bloco System
    ASSERT_EQ(1, (mySystem.getName() == "Ramp_Arid"));
    ASSERT_EQ(1, (mySystem.getFilename() == "C:/stratbr-oiv-1.12.5/plugins/visual/ContinentalCarbonatePlugin/Ramp_Arid.fis"));
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
    ASSERT_EQ(1, (myInputs[1].getInputMfs()[1].getName() == "Shallow"));
    ASSERT_EQ(1, (myInputs[1].getInputMfs()[1].getFunction() == InputFunctions::gauss2mf));
    ASSERT_DOUBLE_EQ(10.3, myInputs[1].getInputMfs()[1].getGauss2mf().getSigma1());
    ASSERT_DOUBLE_EQ(-56.35, myInputs[1].getInputMfs()[1].getGauss2mf().getMean1());
    ASSERT_DOUBLE_EQ(6.65, myInputs[1].getInputMfs()[1].getGauss2mf().getSigma2());
    ASSERT_DOUBLE_EQ(2.384, myInputs[1].getInputMfs()[1].getGauss2mf().getMean2());

    // Teste Input1 - MF2
    ASSERT_EQ(1, (myInputs[1].getInputMfs()[2].getName() == "Intermediary"));
    ASSERT_EQ(1, (myInputs[1].getInputMfs()[2].getFunction() == InputFunctions::gauss2mf));
    ASSERT_DOUBLE_EQ(18.6, myInputs[1].getInputMfs()[2].getGauss2mf().getSigma1());
    ASSERT_DOUBLE_EQ(62.2, myInputs[1].getInputMfs()[2].getGauss2mf().getMean1());
    ASSERT_DOUBLE_EQ(17.81, myInputs[1].getInputMfs()[2].getGauss2mf().getSigma2());
    ASSERT_DOUBLE_EQ(84.92, myInputs[1].getInputMfs()[2].getGauss2mf().getMean2());

    // Teste Input1 - MF3
    ASSERT_EQ(1, (myInputs[1].getInputMfs()[3].getName() == "Deep"));
    ASSERT_EQ(1, (myInputs[1].getInputMfs()[3].getFunction() == InputFunctions::gauss2mf));
    ASSERT_DOUBLE_EQ(50.0, myInputs[1].getInputMfs()[3].getGauss2mf().getSigma1());
    ASSERT_DOUBLE_EQ(260.0, myInputs[1].getInputMfs()[3].getGauss2mf().getMean1());
    ASSERT_DOUBLE_EQ(28.3, myInputs[1].getInputMfs()[3].getGauss2mf().getSigma2());
    ASSERT_DOUBLE_EQ(9999.0, myInputs[1].getInputMfs()[3].getGauss2mf().getMean2());

    // Teste Input2
    ASSERT_EQ(1, (myInputs[2].getName() == "EnergyDissipation"));
    ASSERT_DOUBLE_EQ(0, myInputs[2].getRange().first);
    ASSERT_DOUBLE_EQ(1, myInputs[2].getRange().second);
    ASSERT_EQ(3, myInputs[2].getNumMfs());

    // Teste Input2 - MF1
    ASSERT_EQ(1, (myInputs[2].getInputMfs()[1].getName() == "Low"));
    ASSERT_EQ(1, (myInputs[2].getInputMfs()[1].getFunction() == InputFunctions::gaussmf));
    ASSERT_DOUBLE_EQ(0.15, myInputs[2].getInputMfs()[1].getGaussmf().getSigma());
    ASSERT_DOUBLE_EQ(0.0, myInputs[2].getInputMfs()[1].getGaussmf().getMean());

    // Teste Input2 - MF2
    ASSERT_EQ(1, (myInputs[2].getInputMfs()[2].getName() == "Moderate"));
    ASSERT_EQ(1, (myInputs[2].getInputMfs()[2].getFunction() == InputFunctions::gaussmf));
    ASSERT_DOUBLE_EQ(0.15, myInputs[2].getInputMfs()[2].getGaussmf().getSigma());
    ASSERT_DOUBLE_EQ(0.5, myInputs[2].getInputMfs()[2].getGaussmf().getMean());

    // Teste Input2 - MF3
    ASSERT_EQ(1, (myInputs[2].getInputMfs()[3].getName() == "High"));
    ASSERT_EQ(1, (myInputs[2].getInputMfs()[3].getFunction() == InputFunctions::gaussmf));
    ASSERT_DOUBLE_EQ(0.15, myInputs[2].getInputMfs()[3].getGaussmf().getSigma());
    ASSERT_DOUBLE_EQ(1.0, myInputs[2].getInputMfs()[3].getGaussmf().getMean());


    // Testes do Bloco Outputs
    // Teste Output1
    auto myOutputs = mySystem.getOutputs();
    ASSERT_EQ(1, (myOutputs[1].getName() == "FaciesAssociation"));
    ASSERT_DOUBLE_EQ(0.0, myOutputs[1].getRange().first);
    ASSERT_DOUBLE_EQ(5.0, myOutputs[1].getRange().second);
    ASSERT_EQ(6, myOutputs[1].getNumMfs());

    // Teste Output1 - MF1
    ASSERT_EQ(1, (myOutputs[1].getOutputMfs()[1].getName() == "Cape"));
    ASSERT_EQ(1, (myOutputs[1].getOutputMfs()[1].getFunction() == OutputFunctions::constant));
    ASSERT_DOUBLE_EQ(0.0, myOutputs[1].getOutputMfs()[1].getConstantmf().getValue());

    // Teste Output1 - MF2
    ASSERT_EQ(1, (myOutputs[1].getOutputMfs()[2].getName() == "HighEnergyIntraclastic"));
    ASSERT_EQ(1, (myOutputs[1].getOutputMfs()[2].getFunction() == OutputFunctions::constant));
    ASSERT_DOUBLE_EQ(1.0, myOutputs[1].getOutputMfs()[2].getConstantmf().getValue());

    // Teste Output1 - MF3
    ASSERT_EQ(1, (myOutputs[1].getOutputMfs()[3].getName() == "ModerateEnergyIntraclastic"));
    ASSERT_EQ(1, (myOutputs[1].getOutputMfs()[3].getFunction() == OutputFunctions::constant));
    ASSERT_DOUBLE_EQ(2.0, myOutputs[1].getOutputMfs()[3].getConstantmf().getValue());

    // Teste Output1 - MF4
    ASSERT_EQ(1, (myOutputs[1].getOutputMfs()[4].getName() == "LaminiteRamp"));
    ASSERT_EQ(1, (myOutputs[1].getOutputMfs()[4].getFunction() == OutputFunctions::constant));
    ASSERT_DOUBLE_EQ(3.0, myOutputs[1].getOutputMfs()[4].getConstantmf().getValue());

    // Teste Output1 - MF5
    ASSERT_EQ(1, (myOutputs[1].getOutputMfs()[5].getName() == "SubCoastal"));
    ASSERT_EQ(1, (myOutputs[1].getOutputMfs()[5].getFunction() == OutputFunctions::constant));
    ASSERT_DOUBLE_EQ(4.0, myOutputs[1].getOutputMfs()[5].getConstantmf().getValue());

    // Teste Output1 - MF6
    ASSERT_EQ(1, (myOutputs[1].getOutputMfs()[6].getName() == "Undefined"));
    ASSERT_EQ(1, (myOutputs[1].getOutputMfs()[6].getFunction() == OutputFunctions::constant));
    ASSERT_DOUBLE_EQ(5.0, myOutputs[1].getOutputMfs()[6].getConstantmf().getValue());

    // Testes do Bloco Rules
    // Teste Rule 1
    auto myRules = mySystem.getRules();
    ASSERT_EQ(1, myRules[1].getInputs()[1].getIndex());
    ASSERT_EQ(1, myRules[1].getInputs()[2].getIndex());
    ASSERT_EQ(4, myRules[1].getOutputs()[1].getIndex());
    ASSERT_DOUBLE_EQ(1.0, myRules[1].getWeight());
    ASSERT_EQ(1, (myRules[1].getConnection() == Connections::AND));

    // Teste Rule 2
    ASSERT_EQ(1, myRules[2].getInputs()[1].getIndex());
    ASSERT_EQ(2, myRules[2].getInputs()[2].getIndex());
    ASSERT_EQ(3, myRules[2].getOutputs()[1].getIndex());
    ASSERT_DOUBLE_EQ(1.0, myRules[2].getWeight());
    ASSERT_EQ(1, (myRules[2].getConnection() == Connections::AND));

    // Teste Rule 3
    ASSERT_EQ(1, myRules[3].getInputs()[1].getIndex());
    ASSERT_EQ(3, myRules[3].getInputs()[2].getIndex());
    ASSERT_EQ(1, myRules[3].getOutputs()[1].getIndex());
    ASSERT_DOUBLE_EQ(1.0, myRules[3].getWeight());
    ASSERT_EQ(1, (myRules[3].getConnection() == Connections::AND));

    // Teste Rule 4
    ASSERT_EQ(2, myRules[4].getInputs()[1].getIndex());
    ASSERT_EQ(1, myRules[4].getInputs()[2].getIndex());
    ASSERT_EQ(4, myRules[4].getOutputs()[1].getIndex());
    ASSERT_DOUBLE_EQ(1.0, myRules[4].getWeight());
    ASSERT_EQ(1, (myRules[4].getConnection() == Connections::AND));

    // Teste Rule 5
    ASSERT_EQ(2, myRules[5].getInputs()[1].getIndex());
    ASSERT_EQ(2, myRules[5].getInputs()[2].getIndex());
    ASSERT_EQ(4, myRules[5].getOutputs()[1].getIndex());
    ASSERT_DOUBLE_EQ(1.0, myRules[5].getWeight());
    ASSERT_EQ(1, (myRules[5].getConnection() == Connections::AND));

    // Teste Rule 6
    ASSERT_EQ(2, myRules[6].getInputs()[1].getIndex());
    ASSERT_EQ(3, myRules[6].getInputs()[2].getIndex());
    ASSERT_EQ(2, myRules[6].getOutputs()[1].getIndex());
    ASSERT_DOUBLE_EQ(1.0, myRules[6].getWeight());
    ASSERT_EQ(1, (myRules[6].getConnection() == Connections::AND));

    // Teste Rule 7
    ASSERT_EQ(3, myRules[7].getInputs()[1].getIndex());
    ASSERT_EQ(1, myRules[7].getInputs()[2].getIndex());
    ASSERT_EQ(5, myRules[7].getOutputs()[1].getIndex());
    ASSERT_DOUBLE_EQ(1.0, myRules[7].getWeight());
    ASSERT_EQ(1, (myRules[7].getConnection() == Connections::AND));

    // Teste Rule 8
    ASSERT_EQ(3, myRules[8].getInputs()[1].getIndex());
    ASSERT_EQ(2, myRules[8].getInputs()[2].getIndex());
    ASSERT_EQ(6, myRules[8].getOutputs()[1].getIndex());
    ASSERT_DOUBLE_EQ(1.0, myRules[8].getWeight());
    ASSERT_EQ(1, (myRules[8].getConnection() == Connections::AND));

    // Teste Rule 9
    ASSERT_EQ(3, myRules[9].getInputs()[1].getIndex());
    ASSERT_EQ(3, myRules[9].getInputs()[2].getIndex());
    ASSERT_EQ(6, myRules[9].getOutputs()[1].getIndex());
    ASSERT_DOUBLE_EQ(1.0, myRules[9].getWeight());
    ASSERT_EQ(1, (myRules[9].getConnection() == Connections::AND));

    //Teste conversão associação de fácies
    auto myFaciesAssociation = mySystem.getFaciesAssociationConversion();

    // (1):Cape -> (0):Cape
    ASSERT_EQ(0,  myFaciesAssociation[1]);

    // (2):HighEnergyIntraclastic -> (8):HighEnergyIntraclastic
    ASSERT_EQ(8,  myFaciesAssociation[2]);

    // (3):ModerateEnergyIntraclastic -> (7):ModerateEnergyIntraclastic
    ASSERT_EQ(7,  myFaciesAssociation[3]);

    // (4):LaminiteRamp -> (6):LaminiteRamp
    ASSERT_EQ(6,  myFaciesAssociation[4]);

    // (5):SubCoastal -> (9):SubCoastal
    ASSERT_EQ(9,  myFaciesAssociation[5]);

    // (6):Undefined -> (12):Undefined
    ASSERT_EQ(12,  myFaciesAssociation[6]);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
