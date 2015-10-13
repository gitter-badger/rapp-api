PROJECT(rapp)

set (RAPP_VERSION_MAJOR 0)
set (RAPP_VERSION_MINOR 1)

cmake_minimum_required(VERSION 2.8)

set(LIBRARY_PATH ${LIBRARY_PATH}
		      /lib
		      /usr/lib
		      /usr/lib64
		      /usr/local/lib
		      /usr/local/lib64
		      /usr/lib/x86_64-linux-gnu)

set(INCLUDE_HEADERS ${INCLUDE_HEADERS} /usr/include/)

include_directories(SYSTEM ${INCLUDE_HEADERS})
set (INCLUDES ${INCLUDES} includes)
set (EXAMPLES ${EXAMPLES} examples)
set (TESTS ${TESTS} tests)
add_subdirectory(${INCLUDES})

# Sources are Library-only Executables - Not examples or tests
set (SOURCES ${SOURCES}     ${INCLUDES}/service/asio_service_raw/asio_service_raw.cpp)

# Examples
add_executable ( ex_face_detect  ${EXAMPLES}/face_detect.cpp)
add_executable ( ex_qr_detect    ${EXAMPLES}/qr_detect.cpp)
add_executable ( ex_speech_recog ${EXAMPLES}/speech_to_text.cpp)
add_executable ( ex_ontology     ${EXAMPLES}/ontology_example.cpp)
add_executable ( ex_set_denoise  ${EXAMPLES}/set_denoise_example.cpp)

# Enable Unit Testing
enable_testing ()

# Unit Tests
add_executable ( object_test          ${TESTS}/object_test.cpp)
add_executable ( cloud_test           ${TESTS}/cloud_test.cpp)
add_executable ( service_test         ${TESTS}/service_test.cpp)
add_test (unit_object_test            object_test) 
add_test (unit_cloud_test             cloud_test) 
add_test (unit_service_test           service_test)

# Find PThreads (needed by Boost)
find_package( Threads REQUIRED )

# Find Boost
find_package( Boost 1.49 COMPONENTS system thread random unit_test_framework REQUIRED )

# Find OpenCV 2.0
find_package( OpenCV REQUIRED )

# Set library sources
add_library (lrapp OBJECT ${SOURCES})

# Shared Library
set(RAPP_SHARED_NAME rapp)
add_library (${RAPP_SHARED_NAME} SHARED $<TARGET_OBJECTS:lrapp>)
target_link_libraries(${RAPP_SHARED_NAME} ${Boost_SYSTEM_LIBRARY} ${Boost_RANDOM_LIBRARY})
SET_TARGET_PROPERTIES(
  ${RAPP_SHARED_NAME}
  PROPERTIES
    SOVERSION ${RAPP_VERSION_MAJOR}
    VERSION ${RAPP_VERSION}
)

# Static Library
set(RAPP_STATIC_NAME rapp-static)
add_library (${RAPP_STATIC_NAME} STATIC $<TARGET_OBJECTS:lrapp>)
target_link_libraries(${RAPP_STATIC_NAME} ${Boost_SYSTEM_LIBRARY} ${Boost_RANDOM_LIBRARY})

# Link Tests/Examples
target_link_libraries( rapp_face_detect ${CMAKE_THREAD_LIBS_INIT} ${Boost_THREAD_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_RANDOM_LIBRARY})
target_link_libraries( rapp_object_detect ${CMAKE_THREAD_LIBS_INIT} ${Boost_THREAD_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_RANDOM_LIBRARY})
target_link_libraries( rapp_qr_detect ${CMAKE_THREAD_LIBS_INIT} ${Boost_THREAD_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_RANDOM_LIBRARY})
target_link_libraries( rapp_fetch_data ${CMAKE_THREAD_LIBS_INIT} ${Boost_THREAD_LIBRARY} ${Boost_SYSTEM_LIBRARY} )
target_link_libraries( rapp_ontology_test ${CMAKE_THREAD_LIBS_INIT} ${Boost_THREAD_LIBRARY} ${Boost_SYSTEM_LIBRARY} )



set(CMAKE_COLOR_MAKEFILE on)
set(CMAKE_VERBOSE_MAKEFILE off)


