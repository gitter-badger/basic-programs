#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream file("myFile.txt"); // open file

    file << "Cool This writes to file" << endl;

    file << "A new line" << endl;

    file.close(); // close the file

    return 0;
}
