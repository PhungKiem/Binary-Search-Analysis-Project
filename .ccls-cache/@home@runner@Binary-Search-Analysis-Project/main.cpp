#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>
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
    vector<int> sizes = {5000, 50000, 100000, 150000, 1000000};
    double SumRBS = 0.0, SumIBS = 0.0, SumSeqS = 0.0;

    for (int N : sizes) {
        cout << "\nTesting with N = " << N << "\n";

        for (int iteration = 0; iteration < 10; ++iteration) {
            vector<int> vec;
            for (int i = 0; i < N; ++i) {
                vec.push_back(rand() % 100000 + 1);
            }

            sort(vec.begin(), vec.end());
            int target = rand() % 100000 + 1;

            // Recursive Binary Search Timing
            auto start = chrono::high_resolution_clock::now();
            recursiveBinarySearch(vec, 0, vec.size() - 1, target);
            auto end = chrono::high_resolution_clock::now();
            SumRBS += chrono::duration_cast<chrono::nanoseconds>(end - start).count() / 1000.0;

            // Iterative Binary Search Timing
            start = chrono::high_resolution_clock::now();
            iterativeBinarySearch(vec, target);
            end = chrono::high_resolution_clock::now();
            SumIBS += chrono::duration_cast<chrono::nanoseconds>(end - start).count() / 1000.0;

            // Sequential Search Timing
            start = chrono::high_resolution_clock::now();
            sequentialSearch(vec, target);
            end = chrono::high_resolution_clock::now();
            SumSeqS += chrono::duration_cast<chrono::nanoseconds>(end - start).count() / 1000.0;
        }

        cout << "Average Running Time for Recursive Binary Search: " << SumRBS / 10.0 << " microseconds." << endl;
        cout << "Average Running Time for Iterative Binary Search: " << SumIBS / 10.0 << " microseconds." << endl;
        cout << "Average Running Time for Sequential Search: " << SumSeqS / 10.0 << " microseconds." << endl;

        // Reset accumulators for next N value
        SumRBS = SumIBS = SumSeqS = 0.0;
    }

    return 0;
}
