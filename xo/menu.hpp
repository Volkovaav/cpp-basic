#include <iostream>
#include <string>

#include <cstdlib>
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
        while (true) {
            cout <<name<< "`s movie. ";
            string x;
            std::cin >> x;
            int number=-1;
            try{
                number = stoi(x);
            }
            catch(const std::exception& e){
                std::cerr << e.what() << '\n';
            }
            if (number>=0&&number<9){
                return number;
            }
            else{
                cout<<"Try again!"<<endl;
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

class computer: public player{
    public:
    computer (): name{"bob"} {}
    
    int step() const override{
        int number = rand()%8;
        return number;
    }
    virtual ~computer()= default;
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
            if (field[point]=='-'){
                field[point] = ind[count];
            }
            else{
                movie(pl, count);
                return 0;
            }
            print_field();
            count = (count+1)%2;
            
        }
        if (winner(ind[0])||winner(ind[1])) cout<<pl[(count+1)%2]->getname()<<" won!"<<std::endl;
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

    void with_computer(){
        std::string naming;

        std::cout<<"Enter player`s name"<<std::endl;
        std::cin>>naming;


        player* pl[2];
        pl[0] = new human{naming};
        pl[1] = new computer{};

        movie(pl, 0);
    }
    
    void start_game(){
        int point;

        cout<<"Hello!"<<endl;
        cout<<"1. Game with players"<<endl;
        cout<<"2. Game with computer"<<endl;
        cout<<"3. Exit"<<endl;
        cin>>point;

        switch (point){
            case(1):{
                with_player();
                break;
            }
            case(2):{
                with_computer();
                break;
            }
            case(3):{
                break;
            }
            default:{
                break;
            }
        }
    }
};