#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::ofstream;
using std::string;
using std::vector;

struct Record {
    Record(const string& word, int frequency)
        : _word(word), _frequency(frequency) {}

    string _word;
    int _frequency;
};

class Dictionary {
   public:
    // 统计圣经文件中单词以及该单词在文件中出现的次数
    void read(const std::string& filename) {
        ifstream ifs(filename);
        if (!ifs) {
            cerr << "ifstream open file failed!!!" << endl;
            return;
        }
        string line;
        while (getline(ifs, line)) {
            istringstream iss(line);
            string word;
            while (iss >> word) {
                // 处理单词
                string newword = dealWord(word);
                // 插入
                insert(newword);
            }
        }
        ifs.close();
    }

    string dealWord(string word) {
        for (size_t idx = 0; idx != word.size(); ++idx) {
            if (!isalpha(word[idx])) {
                return string();
            }
        }
        return word;
    }

    void insert(const string& word) {
        if (word == string()) {
            return;
        }

        size_t idx = 0;
        for (; idx != _dict.size(); ++idx) {
            if (word == _dict[idx]._word) {
                ++_dict[idx]._frequency;
                break;
            }
        }

        if (idx == _dict.size()) {
            _dict.push_back(Record(word, 1));
        }
    }
    void store(const std::string& filename) {
        ofstream ofs(filename);
        if (!ofs) {
            cerr << "ofstream open file failed!!!" << endl;
            return;
        }
        for (size_t idx = 0; idx != _dict.size(); ++idx) {
            ofs << _dict[idx]._word << "   " << _dict[idx]._frequency << endl;
        }
        ofs.close();
    }

   private:
    vector<Record> _dict;
};

void test0() {
    Dictionary dict;
    dict.read("The_Holy_Bible.txt");
    dict.store("dict.txt");
}

int main(void) {
    test0();
    return 0;
}