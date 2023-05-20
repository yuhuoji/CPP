/**
 * string
 */
#include <iostream>
#include <string>
using namespace std;
int main() {
    // char* name1 = "Tom";
    char name2[7] = {'C','h','e', 'r', 'r', 'y', '\0'};
    cout << name2 << endl;
    string name3 = string("Alan") + " Hello!";
    
    cout << name3 << endl;
}