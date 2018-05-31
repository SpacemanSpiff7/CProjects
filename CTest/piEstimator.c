//
//  piEstimator.c
//  CTest
//
//  Created by Simone Longo on 5/31/18.
//  Copyright © 2018 Simone Longo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double side;
//int numPts = 10000;

/* Return random number between [-side/2, +side/2] */
double genRand() {
    double rn = (double) (side / 2) * rand()/RAND_MAX;
    return rn;
}

double getRad() {
    double x = genRand();
    double y = genRand();
    
    return sqrt(x*x + y*y);
}

int main(int argc, const char * argv[]) {
    side = atof(argv[1]);
    int numPts = atoi(argv[2]);
    double rad = side / 2;
    int inCount = 0;
    
    for (int i = 0; i < numPts; i++) {
        if (getRad() < rad) {
            inCount++;
        }
    }
    
    printf("%d points inside out of %d attempts\n", inCount, numPts);
    
    double pi = ((double) inCount) / ((double) numPts) * 4.0;
    printf("pi is approximately %f\n\n", pi);
    
    return 0;
}


