/*Write a program that plots an **horizontal** bar chart from a vector containing the length of each bar. 
Display the bar chart horizontally and use equal signs to visualize the columns.
Use `1, 3, 5, 0, 2` to create your vector.*/

#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<int> graph {1,3,4,0,2};

    for (int value:graph){
        for (int i{0}; i<value; i++)
            cout<< "=";
        cout <<endl;
    }
    return 0;
}