/*Write a program that prompts the user for a stirng. Print the stirng in reverse order

### Example of output

```
  Enter string:
  > of that im sure
Reverse is string: erus mi taht fo
```
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
    
    string in {};

    cout << "enter string" << endl;

    getline(cin, in);

    string temp{};
    size_t l{in.length()};

    for (int i{1}; i <= l ; i++){
        temp.push_back(in.at(l-i));

    }
    cout << temp << endl;

    return 0;
}