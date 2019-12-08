#pragma once
#include "minHeap.h"
#include "freqNode.h"
#include <unordered_map> 
class LFUCache
{
public:
	LFUCache(int capacity);
	bool put(float val);
	bool containsVal(float val);
	float peep();
	int getSize();
	std::vector<float> getMapKeys();

private:
	void input(float val);
	minHeap* heap;
	int capacity;
	int size;
	std::unordered_map<float, freqNode*>* hashMap;
};

