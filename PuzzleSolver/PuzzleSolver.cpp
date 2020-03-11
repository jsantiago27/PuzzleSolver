//
//  PuzzleSolver.cpp
//  PuzzleSolver
//
//  Created by Jefferson Santiago on 3/6/20.
//  Copyright © 2020 Jefferson Santiago. All rights reserved.
//

#include "PuzzleSolver.hpp"
#include <iostream>
#include <string.h>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

PuzzleSolver::PuzzleSolver() {
    
}

PuzzleSolver::PuzzleSolver(const char* puzzleFile, const char* keywordFile) : PuzzleReader{puzzleFile} {

    std::cout << "Reading Inputs : " << keywordFile << " file" << std::endl;
    std::string word;
    std::ifstream keyWord(keywordFile);
    while(!std::getline(keyWord, word, '\n').eof()) {
        transform(word.begin(), word.end(), word.begin(), ::toupper);
        keyWords.push_back(KeyWords(word, false));
    }
}


PuzzleSolver::~PuzzleSolver() {
    
}


void PuzzleSolver::showKeyWords() {
    std::cout << "Keyword\t | \t Solved?" << std::endl;
    for(int i = 0 ; i < keyWords.size() ; i++) {
        std::cout << keyWords[i].keyword << "\t | \t " << (keyWords[i].isSolve ? "Solved" : "Not Solved") << std::endl;
    }
}
/*
void PuzzleSolver::solvePuzzle() {
    int current_i = 0, current_j = 0;
    int prev_i = 0, prev_j = 0;
    int currCharPos = 0;
    bool charMatched = false;
    
    for(int i = 0 ; i < keyWords.size() ; i++)
    {
        int keyWordLength = (int)keyWords[i].keyword.length();
        prev_i = current_i;
        prev_j = current_j;
        
        while(true) {
            if(current_i >= rows && !charMatched) {
                break;
            }
            if(current_j >= columns) {
                current_i++;
                current_j = 0;
            }
            if(charMatched && currCharPos >= keyWordLength) {
                keyWords[i].isSolve = true;
                break;
            }
            if(currCharPos >= keyWordLength && charMatched == false) {
                keyWords[i].isSolve = false;
                break;
            }
    
            std::string temp(1, puzzle[(rows*current_i) + current_j]);
            std::cout << "Checking if word " << keyWords[i].keyword << " is in the puzzle" << std::endl;
            std::cout << "Comparing " << keyWords[i].keyword[currCharPos] << " to " << temp << std::endl;
            if(keyWords[i].keyword.at(currCharPos) == puzzle[(rows*current_i) + current_j]) {
                currCharPos++;
                if(current_i < rows && current_j < columns) { // bottom right
                    int tempi = current_i + 1;
                    int tempj = current_j + 1;
                    if(keyWords[i].keyword.at(currCharPos) == puzzle[(rows*tempi) + tempj]) {
                        std::cout << "1. Comparing: " << keyWords[i].keyword[currCharPos] <<  " to " << puzzle[(rows*tempi) + tempj] << std::endl;
                        currCharPos++;
                        current_i = tempi;
                        current_j = tempj;
                        charMatched = true;
                        continue;
                    }
                }
    
                if(current_i > 1 && current_j < columns) {  // top right
                    int tempi = current_i - 1;
                    int tempj = current_j + 1;
                    if(keyWords[i].keyword.at(currCharPos) == puzzle[(rows*tempi) + tempj]) {
                        std::cout << "2. Comparing: " << keyWords[i].keyword[currCharPos] <<  " to " << puzzle[(rows*tempi) + tempj] << std::endl;
                        currCharPos++;
                        current_i = tempi;
                        current_j = tempj;
                        charMatched = true;
                        continue;
                    }
                }
    
                 else if(current_i > 1 && current_j > 1) {  // top left
                    int tempi = current_i - 1;
                    int tempj = current_j - 1;
                    if(keyWords[i].keyword.at(currCharPos) == puzzle[(rows*tempi) + tempj]) {
                        std::cout << "3. Comparing: " << keyWords[i].keyword[currCharPos] <<  " to " << puzzle[(rows*tempi) + tempj] << std::endl;
                        currCharPos++;
                        current_i = tempi;
                        current_j = tempj;
                        charMatched = true;
                        continue;
                    }
                }
    
                if(current_i < rows && current_j > 1) {  // bottom left
                    int tempi = current_i + 1;
                    int tempj = current_j - 1;
                    if(keyWords[i].keyword.at(currCharPos) == puzzle[(rows*tempi) + tempj]) {
                        std::cout << "4. Comparing: " << keyWords[i].keyword[currCharPos] <<  " to " << puzzle[(rows*tempi) + tempj] << std::endl;
                        currCharPos++;
                        current_i = tempi;
                        current_j = tempj;
                        charMatched = true;
                        continue;
                    }
                }
    
    
                if(current_j < columns) { // right
                    int temp = current_j + 1;
                    if(keyWords[i].keyword.at(currCharPos) == puzzle[(rows*current_i) + temp]) {
                        std::cout << "5. Comparing: " << keyWords[i].keyword[currCharPos] <<  " to " <<  puzzle[(rows*current_i) + temp] << std::endl;
                        currCharPos++;
                        current_j = temp;
                        charMatched = true;
                        continue;
                    }
                }
                if(current_j > 1) { // left
                    int temp = current_j - 1;
                    if(keyWords[i].keyword.at(currCharPos) == puzzle[(rows*current_i) + temp]) {
                        std::cout << "6. Comparing: " << keyWords[i].keyword[currCharPos] <<  " to " <<  puzzle[(rows*current_i) + temp] << std::endl;
                        currCharPos++;
                        current_j = temp;
                        charMatched = true;
                        continue;
                    }
                }
                
                if(current_i > 1) { // top
                    int temp = current_i - 1;
                    if(keyWords[i].keyword.at(currCharPos) == puzzle[(rows*temp) + current_j]) {
                        std::cout << "7. Comparing: " << keyWords[i].keyword[currCharPos] <<  " to " << puzzle[(rows*temp) + current_j] << std::endl;
                        currCharPos++;
                        current_i = temp;
                        charMatched = true;
                        continue;
                    }
                }
    
                 if(current_i < rows) { // bot
                    int temp = current_i + 1;
                    std::string tempChar(1, puzzle[(rows*temp) + current_j]);
                    if(keyWords[i].keyword.at(currCharPos) == puzzle[(rows*temp) + current_j]) {
                        std::cout << "8. Comparing: " << keyWords[i].keyword[currCharPos] <<  " to " <<  puzzle[(rows*temp) + current_j] << std::endl;
                        currCharPos++;
                        current_i = temp;
                        charMatched = true;
                        continue;
                    }
                }

                std::cout << "9. Character doesnt match" << std::endl;
                current_j++;
                current_i = prev_i;
                charMatched = false;
                currCharPos = 0;
                continue;
            }
            else {
                std::cout << "2. Character doesnt match" << std::endl;
                std::cout << "Current j: " << current_j << " and current_i: " << current_i << std::endl;
                current_j++;
                current_i = prev_i;
                charMatched = false;
                currCharPos = 0;
                continue;
            }
        }
        std::cout << "Current j: " << current_j << " and current_i: " << current_i << std::endl;
    }
}
*/
void PuzzleSolver::solvePuzzle() {
    for(int i = 0 ; i < keyWords.size() ; i++) {
        int keyWordLength = (int)keyWords[i].keyword.length();
        std::string tempword;
        for(int k = 0 ; k < rows ; k ++) {
            for(int l = 0 ; l < columns ; l++) {
                for(int j = 0 ; j < keyWordLength ; j++) { // check bot
                    if((k+keyWordLength) <= rows) {
                        std::string temp(1, puzzle[(rows*(k + j)) + l]);
                        tempword.append(temp);
                    }
                }
                 //std::cout<< "Bottom Word: " << tempword << std::endl;
                if(tempword.compare(keyWords[i].keyword) == 0) {
                   
                    keyWords[i].isSolve = true;
                }
                tempword.clear();
                
                for(int j = 0 ; j < keyWordLength ; j++) { // check left
                    if((l-keyWordLength + 1) >= 0) {
                        std::string temp(1, puzzle[(rows*k) + (l-j)]);
                        tempword.append(temp);
                    }
                }
                 //std::cout<< "Left Word: " << tempword << std::endl;
                if(tempword.compare(keyWords[i].keyword) == 0) {
                    keyWords[i].isSolve = true;
                }
                tempword.clear();
    
        
                for(int j = 0 ; j < keyWordLength ; j++) { // check right
                   if((l+keyWordLength) <= columns) {
                       std::string temp(1, puzzle[(rows*k) + (l+j)]);
                       tempword.append(temp);
                   }
                }
                 //std::cout<< "Right Word: " << tempword << std::endl;
                if(tempword.compare(keyWords[i].keyword) == 0) {
                    keyWords[i].isSolve = true;
                }
    
                tempword.clear();
        
                for(int j = 0 ; j < keyWordLength ; j++) { // check top
                   if((k-keyWordLength + 1) >= 0) {
                        std::string temp(1, puzzle[(rows*(k - j) + 1) + l]);
                        tempword.append(temp);
                   }
                }
                //std::cout<< "Top Word: " << tempword << " Compared to " << keyWords[i].keyword << std::endl;
                if(tempword.compare(keyWords[i].keyword) == 0) {
                    keyWords[i].isSolve = true;
                }
                    
                tempword.clear();
    
                for(int j = 0 ; j < keyWordLength ; j++) { // check bottom right
                    if((k+keyWordLength) <= rows && (l+keyWordLength) <= columns) {
                        std::string temp(1, puzzle[(rows*(k + j)) + (l+j)]);
                        tempword.append(temp);
                        
                   }
                }
                //std::cout<< "Bottom Right Word: " << tempword << "Compared to " << keyWords[i].keyword << std::endl;
                if(tempword.compare(keyWords[i].keyword) == 0) {
                    keyWords[i].isSolve = true;
                }
    
                tempword.clear();
    
                for(int j = 0 ; j < keyWordLength ; j++) { // check top left
                    if((k-keyWordLength + 1) >= 0 && (l-keyWordLength  + 1) >= 0) {
                       std::string temp(1, puzzle[(rows*(k - j) + 1) + ((l - j))]);
                       tempword.append(temp);
                   }
                }
                //std::cout<< "Top Left Word: " << tempword << " Compared to " << keyWords[i].keyword << std::endl;
                if(tempword.compare(keyWords[i].keyword) == 0) {
                    keyWords[i].isSolve = true;
                }
                
                tempword.clear();
    
                for(int j = 0 ; j < keyWordLength ; j++) { // check top right
                    if((k-keyWordLength) >= 0 && (l+keyWordLength) <= columns) {
                       std::string temp(1, puzzle[(rows*(k - j)) + (l + j)]);
                       tempword.append(temp);
                   }
                }
                 //std::cout<< "Top Right Word: " << tempword << std::endl;
                if(tempword.compare(keyWords[i].keyword) == 0) {
                    keyWords[i].isSolve = true;
                }
                tempword.clear();
    
                for(int j = 0 ; j < keyWordLength ; j++) { // check bot left
                    if((k+keyWordLength) <= rows && (l-keyWordLength + 1) >= 0) {
                       std::string temp(1, puzzle[(rows*(k + j)) + (l-j)]);
                       tempword.append(temp);
                   }
                }
                 //std::cout<< "Bottom Left Word: " << tempword << std::endl;
                if(tempword.compare(keyWords[i].keyword) == 0) {
                    keyWords[i].isSolve = true;
                }
    
                tempword.clear();
            }
        }
    }
}

