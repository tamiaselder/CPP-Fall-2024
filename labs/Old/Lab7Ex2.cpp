// ## Exercise 2 (Iterators)

// Write a program that prompts the user for a string. Print the string in reverse order using iterators.

// ### Example of output

// ```
//   Enter string:
//   > of that im sure

// Reverse is string: erus mi taht fo
// ```


# include <iostream>
# include <string>


int main(){

    std::string david{};
    std::cout<<"Enter a string: " <<std::endl;
    std::getline (std::cin,david);

    auto it = david.end();
    auto first = david.begin();


    while (it!=(first)){
        it -= 1;
        std::cout << *it;
    }
    std::cout << std::endl;

    return 0;
}