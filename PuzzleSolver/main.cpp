//
//  main.cpp
//  PuzzleSolver
//
//  Created by Jefferson Santiago on 3/6/20.
//  Copyright © 2020 Jefferson Santiago. All rights reserved.
//
/*
 Plan:
    In Progress:
        - Creating a Puzzle Reader
        - Output Puzzle
    
 
    In Plan:
        - Puzzle Solve
        - Read Keywords
        -
 
 
 
 
 */
#define DEBUG_MODE

#include <iostream>
#include <string>
#include "PuzzleSolver.hpp"

int main(int argc, const char * argv[]) {
    PuzzleSolver* puzzle = new PuzzleSolver("Puzzle.txt", "KeyWords.txt");
    puzzle->showKeyWords();
    puzzle->showPuzzle();
    
    puzzle->solvePuzzle();
    
    puzzle->showKeyWords();
    
    std::cout << char(0x00002196) << std::endl;
    
    delete puzzle;
    return 0;
}
