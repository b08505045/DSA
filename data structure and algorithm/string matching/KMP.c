#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int * prefix_0_base(char * P, int len){
    int *pi = malloc(len * sizeof(int));
    pi[0] = 0;
    int k = -1;
    for(int i = 1; i < len; i++){
        while(k >= 0 && P[k + 1] != P[i]){
            k = pi[k] - 1;
        }
        if(P[k + 1] == P[i])
            k = k + 1;  
        pi[i] = k + 1;  
    }
    return pi;
}

int * prefix_1_base(char *P, int len){
    int *pi = malloc((len + 1)* sizeof(int));
    pi[1] = 0;
    int k = 0;
    for(int i = 2; i <= len; i++){
        while(k > 0 && P[k + 1] != P[i]){
            k = pi[k];
        }
        if(P[k + 1] == P[i])
            k = k + 1;  
        pi[i] = k;
    }
    return pi;
}

int main() {
    char *P1 = "ABABAABCABAB", *T = "BACBABABAABCBAB";
    int len_P = 12, len_T = 15;
    int *pi_1 = prefix_0_base(P1, len_P);
    for(int i = 0; i < len_P; i++){
        printf("%d ", pi_1[i]);
    }
    printf("\n");
    char *P2 = "lABABAABCABAB";
    int *pi_2 = prefix_1_base(P2, len_P);
    for(int i = 1; i <= len_P; i++){
        printf("%d ", pi_2[i]);
    }
    printf("\n");
}
