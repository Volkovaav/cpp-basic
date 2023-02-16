#include <iostream>
#include <string>
using namespace std;


class player{
    public:
    virtual int step() const = 0;
    virtual ~player() {}
    virtual string getname() const = 0;
};

class human: public player{
    public:
    human (string n): name{n} {}
    
    int step() const override{
    while (true) // Цикл, пока пользователь не введет допустимые данные
        {
            cout << "Enter a double value: ";
            int x{};
            std::cin >> x;
    
            // Проверяем на неудачное извлечение
            if (std::cin.fail()) // предыдущее извлечение не удалось?
            {
                // да, давайте разберемся с ошибкой
                std::cin.clear(); // возвращаем нас в "нормальный" режим работы
                
                std::cout << "Oops, that input is invalid.  Please try again.\n";
            }
            else
            {
                return x;
            }
        }
    }
    virtual ~human()= default;
    virtual string getname() const override{
        return name;
    }

    private:
    string name;
    
};

class new_game{
    private:
    char field[9];
    public:
    new_game(){
        for (int i=0; i<9; i++){
            field[i] = '-';
        }
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
    bool draw(){
        for (int i = 0; i<9; i++){
            if (field[i]== '-'){
                return false;
            }
        }
        return true;
    }
    void print_field(){

        std::cout<<"|"<<0<<"|"<<1<<"|"<<2<<"|"<<std::endl;
        std::cout<<"|"<<3<<"|"<<4<<"|"<<5<<"|"<<std::endl;
        std::cout<<"|"<<6<<"|"<<7<<"|"<<8<<"|"<<std::endl<<std::endl;

        std::cout<<"|"<<field[0]<<"|"<<field[1]<<"|"<<field[2]<<"|"<<std::endl;
        std::cout<<"|"<<field[3]<<"|"<<field[4]<<"|"<<field[5]<<"|"<<std::endl;
        std::cout<<"|"<<field[6]<<"|"<<field[7]<<"|"<<field[8]<<"|"<<std::endl;
    }
    int movie(player** pl, int start){
        char ind[2] = {'x','o'};
        int count = start;
        print_field();
        while(!winner(ind[0])&&!winner(ind[1])&&!draw()){

            int point = pl[count]->step();
            
            field[point] = ind[count];
            print_field();
            count = (count+1)%2;
            
        }
        if (winner(ind[0])||winner(ind[1])) cout<<pl[count]->getname()<<" won!"<<std::endl;
        else if (draw()) cout<<"Draw!"<<std::endl;
        return 0;
    }


    void with_player(){
        std::string naming[2];

        std::cout<<"Enter player`s 1 name"<<std::endl;
        std::cin>>naming[0];

        std::cout<<"Enter player`s 2 name"<<std::endl;
        std::cin>>naming[1];

        player* pl[2];
        pl[0] = new human{naming[0]};
        pl[1] = new human{naming[1]};

        movie(pl, 0);
    }

    
    void start_game(){
        int point;

        cout<<"Hello!"<<endl;
        cout<<"1. Game with players"<<endl;
        cout<<"2. Game with computer"<<endl;
        cin>>point;

        switch (point){
            case(1):{
                with_player();
            }
            default:{
                break;
            }
        }
    }



};






