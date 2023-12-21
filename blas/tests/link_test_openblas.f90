
program link_test_openblas
    implicit none
    
    ! External BLAS library
    external :: dgemm
    
    ! Function declaration
    external :: print_hello
    
    ! Main program
    print *, "Hello, World!"
    
end program link_test_openblas
