#include <stdio.h>

int main() {
    int N, M;
    printf("Enter the number of rows (N) and columns (M): ");
    scanf("%d %d", &N, &M);

    int matrix[N][M];
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (matrix[i][j] < 0) {
                count++;
                break;
            }
        }
    }

    printf("The number of rows with negative elements: %d\n", count);
    return 0;
}

