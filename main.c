//
//  main.c
//  Menu control
//
//  Created by John Mortensen on 9/21/19.
//  Copyright © 2019 Mortensen, John. All rights reserved.
//

//C libraries
#include <stdio.h>
#include <string.h>

//function protypes
#include "portfolio.h"
#include "questions.h"

int main(int argc, const char * argv[]) {
    int menuItems = 10;                             // Number of menu items
    int maxMsgLength = 80;                          // Fixed message length
    int menuRun[] = {0,0,0,0,0,0,0,0,0,0};          // 10 array positions initialized
    char runMsg2D[menuItems][maxMsgLength];         // 2D array ie 10x80
    char *notRun = "Not Run";
    
    for (int exitflag = 0; !exitflag; ) {
        printf("\n"); // provide space after previous lab
        printf("----------------------------------------\n");
        printf("||      MENU SELECTION PORTFOLIO      ||\n");
        printf("|--------------------------------------|\n");
        printf("|Options:                   Run Status:| %d of %d\n", menuRun[0], menuItems);
        printf("|  1. Jumpers                          | %s\n", (menuRun[1] ? runMsg2D[1] : notRun) );
        printf("|  2. Pythagorean Theorem              | %s\n", (menuRun[2] ? runMsg2D[2] : notRun) );
        printf("|  3. Data Types and IO                | \n");
        printf("|  4. Rectangle Area & Perm.           | \n");
        printf("|  5. Temperature Converter            | \n");
        printf("|  6. Seconds Calculator               | \n");
        printf("|  7. Array Code                       | \n");
        printf("|  8. Pretty Patterns                  | \n");
        printf("|  9. Test Questions                   | %s\n", (menuRun[9] ? runMsg2D[9] : notRun) );
        printf("| 10. Historama                        | \n");
        printf("| 99. Exit                             | \n");
        printf("| Select number you would like to run: |\n");
        printf("----------------------------------------\n");
        
        
        for ( int input = 0; !input; ) { //switch control loop
            
            //user input
            scanf("%d", &input);
            
            //menu action
            switch(input) { // switch verifies input and calls function for selected Menu Item
                case 1:
                    // function: jumpers performs nursery ryme
                    // param: runMsg2D[] is updated through function call
                    // returns: >=0 number of jumps, <0 if failure
                    menuRun[input] = jumpers(runMsg2D[input]);
                    break;
                case 2:
                    /* pytahgoraslives(); */
                    // Not implemented
                    // setup to strcpy updating runMsg2D[]
                    strcpy(runMsg2D[input], "pythagorean pressed");
                    menuRun[input] = pythagorean();
                    menuRun[input] = 1;
                    break;
                case 3:
                    //datatypes();
                    break;
                case 4:
                    menuRun[input] = rectangle(runMsg2D[input]);
                    //rectanglelab();
                    break;
                case 5:
                    //temperaturelab();
                    break;
                case 6:
                    //secondscalc();
                    break;
                case 7:
                    //arraycode();
                    break;
                case 8:
                    menuRun[input] = prettypatterns(runMsg2D[input]);
                    //prettypatterns();
                    break;
                case 9:
                    // function: questionManager drives logic for Test Questions
                    // param: runMsg2D[] is updated through function call
                    // returns: >=0 questions run, <0 if failure
                    menuRun[input] = questionDriver(runMsg2D[input]);
                    break;
                case 10:
                    menuRun[input] = historama(runMsg2D[input]);
                    //historama();
                case 99:
                    exitflag = 1;
                    break;
                default:
                    printf("invalid input, try again\n");
                    break;
                    
            }//end of switch
            
            if (!exitflag && menuRun[input]) {
                menuRun[0]++;
            }//updates "Run Status"
            
        }//end of switch control loop
        
    }//end menu control loop
    
    return 0;
}
