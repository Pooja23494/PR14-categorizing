#include <iostream>
#include <vector>
using namespace std;

void selection_sort(vector<int> &a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        swap(a[i], a[min]);
    }
}
void merge(vector<int> &a, int start, int mid, int end)
{
    vector<int> temp;
    int i = start, j = mid + 1;
    while (i <= mid && j <= end)
    {
        if (a[j] >= a[i])
        {
            temp.push_back(a[i++]);
        }
        else
        {
            temp.push_back(a[j++]);
        }
    }
    while (i <= mid)
    {
        temp.push_back(a[i++]);
    }
    while (j <= end)
    {
        temp.push_back(a[j++]);
    }
    for (int k = 0; k < temp.size(); k++)
    {
        a[start + k] = temp[k];
    }
}
void merge_sort(vector<int> &a, int start, int end)
{
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;
    merge_sort(a, start, mid);
    merge_sort(a, mid + 1, end);
    merge(a, start, mid, end);
}
int linear_search(vector<int> &a, int target)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a.at(i) == target)
        {
            return i;
        }
    }
    return -1;
}
int binary_search(vector<int> &a, int target)
{
    int start = 0;
    int end = a.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (a[mid] == target)
        {
            return mid;
        }
        else if (a[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}
void displayArray(vector<int> &a, int n)
{
    cout << "Array is: ";
    for (int i = 0; i < a.size(); i++)
    {
        cout << a.at(i) << " ";
    }
    cout << endl;
}
int main()
{

    int n, element, target, result, choice;
    vector<int> a;

    do
    {
        cout << endl;
        cout << "Enter 1 for create Array" << endl;
        cout << "Enter 2 for Selection Sort" << endl;
        cout << "Enter 3 for Merge Sort" << endl;
        cout << "Enter 4 for Linear Search (Unsorted Array)" << endl;
        cout << "Enter 5 for Binary Search (Sorted Array)" << endl;
        cout << "Enter 6 for Clear Array" << endl;
        cout << "Enter 0 for Exit" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter size of array: ";
            cin >> n;

            for (int i = 0; i < n; i++)
            {
                cout << "Enter element: ";
                cin >> element;
                a.push_back(element);
            }

            displayArray(a, n);
            break;
        case 2:
            selection_sort(a, n);
            cout << "Sorted ";
            displayArray(a, n);
            break;
        case 3:
            merge_sort(a, 0, n - 1);
            cout << "Sorted ";
            displayArray(a, n);
            break;
        case 4:
            cout << "Enter target element: ";
            cin >> target;
            displayArray(a, n);
            result = linear_search(a, target);
            if (result != -1)
            {
                cout << "Element found at " << result << " index" << endl;
            }
            else
            {
                cout << "Element not found" << endl;
            }
            break;
        case 5:
            cout << "Enter target element: ";
            cin >> target;
            displayArray(a, n);
            result = binary_search(a, target);
            if (result != -1)
            {
                cout << "Element found at " << result << " index" << endl;
            }
            else
            {
                cout << "Element not found" << endl;
            }
            break;
        case 6:
            a.clear();
            cout << "Array clear successfully.." << endl;
            break;
        case 0:
            cout << "Exit." << endl;
            break;
        default:
            cout << "Wrong choice!" << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}