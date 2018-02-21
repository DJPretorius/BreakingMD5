//
// Created by Niel on 2018/02/20.
//

#include <cstring>
#include "Reduction.h"

std::string reduce1(std::string hash, int length);

std::string Reduction::reduce(int num, int length, std::string hash) {
    switch (num){
        case 1: return reduce1(hash,length);

        case 2:
            break;
        default: break;
    }
}

std::string reduce1(std::string hash, int length){
    char c_hash[hash.length() +1];
    std::strcpy(c_hash, hash.c_str());
    char letter[1];
    char newWord[length + 1];
    for(int i=1; i<= length; i++){
        std::strncpy(letter,c_hash,i);
        int num = letter[0];
        std::strncpy(letter,c_hash,i+1);
        num += letter[0];
        num = num %(122 - 97 +1) + 97;
        newWord[i-1] = (char)num;

    }
    newWord[length] = '\0';
    std::string toReturn (newWord);
    return toReturn;

}