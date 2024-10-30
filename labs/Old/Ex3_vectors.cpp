/*Write a program that reads `N` double numbers `x_i` and prints their standard deviation.

![](https://latex.codecogs.com/svg.latex?\sigma=\sqrt{\frac{1}{N}\sum_{i=1}^N(x_i-\mu)^2})

where

![](https://latex.codecogs.com/svg.latex?\mu=\frac{1}{N}\sum_{i=1}^Nx_i)

The program should first prompt the user to input the number of numbers. 
Then it should read the numbers, compute their standard deviation, and print it.

How many numbers:
> 3
Insert 3 numbers:
> 2.1
> 2.6
> 1

Their std is 0.6683312552*/

#include <iostream>
#include <vector>
#include <math.h>
#include <limits>
#include <iomanip> 
using namespace std;

int main(){
    int N{};

    cout<< "How many numbers:" << endl;
    cin>> N;

    vector<double> Hold{};

    cout<< "Insert " <<N<< " numbers:" << endl;

    for (int i{0}; i<N; i++){
        double temp{};
        cin>>temp;
        Hold.push_back(temp);
    }

    double mu{};
    for (double value : Hold)
        mu+=value;
    mu=mu/N;

    double stdev{};
    for (double value : Hold){
        double temp{};
        temp = value - mu;
        temp *= temp;
        stdev += temp;
    }
    stdev /= N;
    stdev = sqrt(stdev);

    cout<< "Their Standard Deviation is: " 
        << fixed << setprecision(numeric_limits<double>::max_digits10) 
        << stdev << endl;

    return 0;
}