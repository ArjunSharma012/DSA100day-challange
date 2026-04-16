#include <stdio.h>

int maxLenZeroSumSubarray(int arr[], int n) {
    int prefix_sum = 0, max_len = 0;

    for (int i = 0; i < n; i++) {
        prefix_sum = 0;
        for (int j = i; j < n; j++) {
            prefix_sum += arr[j];
            if (prefix_sum == 0) {
                int len = j - i + 1;
                if (len > max_len)
                    max_len = len;
            }
        }
    }
    return max_len;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d", maxLenZeroSumSubarray(arr, n));
    return 0;
}