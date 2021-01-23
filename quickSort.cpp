// thuật toán sắp xếp dựa trên kỹ thuật chia để trị
#include <iostream> 
using namespace std;  
  //hàm hoán vị 
void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
  
/* This function takes last element as pivot, places  
the pivot element at its correct position in sorted  
array, and places all smaller (smaller than pivot)  
to left of pivot and all greater elements to right  
of pivot */
int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high]; // pivot  
    int i = (low - 1); // Chỉ mục phần tử nhỏ hơn 
  
    for (int j = low; j <= high - 1; j++)  
    {  
        // Nếu phần tử hiện tại nhỏ hơn trục  
        if (arr[j] < pivot)  
        {  
            i++; // chỉ số gia tăng của phần tử nhỏ hơn
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  
  
/* Chức năng chính thực hiện QuickSort
arr [] -> Mảng được sắp xếp,
thấp -> Chỉ số bắt đầu,
cao -> Chỉ số kết thúc */
void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partition(arr, low, high);  
  
        // Sắp xếp riêng biệt các phần tử trước  
        // phân vùng và sau phân vùng 
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}  
  
/* Hàm in một mảng */
void printArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  
  
int main()  
{  
    int arr[] = {10, 7, 8, 9, 1, 5};  
    int n = sizeof(arr) / sizeof(arr[0]);  
    quickSort(arr, 0, n - 1);  
    cout << "Sorted array: \n";  
    printArray(arr, n);  
    system("pause");
    return 0;  
}  