#include "high_score.h"
#include <iostream>
#include <fstream>

void score(std::string name,int result){
    std::ofstream out ("high_score.txt", std::ios::app);
    out << name <<" "<<result << std::endl;
}

void res(){
    const int MAXLEN_STR = 50; 
    const int ROW_COUNT = 100;
    char S[ROW_COUNT][MAXLEN_STR];
    int str_num = 0; 
    std::ifstream in("high_score.txt");
        while (!in.eof()){
          in.getline(S[str_num++], MAXLEN_STR);
        }
    in.close();
    for (int i=0; i<str_num; i++){
        std::cout << S[i] << std::endl;
    }
}


