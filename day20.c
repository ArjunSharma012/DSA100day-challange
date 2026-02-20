#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int count = 0;
    int sum = 0;

    int freq[20001] = {0};  
    int offset = 10000;  

    freq[offset] = 1;  

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        count += freq[sum + offset];
        freq[sum + offset]++;
    }

    printf("%d\n", count);

    return 0;
}