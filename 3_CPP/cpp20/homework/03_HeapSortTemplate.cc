#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

template <typename T, typename Compare = std::less<T>>
class HeapSort {
   public:
    HeapSort(T* arr, size_t size) : _vec(arr, arr + size) { sort(); }

    void heapAdjust(size_t i, size_t n) {
        while (i < n) {
            // 求三个元素的最大值
            int lchild = 2 * i + 1;
            int rchild = 2 * i + 2;
            int maxIdx = i;
            if (lchild < n && _vec[lchild] > _vec[maxIdx]) {
                maxIdx = lchild;
            }
            if (rchild < n && _vec[rchild] > _vec[maxIdx]) {
                maxIdx = rchild;
            }
            // 如果最大值是根结点, 调整结束
            if (maxIdx == i) break;
            // 如果不是，交换根结点和最大值结点
            std::swap(_vec[i], _vec[maxIdx]);
            // 调整maxIdx结点
            i = maxIdx;
        }
    }

    void build_heap(int n) {
        for (int i = (n - 2 >> 1); i >= 0; i--) {
            heapAdjust(i, n);
        }
    }

    void sort() {
        build_heap(_vec.size());
        int len = _vec.size();
        while (len > 1) {
            std::swap(_vec[0], _vec[len - 1]);
            len--;
            heapAdjust(0, len);
        }
    }

    void print() {
        for (auto& elem : _vec) {
            cout << elem << "  ";
        }
        cout << endl;
    }

   private:
    vector<T> _vec;
    Compare _cmp;
};

void test0() {
    int arr[] = {16, 1, 45, 23, 99, 2, 18, 67, 42, 10};
    HeapSort<int> myHeap(arr, 10);

    myHeap.print();
}

int main() {
    test0();
    return 0;
}