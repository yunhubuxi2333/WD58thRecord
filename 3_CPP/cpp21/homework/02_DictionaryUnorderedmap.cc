#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::ofstream;
using std::string;
using std::unordered_map;

class Dictionary {
   public:
    void read(const string& filename) {
        ifstream ifs(filename);
        if (!ifs) {
            cerr << "ifstream open file failed!" << endl;
            return;
        }

        string line;
        while (getline(ifs, line)) {
            istringstream iss(line);
            string word;
            while (iss >> word) {
                // 处理单词
                dealWord(word);

                // 插入到map中
                if (word != string()) {
                    ++_dict[word];
                }
            }
        }

        ifs.close();
    }

    void dealWord(string& word) {
        // 迭代器访问word
        auto it = word.begin();
        while (it != word.end()) {
            if (!isalpha(*it)) {
                it = word.erase(it);
            } else {
                ++it;
            }
        }
    }

    void store(const string& filename) {
        ofstream ofs(filename);
        if (!ofs) {
            cerr << "ofstream open file failed!" << endl;
            return;
        }

        unordered_map<string, int>::iterator it = _dict.begin();
        for (; it != _dict.end(); ++it) {
            ofs << it->first << "  " << it->second << endl;
        }
        ofs.close();
    }

   private:
    unordered_map<string, int> _dict;
};

void test0() {
    Dictionary dict;
    dict.read("The_Holy_Bible.txt");
    dict.store("dictMap.dat");
}
int main() {
    test0();
    return 0;
}