# TODO: Parse argument Release/Debug from Command line
#set(CMAKE_BUILD_TYPE Release)
set(CMAKE_BUILD_TYPE Debug)

# Linux should be the default OS/Platform for RAPP::API
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  
  # using GCC/Linux
  message (STATUS "GCC/Linux" )
  execute_process(COMMAND ${CMAKE_C_COMPILER} -dumpversion OUTPUT_VARIABLE GCC_VERSION)
  
  if (GCC_VERSION VERSION_GREATER 4.7 OR GCC_VERSION VERSION_EQUAL 4.7)
    message(STATUS "Info: g++ version >= 4.7 using C++11")  
  elseif ()
    message (FATAL_ERROR "g++ version >= 4.7 is required")
  endif()
  
  # Do I need this ?
  #add_definitions(-DBOOST_THREAD_USE_LIB)
  
  # NOTE: gnu++11 enables GNU's violating options, whereas c++11 is strictly only the new version
  # static libstdc++ linkage solves issues in Gentoo/OpenNao where packages of newer gcc don't exist.
  # Ideally you should setup using export LD_LIBRARY_PATH, but this is a quick and dirty way of packaging librapp
  # -static-libstdc++
  # -stdlib=libc++ will link using an alternative to gcc std c++ library - WARNING not working on OpenNao
  # -static-libgcc will link statically GLIBC

  set(RAPP_CXX_FLAGS "-std=gnu++11 -Wall -fPIC -static-libstdc++")
  set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} ${RAPP_CXX_FLAGS})
  message(STATUS "CXX Flags: " ${CMAKE_CXX_FLAGS})
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
  #set(CMAKE_EXE_LINKER_FLAGS "-lc++ -lcxxrt") # Set linker flags - WARNING alternative c++ libraries not present on OpenNao
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -mtune=native -march=native") # -s ?
  set(BUILD_SHARED_LIBS OFF)
  message(STATUS "CXX Linker: " ${CMAKE_EXE_LINKER_FLAGS})

elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    # using Clang
    message (STATUS "Clang/OSX" )
    execute_process(COMMAND ${CMAKE_C_COMPILER} -dumpversion OUTPUT_VARIABLE GCC_VERSION)
    if (CLANG_VERSION_MAJOR VERSION_GREATER 3 OR CLANG_VERSION_MAJOR VERSION_EQUAL 3)
        message(STATUS "Info: Clang >= 3.0 using C++11")
    elseif ()
        message(FATAL_ERROR "Clang version >= 3.0 is required")
    endif()
        set(RAPP_CXX_FLAGS "-std=c++11 -Wall")
        set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} ${RAPP_CXX_FLAGS})
        message(STATUS "CXX Flags: " ${CMAKE_CXX_FLAGS})
        set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
        set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -mtune=native -march=native")
        set(BUILD_SHARED_LIBS OFF)
        message(STATUS "CXX Linker: " ${CMAKE_EXE_LINKER_FLAGS})

# Intel Compiler May run on Linux - Maybe we should support it
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
    message (FATAL_ERROR "unsupported compiler")

# We cannot support Microsoft Visual Studio - We cannot support Win32 platforms
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    message (FATAL_ERROR "unsupported compiler")
endif()

#set(MACOSX_RPATH ON)


# Prepare the CMake config files
configure_file(RappConfig.cmake.in "${PROJECT_BINARY_DIR}/RappConfig.cmake" @ONLY)
configure_file(RappConfigVersion.cmake.in "${PROJECT_BINARY_DIR}/RappConfigVersion.cmake" @ONLY)
 
# Install the CMake config files
install(FILES
  "${PROJECT_BINARY_DIR}/RappConfig.cmake"
  "${PROJECT_BINARY_DIR}/RappConfigVersion.cmake"
  DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/CMake/Rapp")


# Install stuff
install (TARGETS ${RAPP_SHARED_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/)
install (TARGETS ${RAPP_STATIC_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/)

install (DIRECTORY ${INCLUDES}/ DESTINATION ${CMAKE_INSTALL_PREFIX}/include/${PROJECT_NAME} FILES_MATCHING PATTERN "*.hpp" PATTERN "*.ihh")
install (FILES ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/include/${PROJECT_NAME}) #copy global include header
