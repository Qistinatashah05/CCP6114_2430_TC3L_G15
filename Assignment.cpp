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
struct Customer {
    int customer_id;  // Integer for the id
    string customer_name;     // TExt for the name
    string customer_city;
    string customer_state;
    string customer_country;
    string customer_phone;
    string customer_email;
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

    cout << "CREATE TABLE customer(" <<endl;
}






int main() {

    string filePath1 ="C:\CCP6114_2430_TC3L_G15\fileInput1.mdb";

    create_fileoutput();
    database_fileInput(filePath1);
    create_table();


    cout << "Press Enter to continue to the next file...";
    cin.get(); // Wait for user input

    string filePath2 ="C:\CCP6114_2430_TC3L_G15\fileInput2.mdb";

    create_fileoutput();
    database_fileInput(filePath2);
    create_table();

    cout << "Press Enter to continue to the next file...";
    cin.get(); // Wait for user input

    string filePath3 ="C:\CCP6114_2430_TC3L_G15\fileInput3.mdb";

    create_fileoutput();
    database_fileInput(filePath3);
    create_table();

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
