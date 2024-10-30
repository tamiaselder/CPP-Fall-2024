/*Write a program that simulates the Rock-Paper-Scissors game. 
The program should ask the player to input his choice ((r) rock, (p) paper, or (s)scissors) and 
randomly generate the computer choice. Then, it should decide the winner and print the result.

The program should start with the player choosing the first letter of the element 
(both uppercase and lowercase letters should be accepted). 
The program should continue to ask for the element until a valid letter is chosen.

After making the correct choice, the program should display the player and computer choice on screen using ASCII art.*/

// for whole program... rock==1 paper==2 scissors==3

#include <iostream>
#include <cstdlib>
using namespace std;


int input (){
    char input{};
    int send{0};
    cout << "Input your choice!" << endl <<	"R/r - rock" << endl << "P/p - paper" << endl << "S/s - scissors" << endl;
    cin >> input;

    if (input=='R'|| input=='r')
        send=1;

    if (input=='P'|| input=='p')
        send=2;

    if (input=='S'|| input=='s')
        send=3;

    return send;
}

void print_ASCII(int print_val){
if (print_val == 1){
    cout << R"(
 __.--.--._
/  | _|  | `|
|  |` |  |  |
| /'--:--:__/
|/  /      |
(  ' \     |
 \    `.  /
  |      |
  |      |)" << endl;
}

if (print_val == 2){
    cout << R"(
    --.--.
   |  |  |
.""|  |  |_
|  |  |  | `|
|  | _|  |  |
|  |` )  |  |
| /'  /     /
|/   /      |
(   ' \     |
\      `.  /
 |        |
 |        |)" << endl;
}

if (print_val == 3){
    cout << R"(
."".   ."",
|  |  /  /
|  | /  /
|  |/ .--._
|    _|  | `|
|  /` )  |  |
| /  /'--:__/
|/  /      |
(  ' \     |
 \    `.  /
  |      |
  |      |)" << endl;

}
}

// return 0-tie 1-player win 2-comp win
int winner (int player, int computer){
    int result{};
    if (player==1){
        if (computer==1)
            return 0;
        if (computer==2)
            return 2;
        if (computer==3)
            return 1;
    }
    if (player==2){
        if (computer==1)
            return 1;
        if (computer==2)
            return 0;
        if (computer==3)
            return 2;
    }
    if (player==3){
        if (computer==1)
            return 2;
        if (computer==2)
            return 1;
        if (computer==3)
            return 0;
    }
    return -1;
}

int main(){
//prompt first 
int user_input{0};

while (user_input==0){
    user_input=input();
}


// this was a test cout << user_input << endl;
//random 

srand((unsigned) time(NULL)); 
int comp_choice{(rand() %3) +1};



//print 
cout<< endl << "Player choice:" << endl;
print_ASCII(user_input);

cout<< endl << "Computer choice:" << endl;
print_ASCII(comp_choice);

//winner
int result = winner(user_input, comp_choice);

if (result == 0)
    cout<< "Its a Tie" <<endl;

if (result == 1)
    cout<< "You Win!" <<endl;

if (result == 2)
    cout<< "YOU LOSE" <<endl;

if (result ==-1)
    cout<< ":(";

return 0;
}