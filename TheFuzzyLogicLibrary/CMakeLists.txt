# CMakeList.txt : CMake project for TheFuzzyLogicLibrary, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_library (TheFuzzyLogicLibrary SHARED "TheFuzzyLogicLibrary.cxx" "FuzzyOperations.cxx" "BaseLinguisticVariable.cxx" "TriangularMembershipFunction.cxx")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET TheFuzzyLogicLibrary PROPERTY CXX_STANDARD 20)
endif()


# add dependencies
include(cmake/CPM.cmake)

#CPMADDPACKAGE("gh:SergiusTheBest/plog#1.1.10")
#CPMADDPACKAGE("gh:open-source-parsers/jsoncpp#1.9.5")
#CPMADDPACKAGE("gl:libeigen/eigen#3.4.0")

# find packages
#find_package(plog CONFIG REQUIRED)

# include dependencies
#include_directories(${plog_SOURCE_DIR}/include)

# link dependencies


# TODO: Add tests and install targets if needed.
