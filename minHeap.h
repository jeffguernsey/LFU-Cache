#pragma once
#include "freqNode.h"
#include <vector>
class minHeap
{
private:
	int minHeap::find(int n);
	void minHeap::shuffleUp(int index);
	void minHeap::shuffleDown(int index);
	int length;
	std::vector<freqNode> heap;
public:
	minHeap::minHeap();
	void minHeap::insert(freqNode Node);
	int minHeap::peep();
	int minHeap::pop();
	void minHeap::deleteVal(int val);
	bool minHeap::empty();
	int minHeap::getLength();
	void minHeap::printHeap();
	void swapIndices(freqNode a, freqNode b);
	void maintainHeap(int index);
};

