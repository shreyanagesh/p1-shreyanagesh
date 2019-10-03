//
//  historama.c
//  Projects
//
//  Created by Nagesh, Shreya on 10/1/19.
//  Copyright © 2019 Vo, Anthony. All rights reserved.
//

#include "portfolio.h"
int historama(char *message) {
    
    int responses[10] = {0};
    int sum = 0;
    
    printf("Type in 10 numbers!: \n");
    for (int iter=0; iter < 10; iter++)
    {
        scanf("%i", &responses[iter]);
        sum = sum + responses[iter];
    }
    
    double average = sum/10;
    
    
    for (int i=0; i < 10; i++) {
        printf("%i: ", responses[i]);
        for (int ast=responses[i]; ast>0; ast--){
            printf("*");
        }
        printf("\n");
    }
    
    double remainder = (sum%10)/10;
    int printedaverage;
    
    if(remainder >= 0.5) {
        printedaverage = average - remainder + 1;
    } else {
        printedaverage = average - remainder;
    }
    
    
    sprintf(message, "Average: %lf", average);
    printf("%s", message);
    
    printf("\n %lf: ", average);
    while (printedaverage > 0) {
        printf("*");
        printedaverage--;
    }
    printf("\n");
    
    
    return average;
}
