cmake_minimum_required(VERSION 2.8)

project(psprot C)
include(CompilerOptions.cmake)

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
   file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
                  "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_run(REQUIRES libconfuse/3.3
                BUILD missing
                BASIC_SETUP CMAKE_TARGETS)

add_subdirectory(vector_template)

add_executable(psprot
    main.c
    cidr_bitmask.c
    handle_argv.c
    ip_knock_info.c
    psprot.c
    pss_config.c
    pss_log.c
    pss_pidfile.c
    signal_handlers.c
)

target_link_libraries(psprot
    CONAN_PKG::libconfuse
    vector_template::vector_template
)
