#include "eshellbackend.h"
#include <string>
#include <iostream>
#include <fstream>
#include <set>

using namespace std;

eShellBackend::eShellBackend()
{
    cout << "Starting shell\n";
    initSystemCommands();
}

string eShellBackend::runCommand(string command)
{
    if (this->systemCommands.find(command) != this->systemCommands.end())
    {
        return command;
    }

    return "Command not found";
}

void eShellBackend::initSystemCommands()
{
    ifstream sysCmdsFile("/home/user/Documents/eShell/eShellBackend/systemCommands");

    if (!sysCmdsFile.is_open())
    {
        sysCmdsFile.close();
        cout << "Could not open file\n";
        return;
    }

    string command;
    while (getline(sysCmdsFile, command))
    {
        this->systemCommands.insert(command);
    }
    sysCmdsFile.close();
}