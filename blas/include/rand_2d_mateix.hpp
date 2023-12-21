#include<vector>
#include<random>
#include<chrono>
#include<cmath>
#include<fstream>
#include<iostream>
#include<cstdlib>


// This is a function that generates a random 2D matrix of size n x n
// with entries in the range [0,1]
std::vector<std::vector<double>> rand_2d_matrix(int n)
{
    // Initialize the random number generator
    std::mt19937_64 rng;
    rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    // Initialize the uniform distribution
    std::uniform_real_distribution<double> unif(0,1);
    // Initialize the matrix
    std::vector<std::vector<double>> A(n, std::vector<double>(n));
    // Fill the matrix with random numbers
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            A[i][j] = unif(rng);
        }
    }
    return A;
}
