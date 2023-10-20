#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <cstdlib>
#include <sys/wait.h>

// print the generations name the process IDs
void printGeneration(int generation)
{
    // get current ID and parent process IDs
    pid_t pid = getpid();
    pid_t ppid = getppid();

    std::string genStr;

    // determine the generation based on argument passed in
    if (generation == 0) {
        genStr = "Parent";
    } else if (generation == 1) {
        genStr = "Child";
    } else if (generation == 2) {
        genStr = "Grandchild";
    } else {
        for (int i = 3; i <= generation; ++i) {
            genStr += "Great ";
        }
        genStr += "Grandchild";
    }

    // print statement
    std::cout << genStr << ". pid: " << pid << " ppid: " << ppid << std::endl;
}
