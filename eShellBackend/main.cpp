#include <iostream>
#include "./eshellbackend.h"
#include <string>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

int main(int argc, char **argv)
{
    eShellBackend be;
    vector<string> res = be.runCommand(argv[1]);
    for (string s : res)
    {
        cout << s << endl;
    }

    // fs::path newDirectory = "../";

    // if (fs::exists(newDirectory) && fs::is_directory(newDirectory))
    // {
    //     fs::current_path(newDirectory);
    //     std::cout << "Working directory changed to: " << fs::current_path() << '\n';
    // }
    // else
    // {
    //     std::cout << "Directory does not exist or is not a valid directory.\n";
    // }

    // currentPath = fs::current_path();

    // cout << "Current working directory: " << currentPath << '\n';
}