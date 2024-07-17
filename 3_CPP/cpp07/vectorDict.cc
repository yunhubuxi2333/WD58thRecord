#include <algorithm>
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

bool operator<(const Record& lhs, const Record& rhs) {
    return lhs._word < rhs._word;
}

class Dictionary {
   public:
    Dictionary(int capacity) { _dict.reserve(capacity); }

    void read(const string& filename) {
        ifstream ifs(filename);
        if (!ifs) {
            cerr << "ifs open file failed" << endl;
            return;
        }

        // 因为磁盘读写速度慢，应该尽量减少次数
        /* string word; */
        /* while(ifs >> word){ */
        /* } */

        string line;
        while (getline(ifs, line)) {
            istringstream iss(line);
            string word;
            while (iss >> word) {
                // 处理单词
                string newWord = dealWord(word);

                // 尝试插入
                insert(newWord);
            }
        }

        // 对vector中的元素进行排序
        sort(_dict.begin(), _dict.end());

        ifs.close();
    }

    string dealWord(const string& word) {
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
            /* Record re(word,1); */
            /* _dict.push_back(re); */
            _dict.push_back(Record(word, 1));
        }
    }

    void store(const string& filename) {
        ofstream ofs(filename);
        if (!ofs) {
            cerr << "ofs open file failed" << endl;
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
    Dictionary dict(10000);
    dict.read("The_Holy_Bible.txt");
    dict.store("dict.txt");
}

int main(void) {
    test0();
    return 0;
}