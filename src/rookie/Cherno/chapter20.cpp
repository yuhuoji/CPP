/**
 * @date 2023-05-18
 * chapter20
 * class
 */
#include <iostream>
using namespace std;
class Log {
public:
    const int logLevelError = 0;
    const int logLevelWarning = 1;
    const int logLevelInfo = 2;

private:
    logLevel = logLevelInfo;

public:
    Log(/* args */) {}
    ~Log() {}
};
int main() {
    Log log;
}