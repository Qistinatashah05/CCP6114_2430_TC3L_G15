// *********************************************************
// Program: YOUR_FILENAME.cpp
// Course: CCP6114 Programming Fundamentals
// Lecture Class: TC3L
// Tutorial Class: TT5L
// Trimester: 2430
// Member_1: 242UC244G9 | Nur Qistina Atashah Binti Jasmin  | NUR.QISTINA.ATASHAH@student.mmu.edu.my | 012-613-5680
// Member_2: 242UC24570  | Ayden Bin Wira | AYDEN.WIRA@student.mmu.edu.my | 010-862-1185
// Member_3: 242UC24571  | Dania Aeisha Binti Jamal Hafiz | EMAIL | 017-885-5074
// Member_4: ID | NAME | EMAIL | PHONE
//*********************************************************
// Task Distribution
// Member_1:view table in csv mode,create base
// Member_2:Create database and view database,Create table
// Member_3:Insert rows to the table,
// Member_4:
// ********************************************************* #include <iostream>

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Table {
    vector<string> columns;
    vector<vector<string>> rows;
};

// Declare the database map globally
map<string, Table> database;

void create_fileoutput() {
    cout << ">CREATE fileOutput1.txt;" << endl;
}

void database_fileInput(const string& pathfile) {
    cout << ">DATABASES;" << endl;
    cout << pathfile << endl;
}

void create_table() {
    cout << "> CREATE TABLE customer(" << endl;
    cout << "customer_id INT," << endl;
    cout << "customer_name TEXT," << endl;
    cout << "customer_city TEXT," << endl;
    cout << "customer_state TEXT," << endl;
    cout << "customer_country TEXT," << endl;
    cout << "customer_phone TEXT," << endl;
    cout << "customer_email TEXT" << endl;
    cout << ");" << endl;

    Table customerTable;
    customerTable.columns = {"customer_id", "customer_name", "customer_city", "customer_state",
                             "customer_country", "customer_phone", "customer_email"};
    database["customer"] = customerTable;
}

void insertRow(int id, string name, string city, string state, string country, string phone, string email) {
    if (database.find("customer") == database.end()) {
        cout << "Error: Table 'customer' does not exist.\n";
        return;
    }

    cout << "> TABLES;" << endl;
    cout << "customer" << endl;
    vector<string> row = {to_string(id), name, city, state, country, phone, email};
    database["customer"].rows.push_back(row);
    cout << ">INSERT INTO customer"<< "(customer_id,customer_name,customer_city,customer_state,customer_country,customer_phone,customer_email) VALUES (" << id << ", '" << name << "', '" << city << "', '"

         << state << "', '" << country << "', '" << phone << "', '" << email << "'));\n";
}

void selectFromTable() {
    if (database.find("customer") == database.end()) {
        cout << "Error: Table 'customer' does not exist.\n";
        return;
    }

    cout << "> SELECT * FROM customer;\n";
    cout << "customer_id,customer_name,customer_city,customer_state,customer_country,customer_phone,customer_email" << endl;

    // Access the "customer" table
    Table& table = database["customer"];

    for (const vector<string>& row : table.rows) {
        for (size_t i = 0; i < row.size(); ++i) {
            cout << row[i];
            if (i < row.size() - 1) {
                cout << ",";
            }
        }
        cout << endl;
    }
}

int main() {
    string filePath = "C:/CCP6114_2430_TC3L_G15/fileInput1.mdb";

    create_fileoutput();
    database_fileInput(filePath);
    create_table();

    insertRow(1, "Lucas Scott", "New York", "New York", "USA", "123-456-7890", "lucas.scott@example.com");
    insertRow(2, "Sarah Smith", "Los Angeles", "California", "USA", "987-654-3210", "sarah.smith@example.com");
    insertRow(3, "Michael Keaton", "Chicago", "Illinois", "USA", "555-123-4567", "michael.keaton@example.com");
    insertRow(4, "Brooke Davis", "San Francisco", "California", "USA", "333-444-5555", "brooke.davis@example.com");

    selectFromTable();

    return 0;
}