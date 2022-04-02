/*
    Operating System: MacOS (Big Sur v11.6)
    Compiler Toolchain: G++
    IDE: Visual Studio Code
    
    Name: XXXXXXXXX
    SSID: XXXXXXXXX
    Assignment #: 1
    Submission Date: 3/3/22


    Program Description:
      This program totals deposits and withdrawls
      transations from an opening balance
*/

#include <iostream>
using namespace std;
int main()
{
    double InitialBalance, CurrentBalance = 0.00, DepositWithdrawl;
    cout << "Enter in a nonzero balance: " ;
    cin >> InitialBalance;
    cout << "Enter transactions (+ deposit or - withdrawl), use 0 to end list: " << endl;
    cin >> DepositWithdrawl;
 
    CurrentBalance = CurrentBalance + DepositWithdrawl; 
    while (DepositWithdrawl != 0 ){
        cin >> DepositWithdrawl;
        CurrentBalance = CurrentBalance + DepositWithdrawl;
        if (DepositWithdrawl == 0){
            CurrentBalance = CurrentBalance + InitialBalance;
            cout << "Your current balance is  " << CurrentBalance;
    
        }
    }
    cout << "\nEnter any alphanumeric key to exit:  " << endl;
    system("read");
}