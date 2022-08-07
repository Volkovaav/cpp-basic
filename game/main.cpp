#include "game.h"
#include "high_score.h"
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]){
    int max;
    if (argc==1){ gam(100);}
    else{
        for (int i=1; i<argc; i++){
            if((!strcmp(argv[i], "-max"))&&(i+1<argc)){
                max = std::atoi(argv[i+1]);
                gam(max);

            }
            if(!strcmp(argv[i], "-table")){
                res();
            }
        }
    }
    return 0;
}
