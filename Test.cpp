#include "gtest/gtest.h"
#include "minHeap.h"
#include "freqNode.h"
#include "LFUCache.h"
#include <iostream>
#include <vector>
TEST(buildMinHeap, buildTest1) {
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


TEST(buildMinLFUCache, buildTest1) {
    LFUCache* cache = new LFUCache(5);
    std::vector<int> nums = { 1,4,1,2,3,5,2,3,4,4,4,2,1,5,2,3,5,6,7,6,7,8,7,5,4,3,2,2,4,1,5 };
    for (int i = 0; i < nums.size(); i++) {
        cache->put(nums[i]);
    }
    EXPECT_EQ(cache->getSize(), 5);
}