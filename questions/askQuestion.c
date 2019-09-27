//
//  scrambler.c
//  parameterFunctionQuestion(s)
//
//  Created by John Mortensen on 9/21/19.
//  Copyright © 2019 Vo, Anthony. All rights reserved.
//

#include "askQuestion.h"

void scrambler(double *choice, double *randomChoice)
{
    int scramble[]={0,0,0,0,0};
    srand((uint)time(0));
    
    for (int i=0, shutOff, randomizer; i < 5; i++) {
        shutOff = 0;
        do {
            // pick random number  from 0 to 3 and test if it unused
            randomizer = (rand() % 5) + 1;
            if (scramble[0] != randomizer && scramble[1] != randomizer && scramble[2] != randomizer && scramble[3] != randomizer  && randomizer != scramble[4] ){
                // scramble section
                randomChoice[randomizer-1] = choice[i];
                scramble[i] = randomizer;
                shutOff = 1;
            }
        } while (shutOff == 0) ;
    } //scramble  answers
    
    // debug scaffolding - uncomment block to see scrambled value ordering
    /*
     printf("1) %lf 2) %lf 3) %lf 4) %lf 5) %lf\n", choice[0], choice[1], choice[2], choice[3], choice[4]);
     printf("1) %d 2) %d 3) %d 4) %d 5) %d\n", scramble[0], scramble[1], scramble[2], scramble[3], scramble[4]);
     printf("1) %lf 2) %lf 3) %lf 4) %lf 5) %lf\n", randomChoice[0], randomChoice[1], randomChoice[2], randomChoice[3], randomChoice[4]);
     */
    
}

int  askQuestion(char *question, double answer, double *choice)
{
    double randomChoice[5];
    scrambler(&choice[0], &randomChoice[0]);
    
    int input;
    printf("%s\n", question);
    printf("1) %lf\n2) %lf\n3) %lf\n4) %lf\n5) %lf\n", randomChoice[0], randomChoice[1], randomChoice[2], randomChoice[3], randomChoice[4]);
    scanf("%d", &input); //ask question - display choices and receive input
    
    int score = 0;
    float epsilon = 0.01f;
    
    // debug scaffolding - uncomment block to see comparison
    /*
     printf("answer %lf - randomChoice %lf - epsilon %lf"\n, answer, randomChoice[input-1], fabs(randomChoice[input - 1] - answer));
     */
    
    if ( fabs(answer - randomChoice[input - 1])  < epsilon ) {
        score++;
        printf("Correct!\n");
    } else {
        printf("Incorrect\n");
    } //checks for correct answer
    
    return score; //returns points gained
}

int  askQuestionTorF(char *question, int answer, char *choice[] )
{
    int input;
    printf("%s\n", question);
    printf("1) %s\n2) %s\n", choice[0], choice[1] );
    scanf("%d", &input); //ask question - display choices and receive input
    
    int score = 0;
    if ( ( answer && input == 1)  || ( !answer && input == 2 ) ){
        score++;
        printf("Correct!\n");
    } else {
        printf("Incorrect\n");
    } //checks for correct answer
    
    return score; //returns points gained
}
