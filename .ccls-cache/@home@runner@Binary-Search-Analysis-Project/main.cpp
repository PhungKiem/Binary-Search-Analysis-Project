#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Recursive Binary Search
int recursiveBinarySearch(const vector<int>& vec, int left, int right, int target) {
    if (left > right)
        return -1;
    int mid = left + (right - left) / 2;
    if (vec[mid] == target)
        return mid;
    else if (vec[mid] > target)
        return recursiveBinarySearch(vec, left, mid - 1, target);
    else
        return recursiveBinarySearch(vec, mid + 1, right, target);
}

// Iterative Binary Search
int iterativeBinarySearch(const vector<int>& vec, int target) {
    int left = 0, right = vec.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (vec[mid] == target)
            return mid;
        else if (vec[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

// Sequential Search
int sequentialSearch(const vector<int>& vec, int target) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] == target)
            return i;
    }
    return -1;
}

int main() {
    vector<int> vec = {34, 7, 23, 32, 5, 62};

    // Sort the vector
    sort(vec.begin(), vec.end());

    // Display the sorted vector
    cout << "Sorted vector: ";
    for (int num : vec)
        cout << num << " ";
    cout << endl;

    int target1 = 23; // An item that is in the list
    int target2 = 100; // An item that is not in the list

    // Recursive Binary Search
    cout << "\nRecursive Binary Search:" << endl;
    int index = recursiveBinarySearch(vec, 0, vec.size() - 1, target1);
    if (index != -1)
        cout << "Target " << target1 << " found at location " << index << endl;
    else
        cout << "Target " << target1 << " was not found, return value is " << index << endl;

    index = recursiveBinarySearch(vec, 0, vec.size() - 1, target2);
    if (index != -1)
        cout << "Target " << target2 << " found at location " << index << endl;
    else
        cout << "Target " << target2 << " was not found, return value is " << index << endl;

    // Iterative Binary Search
    cout << "\nIterative Binary Search:" << endl;
    index = iterativeBinarySearch(vec, target1);
    if (index != -1)
        cout << "Target " << target1 << " found at location " << index << endl;
    else
        cout << "Target " << target1 << " was not found, return value is " << index << endl;

    index = iterativeBinarySearch(vec, target2);
    if (index != -1)
        cout << "Target " << target2 << " found at location " << index << endl;
    else
        cout << "Target " << target2 << " was not found, return value is " << index << endl;

    // Sequential Search
    cout << "\nSequential Search:" << endl;
    index = sequentialSearch(vec, target1);
    if (index != -1)
        cout << "Target " << target1 << " found at location " << index << endl;
    else
        cout << "Target " << target1 << " was not found, return value is " << index << endl;

    index = sequentialSearch(vec, target2);
    if (index != -1)
        cout << "Target " << target2 << " found at location " << index << endl;
    else
        cout << "Target " << target2 << " was not found, return value is " << index << endl;

    return 0;
}
