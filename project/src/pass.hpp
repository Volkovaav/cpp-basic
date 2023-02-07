#include <iostream>
#include <fstream>

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
        std::cout<<"Enter your password:";
        std::cin>>your_password;
        if (exist_user(your_login)){
            std::string filename = "lib/";
            for(size_t i = 0; i<your_login.size(); i++){
                filename.push_back(your_login[i]);
            }
            filename.push_back('.');
            filename.push_back('t');
            filename.push_back('x');
            filename.push_back('t');
            const int MAXLEN_STR = 50; 
            const int ROW_COUNT = 100;
            char S[ROW_COUNT][MAXLEN_STR];
            int str_num = 0; 
            std::ifstream in(filename);
            while (!in.eof()){
                in.getline(S[str_num++], MAXLEN_STR);
            }
            std::cout<<S[0]<<std::endl;
            in.close();
            if (your_login==S[0]&&your_password==S[1]){
                std::cout<<"Signed in!"<<std::endl;
                return 0;
            }
            else{
                std::cout<<"Incorrect username and/or password"<<std::endl;
                try_again();
            }

        }
        else {
            std::cout<<"This user does not exist"<<std::endl;
            try_again();
        }
        return 0;
    }

    bool exist_user(const std::string& login){
        std::fstream log;
        log.open("lib/login.txt", std::fstream::in | std::fstream::out | std::fstream::app);

        const int MAXLEN_STR = 200; 
        const int ROW_COUNT = 100;
        char S[ROW_COUNT][MAXLEN_STR];
        int str_num = 0;
        while (!log.eof()){
            log.getline(S[str_num++], MAXLEN_STR);
        }
        size_t i =0;
        while (i<ROW_COUNT){
            // std::cout<<"i ="<<i<<std::endl;
            if (login==S[i]){
                return true;
            }
            i++;
        }
        return false;
    }
    
    int try_again(){

        int answer;
        std::cout<<"1. Try again"<<std::endl<<"2. Sign Up"<<std::endl<<"3. Exit"<<std::endl;
        std::cin>>answer;
        switch (answer)
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

    int sign_up(){
        std::string new_login;
        std::string new_password;

        std::cout<<"Enter your nickname:"<<std::endl;
        std::cin>>new_login;
        std::cout<<"Enter your password:"<<std::endl;
        std::cin>>new_password;

        if (!exist_user(new_login)){

            std::string user = "lib/";
            for(size_t i = 0; i<new_login.size(); i++){
                user.push_back(new_login[i]);
            }
            user.push_back('.');
            user.push_back('t');
            user.push_back('x');
            user.push_back('t');

            std::fstream log;
            std::fstream use;

            use.open(user, std::fstream::in | std::fstream::out | std::fstream::app);
            log.open("lib/login.txt", std::fstream::in | std::fstream::out | std::fstream::app);

            use<<new_login<<std::endl<<new_password;
            log<<new_login<<std::endl;

            use.close();
            log.close();

            std::cout<<"Registration is completed!"<<std::endl;
            main_menu();
            return 0;
        }
        else {
            std::cout<<"This user already exists!"<<std::endl;
            main_menu();
            return 0;
        }
        return 0;
    }
};