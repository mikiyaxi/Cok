#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <cstdlib>
#include <sys/wait.h>
using namespace std;


// Declaration of printGeneration (implemented in print_generation.cpp)
void printGeneration(int generation);

int main(int argc, char ** argv)
{
    // check if argument passed in is valid
    if (argc != 2) {
        // cout << "Usage: ./generations num_generations" << endl;
        cout << "Usage: " << argv[0] << "num_generations"  << endl; // argv[0] prints out what you error is, dig into it
        return 1;
    }

    // convert argument into integer
    int numGenerations = atoi(argv[1]);
    if (numGenerations <= 0) {
        cout << "Error: num_generations must be greater than 0" << endl;
        return 1;
    }

    // create generation by looping them
    for (int i = 0; i <= numGenerations; ++i) {
        // fork the new process
        pid_t pid = fork();

        if (pid < 0) {
            // fork fail situation
            cerr << "Fork failed" << endl;
            return 1;
        } else if (pid == 0) {
            // Child process continues the loop
        } else {
            // Parent process waits for child to finish
            wait(nullptr);
            printGeneration(i);
            exit(0);
        }
    }
    return 0;
}
