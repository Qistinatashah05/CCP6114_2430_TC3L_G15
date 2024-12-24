#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>

// Structure to represent a table
struct Customer {
    int customer_id;  // Integer for the id
    string customer_name;     // TExt for the name
    string customer_city;
    string customer_state;
    string customer_country;
    string customer_phone;
    string customer_email;

// Global database storage
map<string, Table> database;

// Function to create a table
void createTable(const std::string& name, const std::vector<std::string>& columns) {
    Table newTable;
    newTable.columns = columns;
    database[name] = newTable;
    std::cout << "> TABLE '" << name << "' created successfully.\n";
}

// Function to insert data into a table
void insertIntoTable(const std::string& name, const std::vector<std::string>& values) {
    if (database.find(name) == database.end()) {
        std::cerr << "Error: Table '" << name << "' does not exist.\n";
        return;
    }
    database[name].rows.push_back(values);
}

// Function to display table data
void selectFromTable(const std::string& name) {
    if (database.find(name) == database.end()) {
        std::cerr << "Error: Table '" << name << "' does not exist.\n";
        return;
    }

    const Table& table = database[name];
    std::cout << "> SELECT * FROM " << name << ":\n";

    // Print column headers
    for (const auto& column : table.columns) {
        std::cout << std::setw(15) << column << " ";
    }
    std::cout << "\n";

    // Print rows
    for (const auto& row : table.rows) {
        for (const auto& value : row) {
            std::cout << std::setw(15) << value << " ";
        }
        std::cout << "\n";
    }
}

// Main interpreter function
void interpretCommand(const std::string& command) {
    std::istringstream iss(command);
    std::string action;
    iss >> action;

    if (action == "CREATE") {
        std::string subAction, tableName, columnsDef;
        iss >> subAction >> tableName;
        std::getline(iss, columnsDef, '(');
        std::getline(iss, columnsDef, ')');

        std::istringstream colStream(columnsDef);
        std::vector<std::string> columns;
        std::string column;

        while (std::getline(colStream, column, ',')) {
            column = column.substr(0, column.find(" ")); // Remove column type
            columns.push_back(column);
        }

        createTable(tableName, columns);
    } else if (action == "INSERT") {
        std::string subAction, tableName, valuesDef;
        iss >> subAction >> tableName;
        std::getline(iss, valuesDef, '(');
        std::getline(iss, valuesDef, ')');

        std::istringstream valStream(valuesDef);
        std::vector<std::string> values;
        std::string value;

        while (std::getline(valStream, value, ',')) {
            values.push_back(value);
        }

        insertIntoTable(tableName, values);
    } else if (action == "SELECT") {
        std::string subAction, tableName;
        iss >> subAction >> subAction >> tableName; // Read "FROM table_name"
        selectFromTable(tableName);
    } else {
        std::cerr << "Error: Unrecognized command '" << command << "'.\n";
    }
}

// File interpreter function
void interpretFile(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream inFile(inputFile);
    std::ofstream outFile(outputFile);

    if (!inFile || !outFile) {
        std::cerr << "Error: Unable to open input or output file.\n";
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        if (!line.empty()) {
            std::cout << "> " << line << "\n";
            interpretCommand(line);
        }
    }

    outFile << "Processed " << inputFile << " -> " << outputFile << ".\n";
    std::cout << "Processed " << inputFile << " -> " << outputFile << ".\n";
}

int main() {
    // File paths
    std::string inputFile = "fileInput1.mdb";  // Input file with commands
    std::string outputFile = "fileOutput1.txt"; // Output file for results

    interpretFile(inputFile, outputFile);

    std::cout << "Press Enter to continue to the next file...";
    std::cin.get(); // Wait for user input
    return 0;
}
