#include <iostream> 
using namespace std; 
  
// Để đống một cây con bắt nguồn từ nút i là
// một chỉ mục trong arr []. n là kích thước của đống
void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Khởi tạo lớn nhất dưới dạng gốc
    int l = 2*i + 1; // trái = 2*i + 1 
    int r = 2*i + 2; // phải = 2 * i + 2
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    //Nếu con bên phải lớn hơn con lớn nhất cho đến nay
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // Nếu lớn nhất không phải là gốc
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
  
        // Đánh đống một cách đệ quy cây con bị ảnh hưởng
        heapify(arr, n, largest); 
    } 
} 
  
// hàm để thực hiện sắp xếp đống 
void heapSort(int arr[], int n) 
{ 
    // Xây dựng heap (sắp xếp lại mảng)
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // Từng người một trích xuất một phần tử từ heap
    for (int i=n-1; i>0; i--) 
    { 
        // Di chuyển gốc hiện tại đến cuối
        swap(arr[0], arr[i]); 
  
        // gọi max heapify trên heap giảm
        heapify(arr, i, 0); 
    } 
} 
  
/* in mảng có kích thước n */
void printArray(int arr[], int n) 
{ 
    for (int i=0; i<n; ++i) 
        cout << arr[i] << " "; 
    cout << "\n"; 
} 

int main() 
{ 
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    heapSort(arr, n); 
  
    cout << "Sorted array is \n"; 
    printArray(arr, n); 
    system("pause");
} 