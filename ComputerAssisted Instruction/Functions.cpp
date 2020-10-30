//
//  Functions.cpp
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

int randomNumber(int level)
{
    long srand(time(0));
    switch (level) {
        case 1:
            return (rand() % 10 );
            break;
        case 2:
            return (rand() % 100);
            break;
        case 3:
            return (rand() % 1000);
            break;
        default:
            return (rand() % 10 );
            break;
    }
    
}

bool round(int first, int second, int problem) // takes in two random number and start a round
{
    int correctAnswer;
    
    switch (problem) {
        case 1:
            correctAnswer = first + second;
            break;
        case 2:
            correctAnswer = first - second;
            break;
        case 3:
            correctAnswer = multiply(first, second);
            break;
        case 4:
            correctAnswer = first / second;
            break;
        default:
            correctAnswer = first + second;
            break;
    }
    
    int userAnswer;
    switch (problem) {
        case 1:
            cout << "How much is " << first << " plus " << second << "?";
            break;
        case 2:
            cout << "How much is " << first << " minus " << second << "?";
            break;
        case 3:
            cout << "How much is " << first << " time " << second << "?";
            break;
        case 4:
            cout << "How much is " << first << "divided" << second << "?";
            break;
        default:
            cout << "How much is " << first << " time " << second << "?";
            break;
    }
    cin >> userAnswer;
    
    return feedback(userAnswer, correctAnswer);
    
}


int multiply(int first, int second) // takes in two numbers and multiplies them
{
    return first * second;
}

bool feedback(int userAnswer, int correctAnswer)
{
    if(userAnswer == correctAnswer)
    {
        long srand(time(0));
        int correct = (rand() % 4) + 1;
        switch (correct) {
            case 1:
                cout << "Very good!" << endl;
                break;
            case 2:
                cout << "Excellent!" << endl;
                break;
            case 3:
                cout << "Nice work!" << endl;
                break;
            case 4:
                cout << "Keep up the good work" << endl;
                break;
            default:
                cout << "The program should never reach this stage" << endl;
                break;
        }
        return true;
    }
    else
    {
        long srand(time(0));
        int wrong = (rand() % 4) + 1;
        switch (wrong) {
            case 1:
                cout << "No. Please try again." << endl;
                break;
            case 2:
                cout << "Wrong. Try once more" << endl;
                break;
            case 3:
                cout << "Don't give up!" << endl;
                break;
            case 4:
                cout << "No. Keep trying." << endl;
                break;
            default:
                cout << "The program should never reach this stage" << endl;
                break;
        }
        return false;
    }
}

void finalResult(double correct, double wrong, double attempts)
/*
 Takes number of correct, wrong answers and returns a feedback to the user
 */
{
    cout << setprecision(2) << fixed;
    
    double percentage =  static_cast<double>(correct / attempts) * 100 ;
    if (percentage >= 75 )
    {
        scoreBoard(correct, wrong, attempts);
        cout << "\nCongratulations, you are ready to go to the next level!" << endl;
    }
    else
    {
        scoreBoard(correct, wrong, attempts);
        cout << "\nPlease ask your teacher for extra help." << endl;
    }
}

void scoreBoard(double correct, double wrong, double attempts) // Show the user The score board
{
    cout << setw(10) << "\n\n\t" << correct << "/" << attempts << endl;
    cout << "\t" << setprecision(2) << static_cast<double>((correct / attempts) * 100) << "%" << endl;
}

void restart(double &correct, double &wrong, bool &answer)
{
    correct = 0;
    wrong = 0;
    answer = true;
}

void adjustScore(double &correct, double &wrong, bool answer)
{
    if ( answer == true)
    {
        correct += 1;
    }
    else
    {
        wrong += 1;
    }
}

int chooseDifficulty()
{
    int level;
    cout << "Enter a difficulty level: \n"
    << "1.Easy\n"
    << "2.Medium\n"
    << "3.Hard";
    cin >> level;
    return level;
}

int chooseProblem()
{
    int arithmeticProblem;
    cout << "Choose an arithmetic problem to study\n"
    << "1.Addition\n"
    << "2.Subtraction\n"
    << "3.Multiplication\n"
    << "4.Division";
    cin >> arithmeticProblem;
    
    return arithmeticProblem;
}
