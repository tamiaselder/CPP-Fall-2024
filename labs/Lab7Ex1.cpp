// ## Exercise 1 (Set)
// Implement a function punctuation, which creates a set of all punctuation characters used in a vector of input strings. 
//Once all the input has been processed, print each punctuation character separated by spaces. 
//[Here](https://en.cppreference.com/w/cpp/header/cctype), you can find functions to check if a character is a punctuation.

// ### Example of input
// ```
// {"Sea", "Shore,", "sea", "shell's.", "SHORE.", "line!"}
// ```

// ### Example of output
// ```
// ! ' , .
// ```


# include <set>
# include <vector>
# include <iostream>
# include <string>
# include <cctype>

void printpunct(std::vector<std::string> input_vec){
    std::set<char> punct {};

    for (auto input_line :input_vec){
        for (auto ch : input_line){
            if (std::ispunct(ch)){
                punct.insert(ch);
            }
        }
    }
    for (auto ch: punct){
        std::cout << ch << " " ;
    }
    std::cout << std::endl;

}

int main (){
    std::vector<std::string> david{"Sea", "Shore,", "sea", "shell's.", "SHORE.", "line!"};
    printpunct (david);

    return 0;
}