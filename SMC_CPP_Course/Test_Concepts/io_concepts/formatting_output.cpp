// Illustrates outpt formatting instructions.
// Reads all the numbers in the file rawdata.dat and writes the numbers
// to the screen and to the file neat.dat in a neatly formatted way.
#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <iomanip> // needed for setw
using namespace std;

void makeNeat(ifstream& messFile, ofstream& neatFile,
               int numberAfterDecimalpoint, int fieldWidth);


int main()
{
    ifstream fin;
    ofstream fout;

    fin.open("rawdata.dat");
    if (fin.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    fout.open("neat.dat");
    if (fout.fail())
    {
        cout << "Output file opening failed.\n";
        exit(1);
    }
    makeNeat(fin,fout,5,12);
    fin.close();
    fout.close();
    cout << "End of Program.\n";
    return 0;
}
// Uses iostream, fstream, and iomanip
void makeNeat(ifstream& messyFile, ofstream& neatFile,
               int numberAfterDecimalpoint, int fieldWidth)
{
    neatFile.setf(ios::fixed);
    neatFile.setf(ios::showpoint);
    neatFile.setf(ios::showpos);
    neatFile.precision(numberAfterDecimalpoint);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.setf(ios::showpos);
    cout.precision(numberAfterDecimalpoint);

    double next;
    while (messyFile >> next)
    {
        cout << setw(fieldWidth) << next << endl;
        neatFile << setw(fieldWidth) << next << endl;
    }
}