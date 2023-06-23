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
}