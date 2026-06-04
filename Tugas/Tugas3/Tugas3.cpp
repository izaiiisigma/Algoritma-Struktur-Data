#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int randomNum(int bil)
{
    int jumlah = rand() % bil;
    return jumlah;
}

void randomize()
{
    srand(time(NULL));
}

bool binarySearch(int arr[], int left, int N, int target)
{
    int right = N - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return true;
        else if (target < arr[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return false;
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minidx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minidx])
                minidx = j;
        }
        int temp    = arr[i];
        arr[i]      = arr[minidx];
        arr[minidx] = temp;
    }
}

int main()
{
    int N, X;
    cout << "Masukkan N dan X: ";
    cin >> N >> X;

    int arr[N];

    randomize();
    for (int i = 0; i < N; i++)
    {
        arr[i] = randomNum(25) + 1;
        printf("%d ", arr[i]);
    }
    cout << endl;

    selectionSort(arr, N);

    int totalPasangan = 0;
    for (int i = 0; i < N - 1; i++)
    {
        int target = X - arr[i];
        if (binarySearch(arr, i + 1, N, target))
            totalPasangan++;
    }

    cout << totalPasangan << endl;

    return 0;
}