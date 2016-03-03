#include <iostream>

using namespace std;


//选择排序，不稳定，O（n^2）
void selectSort(vector array,int size)
{
	int minIndex ;
	for (int i = 0;i<size,i++) {
		minIndex = i;
		for (int j = i + 1; j < size; j++) {
			if(array[minIndex] >array[j]){
				//获取最小值的下标
				minIndex = j;
			}
		}
		if(minIndex != i){
			//将每次遍历的最小值与当前的位置数进行交换
			swap(array,i,minIndex);
		}
	}
}

//冒泡排序，稳定排序，O（n^2)
void BubbleSort(T* array,int size){
	for (int i = 0; i < size; i++) {
		for (int j = 1; j < size - i; j++) {
			if(array[j]<array[j-1]){
				//相邻两个数进行比较，小数前移
				swap(array,j,j-1);
			}
		}
	}
}

//插入排序，稳定排序，O（n^2)
void insertSort(T* array,int size){
	for (int i = 1; i < size; i++) {
		//从头进行累加个数比较
		for (int j = i; j > 0; j--) {
			//当前元素的个数内，从后向前比较，小数往前移动
			if(array[j]<array[j-1]){
				swap(array,j,j-1)
			}
		}
	}
}

///////////高级排序

//快速排序，不稳定排序，O（nlogn）
void QuickSort(T* array,int left,int right){
	if(left < right){
		int i = left - 1,j = right + 1;
		//取参考的数值
		T mid = array[(left + right)/2];
		while(true){
			//检测标准数的左边，比他大的数的下标位置
			while (array[++i]<mid) ;
			//检测标准数的右边，比他小的数的下标位置
			while (array[--j]>mid) ;
			if(i >= j){
				//左右两个坐标位置有交集则退出
				break;
			}
			//将左边的大数和右边的小数交换位置
			swap(array,i,j);
		}
		QuickSort(array,left,i-1);
		QuickSort(array,j+1,right);
	}
}

//归并排序，稳定排序，O（nlogn）
void MergeSort(T* array, int size){
	if(left < right){
		int mid = (left + right)/2;
		MergeSort(array,left,mid);
		MergeSort(array,mid + 1,right);
		//合并两条已经排序好的子链
		Merge(array,left,mid,right);
	}
}

void Merge(T* array,int left,int mid,int right){
	T* temp = new T[right - left + 1];
	int i = left,j = mid + 1,m = 0;
	while (i <= mid && j <= right) {
		if(array[i]<array[j]{
			temp[m++] = array[i++];
		}else{
			temp[m++] = array[j++];
		}
	}
	while (i <= mid) {
		temp[m++] = array[i++];
	}
	while (j <= right) {
		temp[m++] = array[j++];
	}
	for (int n = left,m = 0; n <= right; n++,m++) {
		array[n] = temp[m];
	}
	delete temp;
}

//堆排序，不稳定排序，O（nlogn）
void HeapSort(T* array,int size){
	int lastP = size/2;
	//从最后一个有孩子的节点开始建初始堆
	for (int i = lastP - 1; i >= 0; i--) {
		HeapAdjust(array,i,size);
	}
	int j = size;
	//将堆顶元素和无序区间的最后一个元素交换，再调整堆
	while (j > 0) {
		//最前和最后的交换
		Swap(array,0,j-1);
		j--;
		//调整元素的位置
		HeapAjust(array,0,j);
	}
}

void HeapAjust(T* array,int toAjust,int size){
	int pos = toAjust;
	while ((pos * 2 + 1) < size) {
		int lChild = pos * 2 + 1;
		if(array[lChild]>array[pos]){
			pos ＝ lChild; // 左孩子大
		}
		int rChild = lChild + 1;
		if (rChild < size && array[rChild] > array[pos]) {
			pos = rChild; // 右孩子大
		}
		if (pos != toAjust) {
			// 父节点比其中一个孩子小
			swap(array,toAjust,pos);
			toAjust = pos;
		}else {
			break;
		}
	}
}

//二叉树排序，稳定排序，O（nlogn）

int main(int argc, char *argv[]) {
	
}