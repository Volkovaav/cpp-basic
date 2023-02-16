#include <iostream>

class game{
    char field[9];
    public:
    game(){
        for (int i=0; i<9; i++){
            field[i] = '-';
        }
    }
    int start_menu(){
        std::cout<<"Welcome!"<<std::endl;
        std::cout<<"1. Game with players"<<std::endl;
        std::cout<<"2. Game with computer"<<std::endl;

        int point;

        std::cin>>point;
        switch (point)
        {
        case (1):
            game_player();
            return 0;
        
        default:
            return 0;
        }

    }
    void print_field(){

        std::cout<<"|"<<0<<"|"<<1<<"|"<<2<<"|"<<std::endl;
        std::cout<<"|"<<3<<"|"<<4<<"|"<<5<<"|"<<std::endl;
        std::cout<<"|"<<6<<"|"<<7<<"|"<<8<<"|"<<std::endl<<std::endl;

        std::cout<<"|"<<field[0]<<"|"<<field[1]<<"|"<<field[2]<<"|"<<std::endl;
        std::cout<<"|"<<field[3]<<"|"<<field[4]<<"|"<<field[5]<<"|"<<std::endl;
        std::cout<<"|"<<field[6]<<"|"<<field[7]<<"|"<<field[8]<<"|"<<std::endl;
    }
    int game_player(){
        std::string player[2];

        std::cout<<"Enter player`s 1 name"<<std::endl;
        std::cin>>player[0];

        std::cout<<"Enter player`s 2 name"<<std::endl;
        std::cin>>player[1];

        int player_number = 0;
        print_field();
        for (int count = 0; count<9; count++){
            if((winner('x'))||(winner('o'))){
                std::cout<<"Congratulations! Won "<<player[player_number]<<"!"<<std::endl;
                return 0;
            }
            
            player_number = step(player[player_number], player_number);
            print_field();
        }
        std::cout<<"Draw!"<<std::endl;
        return 0;
    }
    bool winner(char val){
        if ((field[0]==val)&&(field[1]==val)&&(field[2]==val)){
            return true;
        }
        else if ((field[3]==val)&&(field[4]==val)&&(field[5]==val)){
            return true;
        }

        else if ((field[6]==val)&&(field[7]==val)&&(field[8]==val)){
            return true;
        }

        else if ((field[0]==val)&&(field[3]==val)&&(field[6]==val)){
            return true;
        }

        else if ((field[1]==val)&&(field[4]==val)&&(field[7]==val)){
            return true;
        }
        else if ((field[2]==val)&&(field[5]==val)&&(field[8]==val)){
            return true;
        }
        else if ((field[0]==val)&&(field[4]==val)&&(field[8]==val)){
            return true;
        }
        else if ((field[2]==val)&&(field[4]==val)&&(field[6]==val)){
            return true;
        }
        else{
            return false;
        }

    }
    
    int step(std::string player_name, int number){
        int point;
        std::cout<<player_name<<"`s field"<<std::endl;
        std::cin>>point;
        if ((point<9)&&(field[point]=='-')){
            if (number==0){
                field[point] = 'x';
                return number+1;
            }
            else {
                field[point] = 'o';
                return number-1;
            }
        }
        else{
            step(player_name, number);
            return 0;
        }
        


    }

};