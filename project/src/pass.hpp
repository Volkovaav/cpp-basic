#include <iostream>
#include <fstream>
#include "code.hpp"

class password{
    private:

    public:
    void start(){
        std::cout<<"Welcome!"<<std::endl;
        main_menu();
    }

    int main_menu(){
            std::cout<<"1. Sign In"<<std::endl;
            std::cout<<"2. Sign Up"<<std::endl;
            std::cout<<"3. Exit"<<std::endl;
            int point;
            std::cin>>point;
            switch (point)
            {
            case (1):
                sign_in();
                return 0;
            case (2):
                sign_up();
                return 0;
            case (3):
                return 0;
            default:
                std::cout<<"Error: number does not exist"<<std::endl;
                return 0;
            }
        }

    int sign_in(){
        std::string your_login;
        std::string your_password;
        std::cout<<"Enter your login:";
        std::cin>>your_login;
        std::filesystem::path userlib("lib/"+your_login);
        if (!std::filesystem::exists(userlib)){
            std::cout<<"This user does not exist!";
            main_menu();
            return 0;
        }
        std::cout<<"Enter your password:";
        std::cin>>your_password;
        cipher user(your_login,your_password);
        if (user.check()){
            std::cout<<"logged in"<<std::endl;
            return 0;
        }
        else{
            std::cout<<"Invalid login/password"<<std::endl;
            main_menu();
            return 0;
        }
        
    }

    int sign_up(){
        std::string new_login;
        std::string new_password;

        std::cout<<"Enter your login:"<<std::endl;
        std::cin>>new_login;
        std::filesystem::path userlib("lib/"+new_login);
        if (std::filesystem::exists(userlib)){
            std::cout<<"This user already exists"<<std::endl;
            main_menu();
            return 0;
        }
        std::cout<<"Enter your password:"<<std::endl;
        std::cin>>new_password;
        cipher user(new_login,new_password);
        user.genkey();
        user.code("/code.txt");
        std::cout<<"user registered!"<<std::endl;
        main_menu();
        return 0;
    }
};