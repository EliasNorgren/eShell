#include "eshellbackend.h"
#include <string>
#include <iostream>
#include <fstream>
#include <set>
#include <filesystem>
#include <list>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>

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

    cout << "Splitted cmd:\n";
    for (string s : splittedCommand)
    {
        cout << s << endl;
    }
    cout << "-------------\n";

    cout << "Sys cmds:\n";
    for (string s : this->systemCommands)
    {
        cout << s << endl;
    }
    cout << "-------------\n";

    string command = splittedCommand[0];
    if (this->systemCommands.find(command) != this->systemCommands.end())
    {
        if (command.compare("ls") == 0)
        {
            return this->runCommandls();
        }
        else if (command.compare("cd") == 0)
        {
            return this->runCommandcd(splittedCommand);
        }

        vector<string> res;
        res.push_back("Command found but no suitable commandFunction found");
        return res;
    }

    // Run outside command

    pid_t pid = fork();

    if (pid == 0)
    {
        // Create a null-terminated array of C-strings
        vector<char *> cstrings;
        for (auto &arg : splittedCommand)
        {
            cstrings.push_back(&arg[0]);
        }
        cstrings.push_back(nullptr);                         // Add a nullptr as the last element                                                                           // Child process
        execvp(splittedCommand[0].c_str(), cstrings.data()); // Executes the command
        vector<string> res;
        res.push_back("Error executing command " + splittedCommand[0] + ".\n");
        return res;
    }
    else if (pid > 0)
    {                  // Parent process
        wait(nullptr); // Wait for the child process to finish
        vector<string> res;
        res.push_back("Process has finished.\n");
        return res;
    }
    else
    {
        vector<string> res;
        res.push_back("Error forking process.\n");
        return res;
    }
}

void eShellBackend::initSystemCommands()
{

    ifstream sysCmdsFile("eShellBackend/systemCommands");

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

vector<string> eShellBackend::runCommandls()
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

vector<string> eShellBackend::runCommandcd(vector<string> cmd)
{
    vector<string> res;
    if (cmd.size() < 2)
    {
        res.push_back("To few arguments to command cd");
        return res;
    }
    fs::path newDirectory = cmd[1];

    if (fs::exists(newDirectory) && fs::is_directory(newDirectory))
    {
        fs::current_path(newDirectory);
        this->cwd = fs::current_path();
        res.push_back("cwd: " + this->cwd);
        std::cout << "Working directory changed to: " << fs::current_path() << '\n';
    }
    else
    {
        std::cout << "Directory does not exist or is not a valid directory.\n";
    }

    return res;
}