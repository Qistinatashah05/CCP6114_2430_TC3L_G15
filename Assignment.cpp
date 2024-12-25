// *********************************************************
// Program: YOUR_FILENAME.cpp
// Course: CCP6114 Programming Fundamentals
// Lecture Class: TC3L
// Tutorial Class: TT5L
// Trimester: 2430
// Member_1: ID | NAME | EMAIL | PHONE
// Member_2: ID | NAME | EMAIL | PHONE
// Member_3: ID | NAME | EMAIL | PHONE
// Member_4: ID | NAME | EMAIL | PHONE
//*********************************************************
// Task Distribution
// Member_1:
// Member_2:
// Member_3:
// Member_4:
// ********************************************************* #include <iostream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// I/O (iostream, fstream, etc.)
//Data structures (vector, map, etc.)
//Algorithms (sort, find, etc.)
//Math utilities (cmath)
//Strings (string)

//ifstream to read txt fiel, getline: reads one line ata  time , inputfile.close()
//ofstream opens file for writing

// Define a struct for rows with a string and an integer
// Define a structure to represent a customer
struct Customer {
    int id;
    string name;
    string city;
    string state;
    string country;
    string phone;
    string email;
};






void create_fileoutput()
{
    cout << ">CREATE fileOutput1.txt;"<< endl;
}

void database_fileInput(const string& pathfile)
{

    cout << ">DATABASES;" <<endl;
    cout << pathfile << endl;

}


void create_table(){

    cout << "> CREATE TABLE customer(" <<endl;
    cout << "customer_id INT," <<endl;
    cout << "customer_name TEXT," <<endl;
    cout << "customer_city TEXT," <<endl;
    cout << "customer_state TEXT," <<endl;
    cout << "customer_country TEXT," <<endl;
    cout << "customer_phone TEXT," <<endl;
    cout << "customer_email TEXT," <<endl;
}

void showTables() {
    cout << "> TABLES;" << endl;
    cout << "customer" << endl;
}



// Function to display all customers
void displayCustomers(const vector<Customer>& customers) {
    cout << "> SELECT * FROM customer;" << endl;
    cout << "customer_id,customer_name,customer_city,customer_state,customer_country,customer_phone,customer_email" << endl;
    for (const auto& customer : customers) {
        cout << customer.id << "," << customer.name << "," << customer.city << "," << customer.state << ","
             << customer.country << "," << customer.phone << "," << customer.email << endl;
    }
}




int main() {

    string filePath ="C:/CCP6114_2430_TC3L_G15/fileInput1.mdb";
    vector<Customer> customers;

    create_fileoutput();
    database_fileInput(filePath);
    create_table();

    // Insert records into the "table"
    customers.push_back({1, "Henry Cavill", "London", "England", "United Kingdom", "865-242-2444", "henry.cavill@example.com"});
    customers.push_back({2, "name2", "city2", "state2", "country2", "phone2", "email2"});
    customers.push_back({3, "name3", "city3", "state3", "country3", "phone3", "email3"});
    customers.push_back({4, "name4", "city4", "state4", "country4", "phone4", "email4"});

    // Display all records
    displayCustomers(customers);

    return 0;

}

vector <string> getVector(string filename)
{
    string value;
    vector<string> values;
    ifstream inputFile;
    inputFile.open(filename);
    if (inputFile.is_open() == true )
        while ( getline (inputFile, value))
    {
        //cout << value <<endl;
        values.push_back(value);
    }
    else
    {
        cout<< "Error message: Cannot open the file" << endl;
        exit(-1);

    }
    return values;

}
