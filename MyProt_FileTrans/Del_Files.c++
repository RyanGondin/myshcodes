#include <iostream>
#include <mysqlx/xdevapi.h>

using namespace std;
using namespace mysqlx;

int main() {
    // Connect to the database
    Session session("localhost", 3306, "username", "password", "database_name");

    // Execute a DELETE query to remove the file from the database
    session.sql("DELETE FROM files WHERE file_name = 'example.txt'").execute();

    // Check if any rows were affected by the query
    if (session.getAffectedRows() > 0) {
        cout << "File deleted successfully!" << endl;
    } else {
        cout << "File not found!" << endl;
    }

    // Disconnect from the database
    session.close();

    return 0;
}