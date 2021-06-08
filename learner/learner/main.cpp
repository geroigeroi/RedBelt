//
//  main.cpp
//  learner
//
//  Created by Andre on 09/05/21.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
using namespace std;

class Learner {
public:
    int Learn(const vector<string>& words) {
        set<string> uniqueWords (words.begin(), words.end());
        int vocSizeOld = (int)vocabulary.size();
        vocabulary.insert(uniqueWords.begin(), uniqueWords.end());
        return int(vocabulary.size() - vocSizeOld);
    }
    vector<string> KnownWords() {
        return {vocabulary.begin(), vocabulary.end()};
        // return result;
    }
private:
    set<string> vocabulary;
};

int main() {
    Learner learner;
    string line;
    while (getline(cin, line)) {
        vector<string> words;
        stringstream ss(line);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        cout << learner.Learn(words) << "\n";
    }
    cout << "=== known words ===\n";
    for (auto word : learner.KnownWords()) {
        cout << word << "\n";
    }
    return 0;
}
