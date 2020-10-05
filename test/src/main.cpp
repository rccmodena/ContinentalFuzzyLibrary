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
    auto my_system = import.importFile("C:/stratbr-oiv-1.12.5/plugins/visual/ContinentalCarbonatePlugin/Ramp_Arid.fis", false);

    // Testes do Bloco System
    ASSERT_EQ(1, (my_system.getName() == "Ramp_Arid"));
    ASSERT_EQ(1, (my_system.getFilename() == "C:/stratbr-oiv-1.12.5/plugins/visual/ContinentalCarbonatePlugin/Ramp_Arid.fis"));
    ASSERT_EQ(1, (my_system.getType() == ControllerType::sugeno));
    ASSERT_EQ(1, (my_system.getVersion() == "2.0"));
    ASSERT_EQ(2, my_system.getNumInputs());
    ASSERT_EQ(1, my_system.getNumOutputs());
    ASSERT_EQ(9, my_system.getNumRules());
    ASSERT_EQ(1, (my_system.getAndMethod() == AndMethods::min));
    ASSERT_EQ(1, (my_system.getOrMethod() == OrMethods::max));
    ASSERT_EQ(1, (my_system.getImpMethod() == ImpMethods::prod));
    ASSERT_EQ(1, (my_system.getAggMethod() == AggMethods::sum));
    ASSERT_EQ(1, (my_system.getDefuzzMethod() == DefuzzMethods::wtaver));

    // Testes do Bloco Inputs

    // Teste Input1
    auto my_inputs = my_system.getInputs();
    ASSERT_EQ(1, (my_inputs[1].getName() == "Depth"));
    ASSERT_DOUBLE_EQ(0.0, my_inputs[1].getRange().first);
    ASSERT_DOUBLE_EQ(3000.0, my_inputs[1].getRange().second);
    ASSERT_EQ(3, my_inputs[1].getNumMfs());

    // Teste Input1 - MF1
    ASSERT_EQ(1, (my_inputs[1].getInputMfs()[1].getName() == "Shallow"));
    ASSERT_EQ(1, (my_inputs[1].getInputMfs()[1].getFunction() == InputFunctions::gauss2mf));
    ASSERT_DOUBLE_EQ(10.3, my_inputs[1].getInputMfs()[1].getGauss2mf().getSigma1());
    ASSERT_DOUBLE_EQ(-56.35, my_inputs[1].getInputMfs()[1].getGauss2mf().getMean1());
    ASSERT_DOUBLE_EQ(6.65, my_inputs[1].getInputMfs()[1].getGauss2mf().getSigma2());
    ASSERT_DOUBLE_EQ(2.384, my_inputs[1].getInputMfs()[1].getGauss2mf().getMean2());

    // Teste Input1 - MF2
    ASSERT_EQ(1, (my_inputs[1].getInputMfs()[2].getName() == "Intermediary"));
    ASSERT_EQ(1, (my_inputs[1].getInputMfs()[2].getFunction() == InputFunctions::gauss2mf));
    ASSERT_DOUBLE_EQ(18.6, my_inputs[1].getInputMfs()[2].getGauss2mf().getSigma1());
    ASSERT_DOUBLE_EQ(62.2, my_inputs[1].getInputMfs()[2].getGauss2mf().getMean1());
    ASSERT_DOUBLE_EQ(17.81, my_inputs[1].getInputMfs()[2].getGauss2mf().getSigma2());
    ASSERT_DOUBLE_EQ(84.92, my_inputs[1].getInputMfs()[2].getGauss2mf().getMean2());

    // Teste Input1 - MF3
    ASSERT_EQ(1, (my_inputs[1].getInputMfs()[3].getName() == "Deep"));
    ASSERT_EQ(1, (my_inputs[1].getInputMfs()[3].getFunction() == InputFunctions::gauss2mf));
    ASSERT_DOUBLE_EQ(50.0, my_inputs[1].getInputMfs()[3].getGauss2mf().getSigma1());
    ASSERT_DOUBLE_EQ(260.0, my_inputs[1].getInputMfs()[3].getGauss2mf().getMean1());
    ASSERT_DOUBLE_EQ(28.3, my_inputs[1].getInputMfs()[3].getGauss2mf().getSigma2());
    ASSERT_DOUBLE_EQ(9999.0, my_inputs[1].getInputMfs()[3].getGauss2mf().getMean2());

    // Teste Input2
    ASSERT_EQ(1, (my_inputs[2].getName() == "EnergyDissipation"));
    ASSERT_DOUBLE_EQ(0, my_inputs[2].getRange().first);
    ASSERT_DOUBLE_EQ(1, my_inputs[2].getRange().second);
    ASSERT_EQ(3, my_inputs[2].getNumMfs());

    // Teste Input2 - MF1
    ASSERT_EQ(1, (my_inputs[2].getInputMfs()[1].getName() == "Low"));
    ASSERT_EQ(1, (my_inputs[2].getInputMfs()[1].getFunction() == InputFunctions::gaussmf));
    ASSERT_DOUBLE_EQ(0.15, my_inputs[2].getInputMfs()[1].getGaussmf().getSigma());
    ASSERT_DOUBLE_EQ(0.0, my_inputs[2].getInputMfs()[1].getGaussmf().getMean());

    // Teste Input2 - MF2
    ASSERT_EQ(1, (my_inputs[2].getInputMfs()[2].getName() == "Moderate"));
    ASSERT_EQ(1, (my_inputs[2].getInputMfs()[2].getFunction() == InputFunctions::gaussmf));
    ASSERT_DOUBLE_EQ(0.15, my_inputs[2].getInputMfs()[2].getGaussmf().getSigma());
    ASSERT_DOUBLE_EQ(0.5, my_inputs[2].getInputMfs()[2].getGaussmf().getMean());

    // Teste Input2 - MF3
    ASSERT_EQ(1, (my_inputs[2].getInputMfs()[3].getName() == "High"));
    ASSERT_EQ(1, (my_inputs[2].getInputMfs()[3].getFunction() == InputFunctions::gaussmf));
    ASSERT_DOUBLE_EQ(0.15, my_inputs[2].getInputMfs()[3].getGaussmf().getSigma());
    ASSERT_DOUBLE_EQ(1.0, my_inputs[2].getInputMfs()[3].getGaussmf().getMean());


    // Testes do Bloco Outputs
    // Teste Output1
    auto my_outputs = my_system.getOutputs();
    ASSERT_EQ(1, (my_outputs[1].getName() == "FaciesAssociation"));
    ASSERT_DOUBLE_EQ(0.0, my_outputs[1].getRange().first);
    ASSERT_DOUBLE_EQ(5.0, my_outputs[1].getRange().second);
    ASSERT_EQ(6, my_outputs[1].getNumMfs());

    // Teste Output1 - MF1
    ASSERT_EQ(1, (my_outputs[1].getOutputMfs()[1].getName() == "Cape"));
    ASSERT_EQ(1, (my_outputs[1].getOutputMfs()[1].getFunction() == OutputFunctions::constant));
    ASSERT_DOUBLE_EQ(0.0, my_outputs[1].getOutputMfs()[1].getConstantmf().getValue());

    // Teste Output1 - MF2
    ASSERT_EQ(1, (my_outputs[1].getOutputMfs()[2].getName() == "HighEnergyIntraclastic"));
    ASSERT_EQ(1, (my_outputs[1].getOutputMfs()[2].getFunction() == OutputFunctions::constant));
    ASSERT_DOUBLE_EQ(1.0, my_outputs[1].getOutputMfs()[2].getConstantmf().getValue());

    // Teste Output1 - MF3
    ASSERT_EQ(1, (my_outputs[1].getOutputMfs()[3].getName() == "ModerateEnergyIntraclastic"));
    ASSERT_EQ(1, (my_outputs[1].getOutputMfs()[3].getFunction() == OutputFunctions::constant));
    ASSERT_DOUBLE_EQ(2.0, my_outputs[1].getOutputMfs()[3].getConstantmf().getValue());

    // Teste Output1 - MF4
    ASSERT_EQ(1, (my_outputs[1].getOutputMfs()[4].getName() == "LaminiteRamp"));
    ASSERT_EQ(1, (my_outputs[1].getOutputMfs()[4].getFunction() == OutputFunctions::constant));
    ASSERT_DOUBLE_EQ(3.0, my_outputs[1].getOutputMfs()[4].getConstantmf().getValue());

    // Teste Output1 - MF5
    ASSERT_EQ(1, (my_outputs[1].getOutputMfs()[5].getName() == "SubCoastal"));
    ASSERT_EQ(1, (my_outputs[1].getOutputMfs()[5].getFunction() == OutputFunctions::constant));
    ASSERT_DOUBLE_EQ(4.0, my_outputs[1].getOutputMfs()[5].getConstantmf().getValue());

    // Teste Output1 - MF6
    ASSERT_EQ(1, (my_outputs[1].getOutputMfs()[6].getName() == "Undefined"));
    ASSERT_EQ(1, (my_outputs[1].getOutputMfs()[6].getFunction() == OutputFunctions::constant));
    ASSERT_DOUBLE_EQ(5.0, my_outputs[1].getOutputMfs()[6].getConstantmf().getValue());

    // Testes do Bloco Rules

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
