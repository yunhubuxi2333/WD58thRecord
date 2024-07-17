#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int x = 0, vote = 0;
        for (int num : nums) {
            if (vote == 0) x = num;
            vote += num == x ? 1 : -1;
        }
        return x;
    }
};

void test0() {
    Solution s;
    vector<int> nums{1, 2, 3, 2, 2, 2, 5, 4, 2};
    cout << s.majorityElement(nums) << endl;
}

int main() {
    test0();
    return 0;
}