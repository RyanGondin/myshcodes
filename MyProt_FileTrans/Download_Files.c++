#include <iostream>
#include <fstream>
#include <mysqlx/xdevapi.h>

using namespace std;
using namespace mysqlx;

int main() {
    // Connect to the database
    Session session("localhost", 3306, "username", "password", "database_name");
    
    // Execute a query to retrieve the file data
    RowResult result = session.sql("SELECT file_data FROM files WHERE file_name = 'example.txt'").execute();
    
    // Check if the query returned a row
    if (result.count() > 0) {
        // Get the file data from the first row
        Row row = result.fetchOne();
        Blob file_data = row.getBlob("file_data");
        
        // Write the file data to a file
        ofstream file("example.txt", ios::out | ios::binary);
        file.write(file_data.data(), file_data.length());
        file.close();
        
        cout << "File downloaded successfully!" << endl;
    } else {
        cout << "File not found!" << endl;
    }
    
    // Disconnect from the database
    session.close();
    
    return 0;
}