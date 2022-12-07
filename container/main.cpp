#include <algorithm>
#include <iostream>

template <typename T>
class SerialContainer{
    public:

        SerialContainer(){
            m_capacity = 0;
            m_size = 0;
            m_temp = nullptr;
        }

        T operator[] (size_t val){
            return m_temp[val];
        }

        void reserve(size_t val){
            T* new_temp = new T[val];

            std::copy(m_temp, m_temp+m_size, new_temp);
            delete[] m_temp;
            m_temp = new_temp;
        }

        void push_back(int val){
            if(m_size>= m_capacity){
                m_capacity+=1;
                reserve(m_capacity);
            }
            m_temp[m_size++] = val;

        }

        size_t size(){
            return m_size;
        }

        void erase(size_t val){
            for (val; val<m_size; val++){
                m_temp[val] = m_temp[val+1];
            }
            
            m_size--;
        }

        void insert(size_t pos, int val){
            m_size++;
            if (m_size>=m_capacity){
                m_capacity++;
                reserve(m_capacity);
            }
            
            for (size_t i = m_size; i>pos; i--){
                m_temp[i] = m_temp[i-1];
            }
            m_temp[pos] = val;

        }

        void print(){
            std::cout<<"elements are:"<<std::endl;
            for(size_t i=0; i<m_size; i++){
                std::cout<<m_temp[i]<<" ";
            }
            std::cout<<std::endl;
        }

    private:
        T* m_temp;
        size_t m_capacity;
        size_t m_size;
};

template <typename T>
struct Node {
    Node(){
        m_prev = nullptr;
        m_next = nullptr;
    };
    T m_value;
    Node<T>* m_prev;
    Node<T>* m_next;
    
};

template <typename T>
class ListContainer {
    private:
        Node<T>* m_first;
        Node<T>* m_last;
        size_t m_size;

    public:
        ListContainer(): m_first(nullptr), m_last(nullptr), m_size(0) {};
        ~ListContainer(){
            delete[] m_first;
            delete[] m_last;
            
        }
        void push_back(T val){
            Node<T>* tmp_node = new Node<T>;
            tmp_node->m_value = val;
            if(m_size > 0){
                m_last->m_next = tmp_node;
                tmp_node->m_prev = m_last;
                m_last = tmp_node;
            }
            else{
                m_first=m_last = tmp_node;
            }
            m_size+=1;
        }

        void insert(size_t position, const T& val){
            Node<T>* new_node = new Node<T>;
            new_node->m_value = val;
            new_node->m_next = nullptr;
            new_node->m_prev = nullptr;
            if (position ==0 ){
                new_node->m_next = m_first;
                m_first->m_prev = new_node;
                m_first=new_node;
            }
            if (position > 0){
                Node<T>* temp = m_first;
                for ( int i=0; i<position-1; i++){
                    temp = temp->m_next;
                }
                new_node->m_prev = temp;
                new_node->m_next = temp->m_next;
                temp->m_next = new_node;
                if (new_node->m_next!=0){
                    new_node->m_next->m_prev = new_node;
                }
            }
            m_size++;
        }

        void erase(size_t position){
            Node<T>* temp = m_first;
            for (size_t i= 0; i<position-1; i++){
                    temp = temp->m_next;
            }
            temp->m_next = temp->m_next->m_next;
            temp->m_next->m_prev = temp;
        }

        size_t size(){
            return m_size;
        }
        T operator[](size_t val){
            Node<T>* temp = m_first;
            for ( int i=0; i<val; i++){
                temp = temp->m_next;    
            }
            return temp->m_value;
        }
        void print(){
            Node<T>* temp = m_first;
             while (temp != nullptr) {
                std::cout<<temp->m_value<<" ";
                temp = temp->m_next;
            }
            std::cout<<std::endl;
        }

};

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

