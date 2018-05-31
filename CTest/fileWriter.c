//
//  fileWriter.c
//  CTest
//
//  Created by Simone Longo on 5/31/18.
//  Copyright © 2018 Simone Longo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

long factorial(int n){
    long result = 1;
    while((n) > 0){
        result *= n;
        n--;
    }
    return result;
}

long nCk(int n, int k){
    long nck = factorial(n)/(factorial(n-k)*factorial(k));
    return nck;
}

int main(int argc, const char * argv[]){
    FILE *fp;
    fp = fopen("pascalTriangle.txt", "w");
    
    int lines = atoi(argv[1]);
    
    for (int i = 0; i < lines; i++){
        int tabNum = lines - i;
        for (int j = 0; j < tabNum; j++) {
            printf(" ");
            fprintf(fp, " ");
        }
        for (int k = 0; k <= i; k++){
            long res = nCk(i, k);
            printf("%ld ", res);
            fprintf(fp, "%ld ", res);
        }
        fprintf(fp, "\n");
        printf("\n");
    }
    fclose(fp);
    return 0;
}
