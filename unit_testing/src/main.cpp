#include <iostream>
#include "ListCont.hpp"
#include "SerialCont.hpp"

void SerialContainerExample(){
    SerialContainer<int> cont;
    std::cout<<"Serial type container:"<<std::endl;
    for (int i=0; i<10; i++){
        cont.push_back(i);
    }
    cont.print();
    size_t len = cont.size();
    std::cout<<"size = "<<cont.size()<<std::endl;
    std::cout<<"Removal of 3rd, 5th and 7th element" <<std::endl;
    cont.erase(0);
    cont.erase(3);
    cont.erase(4);
    cont.print();
    std::cout<<"adding element 10 to the beginning of the container" <<std::endl;
    cont.insert(0,10);
    cont.print();
    std::cout<<"adding element 20 to the middle of the container" <<std::endl;
    cont.insert(len/2-1,20);
    cont.print();
    std::cout<<"adding element 30 to the end of the container" <<std::endl;

    cont.push_back(30);
    cont.print();
    std::cout<<std::endl;
}
void ListContainerExample(){
    ListContainer<int> cont;
    std::cout<<"List type container:"<<std::endl;
    for (int i=0; i<10; i++){
        cont.push_back(i);
    }
    cont.print();
    size_t len = cont.size();
    std::cout<<"size = "<<cont.size()<<std::endl;
    std::cout<<"Removal of 3rd, 5th and 7th element" <<std::endl;
    cont.erase(2);
    cont.erase(3);
    cont.erase(4);
    cont.print();
    std::cout<<"adding element 10 to the beginning of the container" <<std::endl;
    cont.insert(0,10);
    cont.print();
    std::cout<<"adding element 20 to the middle of the container" <<std::endl;
    cont.insert(len/2-1,20);
    cont.print();
    std::cout<<"adding element 30 to the end of the container" <<std::endl;
    cont.push_back(30);
    cont.print();
    std::cout<<std::endl;
}
int main(){
    ListContainerExample();
    SerialContainerExample();
    return 0;
}

