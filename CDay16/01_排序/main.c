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
//�鲢����
void merge_sort(int arr[], int n);
//��������
void quick_sort(int arr[], int n);
//������
void heap_sort(int arr[], int n);
//ϴ���㷨
void shuffle(int arr[], int n);
int main() {
	int arr[N] = { 38,27,43,3,9,82,10 };
	print_array(arr, SIZE(arr));

	//merge_sort(arr, N);
	//printf("�鲢�����\n");
	//print_array(arr, N);

	//quick_sort(arr, N);
	//printf("���������\n");
	//print_array(arr, N);

	heap_sort(arr, N);
	printf("�������\n");
	print_array(arr, N);

	shuffle(arr, N);
	printf("����˳���\n");
	print_array(arr, N);

	return 0;
}
/****************************************************************************/
/*								�鲢����									*/
/****************************************************************************/
int temp[N];
void merge(int arr[], int left, int mid, int right) {
	//�������:[left,mid]
	//�ұ�����:[mid+1,right]
	int i = left, j = mid + 1, k = left;
	//������������
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
		}
	}//�˳�������i>mid || j> right
	while (i <= mid) {
		temp[k++] = arr[i++];
	}
	while (j <= right) {
		temp[k++] = arr[j++];
	}
	//��temp����Ķ�ӦԪ�ظ��Ƶ�ԭ������
	for (int k = left; k <= right; k++) {
		arr[k] = temp[k];
	}
	print_array(arr, N);
}
void m_sort(int arr[], int left, int right) {
	//�߽�����
	if (left >= right)	return;
	//�ݹ鹫ʽ
	int mid = left + (right - left >> 1);
	//����������������
	m_sort(arr, left, mid);
	//���ұ������������
	m_sort(arr, mid + 1, right);
	//�鲢
	merge(arr, left, mid, right);
}
void merge_sort(int arr[], int n) {
	m_sort(arr, 0, n - 1);
}

/****************************************************************************/
/*								��������									*/
/****************************************************************************/

int partition(int arr[], int left, int right) {
	// 1.ѡȡ��׼ֵ
	int pivot = arr[left];
	// 2.˫�����
	int i = left, j = right;
	while (i < j) {
		//���ƶ�j���ҵ�С��pivot��Ԫ��
		while (i < j && arr[j]>= pivot) {
			j--;
		}//	i==j	||	arr[j] < pivot
		arr[i] = arr[j];

		//���ƶ�i���ҵ�����pivot��Ԫ��
		while (i < j && arr[i] <= pivot) {
			i++;
		}//	i==j	||	arr[i] > pivot
		arr[j] = arr[i];

	}//i==j
	arr[i] = pivot;
	return i;
}
void q_sort(int arr[], int left, int right) {
	//�߽�����
	if (left >= right)	return;
	//�ݹ鹫ʽ
	//1.����
	int idx = partition(arr, left, right);
	//2.����������������
	q_sort(arr, left, idx - 1);
	//3.���ұ������������
	q_sort(arr, idx + 1, right);
}
void quick_sort(int arr[], int n) {
	q_sort(arr, 0, n - 1);
}

/****************************************************************************/
/*								������										*/
/****************************************************************************/

// i: ��Ҫ�����Ľ������
// n: ���������Χ
void heapify(int arr[], int i, int n) {
	while (i < n) {
		//������Ԫ�ص����ֵ
		int lchild = 2 * i + 1;
		int rchild = 2 * i + 2;
		int maxIdx = i;
		if (lchild<n && arr[lchild]>arr[maxIdx]) {
			maxIdx = lchild;
		}
		if (rchild < n && arr[rchild]>arr[maxIdx]) {
			maxIdx = rchild;
		}
		//������ֵ�Ǹ���㣬��������
		if (maxIdx == i)	break;
		//������ǣ��������������ֵ���
		SWAP(arr, i, maxIdx);
		//����maxIdx���
		i = maxIdx;
	}
}
void build_heap(int arr[], int n) {
	//�Ӻ���ǰ���ι��������
	//�ҵ���һ����Ҷ�ӽ�㣺lchild(i) = 2i + 1 < n;==>i < n - 2 >> 1;
	for (int i = (n - 2 >> 1); i >= 0; i--) {
		heapify(arr, i, n);
	}
}
void heap_sort(int arr[], int n) {
	//1.�����󶥶�
	build_heap(arr, n);
	//2.��ʼ������������
	int len = n;
	//3.�����Ѷ�Ԫ�غ����������һ��Ԫ�أ�ֱ��len == 1
	while (len > 1) {
		SWAP(arr, 0, len - 1);
		len--;
		heapify(arr, 0, len);
	}
}

/****************************************************************************/
/*								ϴ���㷨									*/
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