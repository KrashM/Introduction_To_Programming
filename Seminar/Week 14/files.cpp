#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;

int main(){

    {
        ifstream inFile("myInput.txt");
        
        if(!inFile.is_open()){
            cout << "Error opening the file\n";
            return -1;
        }

        int x, y;

        inFile >> x >> y;

        cout << x << ' ' << y << '\n';

        inFile.close();

    }

    {

        ofstream outFile("myOutput.txt");

        outFile << "Hello World\n";

        outFile.close();

    }

}