#include <bits/stdc++.h>
using namespace std;

//lambda
void solve(vector<int>& arr, int x) {
    int n = arr.size();
    sort(arr.begin(),arr.end(), [x](const int a, const int b) {
        return abs(a-x) < abs(b-x);
    });
    return;
}

int partition(int arr[], int low, int high)
{
    int i = low;
    int j = high;
    int pivot = arr[low];
    while (i < j)
    {
        while (pivot>=arr[i]) i++;
        while (pivot<arr[j]) j--;
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
    int pivot = partition(arr, low, high);
    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {4, 2, 8, 3, 1, 5, 7,11,6};
    int size = sizeof(arr) / sizeof(int);

    int temp[2] = {2,1};
    cout<<partition(temp,0,1);

    cout<<"Before Sorting"<<endl;
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    cout<<"After Sorting"<<endl;
    printArray(arr, size);

    return 0;
}
