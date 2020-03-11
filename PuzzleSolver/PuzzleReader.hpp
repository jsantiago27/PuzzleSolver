//
//  PuzzleReader.hpp
//  PuzzleSolver
//
//  Created by Jefferson Santiago on 3/6/20.
//  Copyright © 2020 Jefferson Santiago. All rights reserved.
//

#ifndef PuzzleReader_hpp
#define PuzzleReader_hpp

#include <stdio.h>
#include <string>
#include <vector>


class PuzzleReader {
private:
    std::vector<std::string> wordList;
    
protected:
    int rows;
    int columns;
    //char** puzzle;
    std::vector<char> puzzle;
    
public:
    PuzzleReader();
    PuzzleReader(const char* puzzleFile);
    PuzzleReader(std::vector<char> puzzle);
    PuzzleReader(std::vector<char> puzzle, int row, int col);
    virtual ~PuzzleReader();
    void showPuzzle();
    
};

#endif /* PuzzleReader_hpp */
