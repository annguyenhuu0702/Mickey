//sắp xếp trộn
#include<iostream>
using namespace std;
 
// Hợp nhất hai mảng con của arr [].
// Mảng con đầu tiên là arr [l..m]
// Mảng con thứ hai là arr [m + 1..r]
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Tạo mảng tạm thời
    int L[n1], R[n2];
 
    // Sao chép dữ liệu vào mảng tạm thời L [] và R []
    for(int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    //Hợp nhất các mảng tạm thời lại thành arr [l..r]
     
    // Chỉ mục ban đầu của mảng con đầu tiên
    int i = 0; 
     
    // Chỉ mục ban đầu của mảng con thứ hai
    int j = 0; 
     
    //Chỉ mục ban đầu của mảng con đã hợp nhất
    int k = l;
     
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]) 
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Sao chép các phần tử còn lại của
    // L [], nếu có
    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Sao chép các phần tử còn lại của
    // R [], nếu có
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
// l là chỉ mục bên trái và r là
// chỉ mục bên phải của mảng con
// trong tổng số arr được sắp xếp
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
         
        // Tương tự như (l + r) / 2, nhưng tránh
        // tràn cho l và h lớn
        int m = l + (r - l) / 2;
 
        //Sắp xếp nửa thứ nhất và thứ hai
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}
 
// Hàm in một mảng
void printArray(int A[], int size)
{
    for(int i = 0; i < size; i++)
        cout << A[i] << " ";
}
 
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Given array is \n";
    printArray(arr, arr_size);
 
    mergeSort(arr, 0, arr_size - 1);
 
    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    system("pause");
    return 0;
}
 