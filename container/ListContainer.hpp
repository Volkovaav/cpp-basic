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
            while (m_first != nullptr){
                Node<T>* tmp_node = m_last;
                m_last = m_last->m_prev;
                if (m_last == nullptr){
                    m_first = nullptr;
                    if(tmp_node != nullptr){
                        delete tmp_node;
                    }
                    return;
                }
                m_last->m_next = nullptr;
                if (tmp_node != nullptr){
                    delete tmp_node;
                }
            }
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
