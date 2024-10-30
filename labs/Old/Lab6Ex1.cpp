// Implement a function to construct an N x M random matrix.
// Use the `using` statement; for instance, you can define your 
// matrix type as `using matrix_type = std::vector<std::vector<double>>`.

#include <iostream>
#include <vector>
#include <random>

using matrix_type = std::vector<std::vector<double>>;

struct sizematch {
    unsigned long long  sz1{};
    unsigned long long  sz2{};
};

matrix_type generatematrix (int n, int m){
    matrix_type matrix{};
    for (int i{}; i < n; i++){
        std::vector<double> temp {};  
        for (int j{}; j<m; j++){
            int temp1 {rand()%10000 +1};
            int temp2 {rand()%1000 +1};
            double rand_doub = temp1/(double)temp2;
            temp.push_back(rand_doub);
        }
        matrix.push_back(temp);
    }
    return matrix;
}

matrix_type addmatricies (matrix_type A, matrix_type B){
    auto test1 = A.size();
    auto test2 = B.size();
    auto test3 = A.at(0).size();
    auto test4 = B.at(0).size();

    if (test1 != test2 )
        throw sizematch{test1, test2};

    if (test3 != test4)
        throw sizematch{test3,test4};

    matrix_type sum{};
    
    for (int i{}; i<test1; i++){
        std::vector<double> temp{};
        for (int j{}; j<test3; j++){
            double a {A.at(i).at(j)};
            double b {B.at(i).at(j)};
            temp.push_back(a+b);
        }
        sum.push_back(temp);
    }

    return sum;

}


int main (){

    srand((unsigned) time(NULL)); 
    int n {rand()%10 +1};
    int m {rand()%10 +1};
   
    matrix_type matrix1{};
    matrix_type matrix2{};
    matrix1 = generatematrix (n,m);
    matrix2 = generatematrix (n,m);

    //std::cout << "Generated a " << n << " by " << m << " matrix!"<< std::endl;

    std::cout << "Matrix 1:" << std::endl;
    for (auto i : matrix1){
        for (auto j : i){
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Matrix 2:" << std::endl;
    for (auto i : matrix2){
        for (auto j : i){
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    try{
        matrix_type matrix3 = addmatricies (matrix1,matrix2);
        std::cout << "sum of matricies: " << std::endl;
        for (auto i : matrix3){
            for (auto j : i){
                std::cout << j << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    catch(sizematch& e)
    {
        std::cout << e.sz1 << " and " << e.sz2 << " do not match. Unable to add matricies" << std::endl;
    }

    return 0;
}