#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;

class Solution {
   public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 0);
        res[0] = 1;
        for (int i = 1; i < rowIndex + 1; i++) {
            for (int j = i; j >= 1; j--) {
                res[j] += res[j - 1];
            }
        }

        return res;
    }
};

void test0() {
    Solution s1;
    for (auto ele : s1.getRow(5)) {
        cout << ele << " ";
    }
    cout << endl;
}

int main() {
    test0();
    return 0;
}