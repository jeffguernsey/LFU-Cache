#pragma once
#include "minHeap.h"
#include "freqNode.h"
#include <unordered_map> 
class LFUCache
{
public:
	minHeap* heap;
	int capacity;
	int size;
	std::unordered_map<float, freqNode*>* hashMap;
	LFUCache(int capacity);
	bool put(float val);
	bool containsVal(float val);
	float peep();

private:
	void input(float val);

};

