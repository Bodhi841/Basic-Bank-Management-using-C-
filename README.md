# Basic-Bank-ManagemeBank Management System (C++)
This is a simple Bank Management System implemented in C++. It provides functionality for user registration, login, and money management. The system includes features like signing up, logging in, depositing money, withdrawing money, and viewing transaction history. All user and transaction data are saved in files for persistence.

Features:
User Registration (Sign Up): Allows new users to create an account with a username, email, mobile number, and password. A unique account number is generated during registration.
User Login (Sign In): Users can log in using their username and password. If the credentials match, they are granted access to their account.
Money Management: Users can deposit and withdraw money, with the system keeping track of their current balance.
Transaction History: A history of all transactions (deposits and withdrawals) is maintained in a file, including the amount and the date/time of each transaction.
Account Persistence: All user details, including credentials and transaction history, are saved in text files, which ensures the data is persistent across multiple sessions.
How It Works:
Sign Up: New users are prompted to enter their details (username, email, mobile number, and password). A random account number is generated, and the details are saved in a file.
Sign In: Users can log in using their username and password. The system checks if the provided credentials match any user in the file.
Money Management: Users can deposit or withdraw money, and the system will update the balance accordingly. The transaction details are saved in a file for future reference.
Transaction History: Users can view all of their previous transactions, including deposits and withdrawals, along with timestamps.
Files Used:
user.txt: Stores user information such as username, password, email, mobile number, and account number.
transaction_history.txt: Keeps a log of all transactions (deposit and withdrawal) for each user.
Requirements:
A C++ compiler to compile and run the program.
The program uses basic file handling to save and read user and transaction data.nt-using-C-
