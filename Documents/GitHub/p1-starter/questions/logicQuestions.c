//
//  logicQuestions.c
//  Projects
//
//  Created by John Mortensen on 9/21/19.
//  Copyright © 2019 Vo, Anthony. All rights reserved.
//

#include <stdio.h>
#include "questions.h"
#include "askQuestion.h"

int logicQuestionMaker(int negate, int arg1, char *operator, int arg2) { //function that creates logic questions based off of given paramters

    char question[80];
    char *true="TRUE";
    char *false="FALSE";

    // format args
    char *arg1Str = arg1 ? true : false;
    char *arg2Str = arg2 ? true : false;
    
    // format question
    if (negate)
        sprintf(question,"!(%s %s %s)", arg1Str, operator, arg2Str);  //question
    else
        sprintf(question,"(%s %s %s)", arg1Str, operator, arg2Str);  //question
    
    // supply choices
    char *choice[] = { true, false };

    // calculate answer
    int answer;
    if (strcmp(operator, "&&") == 0)   // note: equal strcmp returns 0
        answer = negate ? ( ! (arg1 && arg2) ) : (arg1 && arg2);
    else // (strcmp(operator, "||") == 0)
        answer = negate ? ( ! (arg1 || arg2) ) : (arg1 || arg2);

    return askQuestionTorF( question, answer, choice );
}

int logicQuestions(int questions)
{
    int score=0;
    char *operators[] = {"&&", "||"};
    int argOptions[4][2] = {
        {1,1},
        {1,0},
        {0,1},
        {0,0}
    };// random logic options

    char *operatorRand;
    int argRandom, arg1Rand, arg2Rand;
    int negateRand;
   
   srand((uint)time(0));
   
   for (int i = 0; i < questions; i++) {
       argRandom = rand() % 4;
       negateRand = rand() % 2;
       arg1Rand = argOptions[argRandom][0];   // 1 or 0
       operatorRand = operators[rand() % 2];
       arg2Rand = argOptions[argRandom][1];  // 1 or 0
       
       // scaffolding line below
       // printf("Not %d, Arg1 %d, Operator %s, Arg2 %d\n", negateRand, arg1Rand, operatorRand, arg2Rand);
       
       score += logicQuestionMaker(negateRand, arg1Rand, operatorRand, arg2Rand);
       
       // debug scaffolding - uncomment block to watch loop progress
       /*
        printf("counter %d / questions %d / score %d\n", i, questions, score);
        `   */
       
   } //asks random questions (i.e. random arguments and operators)
   
   return score;
}
