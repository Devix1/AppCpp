#include <windows.h>
#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>

using namespace std;

string formatWithDots(int number)
{
    string numStr = to_string(number);
    int insertPosition = numStr.length() - 3;
    while (insertPosition > 0)
    {
        numStr.insert(insertPosition, ".");
        insertPosition -= 3;
    }
    return numStr;
}

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    setlocale(LC_ALL, "RU");

    int pin = 0;
    int Attempts = 3;
    int AttemptsWitgdraw = 3;
    int AttemptsBalance = 3;
    int balance = 1000;
    int withdraw;
    int pickUser;
    int topUp;
    int pinUser = pin;

    cout << "Welcome ATM goodBank!" << endl;

    while (true)
    {
        cout << "Create PIN code!" << endl;
        cin >> pin;
        cout << endl;
        if (pin >= 1000 && pin <= 9999)
        {
            break;
        }
        else
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout << "The pin code must consist of 4 digits" << endl;
            SetConsoleTextAttribute(hConsole, 7);
        }
    }

    while (true)
    {
        SetConsoleTextAttribute(hConsole, 2);
        cout << "Enter your pin code" << endl;
        SetConsoleTextAttribute(hConsole, 7);
        cin >> pinUser;
        cout << endl;
        if (pinUser == pin)
        {
            break;
        }
        else
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout << "PIN code is incorrect" << endl;
            SetConsoleTextAttribute(hConsole, 7);
            Attempts--;
            SetConsoleTextAttribute(hConsole, 14);
            cout << "Attemrts: " << Attempts << endl;
            SetConsoleTextAttribute(hConsole, 7);
            if (Attempts == 0)
            {
                return -1;
            }
        }
    }

    while (true)
    {
        cout << "Choose an action" << endl;
        cout << "1 - View balance" << endl;
        cout << "2 - Withdraw money" << endl;
        cout << "3 - Top up your account" << endl;
        cout << "4 - Exit ATM" << endl;
        cout << endl;
        cin >> pickUser;
        cout << endl;

        
        
        
        
        if (pickUser == 1)
        {
            cout << "Please enter your pin code" << endl;
            cin >> pinUser;
            if (pin == pinUser)
            {
                cout << endl;
                SetConsoleTextAttribute(hConsole, 2);
                cout << "Balance: " << balance << "$" << endl;
                SetConsoleTextAttribute(hConsole, 7);
                cout << endl;
            }
            else
            {
                cout << endl;
                SetConsoleTextAttribute(hConsole, 12);
                cout << "PIN code is incorrect" << endl;
                SetConsoleTextAttribute(hConsole, 7);
                AttemptsBalance--;
                SetConsoleTextAttribute(hConsole, 14);
                cout << "Attemrts: " << AttemptsBalance << endl;
                SetConsoleTextAttribute(hConsole, 7);
                if (AttemptsBalance == 0)
                {
                    SetConsoleTextAttribute(hConsole, 12);
                    cout << "Card is blocked." << endl;
                    SetConsoleTextAttribute(hConsole, 7);
                    break;
                }
            }
        }


        else if(pickUser == 2){
            cout << "Please enter your pin code" << endl;
            cin >> pinUser;
            cout << endl;
              if (pin == pinUser)
            {
                cout << "Enter the amount to withdraw"<< endl;
                cin >> withdraw;
                cout << endl;
                if (withdraw > balance){
                    SetConsoleTextAttribute(hConsole, 12);
                    cout << "Insufficient funds on the card" << endl;
                    SetConsoleTextAttribute(hConsole, 7);
                    cout << endl;
                }else{
                    balance -= withdraw;
                }
            }else{

                cout << endl;
                SetConsoleTextAttribute(hConsole, 12);
                cout << "PIN code is incorrect" << endl;
                SetConsoleTextAttribute(hConsole, 7);
                AttemptsWitgdraw--;
                SetConsoleTextAttribute(hConsole, 14);
                cout << "Attemrts: " << AttemptsWitgdraw << endl;
                SetConsoleTextAttribute(hConsole, 7);
                cout << endl;
                if (AttemptsWitgdraw == 0)
                {
                    SetConsoleTextAttribute(hConsole, 12);
                    cout << "Card is blocked." << endl;
                    SetConsoleTextAttribute(hConsole, 7);
                    break;
                }

            }
        }

        else if(pickUser == 3){
          cout << "Enter the replenishment amount up to $100,000" << endl;
          cin >> topUp;
          if (topUp <= 0 || topUp > 100000){
            SetConsoleTextAttribute(hConsole, 12);
            cout << "Error" << endl;
            SetConsoleTextAttribute(hConsole, 7);
            cout << endl;
          }else {
            balance += topUp;
            SetConsoleTextAttribute(hConsole, 2);
            cout << "Succes!"<< endl; 
            SetConsoleTextAttribute(hConsole, 7);
            cout << endl;
          }
        }


        else if (pickUser == 4){
            cout << "GoodBye!"<<endl;
            break;
        }

        
    }
    system("pause");
    return -1;
}

// cout << "Enter an amount up to $100,000"<<endl;
//           cin >> topUp;
