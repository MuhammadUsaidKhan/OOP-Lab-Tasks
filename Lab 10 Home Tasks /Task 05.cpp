#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void createInitialFile() {
    ofstream outFile("data.txt");
    if (outFile) {
        outFile << "AI is the future. AI will transform the world. Embrace AI now.";
        outFile.close();
        cout << "Created data.txt with initial content.\n";
    } else {
        cerr << "Error creating data.txt\n";
    }
}

void replaceWordsInFile(const string& searchWord, const string& replacementWord) {
    if (searchWord.empty()) {
        cerr << "Error: Search word cannot be empty.\n";
        return;
    }

    if (searchWord.length() < replacementWord.length()) {
        cerr << "Error: Replacement word is longer than search word.\n";
        return;
    }
    ifstream inFile("data.txt");
    if (!inFile) {
        cerr << "Error opening file for reading.\n";
        return;
    }

    string content;
    char ch;
    while (inFile.get(ch)) {
        content += ch;
    }
    inFile.close();

    bool changesMade = false;
    size_t pos = 0;

    while ((pos = content.find(searchWord, pos)) != string::npos) {
        content.replace(pos, searchWord.length(), replacementWord);
        
        // Pad with spaces if needed
        if (replacementWord.length() < searchWord.length()) {
            content.insert(pos + replacementWord.length(), 
                          searchWord.length() - replacementWord.length(), ' ');
        }
        
        pos += replacementWord.length();
        changesMade = true;
    }

    if (changesMade) {
        ofstream outFile("data.txt");
        if (outFile) {
            outFile << content;
            outFile.close();
            cout << "Replacements completed successfully.\n";
        } else {
            cerr << "Error opening file for writing.\n";
        }
    } else {
        cout << "No occurrences found.\n";
    }
}

void displayFileContent() {
    ifstream inFile("data.txt");
    if (inFile) {
        cout << "\nUpdated file content:\n";
        string line;
        while (getline(inFile, line)) {
            cout << line << '\n';
        }
        inFile.close();
    } else {
        cerr << "Error reading file.\n";
    }
}

int main() {
    createInitialFile();
    
    string searchWord, replacementWord;
    
    cout << "\nEnter word to search: ";
    getline(cin, searchWord);
    cout << "Enter replacement word: ";
    getline(cin, replacementWord);
    
    replaceWordsInFile(searchWord, replacementWord);
    displayFileContent();
    
    return 0;
}
