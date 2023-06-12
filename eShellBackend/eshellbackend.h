#ifndef ESHELLBACKEND_H
#define ESHELLBACKEND_H
#include <string>
#include <set>

using namespace std;

class eShellBackend
{

private:
    set<string> systemCommands;
    void initSystemCommands();

public:
    eShellBackend();
    string runCommand(string command);
};

#endif // ESHELLBACKEND_H
