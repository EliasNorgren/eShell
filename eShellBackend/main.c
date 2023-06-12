#include <iostream>
#include "eshellbackend.h"
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    eShellBackend be;
    string res = be.runCommand(argv[1]);
    cout << res << "\n";
}