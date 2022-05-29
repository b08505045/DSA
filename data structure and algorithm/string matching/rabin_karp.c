#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


long long mod(long long t, long long q){
    if(t > 0)
        return t % q;
    else if(t == 0) return 0;
    else
        return t % q + q;
}

int main() {
    long long q = 17, d = 10, len_P = 5, len_T = 16, h = 1;
    char *P = "41592";
    char *T = "3141592653589793";
    long long p = 0, t = 0;
    for(int i = 0; i < len_P; i++){
        p = mod((d * p + P[i] - '0'), q);
        t = mod((d * t + T[i] - '0'), q);
        // printf("p : %d\n", p);
    }
    
    // (a*b)mod q = (a mod q * b mod q)(mod q)
    for(int i = 1; i < len_P; i++){
        h = mod(h * d, q); //
    }
    printf(" p : %d, h : %d\n", p, h);

    long long *t_arr = malloc((len_T - len_P) * sizeof(long long));
    int spurious = 0; // spurious = 1 if spurious hits

    for(int s = 0; s < len_T - len_P; s++){
        t_arr[s] = t;
        printf("s : %d, t : %d\n", s, t);
        if(p == t){
            for(int i = 0; i < len_P; i++){
                if(P[i] != T[i + s]){
                    spurious = 1;
                    break;
                }
            }
            if(spurious)
                printf("shift %d spurious occur\n", s);
            else
                printf("shift %d match !\n", s);
        }
        t = mod((d * (t - (T[s] - '0') * h) + T[s + len_P] - '0'), q);
    }

    for(int i = 0; i < len_T - len_P; i++){
        printf("%d ", t_arr[i]);
    }
    printf("\nEnd\n");
}
