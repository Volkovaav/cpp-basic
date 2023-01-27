#include "ListContainer.hpp"
#include <gtest/gtest.h>


TEST (List, empty){
    // ARRANGE
    ListContainer<int> listcont;
    // ACT

    // ASSERT
    ASSERT_TRUE(listcont.empty());
    ASSERT_EQ(listcont.size(), 0);
}

TEST (List, size){
    // ARRANGE
    ListContainer<int> listcont;
    for(int i = 0; i<10; i++){
        listcont.push_back(i);
    }
    // ACT

    // ASSERT
    ASSERT_EQ(listcont.size(), 10);
    ASSERT_FALSE(listcont.empty());
}

TEST (List, push_back){
    ListContainer<int> listcont;

    listcont.push_back(0);

    ASSERT_EQ(listcont.size(), 1);
}

TEST(List, getting_item){
    ListContainer<int> listcont;
    const int count = 10;
    for(int i = 0; i<count; i++){
        listcont.push_back(i);
    }
    
    int item6 = listcont[6];
    int item0 = listcont[0];

    ASSERT_EQ(item6, 6);
    ASSERT_EQ(item0, 0);
}

TEST (List, insert_begginning){
    ListContainer<int> listcont;
    const int count = 10;
    const int val = 42;
    for(int i = 0; i<count; i++){
        listcont.push_back(i);
    }
    const int list0 = listcont[0];

    listcont.insert(0,val);

    ASSERT_EQ(listcont[0],val);
    ASSERT_EQ(listcont[1],list0);
}

TEST (List, insert){
    ListContainer<int> listcont;
    const int count = 10;
    for(int i = 0; i<count; i++){
        listcont.push_back(i);
    }
    int position = 5;
    int value = 42;
    int value_after = listcont[position];

    listcont.insert(position, value);
    
    ASSERT_EQ(listcont.size(), count+1);
    ASSERT_EQ(listcont[position], value);
    ASSERT_EQ(listcont[position+1], value_after);
}

TEST (List, pop_back){
    ListContainer<int> listcont;
    const int count = 10;
    for(int i = 0; i<count; i++){
        listcont.push_back(i);
    }
    int value = listcont[count-2];

    listcont.pop_back();

    ASSERT_EQ(listcont.size(), count-1);
    ASSERT_EQ(listcont[count-2], value);
}

TEST(List, erase_beginning){
    ListContainer<int> listcont;
    const int count = 10;
    for(int i = 0; i<count; i++){
        listcont.push_back(i);
    }
    int value = listcont[1];

    listcont.erase(0);

    ASSERT_EQ(listcont.size(), count-1);
    ASSERT_EQ(listcont[0], value);
}

TEST(List, erase){
    ListContainer<int> listcont;
    const int count = 10;
    for(int i = 0; i<count; i++){
        listcont.push_back(i);
    }
    size_t position = 6;
    int value_p1 = listcont[position+1];
    int value_m1 = listcont[position-1];

    listcont.erase(position);

    ASSERT_EQ(listcont.size(), count-1);
    ASSERT_EQ(listcont[position-1], value_m1);
    ASSERT_EQ(listcont[position], value_p1);
}