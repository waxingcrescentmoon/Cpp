// Some files may be corrupted. 
// Check before you open the file and then execute.


#include <iostream> // For cout & cin
#include <fstream> // file stream. For file I/O
#include <cstdlib> // for exit
using namespace std;

int main()
{
    // ifstream and ofstream must be declared if you want a stream
    // to a file. Simlar to declaring avariable. ifstream and ofstring
    // are defined in <fstream>.
    ifstream inStream; 
    ofstream outStream; 

    inStream.open("infile.dat"); // Open infile.dat with inStream.
    if (inStream.fail( ))
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    outStream.open("outfile.dat"); // Open outfile.dat with outStream.
    if (outStream.fail( ))
    {
        cout << "Output file opening failed.\n";
        exit(1);
    }

    int first, second, third; // Declare variables.
    inStream >> first >> second >> third; //Use inStream to assign text in infile.dat to variables. 
    outStream << "The sum of the first 3\n"
              << "numbers in infile.dat\n"
              << "is " << (first + second +third) // Sum streamed values.
              << endl;
    inStream.close(); // Close infile.dat.
    outStream.close(); // Clost outfile.dat.
    return 0;
}