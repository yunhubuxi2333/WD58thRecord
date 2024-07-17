#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
using namespace std;
class Dictionary {
   private:
    map<string, int> _dict;
    ifstream _ifs;
    ofstream _ofs;
    istringstream _iss;

   public:
    Dictionary(string filename, string targetfile)
        : _dict(), _ifs(), _ofs(targetfile), _iss(filename) {}
    Dictionary() {}

    void resStore() {
        for(auto it = _dict.begin(); it != _dict.end(); it++) {}
    }

    void readFile(string& filename, string& targetfile) {
        _ifs.open(filename);
        string word;
        if (!_ifs) {
            cerr << "open file faild" << endl;
        }
        while (_ifs >> word) {
            for (auto it = word.begin(); it != word.end(); it++) {
                if (!isalpha(*it)) {
                    word.erase(it);
                }
                *it = tolower(*it);
            }
            auto it = _dict.find(word);
            _dict[word]++;
        }
    }
};