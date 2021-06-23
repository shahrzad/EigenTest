cmake_minimum_required(VERSION 3.19)
project(EigenTest)

set(CMAKE_CXX_STANDARD 14)

#add_executable(EigenTest main.cpp)

#find_package( LAPACK REQUIRED )
#include_directories(${LAPACK_INCLUDE_DIR})
#message ("lapack" ${LAPACK_INCLUDE_DIR})
#
#find_package( BLAS REQUIRED )
#include_directories(${BLAS_INCLUDE_DIR})

#set(EIGEN_WITH_HPX OFF CACHE BOOL "HPX backend")
#if(EIGEN_WITH_HPX)
#    add_definitions(-DEIGEN_HAS_HPX)
#endif()

#set(OPENMP_BACKEND OFF CACHE BOOL "OpenMP backend")
#if (OPENMP_BACKEND)
#    find_package(OpenMP)
#    if (OPENMP_FOUND)
#        set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
#        set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
#        set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
#    endif()
#    add_executable(EigenTest main.cpp)
#endif()

set(HPX_BACKEND OFF CACHE BOOL "HPX backend")
if (HPX_BACKEND)
    add_definitions(-DEIGEN_HAS_HPX)
    find_package(HPX REQUIRED)
    add_hpx_executable(EigenTest SOURCES main.cpp)
else()
    find_package(OpenMP)
    if (OPENMP_FOUND)
        set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
        set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
        set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
    endif()
    add_executable(EigenTest main.cpp)
endif()

#include_directories(/home/shahrzad/lib/eigen/include/eigen3/)
include_directories(/home/shahrzad/src/eigen/)

#target_link_libraries(BlazeTest PUBLIC ${BLAS_LIBRARIES} ${LAPACK_LIBRARIES})
#find_package(HPX REQUIRED)
#add_hpx_executable(EigenTest SOURCES main.cpp)

#get_cmake_property(_variableNames VARIABLES)
#list (SORT _variableNames)
#foreach (_variableName ${_variableNames})
#    message(STATUS "${_variableName}=${${_variableName}}")
#endforeach()




