#include <iostream>
#include <mysqlx/xdevapi.h>

using namespace std;
using namespace mysqlx;

int main() {
    // Connect to the database
    Session session("localhost", 3306, "username", "password", "database_name");

    // Execute a query to retrieve the available files
    RowResult result = session.sql("SELECT file_name FROM files").execute();

    // Iterate through the result set and print the file names
    for (Row row : result.fetchAll()) {
        string file_name = row.get<string>("file_name");
        cout << file_name << endl;
    }

    // Disconnect from the database
    session.close();

    return 0;
}