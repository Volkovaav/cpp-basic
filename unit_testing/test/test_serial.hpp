#include "SerialCont.hpp"
#include <gtest/gtest.h>

TEST (Serial, empty){
    // ARRANGE
    SerialContainer<int> Serialcont;
    // ACT

    // ASSERT
    ASSERT_TRUE(Serialcont.empty());
    ASSERT_EQ(Serialcont.size(), 0);
}

TEST (Serial, size){
    // ARRANGE
    SerialContainer<int> Serialcont;
    for(int i = 0; i<10; i++){
        Serialcont.push_back(i);
    }
    // ACT

    // ASSERT
    ASSERT_EQ(Serialcont.size(), 10);
    ASSERT_FALSE(Serialcont.empty());
}
TEST (Serial, push_back){
    SerialContainer<int> Serialcont;

    Serialcont.push_back(0);

    ASSERT_EQ(Serialcont.size(), 1);
}

TEST(Serial, getting_item){
    SerialContainer<int> Serialcont;
    const int count = 10;
    for(int i = 0; i<count; i++){
        Serialcont.push_back(i);
    }
    
    int item6 = Serialcont[6];
    int item0 = Serialcont[0];

    ASSERT_EQ(item6, 6);
    ASSERT_EQ(item0, 0);
}

TEST (Serial, insert_begginning){
    SerialContainer<int> Serialcont;
    const int count = 10;
    const int val = 42;
    for(int i = 0; i<count; i++){
        Serialcont.push_back(i);
    }
    const int Serial0 = Serialcont[0];

    Serialcont.insert(0,val);

    ASSERT_EQ(Serialcont[0],val);
    ASSERT_EQ(Serialcont[1],Serial0);
}