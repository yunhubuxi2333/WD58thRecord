#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 7
#define SIZE(a) sizeof(a)/sizeof(a[0])
#define SWAP(arr,i,j){			\
	int t = arr[i];				\
	arr[i] = arr[j];			\
	arr[j] = t;					\
}
void print_array(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
//归并排序
void merge_sort(int arr[], int n);
//快速排序
void quick_sort(int arr[], int n);
//堆排序
void heap_sort(int arr[], int n);
//洗牌算法
void shuffle(int arr[], int n);
int main() {
	int arr[N] = { 38,27,43,3,9,82,10 };
	print_array(arr, SIZE(arr));

	//merge_sort(arr, N);
	//printf("归并排序后：\n");
	//print_array(arr, N);

	//quick_sort(arr, N);
	//printf("快速排序后：\n");
	//print_array(arr, N);

	heap_sort(arr, N);
	printf("堆排序后：\n");
	print_array(arr, N);

	shuffle(arr, N);
	printf("打乱顺序后：\n");
	print_array(arr, N);

	return 0;
}
/****************************************************************************/
/*								归并排序									*/
/****************************************************************************/
int temp[N];
void merge(int arr[], int left, int mid, int right) {
	//左边区间:[left,mid]
	//右边区间:[mid+1,right]
	int i = left, j = mid + 1, k = left;
	//遍历两个区间
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
		}
	}//退出条件是i>mid || j> right
	while (i <= mid) {
		temp[k++] = arr[i++];
	}
	while (j <= right) {
		temp[k++] = arr[j++];
	}
	//将temp数组的对应元素复制到原数组中
	for (int k = left; k <= right; k++) {
		arr[k] = temp[k];
	}
	print_array(arr, N);
}
void m_sort(int arr[], int left, int right) {
	//边界条件
	if (left >= right)	return;
	//递归公式
	int mid = left + (right - left >> 1);
	//对左边区间进行排序
	m_sort(arr, left, mid);
	//对右边区间进行排序
	m_sort(arr, mid + 1, right);
	//归并
	merge(arr, left, mid, right);
}
void merge_sort(int arr[], int n) {
	m_sort(arr, 0, n - 1);
}

/****************************************************************************/
/*								快速排序									*/
/****************************************************************************/

int partition(int arr[], int left, int right) {
	// 1.选取基准值
	int pivot = arr[left];
	// 2.双向分区
	int i = left, j = right;
	while (i < j) {
		//先移动j，找到小于pivot的元素
		while (i < j && arr[j]>= pivot) {
			j--;
		}//	i==j	||	arr[j] < pivot
		arr[i] = arr[j];

		//再移动i，找到大于pivot的元素
		while (i < j && arr[i] <= pivot) {
			i++;
		}//	i==j	||	arr[i] > pivot
		arr[j] = arr[i];

	}//i==j
	arr[i] = pivot;
	return i;
}
void q_sort(int arr[], int left, int right) {
	//边界条件
	if (left >= right)	return;
	//递归公式
	//1.分区
	int idx = partition(arr, left, right);
	//2.对左边区间进行排序
	q_sort(arr, left, idx - 1);
	//3.对右边区间进行排序
	q_sort(arr, idx + 1, right);
}
void quick_sort(int arr[], int n) {
	q_sort(arr, 0, n - 1);
}

/****************************************************************************/
/*								堆排序										*/
/****************************************************************************/

// i: 需要调整的结点索引
// n: 索引的最大范围
void heapify(int arr[], int i, int n) {
	while (i < n) {
		//求三个元素的最大值
		int lchild = 2 * i + 1;
		int rchild = 2 * i + 2;
		int maxIdx = i;
		if (lchild<n && arr[lchild]>arr[maxIdx]) {
			maxIdx = lchild;
		}
		if (rchild < n && arr[rchild]>arr[maxIdx]) {
			maxIdx = rchild;
		}
		//如果最大值是根结点，调整结束
		if (maxIdx == i)	break;
		//如果不是，交换根结点和最大值结点
		SWAP(arr, i, maxIdx);
		//调整maxIdx结点
		i = maxIdx;
	}
}
void build_heap(int arr[], int n) {
	//从后往前依次构建大根堆
	//找到第一个非叶子结点：lchild(i) = 2i + 1 < n;==>i < n - 2 >> 1;
	for (int i = (n - 2 >> 1); i >= 0; i--) {
		heapify(arr, i, n);
	}
}
void heap_sort(int arr[], int n) {
	//1.构建大顶堆
	build_heap(arr, n);
	//2.初始化无序区长度
	int len = n;
	//3.交换堆顶元素和无序区最后一个元素，直到len == 1
	while (len > 1) {
		SWAP(arr, 0, len - 1);
		len--;
		heapify(arr, 0, len);
	}
}

/****************************************************************************/
/*								洗牌算法									*/
/****************************************************************************/
void shuffle(int arr[], int n) {
	int index;
	int temp = 0;
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		index = rand() % (n - i) + i;
		if (index != i) {
			temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
		}
	}
}