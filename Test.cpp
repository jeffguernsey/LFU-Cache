#include "gtest/gtest.h"
#include "minHeap.h"
#include "freqNode.h"
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
        nodes[1]->incrementFreq();
    }
    //How do i know update the nodes position?
    //It does not know where it is
    heap.printHeap();
    heap.maintainHeap(nodes[1]->getIndex());
    while (heap.getLength() > 0) {
        sortedVals.push_back(heap.pop());
    }
    
    EXPECT_EQ(sortedVals, expected);
}