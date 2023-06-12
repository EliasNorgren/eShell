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
    cout << command << "\n";

    return "asdasd";
}

void eShellBackend::initSystemCommands()
{
    cout << "Before file open\n";
    ifstream sysCmdsFile("systemCommands");
    cout << "After file open\n";

    string command;
    // Use a while loop together with the getline() function to read the file line by line
    while (getline(sysCmdsFile, command))
    {
        // Output the text from the file
        cout << command;
    }

    // Close the file
    sysCmdsFile.close();
}