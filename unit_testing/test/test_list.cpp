#include "ListContainer.hpp"
#include <gtest/gtest.h>


TEST (List, empty){
    // ARRANGE
    ListContainer<int> listcont2;
    // ACT

    // ASSERT
    ASSERT_EQ(listcont2.size(), 0);
    ASSERT_TRUE(listcont2.empty());
}

TEST (List, PushBack){
    ListContainer<int> listcont;

    listcont.push_back(0);

    ASSERT_EQ(listcont.size(), 1);
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

    listcont.insert(0, 42);
    
    ASSERT_EQ(listcont.size(), count+1);
    ASSERT_EQ(listcont[0], 42);
}

TEST (List, erase){
    ListContainer<int> listcont;
    const int count = 10;

    for(int i = 0; i<count; i++){
        listcont.push_back(i);
    }
    int list6 = listcont[6];
    listcont.erase(5);

    ASSERT_EQ(listcont.size(), count-1);
    ASSERT_EQ(listcont[5], list6);
}

