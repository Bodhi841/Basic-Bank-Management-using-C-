#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

class UserEntry
{
public:
    void entry()
    {
        int entryNumber;

        cout << "\n========= WELCOME TO THE BANK =========" << endl;
        cout << "\n1 for sign in\n2 for sign up" << endl;
        cout << "\n=========================================" << endl;
        cout << "Enter Number: ";
        cin >> entryNumber;
        cout << "===========================================" << endl;

        if (entryNumber == 1)
        {
            string filename = "transaction.txt"; // File to search
            string userName;
            string password;
            cout << "\nEnter the username : ";
            cin >> userName;
            cout << "Enter Password : ";
            cin >> password;
            signIn(filename, userName, password);
        }
        else
        {
            signUp("user.txt");
        }
    }

    void signIn(const string &filename, const string &userName, const string &password)
    {
        ifstream file(filename); // Open the file for reading
        if (!file.is_open())
        {
            cout << "Unable to open the file." << endl;
            return;
        }

        string line;
        bool found = false;

        // Read the file line by line
        while (getline(file, line))
        {
            // Check if the search term exists in the current line
            if (line.find(userName) != string::npos && line.find(password) != string::npos)
            {
                cout << "\n===========================================\nWelcome Back " << userName << "\n===========================================" << endl; // Print the line containing the search term
                found = true;
            }
        }

        if (!found)
        {
            cout << "\n===========================================" << endl;
            cout << "User not found \nPlease sign up" << endl;
        }

        file.close(); // Close the file after reading
    }

    void signUp(const string &filename)
    {
        ofstream file(filename, ios::app); // Open in append mode
        if (!file.is_open())
        {
            cout << "Unable to open the file." << endl;
            return;
        }

        string username;
        string email;
        string mobNo;
        string password;

        cout << "\nPlease Enter Your Details" << endl;

        // Get username and email
        cout << "Enter Username: ";
        cin >> username;

        cout << "Enter Email: ";
        cin >> email;

        // Mobile number validation
        cout << "Enter Mobile Number (10 digits): ";
        cin >> mobNo;

        while (mobNo.length() != 10)
        {
            cout << "Invalid mobile number! Please enter a valid 10-digit number: ";
            cin >> mobNo;
            // cout << "\n======================================" << endl;
        }

        cout << "======================================" << endl;
        cout << "Welcome to the Bank, " << username << endl;
        cout << "======================================" << endl;

        // Display and confirm user details
        cout << "\nPlease Check Your Details:\n";
        cout << "Username: " << username << endl;
        cout << "Email: " << email << endl;
        cout << "Mobile Number: " << mobNo << endl;

        string response;
        cout << "\nDo you want to revise something? (Y/N): ";
        cin >> response;

        if (response == "Y" || response == "y")
        {
            signUp(filename); // Call again for revision
            return;           // Exit the current function to allow revision
        }

        // Generate random account number using current time as seed
        srand(static_cast<unsigned>(time(0)));
        int accNo = rand();

        cout << "\n======================================" << endl;
        cout << "Your Account Number is: " << accNo << endl;

        // Password input
        cout << "Please enter a strong password: ";
        cin >> password;
        cout << "======================================" << endl;

        // Write the user details to the file
        file << username << " " << password << " " << email << " " << mobNo << " " << accNo << endl;

        cout << "Details have been successfully saved!" << endl;

        file.close(); // Close the file
    }
};

class MoneyManagement
{
public:
    int balance = 0; // Balance to track the current money

    void userChoice()
    {
        int enterNO;
        cout << "\n\n1. Deposit Money\n2. WithDraw Money\n3. Transction History\n4. Exit\n\n==========================================\nEnter Number: ";
        cin >> enterNO;
        cout << "==========================================" << endl;

        if (enterNO == 1)
        {
            deposit();
        }
        else if (enterNO == 2)
        {
            withDraw();
        }
        else if (enterNO == 3)
        {
            showTransactionHistory();
        }
        else if (enterNO == 4)
        {
            cout << "Thank you for using the bank system." << endl;
            cout << "==========================================" << endl;
            exit(0);
        }

        else
        {
            cout << "Invalid option. Try again!" << endl;
            userChoice();
        }
    }

    void deposit()
    {
        int amount; // Local variable for deposit input
        cout << "\nHow much money do you want to deposit: ";
        cin >> amount;

        balance += amount;                 // Add to balance
        logTransaction("Deposit", amount); // Log transaction

        cout << "Deposited: " << amount << ". Current balance: " << balance << endl;
        cout << "\n=====================================================" << endl;
        userChoice();
    }

    void withDraw()
    {
        int amount; // Local variable for withdrawal input
        cout << "\nHow much money do you want to withdraw: ";
        cin >> amount;

        if (amount <= balance)
        {
            balance -= amount;                  // Deduct from balance
            logTransaction("Withdraw", amount); // Log transaction
            cout << "Withdrew: " << amount << ". Remaining balance: " << balance << endl;
            cout << "\n=====================================================" << endl;
        }
        else
        {
            cout << "You don't have enough money in your account." << endl;
            cout << "\n=====================================================" << endl;
        }
        userChoice();
    }

    void logTransaction(const string &type, int amount)
    {
        ofstream file("transaction_history.txt", ios::app); // Open in append mode
        if (file.is_open())
        {
            time_t now = time(0);
            char *dt = ctime(&now); // Get current time

            file << type << " of " << amount << " on " << dt; // Write to file
            file.close();
        }
        else
        {
            cout << "Unable to open the transaction history file." << endl;
        }
    }

    void showTransactionHistory()
    {
        ifstream file("transaction_history.txt"); // Open the file for reading
        if (file.is_open())
        {
            string line;
            cout << "\nTransaction History:" << endl;
            while (getline(file, line))
            { // Read file line by line
                cout << line << endl;
            }
            cout << "\n=====================================================" << endl;
            file.close();
        }
        else
        {
            cout << "No transaction history found." << endl;
        }
        userChoice();
    }
};

int main()
{
    UserEntry uEntry;
    uEntry.entry();

    MoneyManagement mm;
    mm.userChoice();

    return 0;
}