#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream file("myFile.txt");

    file << "Amazgvnging";

    file.close();

    return 0;
}
