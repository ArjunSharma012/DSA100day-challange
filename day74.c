#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char votes[n][100];
    for (int i = 0; i < n; i++) {
        scanf("%s", votes[i]);
    }

    char unique[n][100];
    int count[n];
    int uniqueCount = 0;

    for (int i = 0; i < n; i++) {
        int found = 0;

        for (int j = 0; j < uniqueCount; j++) {
            if (strcmp(votes[i], unique[j]) == 0) {
                count[j]++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(unique[uniqueCount], votes[i]);
            count[uniqueCount] = 1;
            uniqueCount++;
        }
    }

    int maxVotes = 0;
    char winner[100] = "";

    for (int i = 0; i < uniqueCount; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, unique[i]);
        } 
        else if (count[i] == maxVotes) {
            if (strcmp(unique[i], winner) < 0) {
                strcpy(winner, unique[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}