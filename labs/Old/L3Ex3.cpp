//Write a program that reads a string of integer numbers separated by space and removes duplicated numbers 
//(the order of the output is not important). Finally, print the result.


#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main () {

    string input{};
    vector <int> numbers{};

    cout << "enter string of numbers" << endl;

    while (cin >> input){
        numbers.push_back(stoi(input));
    }


    int in {0};
    vector <int> norep{};
    for (int a : numbers){

        for(int b : norep){
            if (a == b)
                in = 1;
        }

        if (in  == 0)
            norep.push_back(a);
        in = 0;
    }
    for(int c : norep){
        cout << c << " ";
    }
    cout << endl;

    return 0;
}