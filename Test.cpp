#include "gtest/gtest.h"
#include "minHeap.h"
#include "freqNode.h"
#include "LFUCache.h"
#include <iostream>
#include <vector>
TEST(buildMinHeap, buildTest1) {
    //Testing a simple build
    std::vector<float> values = { 4,8,1,3,6,9,10,1 };
    std::vector<int> freqs    = { 4,8,0,2,7,1,3,9 };
    std::vector<float> expected = { 1,9,3,10,4,6,8,1 };
    minHeap heap;
    for (int i = 0; i < values.size(); i++) {
        freqNode* node = new freqNode(values[i], freqs[i]);
        heap.insert(node);
    }
    std::vector<float> sortedVals = {};
    while (heap.getLength() > 0) {
        sortedVals.push_back(heap.pop());
    }
    EXPECT_EQ(sortedVals,expected);
}

TEST(buildMinHeap, buildTest2) {
    //Testing a build that increments the value after insertion
    std::vector<float> values = { 4,8,1,3,6,9,10,1 };
    std::vector<int> freqs =    { 4,8,0,2,7,1,3,9 };
    std::vector<float> expected = { 9,3,10,4,1,6,8,1 };
    std::vector<freqNode*> nodes = {};
    minHeap heap;
    for (int i = 0; i < values.size(); i++) {
        freqNode* temp = new freqNode(values[i], freqs[i]);
        nodes.push_back(temp);
        heap.insert(temp);
    }
    std::vector<float> sortedVals = {};
    for (int i = 0; i < 5; i++) {
        //Increment nodes[2], a pointer to the freq node with value 1, freq 0 
        nodes[2]->incrementFreq();
    }
    //Make sure that the updated node is still in the correct position post update
    heap.maintainHeap(nodes[2]->getIndex());
    while (heap.getLength() > 0) {
        sortedVals.push_back(heap.pop());
    }
    
    EXPECT_EQ(sortedVals, expected);
}


TEST(buildMinLFUCache, buildTestStandard) {
    //Testing a simple build
    LFUCache* cache = new LFUCache(5);
    std::vector<float> nums = { 1,4,1,2,3,5,2,3,4,4,4,2,1,5,2,3,5,6,7,6,7,8,7,5,4,3,2,2,4,1,5 };
    std::vector<float> expected = {1,2,3,4,5};
    for (int i = 0; i < nums.size(); i++) {
        cache->put(nums[i]);
    }
    EXPECT_EQ(cache->getSize(), 5);
    std::vector<float> actual = cache->getMapKeys();
    EXPECT_EQ(actual, expected);
}

TEST(buildMinLFUCache, buildTestNewElem) {
    //Testing a simple build that will pop a larger freq occurence for a smaller one
    LFUCache* cache = new LFUCache(5);
    std::vector<float> nums = { 1,1,2,2,2,3,3,3,4,4,4,5,5,5,6};
    std::vector<float> expected = { 2,3,4,5,6 };
    for (int i = 0; i < nums.size(); i++) {
        cache->put(nums[i]);
    }
    EXPECT_EQ(cache->getSize(), 5);
    std::vector<float> actual = cache->getMapKeys();
    EXPECT_EQ(actual, expected);
}

TEST(buildMinLFUCache, buildTestEqualFreq) {
    //Testing behaviour when two values have the same freq, current implementation does not guarantee a stable pop
    LFUCache* cache = new LFUCache(5);
    std::vector<float> nums = { 1,1,2,2,3,3,3,4,4,4,5,5,5,6 };
    std::vector<float> expected = { 1,3,4,5,6 };
    for (int i = 0; i < nums.size(); i++) {
        cache->put(nums[i]);
    }
    EXPECT_EQ(cache->getSize(), 5);
    std::vector<float> actual = cache->getMapKeys();
    EXPECT_EQ(actual, expected);
}

TEST(buildMinLFUCache, buildTestNegative) {
    //Testing behaviour with negative numbers
    LFUCache* cache = new LFUCache(5);
    std::vector<float> nums = { 1,1,1,2,2,3,3,3,4,4,4,5,5,5,-3,-3,-3,-3 };
    std::vector<float> expected = { -3,1,3,4,5 };
    for (int i = 0; i < nums.size(); i++) {
        cache->put(nums[i]);
    }
    EXPECT_EQ(cache->getSize(), 5);
    std::vector<float> actual = cache->getMapKeys();
    EXPECT_EQ(actual, expected);
}

