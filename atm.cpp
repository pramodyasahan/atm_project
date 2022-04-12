#include <conio.h>
#include <iostream>
#include <string>
using namespace std;

class atm
{
private:
    long int account_no;
    string name;
    int PIN;
    double balance;
    string mobile_no;

public:
    void setData(long int account_no_a, string name_a, int PIN_a, double balance_a, string mobile_no_a)
    {
        account_no = account_no_a;
        name = name_a;
        PIN = PIN_a;
        balance = balance_a;
        mobile_no = mobile_no_a;
    }

    long int getAccountNo()
    {
        return account_no;
    }

    string getName()
    {
        return name;
    }

    int getPIN()
    {
        return PIN;
    }

    double getBalance()
    {
        return balance;
    }

    string getMobileNo()
    {
        return mobile_no;
    }

    void setMobile(string mob_prev, string mob_new)
    {
        if (mob_prev == mobile_no)
        {
            mobile_no = mob_new;
            cout << endl
                 << "Sucessfully Updated Mobile no.";
            _getch();
        }
        else // Does not update if old mobile no. does not matches
        {
            cout << endl
                 << "Incorrect !!! Old Mobile no";
            _getch(); // getch is to hold the screen ( untill user press any key )
        }
    }

    int cashWithdraw(int amount_a)
    {
        if (amount_a > 0 && balance > amount_a)
        {
            balance -= amount_a;
            cout << endl
                 << "Please Collect Your Cash";
            cout << endl
                 << "Available Balance :" << balance;
            _getch();
        }
        else
        {
            cout << endl
                 << "Invalid Input or Insufficient Balance";
            _getch();
        }
    }
};


int main(void)
{
    int choice = 0, enterPIN;
    long int enterAccountNo;

    system("cls");
    atm user1;
    user1.setData(12345678, "Pramodya", 4453, 100000.0, "0711780838");

    do
    {
        system("cls");

        cout << endl
             << "****Welcome to ATM*****" << endl;
        cout << endl
             << "Enter Your Account No ";
        cin >> enterAccountNo;

        cout << endl
             << "Enter PIN ";
        cin >> enterPIN;

        if ((enterAccountNo == user1.getAccountNo()) && (enterPIN == user1.getPIN()))
        {
            do
            {
                int amount = 0;
                string oldMobileNo, newMobileNo;

                system("cls");
                // user Interface
                cout << endl
                     << "***** Welcome to ATM *****" << endl;
                cout << endl
                     << "Select Options ";
                cout << endl
                     << "1. Check Balance";
                cout << endl
                     << "2. Cash withdraw";
                cout << endl
                     << "3. Show User Details";
                cout << endl
                     << "4. Update Mobile no.";
                cout << endl
                     << "5. Exit" << endl;
                cin >> choice;

                switch (choice)
                {
                    case 1:
                        cout << endl;
                        cout << "Your account balance is: " << user1.getBalance();
                        _getch();
                        break;
                    
                    case 2:
                        cout << endl;
                        cout << "Enter the amount: ";
                        cin >> amount;
                        user1.cashWithdraw(amount);
                        _getch();
                        break;

                    case 3:
                        cout << endl
                             << "**Account details**\n\n";
                        cout << "-->Acount Number: "
                             << user1.getAccountNo() << endl;
                        cout << "-->Name         : "
                             << user1.getName() << endl;
                        cout << "-->Balance      : "
                             << user1.getBalance() << endl;
                        cout << "-->Mobile number: "
                             << user1.getMobileNo() << endl;
                        _getch();
                        break;

                    case 4:
                        cout << endl;
                        cout << "Enter old mobile no: ";
                        cin >> oldMobileNo;
                        cout << "Enter new mobile no: ";
                        cin >> newMobileNo;

                        user1.setMobile(oldMobileNo, newMobileNo);
                        break;

                    case 5:
                        exit(0);

                    default:
                        cout << endl
                             << "Enter Valid Data !!!";
                }
            } while (1);
        }
        else
        {
            cout << endl
                 << "User Details are Invalid !!! ";
            _getch();
        }

    } while (1);
    return 0;
}
