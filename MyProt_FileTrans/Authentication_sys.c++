#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int AutenticationManager() {

    string username;
    string password;
    string email;
    int failed_attempts;
    const int MAX_ATTEMPTS = 5;

    // User registration
    cout << "Please enter a username: ";
    cin >> username;

    cout << "Please enter a password: ";
    cin >> password;

    cout << "Please enter an email address: ";
    cin >> email;

    // Password requirements
    if (password.length() < 8) {
        cout << "Error: Password must be at least 8 characters long." << endl;
        return 1;
    }

    vector<char> valid_chars = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                                'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                                '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '!', '@', '#', '$', '%', '^', '&', '*'};

    if (find_if(password.begin(), password.end(), [&](char c) { return find(valid_chars.begin(), valid_chars.end(), c) == valid_chars.end(); }) != password.end()) {
        cout << "Error: Password must contain at least one of the following characters: a-z, A-Z, 0-9, !@#$%^&*" << endl;
        return 1;
    }

    // Two-factor authentication
    cout << "Please enter a one-time password: ";
    string one_time_password;
    cin >> one_time_password;

    // Password reset
    cout << "If you forget your password, you can reset it through your registered email address.\n";

    // Login attempts
    failed_attempts = 0;
    while (failed_attempts < MAX_ATTEMPTS) {
        cout << "Please enter your username and password: ";
        string input_username, input_password;
        cin >> input_username >> input_password;
        if (input_username == username && input_password == password) {
            cout << "Login successful!\n";
            break;
        } else {
            failed_attempts++;
            cout << "Incorrect username or password!\n";
        }
    }

    if (failed_attempts >= MAX_ATTEMPTS) {
        cout << "Too many failed attempts. Your account has been locked.\n";
    }

    return 0;
}