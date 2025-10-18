#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define max 5000

int rep = 0;
int k[max] = {0};

int is_pow2(unsigned int x){
    if (x == 0) {
        return 0;
    }
    return (x & (x - 1)) == 0;
}

int frozen() {
    for(int i=0;i<max;i++){
        if(is_pow2(k[i]))
            printf("%d, ",(int)log2(k[i]));
        if(is_pow2(k[i]))
            printf("%d, ",(int)k[i]);
    }
}

int primegame(double n) {
    int c[] = {17,78,19,23,29,77,95,77,1,11,13,15,1,55};
    int m[] = {91,85,51,38,33,29,23,19,17,13,11,2,7,1};
    int x=0;
    double tmp=0;
    for(int i=0;i<14;i++){
        if(rep>max) return 0;
        tmp = n*c[i]/m[i];
        if(tmp==(int)tmp){
            n = tmp;
            k[rep]=n;
            rep++;
            primegame(n);
        }else{
            x++;
            if(x==13) return 0;
        }
    }
}

int main() {
    double n = 2;
    printf("%d,",(int)n);
    primegame(n);
    frozen();
    return 0;
}
