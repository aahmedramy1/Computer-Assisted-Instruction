//
//  main.cpp
//  Computer-Assisted Instruction
//
//  Created by Ahmed Ramy on 3/27/20.
//  Copyright © 2020 Ahmed Ramy. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <iomanip>
#include "Functions.hpp"

using namespace std;



int main() {
    
    // initializing the program
    bool answer = true;
    
    // random numbers
    int first = 0;
    int second = 0;
    
    // player's Score
    double correct = 0;
    double wrong = 0;
    
    // Amount of attempts available for the user
    double maximumAttempts = 10;
    
    // User Settings
    int level;
    int arithmeticProblem;
    
    
    while(true)
    {
        
        // User choose problem to practice
        arithmeticProblem = chooseProblem();
        
        // User Choose Difficulty
        level = chooseDifficulty();
        
        for(int counter = 1 ;counter <= maximumAttempts; counter++) // loop for the maximum Attemps per round
        {
            
            
            if (answer) // if answer is correct 2 new numbers are generated
            {
                first = randomNumber(level);
                second = randomNumber(level);
            } // end if
            
            answer = round(first, second, arithmeticProblem);
            adjustScore(correct, wrong, answer);
            
            if ( counter == 10)
            {
                finalResult( correct, wrong, maximumAttempts);
            }
            
        } // end for loop
        restart(correct, wrong, answer);
    } // end while 
    

} // end main





