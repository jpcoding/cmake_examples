add_executable(link_test_openblas link_test_openblas.cpp)
#link to blas 

target_include_directories(link_test_openblas PUBLIC ${CMAKE_SOURCE_DIR}/include )

target_link_libraries(link_test_openblas BLAS::BLAS ${LIBM} Eigen3::Eigen)

message("what is this BLAS::BLAS")

add_executable(link_test_fortran link_test_openblas.f90)
target_link_libraries(link_test_fortran BLAS::BLAS)



