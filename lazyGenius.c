#include <stdio.h>

// Define the given matrix
int matrix[5][5] = {
    {10, 1, 16, 4, 9},
    {24, 7, 23, 2, 11},
    {12, 19, 6, 17, 8},
    {25, 15, 5, 22, 14},
    {13, 20, 3, 21, 18}
};


// Function to pad the input array with 1s to make its length a multiple of 5
void pad_array(int arr[], int n) {
    while (n % 5 != 0) {
        arr[n] = 1;
        n++;
    }
}

// Function to multiply the input array with the matrix
void multiply_with_matrix(int arr[], int result[], int n) {
    for (int i = 0; i < n; i += 5) {
        for (int j = 0; j < 5; j++) {
            result[i + j] = 0;
            for (int k = 0; k < 5; k++) {
                result[i + j] += arr[i + k] * matrix[k][j];
            }
        }
    }
}

// Function to map the result to alphabets
void map_to_alphabets(int arr[], int n) {
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < n; i++) {
        arr[i] %= 26;
        printf("%c", alphabet[arr[i]]);
    }
    printf("\n");
}

int main() {
    int T, N;
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &N);
        int message[25]; // Maximum possible length is 20, padded to 25
        for (int i = 0; i < N; i++) {
            scanf("%d", &message[i]);
        }

        // Step 1: Pad the array
        pad_array(message, N);

        // Step 2: Multiply with the matrix
        int result[25]; // Result array
        multiply_with_matrix(message, result, N);

        // Step 3: Map to alphabets and print the result
        map_to_alphabets(result, N);
    }

    return 0;
}
