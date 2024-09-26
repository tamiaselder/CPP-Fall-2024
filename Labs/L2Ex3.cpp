/*
Write a program that prompts the user for a string and checks (and prints) if it is a palindrome. That is "a word, phrase, or sequence that reads the same backward as forward".
Example: `madam` or `nurses run`. Note that, as in the second example, spaces (and capitalization) should be ignored.

### Example of output

```
  Enter string:
  > madam

madam is a palindrome*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){

    string input{};
    string wospace{};
    string lstring{};
    string test{};

    cout << "enter string" << endl;

    getline(cin,input);

    for (size_t i{}; i < input.length(); i++){
        if(!isspace(input.at(i)))
            wospace += input.at(i);
    }

    for (char c : wospace)
    {
        lstring += std::tolower(c);
    }

    size_t L = lstring.length();
    for (int i{1}; i <= L ; i++){
        test += lstring.at(L-i);
    }
    
    if (test == lstring){
        cout << "[" << input << "] is a palindrome" << endl;
    }else{
        cout << "[" << input << "] is a not palindrome" << endl;
    } 


    return 0;
}