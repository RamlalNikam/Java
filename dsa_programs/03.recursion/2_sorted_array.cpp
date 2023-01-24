#include <iostream>
using namespace std;
// To check weather the array is sorted or not.
bool isSorted(int *arr, int size)
{
    // Base Case:
    if (size == 0 || size == 1)
        return true;

    // Processing:
    if (arr[0] > arr[1])
        return false;
    else
    {
        // Recurance Relation
        bool remaningPart = isSorted(arr + 1, size - 1);
        return remaningPart;
    }
}
// To find the sum of an array.
void sumArr(int *arr, int size, int sum)
{
    // Base Case:
    if (size == 0){
        cout << endl << "Sum = " << sum;
        return ;
    }
    // Processing:
    sum = sum + arr[0];
    // Recurence Relation:
    sumArr(arr + 1, size - 1, sum);
}
int main()
{
    bool ans;
    int arr[5] = {5, 6, 7, 8, 9};
    ans = isSorted(arr, 5);
    if (ans)
        cout << endl
             << "Your array is sorted.";
    else
        cout << endl
             << "Your array is not sorted.";
    // Sum of Array:
    sumArr(arr, 5, 0);

    return 0;
}