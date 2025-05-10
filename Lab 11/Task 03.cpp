#include <iostream>
#include <exception>
#include <string>
#include <fstream>
using namespace std;

class FileException : public exception {
protected:
    string filename;
    string message;
    
public:
    FileException(const string& fname, const string& msg) 
        : filename(fname), message(msg) {}
        
    const char* what() const noexcept override {
        static string fullMsg = "FileException - " + filename + ": " + message;
        return fullMsg.c_str();
    }
};
class FileNotFoundException : public FileException {
public:
    FileNotFoundException(const string& fname) 
        : FileException(fname, "File not found!") {}
};
class PermissionDeniedException : public FileException {
public:
    PermissionDeniedException(const string& fname) 
        : FileException(fname, "Access denied!") {}
};

void readFile(const string& filename) {
    ifstream file(filename);
    
    if (!file) {
        ifstream test(filename);
        if (!test) {
            throw FileNotFoundException(filename);
        }
        throw PermissionDeniedException(filename);
    }
    
    string line;
    cout << "File contents:" << endl;
    while (getline(file, line)) {
        cout << line << endl;
    }
    
    file.close();
}

int main() {
    string filename;
    cout << "Enter filename to read: ";
    cin >> filename;
    
    try {
        readFile(filename);
    } 
    catch (const PermissionDeniedException& e) {
        cerr << "Error: " << e.what() << endl;
    }
    catch (const FileNotFoundException& e) {
        cerr << "Error: " << e.what() << endl;
    }
    catch (const FileException& e) {
        cerr << "Generic file error: " << e.what() << endl;
    }
    catch (...) {
        cerr << "An unknown error occurred" << endl;
    }
    
    return 0;
}
