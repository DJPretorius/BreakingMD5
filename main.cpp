#include <iostream>
#include "md5.h"
#include <fstream>
#include <ctime>
#include <unordered_map>
#include <list>
#include "Reduction.h"

void savePairs(std::string fileName, std::list<std::pair<std::string, std::string>>* foundList, bool append = false);

int main() {
    time_t start;
    std::time(&start);
    std::ifstream hashesFile;
    std::string fileName = "HashedPassword(4-5-2017).txt";
    hashesFile.open(fileName , std::ios::in);
    if(!hashesFile.is_open()){
        std::cout << "File "<<fileName <<" was not opened"<< std::endl;
        return 1;
    }

    std::unordered_map<std::string,int> hashedMap;
    std::string word;
    int i=0;
    while(hashesFile >> word){
        hashedMap.insert({word,i++});
    }
    hashesFile.close();
//    std::cout<<hashedMap.size()<<std::endl;

    char alpha[26];
    for(char c = 'a'; c<='z'; c++){
        alpha[c-97]= c;
    }

    std::list<std::pair<std::string,std::string>> foundList;
    std::pair<std::string,std::string> foundPair;

    char wordLen1[1];
    for(int x = 0; x< 26; x++){
        wordLen1[0] = alpha[x];
        std::string hash = (md5(std::string(wordLen1)));
        size_t found = hashedMap.count(hash);
        if(found){
//            std::cout << wordLen1<<" "<<hash <<std::endl;
            foundPair.first = std::string(wordLen1);
            foundPair.second = hash;
            foundList.push_back(foundPair);
        }
    }
    savePairs("length1.txt",&foundList);
    char wordLen2[2] = {'a','a'};
    for(int x = 0; x< 2; x++){                      //Gebruik Wile loops
        for(int y = 0; y<26; y++){
            wordLen2[x] = alpha[y];
            std::string hash = (md5(std::string(wordLen2)));
            size_t found = hashedMap.count(hash);
            std::cout << wordLen2<<" "<<hash <<std::endl;
            if(found){
                foundPair.first = std::string(wordLen1);
                foundPair.second = hash;
                foundList.push_back(foundPair);
            }
        }
    }

//    Reduction red;
//    std::string out = red.reduce(1,5,foundPair.second);
//    std::cout<< out<<std::endl;



    time_t end;
    std::time(&end);
    std::cout << "Runtime: " <<difftime(end,start) << "s"<<std::endl;
    return 0;
}

void savePairs(std::string fileName, std::list<std::pair<std::string, std::string>>* foundList, bool append){
    std::ofstream foundPasswords;
    if(append){
        foundPasswords.open(fileName,std::ios::out | std::ios::app);
    }else{
        foundPasswords.open(fileName,std::ios::out);
    }
    std::list<std::pair<std::string, std::string>>::iterator it;

    for(it = foundList->begin(); it != foundList->end(); it++){
        foundPasswords << it->first <<" "<< it->second <<"\n";
    }
    foundPasswords.close();
}