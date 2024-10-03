//Write a program that reads an integer input, and prints the corresponding month. If the input is larger than 12 or smaller or equal than zero, it should display an error message.


#include <iostream>
#include <vector>

using namespace std;


int main () {
    vector <string> months {"Janurary","February","March","April","May","June","July","August","September","October","November","December"};

    cout << "enter the number of month" << endl;

    int month{};

    cin >> month; 

    if ( month > 0 && month <13)
        cout << months.at(month-1) << endl;
    else 
        cout << "Error, No month associated with that number" << endl;

}
