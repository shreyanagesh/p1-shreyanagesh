//
//  mathQuestions.c
//  parameterFunctionQuestion(s)
//
//  Created by John Mortensen on 9/21/19.
//  Copyright © 2019 Vo, Anthony. All rights reserved.
//

#include "questions.h"
#include "askQuestion.h"

int mathQuestionMaker(double arg1, char operator, double arg2) { //function that creates math questions based off of given paramters
    char question[80];
    
    sprintf(question,"%lf %c %lf is?", arg1, operator, arg2);  //question
    
    double answer = 0.0;
    switch (operator) {
        case '+':
            answer = arg1 + arg2;
            break;
        case '-':
            answer = arg1 - arg2;
            break;
        case '/':
            answer = arg1 / arg2;
            break;
        case '*':
            answer = arg1 * arg2;
            break;
        case '%':
            answer = (double)((int)arg1 % (int)arg2);
            break;
    } //correct answer is based off of operator
    
    double choice[] = {
        arg1 + arg2,
        arg1 - arg2,
        arg1 / arg2,
        arg1 * arg2,
        (double)((int)arg1 % (int)arg2)
    }; //make other choices for question
    
    return askQuestion(question, answer, choice);
    
}

int mathQuestions(int questions)
{
    int score=0;
    char operators[] = {'+', '-', '/', '*', '%'};
    char operatorRand;
    int arg1Rand, arg2Rand;
    
    srand((uint)time(0));
    
    for (int i = 0; i < questions; i++) {
        arg1Rand = rand() % 20 +3;
        operatorRand = operators[rand() % 5];
        do {
            arg2Rand = (rand() % 20) +3;  // Avoid zero (1/0), Avoid simple math and dups (2*2)/(2+2) dangerous (1/0)
        } while (arg1Rand == arg2Rand);   // Avoid dups (8-8)/(8%8)
        
        score += mathQuestionMaker(arg1Rand, operatorRand, arg2Rand);
        
        // debug scaffolding - uncomment block to watch loop progress
        /*
        printf("counter %d / questions %d / score %d\n", i, questions, score);
    `   */
        
    } //asks random questions (i.e. random arguments and operators)
    
    return score;
}
