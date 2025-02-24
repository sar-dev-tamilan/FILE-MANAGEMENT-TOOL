#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void writeToFile(const string& filename) {
    ofstream file(filename, ios::out);
    if (!file) {
        cout << "Error opening file for writing!" << endl;
        return;
    }
    string data;
    cout << "Enter data to write to file: ";
    cin.ignore();
    getline(cin, data);
    file << data << endl;
    file.close();
    cout << "Data written successfully!" << endl;
}

void appendToFile(const string& filename) {
    ofstream file(filename, ios::app);
    if (!file) {
        cout << "Error opening file for appending!" << endl;
        return;
    }
    string data;
    cout << "Enter data to append to file: ";
    cin.ignore();
    getline(cin, data);
    file << data << endl;
    file.close();
    cout << "Data appended successfully!" << endl;
}

void readFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error opening file for reading!" << endl;
        return;
    }
    string data;
    cout << "File contents:" << endl;
    while (getline(file, data)) {
        cout << data << endl;
    }
    file.close();
}

int main() {
    string filename = "filedata.txt";
    int choice;
    
    do {
        cout << "\nFile Management Tool" << endl;
        cout << "1. Write to File" << endl;
        cout << "2. Append to File" << endl;
        cout << "3. Read from File" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                writeToFile(filename);
                break;
            case 2:
                appendToFile(filename);
                break;
            case 3:
                readFromFile(filename);
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);
    
    return 0;
}