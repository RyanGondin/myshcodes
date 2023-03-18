#include <iostream>

using namespace std;

int main() {
    int choice;
    
    do {
        cout << "+----------------------------------------------------+" << endl;
        cout << "|                 File Transfer Application          |" << endl;
        cout << "+----------------------------------------------------+" << endl;
        cout << "| Please select an option:                           |" << endl;
        cout << "| 1. Upload file                                     |" << endl;
        cout << "| 2. Download file                                   |" << endl;
        cout << "| 3. List available files                            |" << endl;
        cout << "| 4. Delete file                                     |" << endl;
        cout << "| 5. Exit                                            |" << endl;
        cout << "+----------------------------------------------------+" << endl;
        cout << "Enter your choice: ";
        
        cin >> choice;
        
        switch (choice) {
            case 1:
                // code to upload file
                cout << "You selected option 1: Upload file" << endl;
                break;
            case 2:
                // code to download file
                cout << "You selected option 2: Download file" << endl;
                break;
            case 3:
                // code to list available files
                cout << "You selected option 3: List available files" << endl;
                break;
            case 4:
                // code to delete file
                cout << "You selected option 4: Delete file" << endl;
                break;
            case 5:
                cout << "Exiting application..." << endl;
                break;
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
                break;
        }
        
        cout << endl;
        
    } while (choice != 5);
    
    return 0;
}