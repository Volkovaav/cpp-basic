#include <fstream>
#include <iostream>
#include <bitset>

class cipher {
    private:
    std::string login_bicode;
    public:
    cipher (const std::string& login){
        for (size_t i=0; i<login.size(); i++){
            std::string temp;
            temp = std::bitset<8>(login[i]).to_string();
            for (size_t j =0; j<temp.size(); j++){
                login_bicode.push_back(temp[j]);
            }
        }
    }
    void print(){
        std::cout<<login_bicode<<std::endl;
    }
    void coder(const std::string& in){
        std::fstream log;
        log.open("log.txt", std::fstream::in | std::fstream::out | std::fstream::app);
        std::string in_bicode;
        // std::cout<<in.size()<<std::endl;
        for (size_t i = 0; i<in.size(); i++){
            std::cout<<i<<std::endl;
            // in_bicode = nullptr;
            std::string temp;
            temp = std::bitset<8>(in[i]).to_string();
            std::cout<<temp<<std::endl;
            for (size_t j =0; j<temp.size(); j++ ){
                std::cout<<temp[j]<<std::endl;
                in_bicode.push_back(temp[j]);
            }
            // in_bicode.push_back('/n');
            
        }
        log<<in_bicode<<std::endl;
        log.close();
    }

    void decoder(const char* filename){
        // const char* filename = "log.txt";
        remove(filename);
    }
};

int main (){
    
    std::string str = "he";
    cipher chip(str);
    // chip.coder(str);
    // chip.decoder("1.txt");
    chip.print();



}