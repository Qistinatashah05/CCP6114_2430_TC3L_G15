#include<fstream>
#include<iostream>
#include<iomanip>
#include<string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

//Ayden Wira

struct Employee{
    int employee_id;
    string employee_name;
    int employee_age;
    float employee_income;
    string employee_office;
    string employee_phone;
    string employee_email;
};

void create_fileoutput()
{
    cout <<">CREATE fileOutput3.txt"<< endl;
}

void database_fileInput(const string & pathfile)
{
    cout << ">DATABASES;" << endl;
    cout << pathfile << endl;
}

void create_table(){
    cout << "CREATE TABLE Employee(" << endl;

}

int main() {

    string filePath ="C:\HUGE IT\CCP6114_2430_TC3L_G15\fileInput3.mdb";

    create_fileoutput();
    database_fileInput(filePath);
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
    return values;

}
