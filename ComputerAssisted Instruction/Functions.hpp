//
//  Functions.hpp
//  Computer-Assisted Instruction
//
//  Created by Ahmed Ramy on 3/27/20.
//  Copyright © 2020 Ahmed Ramy. All rights reserved.
//

#ifndef Functions_hpp
#define Functions_hpp

#include <stdio.h>
#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

#endif /* Functions_hpp */

int randomNumber(int); // generate a random number depending on the difficulty provided
int multiply(int, int);
bool round(int, int, int);
bool feedback(int, int);
void finalResult(double, double, double);
void scoreBoard(double, double, double);
void restart(double &, double &, bool &); // initialized all variables to start over
void adjustScore(double &, double &, bool); // adjust the score
int chooseDifficulty(); // Choose the difficulty
int chooseProblem(); // Choose Arithmetic Problem
