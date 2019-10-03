//
//  main.c
//  pythagoraslab
//
//  Created by Nagesh, Shreya on 9/13/19.
//  Copyright © 2019 Nagesh, Shreya. All rights reserved.
//

#include "portfolio.h"


// defining and declaring function
double computeHypotenuse(double a, double b)
{
    double hyp = 0.0;
    hyp = sqrt(a*a + b*b); // this is the formula to find hypotenuse
    return hyp;
}

// main
int pythagorean(void) {
    double a, b, c = 0.0; // initializing values
    printf("Choose 'a' value"); //this is asking for side length a
    scanf("%lf",&a); // outputs value double
    printf("Choose 'b' value"); // this is asking for side length b
    scanf("%lf",&b); // outputs value double
    
    
    c = computeHypotenuse(a, b); // invokes the function
    
    
    printf("hypotenuse value: %lf", c); // this is asking for the hypotenuse value
    
    return 0;
    
}

