#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
using namespace std;


struct Customer {
    int customer_id;
    string customer_name;
    string customer_city;
    string customer_state;
    string customer_country;
    string customer_phone;
    string customer_email;
};

struct Table {
    vector<string> columns;
    vector<vector<string>> rows;

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

    vector<string> row = {to_string(id), name, city, state, country, phone, email};
    database["customer"].rows.push_back(row);
    cout << ">INSERT INTO customer(VALUES (" << id << ", '" << name << "', '" << city << "', '"
         << state << "', '" << country << "', '" << phone << "', '" << email << "'));\n";
}

void selectFromTable() {
    if (database.find("customer") == database.end()) {
        cout << "Error: Table 'customer' does not exist.\n";
        return;
    }

    cout << "> SELECT * FROM customer;\n";

    Table& table = database["customer"];


    for (const string& column : table.columns) {
        cout << setw(15) << column;
    }
    cout << endl;


    for (const vector<string>& row : table.rows) {
        for (const string& value : row) {
            cout << setw(15) << value;
        }
        cout << endl;
    }
}


int main() {
    string filePath = "C:/CCP6114_2430_TC3L_G15/fileInput1.mdb";

    create_fileoutput();
    database_fileInput(filePath);
    create_table();


    insertRow(1, "LucasScott", "NewYork", "NewYork", "USA", "123-456-7890", "lucas.scott@example.com");
    insertRow(2, "SarahSmith", "LosAngeles", "California", "USA", "987-654-3210", "sarah.smith@example.com");
    insertRow(3, "MichaelKeaton", "Chicago", "Illinois", "USA", "555-123-4567", "michael.keaton@example.com");
    insertRow(4, "BrookeDavis", "SanFrancisco", "California", "USA", "333-444-5555", "brooke.davis@example.com");

    selectFromTable();

    return 0;


}
