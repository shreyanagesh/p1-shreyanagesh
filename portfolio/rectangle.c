//
//  rectangle.c
//  Projects
//
//  Created by Nagesh, Shreya on 10/1/19.
//  Copyright © 2019 Vo, Anthony. All rights reserved.
//


/*
 * C Program to calculate area & perimeter of a rectangle and area & circumference of a circle
 */
#include<stdio.h>
#include "portfolio.h"

int rectangle(char *message) {
    int length, width, area,perimeter;
    
    printf ("Let's find the area and perimeter of a rectangle!");
    
    printf("\nEnter the Length of Rectangle : ");
    scanf("%d", &length);
    
    printf("\nEnter the Width of Rectangle : ");
    scanf("%d", &width);
    
    area = length * width;
    
    perimeter=2*(length+width);
    
    printf("\nArea of Rectangle : %d", area);
    
    printf("\nPerimeter of Rectangle : %d", perimeter);
    
    {
        
        int rad;
        float PI=3.14,area,ci;
        
        printf ("\nLet's find the area and circumference of a circle!");
        printf("\nEnter radius of circle: ");
        scanf("%d",&rad);
        
        area = PI * rad * rad;
        printf("\nArea of circle : %f ",area);
        
        ci = 2 * PI * rad;
        printf("\nCircumference : %f ",ci);
        
        return(0);
    }
    return (0);
}
