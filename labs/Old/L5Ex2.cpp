/*Implement the `Matrix` struct using a `std::vector<std::vector<double>>`.
mplement a function to initialize an `n x m` zero matrices, a function to initialize a `n x n` identity, 
and a function to print the matrix.*/

#include <iostream>
#include <vector>

using namespace std;

struct Matrix{
    vector<vector<double>> matrix;
};

Matrix initilize_zero(int n, int m, Matrix A){
    for (int i{0}; i < n; i++){
        vector<double> temp{};
        for (int j{0}; j < m; j++){
            temp.push_back(0.00);
        }
        A.matrix.push_back(temp);
    }
    return A;
}

Matrix initilize_identity(int n, Matrix A){
    for (int i{0}; i < n; i++){
        vector<double> temp{};
        for (int j{0}; j < n; j++){          
            if (i==j){
            temp.push_back(1.00);
            }else{
            temp.push_back(0.00);  
            }                   
        }
        A.matrix.push_back(temp); 
    }
    return A;
}

void print_matrix(Matrix A){
    for (int i{0}; i < A.matrix.size(); i++){
        cout << "[";
        for (int j{0}; j < A.matrix[i].size(); j++){
            cout << A.matrix[i][j];
            if ((j+1) != A.matrix[i].size())
                cout << " ";
        }
    cout << "]" << endl;
    }
}

int main () {
    //cout << "HELOOOO" << endl;
    Matrix A{};
    Matrix B{};
    A = initilize_zero(2,2,A);
    B = initilize_identity(3,B);
    print_matrix(A);
    print_matrix(B);
    
    return 0;
}