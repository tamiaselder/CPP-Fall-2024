#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

void justified(vector<string> line){
    int spaces{30};
    int numwords{};

    for (string s : line){
        spaces -= s.length();
        numwords += 1;
    }

    int word {1};
    for (string pnt : line){
        cout << pnt;

        if (word == numwords){
            cout << endl;
        }else{
            int pspace = spaces / (numwords - word);
            for (int i{0}; i<pspace; i++){
                cout << " ";
            }
            spaces -= pspace;
        }

        word ++;
    }

}

int main(){

    // Excersize one 
    vector <string> uin {};

    string in {};
    string temp{};
    int j {0};

    while(cin >> in){
        for (size_t i{}; i < in.length(); i++){
            j++;
            if (j == in.length()){
                uin.push_back(in);
                j=0;
            }
        }

    }
    
    //Excersize two
    vector <string> line{};
    int last_word{0};
    int counter{1};
    for (string word : uin){
        
        if (counter == uin.size())
            last_word = 1;

        int size {0};
        for (string sz : line){
            size += sz.length();
            size++;
        }
        if (word.length()+size <=30){
            line.push_back(word);
            
            if (last_word){
                for(string out : line){
                
                cout << out << " ";
            }
            cout << endl;
            }
        }
        else{
            //Excersize three
            
            justified(line);  //justified line impl here

            

            line.clear();

            if (word.length() > 30){
                cout << word << endl;
            }else{
                line.push_back(word);
            }


        }
        counter ++;
    }


    return 0;
}