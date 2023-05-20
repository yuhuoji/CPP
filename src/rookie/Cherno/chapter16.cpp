/**
 * pointer
 * dereference
 */
#include <iostream>
#include <cstring>
using namespace std;
int main() {
    void* ptr = nullptr;

    char* buffer = new char[8];
    memset(buffer, 0, 8);
    delete[] buffer;

    return 0;
}