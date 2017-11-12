project(Neurons)
cmake_minimum_required(VERSION 2.6)
set(CMAKE_CXX_FLAGS "-W -Wall -pedantic -std=c++11")

enable_testing()
add_subdirectory(gtest)
include_directories(${gtest_SOURCE_DIR}/include ${gest_SOURCE_DIR})

add_executable (neuron Network.cpp neuron.cpp main_neuron.cpp)

add_executable (neuron1TEST neuron.cpp Network.cpp neuron1TEST.cpp)
target_link_libraries(neuron1TEST gtest gtest_main)
add_test(neuron1TEST neuron1TEST)

# add a target to generate API documentation with Doxygen
find_package(Doxygen)
if(DOXYGEN_FOUND)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in 
${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
add_custom_target(doc ALL
${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
COMMENT "Generating API documentation with Doxygen" VERBATIM
)
endif(DOXYGEN_FOUND)
