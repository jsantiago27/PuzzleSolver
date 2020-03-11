//
//  PuzzleSolver.hpp
//  PuzzleSolver
//
//  Created by Jefferson Santiago on 3/6/20.
//  Copyright © 2020 Jefferson Santiago. All rights reserved.
//

#ifndef PuzzleSolver_hpp
#define PuzzleSolver_hpp

#include "PuzzleReader.hpp"
#include <stdio.h>
#include <vector>
#include <fstream>

class PuzzleSolver : public PuzzleReader {
    
private:
    
    struct KeyWords {
        public:
            std::string keyword;
            bool isSolve;
        
            KeyWords(std::string keyword, bool isSolve) {
                this->keyword = keyword;
                this->isSolve = isSolve;
            }
    };
    
    std::vector<struct KeyWords> keyWords;
    
    
    
public:
    PuzzleSolver();
    PuzzleSolver(const char* puzzleFile, const char* keywordFile);
    ~PuzzleSolver();
    
    void showKeyWords();
    void solvePuzzle();
    
};
#endif /* PuzzleSolver_hpp */
