// Name: XXXXXXXX
// SSID: XXXXXXXX
// Assignment #: 2
// Submission Date: 3/21/2022
//
// Operating System: MacOS (Big Sur v11.6)
// Compiler Toolchain: G++
// IDE: Visual Studio Code
//
// Description: A program to encrypt and decrypt a message using a shift cipher
// The plaintext message must only contain the codebook characters
//
// command line arguments
// -p ThePla?Nt]xTM]ss2ge1? - the plaintext (p) message to be encrypted
// -C pC9lG1VjOwSpiwNNXB9xV - the cipher (C) text to be decrypted
// -k 9 - the key (k) shift value
// -E - the option to encrypt (E)
// -D - the option to decrypt (D)
//

#include <iostream> //std::cout , std::cin , etc.
#include <cstdlib> //C++ version of stdlib.h
#include <cstring> //C++ version of string.h
#include <string>
using namespace std;
char codebook [] = { 'Z','z','Y','y','X','x','W','w','V','v','U','u','T','t','S','s','R','r','Q','q',\
'P','p','O','o','N','n','M','m','L','l','K','k','J','j','I','i','H','h','G','g',\
'F','f','E','e','D','d','C','c','B','b','A','a','9','8','7','6','5','4','3','2',\
'1','0',']','?'};


// Todo A2: encrypt using std:: string
void encrypt(std:: string& plaintext, int k){
    string encrypted = "";
    for (int i = 0; i < plaintext.size(); i++){
        for (int j = 0; j < sizeof(codebook); j++){
            if (plaintext[i] == codebook[j]){
                encrypted += codebook[((j+k) % 64)];
                
            }
        }
    }
    cout << "The plaintext was: " << plaintext << "\n";
    cout << "The ciphertext is: " << encrypted << "\n";
    cout << "enter any key to exit  " << "\n";
    system("read");
}
    // Todo A2: decrypt using std:: string
void decrypt(std:: string& ciphertext , int k){
    string decrypted = "";
    for (int i = 0; i < ciphertext.size(); i++){
        for (int j = 0; j < sizeof(codebook); j++){
            if (ciphertext[i] == codebook[j]){
                if (j-k >= 0){
                    decrypted += codebook[((j-k) % 64)];
                }
                if (j-k  < 0){
                    decrypted += codebook[((j-k) % 64) + 64];
                }
            }
        }
    }
    cout << "The ciphertext was: " << ciphertext << "\n";
    cout << "The plaintext is: " << decrypted << "\n";
    cout << "enter any key to exit  " << "\n";
    system("read");
}


int main(int argc , char *argv [])
{
    // Example variables for A02
    int k = 0; // index to k
    int msg_index = 0; // msg_index of plaintext or ciphertext in argv
    std:: string msg; // string to hold the plaintext or ciphertext;
    bool do_encrypt = false; // True for encrypt or False for decrypt
    
    // Todo A2: process the command line arguments
    for (int i = 1; i < argc; i++){
        // use strcmp to compare command line switches to argv[i]
        // .... your code goes here

        if (std::string(argv[i]) == "-p"){
            msg = argv[i + 1];
            msg_index = i + 1;
        }
        else if (std::string(argv[i]) == "-C"){
            msg = argv[i + 1];
            msg_index = i + 1;
        }
        else if (std::string(argv[i]) == "-k"){
            k = stoi(argv[i + 1]);
        }
        else if (std::string(argv[i]) == "-E"){
            do_encrypt = true;
        } 
        else if (std::string(argv[i]) == "-D"){
            do_encrypt = false;
        } 
    }
    
    if (do_encrypt){
        encrypt(msg,k);

        }
    else if (!do_encrypt) {
        decrypt(msg,k);
    }
    return 0;
}