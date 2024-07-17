#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

void test0() {
    vector<vector<int>> vec_of_vecs;

    for (int i = 1; i <= 3; i++) {
        vector<int> temp_vec;
        for (int j = 1; j <= 5; j++) {
            temp_vec.push_back(i * j);
        }
        vec_of_vecs.push_back(temp_vec);
    }

    for (size_t i = 0; i < vec_of_vecs.size(); i++) {
        cout << "Vector: ";
        for (auto& ele : vec_of_vecs[i]) {
            cout << ele << " ";
        }
        cout << endl;
    }
}
int main() {
    test0();
    return 0;
}