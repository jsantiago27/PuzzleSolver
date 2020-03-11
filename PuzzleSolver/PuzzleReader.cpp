//
//  PuzzleReader.cpp
//  PuzzleSolver
//
//  Created by Jefferson Santiago on 3/6/20.
//  Copyright © 2020 Jefferson Santiago. All rights reserved.
//

#include "PuzzleReader.hpp"
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <vector>

PuzzleReader::PuzzleReader(){
    
}


PuzzleReader::PuzzleReader(const char* puzzleFile) {
    
    std::cout << "Reading puzzle inputs in : " << puzzleFile << std::endl;
    
    std::ifstream infile(puzzleFile);
    std::string word;
    while (!std::getline(infile, word, '\n').eof())
    {
        std::stringstream ss(word);
        while(std::getline(ss, word, ' ')) {
              wordList.push_back(word);
        }
    }
    rows = stoi(wordList[0]);
    columns = stoi(wordList[1]);
    
    for(int i = 0 ; i < rows ; i++) {
        char buf[2];
        for(int j = 0 ; j < columns ; j++) {
            wordList[((rows)*i)+ j + 2].copy(buf, 1, 0);
            puzzle.push_back(*buf);
            buf[1] = '\0';
        }
    }
}
PuzzleReader::PuzzleReader(std::vector<char> puzzle) {
    this->puzzle = puzzle;
}

PuzzleReader::PuzzleReader(std::vector<char> puzzle, int row, int col) {
    this->puzzle = puzzle;
    this->rows = row;
    this->columns = col;
}

PuzzleReader::~PuzzleReader() {
    
}

void PuzzleReader::showPuzzle() {
    std::vector<char> currPuzzle = this->puzzle;
    
#ifdef DEBUG_MODE
    std::cout << "showing puzzle" << std::endl;
#endif
    
    for(int i = 0 ; i < rows ; i++) {
        for(int j = 0 ; j < columns ; j++) {
            std::cout << currPuzzle[ (rows * i) + j ] << " " ;
        }
        std::cout << std::endl;
    }
}
