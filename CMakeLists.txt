cmake_minimum_required(VERSION 3.21)
project(PricingUtil LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif ()

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3") #time to fly
endif ()

# Add Pybind11
include(FetchContent)
set(PYBIND11_VERSION 2.8.1)
FetchContent_Declare(
        pybind11
        GIT_REPOSITORY https://github.com/pybind/pybind11.git
        GIT_TAG v${PYBIND11_VERSION}
)
FetchContent_MakeAvailable(pybind11)


include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE) #windows tings
FetchContent_MakeAvailable(googletest)
enable_testing()

add_executable(
        PriceUtilTests
        ${CMAKE_SOURCE_DIR}/src/pricingutil.cpp
        ${CMAKE_SOURCE_DIR}/tst/test_pricingutil.cpp
)

target_link_libraries(
        PriceUtilTests
        GTest::gtest_main
)

target_include_directories(
  PriceUtilTests PRIVATE
  ${CMAKE_SOURCE_DIR}/src
  )