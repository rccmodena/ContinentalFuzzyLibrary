cmake_minimum_required(VERSION 3.5)
project(ContinentalFuzzy VERSION 1.0.0 LANGUAGES CXX)

add_definitions(-DMAKE_CONTINENTALFUZZY_LIB)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

# Load custom configuration file for CMake (if any).
if(EXISTS ${CMAKE_SOURCE_DIR}/CMakeLists.config)
    include(${CMAKE_SOURCE_DIR}/CMakeLists.config)
endif()

#Make sure that custom modules like FindRapidJSON are found
list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_SOURCE_DIR}/cmake)

##############################################
# Declare dependencies
find_package(Qt5Core CONFIG REQUIRED)

find_package(OpenMP)

##############################################
# Create target and set properties

add_library(ContinentalFuzzy
    src/Version.cpp
    src/domain/fis/System.cpp
    src/domain/fuzzy/SugenoController.cpp
    src/domain/fis/RuleVariable.cpp
    src/domain/fis/Variable.cpp
    src/domain/fis/Rule.cpp
    src/domain/fis/MembershipFunction.cpp
    src/domain/fis/definition/AggMethods.cpp
    src/domain/fis/definition/AndMethods.cpp
    src/domain/fis/definition/Blocks.cpp
    src/domain/fis/definition/Connections.cpp
    src/domain/fis/definition/ControllerType.cpp
    src/domain/fis/definition/DefuzzMethods.cpp
    src/domain/fis/definition/InputFunctions.cpp
    src/domain/fis/definition/OutputFunctions.cpp
    src/domain/fis/definition/ImpMethods.cpp
    src/domain/fis/definition/OrMethods.cpp
    src/domain/fis/definition/VariableType.cpp
    src/domain/fis/definition/FaciesAssociationsImplemented.cpp
    src/domain/fis/rulevariable/RuleInput.cpp
    src/domain/fis/rulevariable/RuleOutput.cpp
    src/domain/fis/membershipfunction/ConstantMF.cpp
    src/domain/fis/membershipfunction/Gauss2MF.cpp
    src/domain/fis/membershipfunction/GaussMF.cpp
    src/domain/fis/membershipfunction/LinearMF.cpp
    src/domain/fis/membershipfunction/TrapMF.cpp
    src/domain/fis/membershipfunction/TriMF.cpp
    src/domain/fis/membershipfunction/InputMembershipFunction.cpp
    src/domain/fis/membershipfunction/OutputMembershipFunction.cpp
    src/domain/fuzzy/definition/sugeno/SugenoAggMethods.cpp
    src/domain/fuzzy/definition/sugeno/SugenoAndMethods.cpp
    src/domain/fuzzy/definition/sugeno/SugenoDefuzzMethods.cpp
    src/domain/fuzzy/definition/sugeno/SugenoImpMethods.cpp
    src/domain/fuzzy/definition/sugeno/SugenoInputFunctions.cpp
    src/domain/fuzzy/definition/sugeno/SugenoOrMethods.cpp
    src/domain/fuzzy/definition/sugeno/SugenoOutputFunctions.cpp
    src/domain/fuzzy/rulevariable/SugenoRuleInput.cpp
    src/domain/fuzzy/rulevariable/SugenoRuleOutput.cpp
    src/domain/fuzzy/variable/SugenoInput.cpp
    src/domain/fuzzy/variable/SugenoOutput.cpp
    src/domain/fuzzy/SugenoRule.cpp
    src/domain/fuzzy/SugenoRuleVariable.cpp
    src/domain/fuzzy/SugenoVariable.cpp
    src/domain/fis/variable/Input.cpp
    src/domain/fis/variable/Output.cpp
    src/service/fuzzy/AbstractFuzzyControllerService.cpp
    src/service/fuzzy/SugenoControllerService.cpp
    src/service/fuzzy/MamdaniControllerService.cpp
    src/service/fis/FisService.cpp
    src/service/fis/InputFisService.cpp
    src/service/fis/OutputFisService.cpp
    src/service/fis/MembershipFunctionFisService.cpp
    src/service/fuzzy/membershipfunction/GaussMembershipFunctionService.cpp
    src/service/fuzzy/membershipfunction/GaussTwoMembershipFunctionService.cpp
    src/service/fuzzy/membershipfunction/TrapezoidalMembershipFunctionService.cpp
    src/service/fuzzy/membershipfunction/TriangularMembershipFunctionService.cpp
    src/service/fuzzy/membershipfunction/LinearMembershipFunctionService.cpp
    src/service/fuzzy/operators/MaxOrMethod.cpp
    src/service/fuzzy/operators/MinAndMethod.cpp
    src/service/fuzzy/operators/NotMethod.cpp
    src/service/fuzzy/operators/ProborOrMethod.cpp
    src/service/fuzzy/operators/ProdAndMethod.cpp
)

#Add an alias so that library can be used inside the build tree, e.g. when testing
add_library(ContinentalFuzzy::ContinentalFuzzy ALIAS ContinentalFuzzy)

#Set target properties
target_include_directories(ContinentalFuzzy
    PUBLIC
       $<INSTALL_INTERFACE:include>
       $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_features(ContinentalFuzzy PRIVATE cxx_auto_type)
target_compile_options(ContinentalFuzzy PRIVATE $<$<CXX_COMPILER_ID:GNU>:-Wall>)

target_link_libraries(ContinentalFuzzy
    PUBLIC Qt5::Core
    PUBLIC OpenMP::OpenMP_CXX
)

##############################################
# Installation instructions

include(GNUInstallDirs)
set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/ContinentalFuzzy)

install(TARGETS ContinentalFuzzy
    EXPORT ContinentalFuzzy-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

#This is required so that the exported target has the name ContinentalFuzzy and not ContinentalFuzzy
set_target_properties(ContinentalFuzzy PROPERTIES EXPORT_NAME ContinentalFuzzy)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

#Export the targets to a script
install(EXPORT ContinentalFuzzy-targets
  FILE
    ContinentalFuzzyTargets.cmake
  NAMESPACE
    ContinentalFuzzy::
  DESTINATION
    ${INSTALL_CONFIGDIR}
)

#Create a ConfigVersion.cmake file
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/ContinentalFuzzyConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/cmake/ContinentalFuzzyConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/ContinentalFuzzyConfig.cmake
    INSTALL_DESTINATION ${INSTALL_CONFIGDIR}
)

#Install the config, configversion and custom find modules
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/ContinentalFuzzyConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/ContinentalFuzzyConfigVersion.cmake
    DESTINATION ${INSTALL_CONFIGDIR}
)

##############################################
## Exporting from the build tree
# configure_file(
#     ${CMAKE_CURRENT_LIST_DIR}/cmake/FindRapidJSON.cmake
#     ${CMAKE_CURRENT_BINARY_DIR}/FindRapidJSON.cmake
#     COPYONLY)

export(EXPORT ContinentalFuzzy-targets FILE ${CMAKE_CURRENT_BINARY_DIR}/ContinentalFuzzyTargets.cmake NAMESPACE ContinentalFuzzy::)

add_subdirectory(test)
add_subdirectory(console)
