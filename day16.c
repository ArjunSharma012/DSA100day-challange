#include <stdio.h>

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    int freq[1000] = {0};  

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        freq[arr[i]]++;
    }

    printf("Frequencies:\n");
    for(int i = 0; i < 1000; i++) {
        if(freq[i] != 0)
            printf("%d occurs %d times\n", i, freq[i]);
    }

    return 0;
}

