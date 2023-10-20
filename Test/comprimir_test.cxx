// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN
// This includes the catch.hpp file
#include "../lib/catch.hpp"

// Include the header file of the class that you are testing
#include "../h/Master.h"

// Create a test case
TEST_CASE("Guarda comprimido")
{
    // Create a section
    SECTION("Guardar con exito")
    {

        // test_name -s or test_name.exe -s
        INFO("Section: Guardar con exito");

        // Check if the result of the function is the same as the expected value,
        // if they are not, the test will fail.
        REQUIRE(add(1, 2) == 3);
    }

    // Create a section, this is just to organize your tests
    SECTION("Negative addition")
    {
        // INFO is used in a test environment to provide additional information
        // during the execution of unit tests. By default, INFO messages are not
        // included in the output, but they are included when an assertion (such as REQUIRE, CHECK, etc.)
        // within the section fails. If you want INFO messages to always be included in the output,
        // you can use the -s command line option.
        // test_name -s or test_name.exe -s
        INFO("Section: Negative addition");

        // Check if the result of the function is the same as the expected value,
        // if they are not, the test will fail.
        REQUIRE(add(-1, -2) == -3);
    }

    // Create a section, this is just to organize your tests
    SECTION("Zero addition")
    {
        // INFO is used in a test environment to provide additional information
        // during the execution of unit tests. By default, INFO messages are not
        // included in the output, but they are included when an assertion (such as REQUIRE, CHECK, etc.)
        // within the section fails. If you want INFO messages to always be included in the output,
        // you can use the -s command line option.
        // test_name -s or test_name.exe -s
        INFO("Section: Zero addition");

        // Check if the result of the function is the same as the expected value,
        // if they are not, the test will fail.
        REQUIRE(add(-100, 100) == 0);
    }
}

// Create a test case
TEST_CASE("Double Multiplication ")
{
    // Create a section, this is just to organize your tests
    SECTION("Positive multiplication")
    {

        // INFO is used in a test environment to provide additional information
        // during the execution of unit tests. By default, INFO messages are not
        // included in the output, but they are included when an assertion (such as REQUIRE, CHECK, etc.)
        // within the section fails. If you want INFO messages to always be included in the output,
        // you can use the -s command line option.
        // test_name -s or test_name.exe -s
        INFO("Section: Positive multiplication");

        // Check if the result of the function is the same as the expected value,
        // if they are not, the test will fail.
        REQUIRE(multiply(1, 2) == 2);
    }

    // Create a section, this is just to organize your tests
    SECTION("Negative multiplication")
    {
        // INFO is used in a test environment to provide additional information
        // during the execution of unit tests. By default, INFO messages are not
        // included in the output, but they are included when an assertion (such as REQUIRE, CHECK, etc.)
        // within the section fails. If you want INFO messages to always be included in the output,
        // you can use the -s command line option.
        // test_name -s or test_name.exe -s
        INFO("Section: Negative multiplication");

        // Check if the result of the function is the same as the expected value,
        // if they are not, the test will fail.
        REQUIRE(multiply(-1, -2) == 2);
    }

    // Create a section, this is just to organize your tests
    SECTION("Zero multiplication")
    {
        // INFO is used in a test environment to provide additional information
        // during the execution of unit tests. By default, INFO messages are not
        // included in the output, but they are included when an assertion (such as REQUIRE, CHECK, etc.)
        // within the section fails. If you want INFO messages to always be included in the output,
        // you can use the -s command line option.
        // test_name -s or test_name.exe -s
        INFO("Section: Zero multiplication");

        // Check if the result of the function is the same as the expected value,
        // if they are
        REQUIRE(multiply(-100, 0) == 0);
    }
}