set(Z5_TEST_NAME z5test)
set(CMAKE_OSX_DEPLOYMENT_TARGET "10.15")
find_package(z5 REQUIRED)
set_package_properties(z5 PROPERTIES
    TYPE REQUIRED
    PURPOSE "Read data from Zarr formats"
    )

PDAL_ADD_PLUGIN(libname reader z5
    FILES
        io/Z5Reader.cpp
    INCLUDES
        ${Z5_INCLUDE_DIR}
        ${NLOHMANN_INCLUDE_DIR}
)

option(BUILD_Z5_TESTS "Build z5 tests" ON)
if (WITH_TESTS)
if (BUILD_Z5_TESTS)
    configure_file(
        test/Config.hpp.in
        "${CMAKE_CURRENT_BINARY_DIR}/test/Config.hpp"
    )

    PDAL_ADD_TEST(${Z5_TEST_NAME}
        FILES
            test/Z5ReaderTest.cpp
        LINK_WITH
            ${libname}
        INCLUDES
            ${Z5_INCLUDE_DIR}
            ${NLOHMANN_INCLUDE_DIR}
            ${PROJECT_BINARY_DIR}/plugins/z5/test
            ${PROJECT_SOURCE_DIR}/plugins/z5/io
    )
endif()
endif()
