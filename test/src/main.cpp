#include <gtest/gtest.h>
#include <continental/fuzzy/service/fis/FisService.h>
#include <continental/fuzzy/domain/fis/definition/AggMethods.h>
#include <continental/fuzzy/domain/fis/definition/AndMethods.h>
#include <continental/fuzzy/domain/fis/definition/ControllerType.h>
#include <continental/fuzzy/domain/fis/definition/DefuzzMethods.h>
#include <continental/fuzzy/domain/fis/definition/ImpMethods.h>
#include <continental/fuzzy/domain/fis/definition/OrMethods.h>

#include <QString>

using namespace continental::fuzzy::service::fis;
using namespace continental::fuzzy::domain::fis::definition;

TEST(ContinentalFuzzyTest, TestImportFisFile)
{
    FisService import;
    auto my_system = import.importFile("C:/stratbr-oiv-1.12.5/plugins/visual/ContinentalCarbonatePlugin/Ramp_Arid.fis", false);

    // Testes do Bloco System
    ASSERT_EQ (1, (my_system->getName() == "Ramp_Arid"));
    ASSERT_EQ (1, (my_system->getFilename() == "C:/stratbr-oiv-1.12.5/plugins/visual/ContinentalCarbonatePlugin/Ramp_Arid.fis"));
    ASSERT_EQ (1, (my_system->getType() == ControllerType::sugeno));
    ASSERT_EQ (1, (my_system->getVersion() == "2.0"));
    ASSERT_EQ (2, my_system->getNumInputs());
    ASSERT_EQ (1, my_system->getNumOutputs());
    ASSERT_EQ (9, my_system->getNumRules());
    ASSERT_EQ (1, (my_system->getAndMethod() == AndMethods::min));
    ASSERT_EQ (1, (my_system->getOrMethod() == OrMethods::max));
    ASSERT_EQ (1, (my_system->getImpMethod() == ImpMethods::prod));
    ASSERT_EQ (1, (my_system->getAggMethod() == AggMethods::sum));
    ASSERT_EQ (1, (my_system->getDefuzzMethod() == DefuzzMethods::wtaver));

    // Testes do Bloco Inputs
    auto my_inputs = my_system->getInputs();

    //ASSERT_EQ (9, );

    // Testes do Bloco Outputs

    // Testes do Bloco Rules
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
