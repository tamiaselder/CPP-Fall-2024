// Implement the class StopWatch. The class should contain:

// - An constructor that initialises the start time with the current time
// - Function `start` that resets the start time
// - Function `stop` that sets the end time
// - Function `get_time` that returns the elapsed time in *seconds*.

#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;


class StopWatch{
    private: 
    time_t startTime;
    time_t endTime;

    public: 
    StopWatch(){
        startTime = time(NULL);
    }

    void start(){
        startTime = time(NULL);
    }
    void stop(){
        endTime = time(NULL);
    }

    int get_time(){
        return endTime-startTime;
    }
};

int main(){
    StopWatch mystopwatch;
    for (size_t i = 0; i < 1000000000; i++)

    mystopwatch.stop();
    cout << mystopwatch.get_time()<< " seconds" <<endl;
    mystopwatch.start();
    for (size_t i = 0; i < 300000000; i++)

    mystopwatch.stop();
    cout << mystopwatch.get_time()<< " seconds" <<endl;
    
    return 0;
}

