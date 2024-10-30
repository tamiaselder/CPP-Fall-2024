//Write a program that prompts the user for a number until the user inputs an integer.

#include <iostream>
#include <string>
#include <typeinfo>


using namespace std;

int main(){

    cout << "enter an integer: " << endl;

    string in{};

    int restart {0};
    while (restart == 0){
        restart = 1;
        in.clear();
        getline(cin, in);

        int num{};
        double test{};

        try {
            num = stoi(in);
        } catch (const invalid_argument& e) {
            restart = 0;
        } catch (const out_of_range& e) {
            cerr << "Try again" << endl;
            restart = 0;
        }

        try {
            test = stod(in);
                if (test == num){
                    cout << "The number is: " << num << endl;
                }else{
                    cout << "Try again" << endl;
                restart = 0;
                }
        } catch (const invalid_argument& e) {
            cerr << "Try again" << endl;
            restart = 0;
        } catch (const out_of_range& e) {
            cerr << "Try again" << endl;
            restart = 0;
        }
        

    }
    return 0;
}

/*try {
        num = std::stoi(str);
        std::cout << "stoi: " << num << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Out of range: " << e.what() << std::endl;
    }*/