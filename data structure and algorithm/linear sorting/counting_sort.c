#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
void counting_sort (int A[], int B[], int n, int K) { // A = input array, B = output array, n - number of input, K = num of total elements may appear
    int *C = malloc(K * sizeof(int));
    for(int i = 0; i < K; i++){
        C[i] = 0;
    }
    for(int i = 1; i <= n; i++){
        C[A[i]] = C[A[i]] + 1;
    }
    for(int i = 1; i < K; i++){
        C[i] = C[i] + C[i - 1];
    }
    for(int i = n; i >= 1; i--){
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }
}

void alt_counting_sort (int A[], int B[], int n, int K) { // A = input array, B = output array, n - number of input, K = num of total elements may appear
    int *C = malloc(K * sizeof(int));
    for(int i = 0; i < K; i++){
        C[i]=0;
    }
    for(int i = 1; i <= n; i++){
        C[A[i]] = C[A[i]] + 1;
    }
    for(int i = K - 1 - 1; i >= 0; i--){
        C[i - 1] = C[i] + C[i - 1];
    }
    for(int i = n; i >= 1; i--){
        B[n - C[A[i]]] = A[i];
        C[A[i]]--;
    }
}

int main() {
    int n = 8, K = 6;
    int A[9] = {-1, 2, 5, 3, 0, 2, 3, 0, 3};
    
    int *B = calloc(n + 1, sizeof(int));
    counting_sort(A, B, n, K);
    for(int i = 1; i <= n; i++){
        printf("%d ", B[i]);
    }
    printf("\nnext\n");
    
    int C[9] = {-1, 2, 5, 3, 0, 2, 3, 0, 3};
    int *D = calloc(n + 1, sizeof(int));
    alt_counting_sort(C, D, n, K);
    for(int i = 1; i <= n; i++){
        printf("%d ", B[i]);
    }
    printf("\nEnd\n");
}
