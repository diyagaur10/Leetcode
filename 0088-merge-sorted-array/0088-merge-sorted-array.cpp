#include <vector>
#include <algorithm>

class Solution {
public:
    void merge(std::vector<int>& arr1, int m, std::vector<int>& arr2, int n) {
        int i = m - 1;  // Pointer for the end of initialized elements in arr1
        int j = n - 1;  // Pointer for the end of arr2
        int k = m + n - 1;  // Pointer for the end of arr1 (including placeholders)

        // Merge arr2 into arr1 starting from the end
        while (i >= 0 && j >= 0) {
            if (arr1[i] > arr2[j]) {
                arr1[k--] = arr1[i--];
            } else {
                arr1[k--] = arr2[j--];
            }
        }

        // If there are any remaining elements in arr2, copy them over
        while (j >= 0) {
            arr1[k--] = arr2[j--];
        }

        // No need to copy the remaining elements of arr1, since they are already in place
    }
};
