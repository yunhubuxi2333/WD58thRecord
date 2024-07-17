#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

template <typename T, typename Compare = std::less<T>>
class MyQsort {
   public:
    MyQsort(T* arr, size_t size, Compare com) : _vec(arr, arr + size) {
        quick(0, _vec.size() - 1, com);
    }

    void quick(int left, int right, Compare& com) {
        int pivot;
        if (left < right) {
            pivot = partition(left, right, com);
            quick(left, pivot - 1, com);
            quick(pivot + 1, right, com);
        }
    }
    int partition(int left, int right, Compare& com) {
        T pivot = _vec[right];
        int i = left - 1;
        for (int j = left; j < right; j++) {
            if (com(_vec[j], pivot)) {
                ++i;
                std::swap(_vec[i], _vec[j]);
            }
        }
        std::swap(_vec[i + 1], _vec[right]);
        return i + 1;
    }

    void print() {
        for (auto& elem : _vec) {
            cout << elem << "  ";
        }
        cout << endl;
    }

   private:
    vector<T> _vec;
};

void test0() {
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    MyQsort<int> mqInt(arr, 10, std::less<int>());
    mqInt.print();
}

int main() {
    test0();
    return 0;
}