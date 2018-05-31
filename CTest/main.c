//
//  main.c
//  CTest
//
//  Created by Simone Longo on 5/31/18.
//  Copyright © 2018 Simone Longo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

long factorial(int);
long nCk(int, int);
long nPk(int, int);

int main(int argc, const char * argv[]) {
    int n, k;
    long nck, npk;
    
    n = atoi(argv[1]);
    k = atoi(argv[2]);
    
    if (k > n){
        printf("Invalid arguments/n");
        exit(0);
    }
    
    nck = nCk(n, k);
    npk = nPk(n, k);
    //printf("%d! = %ld\n\n", n, factorial(n));
    printf("%d choose %d equals %ld\n\n", n, k, nck);
    printf("%d nPk %d equals %ld\n", n, k, npk);
    return 0;
}

long nCk(int n, int k){
    long nck = factorial(n)/(factorial(n-k)*factorial(k));
    return nck;
}

long nPk(int n, int k){
    long npk = factorial(n)/factorial(n-k);
    return npk;
}

long factorial(int n){
    long result = 1;
    while((n) > 0){
        result *= n;
        n--;
    }
    return result;
}
