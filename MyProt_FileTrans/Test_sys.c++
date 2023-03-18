#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cassert>

using namespace std;

// Testcase:
// Create a file and transfer it to a different folder on the same system
// Results should be stored in a log file

// Function for file transfer
int transfer_file(string source_file, string dest_path) {
    string dest_file = dest_path + "/" + source_file;
    ifstream src(source_file, ios::binary);
    ofstream dest(dest_file, ios::binary);
    dest << src.rdbuf();
    src.close();
    dest.close();
    return 0;
}

int main() {
    // Timestamp for logging
    time_t now = time(0);
    tm* ltm = localtime(&now);

    // Create source and destination files
    string source_file = "test.txt";
    ofstream src(source_file, ios::out);
    src << "This is a test file." << endl;
    src.close();

    string dest_path = "dest_folder";
    int status = transfer_file(source_file, dest_path);
    assert(status == 0);

    // Log the transfer to a file
    string log_file = "log.txt";
    ofstream log(log_file, ios::app);
    log << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << " File transfer of '" << source_file << "' successful." << endl;
    log.close();

    return 0;
}