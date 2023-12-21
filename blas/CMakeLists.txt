cmake_minimum_required(VERSION 3.20)

project(
    CBlasExample
    VERSION 0.0.1
    LANGUAGES CXX Fortran
)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# set(BLA_VENDOR ACML)
find_package(BLAS)
message(STATUS "BLAS found: ${BLAS_LIBRARIES}")
cmake_path(GET BLAS_LIBRARIES PARENT_PATH blas_lib_path)
message(STATUS "BLAS lib path: ${blas_lib_path}")
cmake_path(GET blas_lib_path PARENT_PATH BLAS_PATH)
#now create the inlude path for the blas
cmake_path(APPEND BLAS_INCLUDE_DIRS "${BLAS_PATH}/include")
message(STATUS "BLAS include dirs: ${BLAS_INCLUDE_DIRS}")


find_package(PkgConfig REQUIRED)


find_file(BLAS_INCLUDE_DIRS NAMES cblas.h)
message(STATUS "[BLAS include dirs]: ${BLAS_INCLUDE_DIRS}")

## create an empty libm or default to use system libm
set(LIBM "m")

## math library
## if use amd libm 
option(USE_AMD_LIBM "Use AMD libm" ON)
if(USE_AMD_LIBM)
    find_library(AMD_LIBM_LIBRARIES NAMES amdlibm)
    find_path(AMD_LIBM_INCLUDE_DIRS NAMES amdlibm.h)
    ## set flags for amd libm 
    include_directories(${AMD_LIBM_INCLUDE_DIRS})
    message(STATUS "AMD libm found: ${AMD_LIBM_LIBRARIES}")
    message(STATUS "AMD include dirs: ${AMD_LIBM_INCLUDE_DIRS}/blis")
    set(LIBM ${AMD_LIBM_LIBRARIES} "m")
    message("MATH LIB ${LIBM}")
endif()

option(USE_AMD_BLIS "Use AMD BLIS" OFF)


## LAPACK library
option(USE_AMD_LIBFLAME "Use AMD libflame" OFF)



pkg_check_modules(BLAS blis)
message(STATUS "BLAS found: ${BLAS_LIBRARIES}")
message(STATUS "BLAS include dirs: ${BLAS_INCLUDE_DIRS}")
include_directories(${BLAS_INCLUDE_DIRS})

find_package(Eigen3 REQUIRED)
message(STATUS "Eigen3 found: ${EIGEN3_INCLUDE_DIRS}")
message(STATUS "Eigen3 version: ${EIGEN3_VERSION}")
include_directories(${EIGEN3_INCLUDE_DIRS})




## AMD libm 
# # find_package(amdlibm)
# find_library(AMD_LIBM_LIBRARIES NAMES amdlibm)
# find_path(AMD_LIBM_INCLUDE_DIRS NAMES amdlibm.h)
# include_directories(${AMD_LIBM_INCLUDE_DIRS})
# message(STATUS "AMD libm found: ${AMD_LIBM_LIBRARIES}")
# message(STATUS "AMD include dirs: ${AMD_LIBM_INCLUDE_DIRS}")




add_subdirectory(tests)


## define installation destinations
# if (NOT DEFINED CMAKE_INSTALL_LIBDIR)
#     set(CMAKE_INSTALL_LIBDIR lib)
# endif()
# if (NOT DEFINED CMAKE_INSTALL_INCLUDEDIR)
#     set(CMAKE_INSTALL_INCLUDEDIR include)
# endif()
# if (NOT DEFINED CMAKE_INSTALL_BINDIR)

