#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>


class cipher{
    private:
    std::string m_filename;
    std::string m_login;
    std::string m_pass;
    public:
    cipher(std::string login, std::string pass){
        m_login = login;
        m_pass = pass;
        m_filename ="lib/"+login;
        std::ofstream file("temp.txt", std::ios::out);
        file<<login<<" "<<pass;
    }
    long filesize(std::string filename){
        std::ifstream file(filename, std::ios::out);
        file.seekg(0,std::ios::end);
        long res = (long)file.tellg();
        file.seekg(0,std::ios::beg);
        file.close();
        return res;
    }
    void genkey(){
        long len = filesize("temp.txt");
        char* key = new char[len];
        for (long i =0; i<len; i++){
            key[i]= (char)rand()%256;
            // std::cout<<key[i];
        }
        std::filesystem::path userlib(m_filename);
        if (!std::filesystem::exists(userlib)){
            std::filesystem::create_directories(userlib);
        }
        std::fstream file(m_filename+"/key.bin", std::ios::out );
        file<<key;
        delete[] key;
    }
    void code(std::string codefilename){
        // std::cout<<m_filename<<codefilename;
        std::ifstream keyfile(m_filename+"/key.bin", std::ios::in|std::ios::binary);
        std::ifstream logfile("temp.txt", std::ios::in|std::ios::binary);
        std::fstream codefile(m_filename+codefilename,std::ios::out|std::ios::binary);

        char byte;
        char bytekey;
        while(logfile.read(&byte,sizeof(char))){
            keyfile.read(&bytekey, sizeof(char));
            char resbyte = bytekey^byte;
            codefile.write(&resbyte, sizeof(char));
        }
        keyfile.close();
        logfile.close();
        codefile.close();
        
    }
    ~cipher(){
        remove("temp.txt");
    }

    bool check(){
        std::filesystem::path userlib(m_filename);
        if (std::filesystem::exists(userlib)){
            code("/test.txt");
            if (filesize(m_filename+"/test.txt")==filesize(m_filename+"/code.txt")){
                std::ifstream testfile(m_filename+"/test.txt", std::ios::in|std::ios::binary);
                std::ifstream codefile(m_filename+"/code.txt",std::ios::in|std::ios::binary);
                char byte;
                char bytetest;
                while (codefile.get(byte)&&testfile.get(bytetest)){
                    if (bytetest!=byte){
                        return false;
                    }
                }
                return true;
            }
            else{return false;}
        }
        else {return false;}
        
        
    }
};
