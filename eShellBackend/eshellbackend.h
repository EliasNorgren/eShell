#ifndef ESHELLBACKEND_H
#define ESHELLBACKEND_H
#include <string>
#include <set>
#include <list>
#include <vector>

using namespace std;

class eShellBackend
{

private:
    set<string> systemCommands;
    string cwd;

    void initSystemCommands();
    vector<string> runCommandls(vector<string>);
    vector<string> getSplittedCommand(string command);

public:
    eShellBackend();
    vector<string> runCommand(string command);
};

#endif // ESHELLBACKEND_H
