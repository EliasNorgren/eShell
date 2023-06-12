#include "eshellbackend.h"
#include <string>
#include <iostream>
#include <fstream>
#include <set>
#include <filesystem>
#include <list>
#include <vector>

using namespace std;
namespace fs = std::filesystem;

eShellBackend::eShellBackend()
{
    cout << "Starting shell...\n";
    this->cwd = fs::current_path();
    initSystemCommands();
    cout << "Shell started!\n";
}

vector<string> eShellBackend::runCommand(string input)
{
    vector<string> splittedCommand = getSplittedCommand(input);
    string command = splittedCommand[0];
    if (this->systemCommands.find(input) != this->systemCommands.end())
    {
        if (command.compare("ls") == 0)
        {
            return this->runCommandls(splittedCommand);
        }

        vector<string> res;
        res.push_back("Command found but no suitable commandFunction found");
        return res;
    }
    vector<string> res;
    res.push_back("Command not found");
    return res;
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

vector<string> eShellBackend::getSplittedCommand(string command)
{

    istringstream iss(command);
    vector<std::string> words;
    string word;

    while (iss >> word)
    {
        words.push_back(word);
    }

    return words;
}

// COMMANDFUNCTIONS !! ------------------------------------

vector<string> eShellBackend::runCommandls(vector<string>)
{
    vector<string> result;

    for (const auto &entry : fs::directory_iterator(this->cwd))
    {
        if (entry.is_regular_file())
        {
            string line = "File: " + entry.path().filename().string() + "Size: " + to_string(fs::file_size(entry)) + " bytes";
            result.push_back(line);
            // fs::file_time_type fileTime = fs::last_write_time(entry);

            // cout << "Last modified: " << '\n';
            // Add more details as needed
        }
        else if (entry.is_directory())
        {
            string line = "Directory: " + entry.path().filename().string();
            result.push_back(line);
        }
    }
    return result;
}