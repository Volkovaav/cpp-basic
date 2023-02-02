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
    ASSERT_EQ(Serialcont.size(), count+1);
    ASSERT_EQ(Serialcont[0],val);
    ASSERT_EQ(Serialcont[1],Serial0);
}

TEST (Serial, insert){
    SerialContainer<int> Serialcont;
    const int count = 10;
    for(int i = 0; i<count; i++){
        Serialcont.push_back(i);
    }
    int position = 5;
    int value = 42;
    int value_after = Serialcont[position];

    Serialcont.insert(position, value);
    
    ASSERT_EQ(Serialcont.size(), count+1);
    ASSERT_EQ(Serialcont[position], value);
    ASSERT_EQ(Serialcont[position+1], value_after);
}

TEST (Serial, pop_back){
    SerialContainer<int> Serialcont;
    const int count = 10;
    for(int i = 0; i<count; i++){
        Serialcont.push_back(i);
    }
    int value = Serialcont[count-2];

    Serialcont.pop_back();

    ASSERT_EQ(Serialcont.size(), count-1);
    ASSERT_EQ(Serialcont[count-2], value);
}

TEST(Serial, erase_beginning){
    SerialContainer<int> Serialcont;
    const int count = 10;
    for(int i = 0; i<count; i++){
        Serialcont.push_back(i);
    }
    int value = Serialcont[1];

    Serialcont.erase(0);

    ASSERT_EQ(Serialcont.size(), count-1);
    ASSERT_EQ(Serialcont[0], value);
}

TEST(Serial, erase){
    SerialContainer<int> Serialcont;
    const int count = 10;
    for(int i = 0; i<count; i++){
        Serialcont.push_back(i);
    }
    size_t position = 6;
    int value_p1 = Serialcont[position+1];
    int value_m1 = Serialcont[position-1];

    Serialcont.erase(position);

    ASSERT_EQ(Serialcont.size(), count-1);
    ASSERT_EQ(Serialcont[position-1], value_m1);
    ASSERT_EQ(Serialcont[position], value_p1);
}

TEST(Serial, init_string){
    SerialContainer<char> Serialcont;

    Serialcont.push_back('a');
    Serialcont.push_back('b');
    Serialcont.push_back('c');
    
    ASSERT_EQ(Serialcont.size(), 3);
    ASSERT_EQ(Serialcont[0],'a');
}