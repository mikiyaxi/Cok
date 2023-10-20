#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <cstdlib>
#include <sys/wait.h>


// print the generation name the process IDs
void printGeneration(int gen) {
    // get current ID and parent process ID
    pid_t pid = getpid();
    pid_t ppid = getppid();

    std::string genStr;

    // determine the generation based on argument passed in
    if (gen == 0) {
        genStr = "Parent";
    } else if (gen == 1) {
        genStr = "Child";
    } else if (gen == 2) {
        genStr = "Grandchild";
    } else {
        for (int i = 3; i <= gen; ++i) {
            genStr += "Great ";
        }
        genStr += "Grandchild";
    }

    // print
    std::cout << genStr << ". pid: " << pid << " ppid: " << ppid << std::endl;
}


int main(int argc, char **argv) {
    // check if argument passed in is valid
    if (argc != 2) {
        std::cout << "Usage: ./generations num_generations" << std::endl;
        return 1;
    }

    // convert argument to integer
    int numGenerations = std::atoi(argv[1]);
    // validate inputs
    if (numGenerations < 0) {
        std::cout << "Error: num_generations must be greater than 0" << std::endl;
        return 1;
    }

    // create generation by looping them
    for (int i = 0; i <= numGenerations; ++i) {
        // fork new process
        pid_t pid = fork();

        if (pid < 0) {
            // ford fail situation
            std::cerr << "Fork failed" << std::endl;
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

