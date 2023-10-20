
#include <iostream>
using namespace std;

// g++ -Wall -o hello_name && ./hello_name


// version 1
// int main(int argc, char *argv[])
// {
//     if (argc > 1) {
//         cout << "Hello, " << argv[1] << "!" << endl;
//     } else {
//         cout << "Hello, World!" << endl;
//     }
//     return 0;
// }




// version 2 
int main()
{
    string name; 
    // getline() reads in characters until and input stream (std::cin) until delimiter read
    getline(cin, name); 

    // in C++, std:string object is not implicitly convertible to boolean
    // can't do something like if (name) {}
    if (!name.empty()) {
        cout << "Hello, " << name << "!" << endl; 
    } else {
        cout << "Hello World!" << endl;
    }
    return 0;
}


