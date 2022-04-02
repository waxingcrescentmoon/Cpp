// Reads first three numbers fromt infile.dat, sums them,
// and writes the sume into outfile.dat
// Close the file once you no longer need it open. The file
// Will automatically close once the application ends, but
// it is wasted resources while the app is running. In addition,
// files can become corrupted if left open.

// When used with a stream of type ofstream, the member function "open"
// will create an output file if it does not already exist.
// If the output file does exist the member function "open" will 
// discard the contents of the file so that the optput file is empty
// after the call to open.



#include <iostream>
#include <fstream> //file stream
using namespace std;

int main()
{
    // ifstream and ofstream must be declared if you want a stream
    // to a file. Simlar to declaring avariable. ifstream and ofstring
    // are defined in <fstream>.
    ifstream inStream; 
    ofstream outStream; 

    inStream.open("infile.dat"); // Open infile.dat with inStream.
    outStream.open("outfile.dat"); // Open outfile.dat with outStream.

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