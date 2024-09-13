/*Write a program that prompts the user for strictly positive doubles. 
Continue to request numbers until a negative number (or zero) is read. 
The program should compute and print the maximum of the numbers. 
If the first number entered is negative (or zero), the maximum should be 0.*/

#include <iostream>

int main(){

    double entered {};
    double max {0};

    std::cout << "Enter positive doubles:";

    while (entered <= 0){
        std::cin >> entered;
        if (entered>max)
            max=entered;
    }

    std::cout << "the maximum is" <<max<< std::endl;

    return 0;
}