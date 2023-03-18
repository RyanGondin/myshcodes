#include <iostream>
#include <fstream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <mysql_error.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

using namespace std;
using namespace sql;

int main() {
    string filename;
    cout << "Enter filename: ";
    cin >> filename;

    ifstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "Error: Failed to open file" << endl;
        return 1;
    }

    // Read file contents into a string
    string data((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    // Connect to database
    Driver *driver;
    Connection *con;
    Statement *stmt;
    PreparedStatement *prep_stmt;
    ResultSet *res;

    driver = get_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "username", "password");
    con->setSchema("databasename");

    // Insert file data into database
    prep_stmt = con->prepareStatement("INSERT INTO files (filename, data) VALUES (?, ?)");
    prep_stmt->setString(1, filename);
    prep_stmt->setBlob(2, data.c_str(), data.size());
    prep_stmt->executeUpdate();

    // Close database connection
    delete prep_stmt;
    delete res;
    delete stmt;
    delete con;

    cout << "File uploaded successfully" << endl;
    return 0;
}