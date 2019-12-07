#include "minHeap.h"
#include "freqNode.h"
#include <iostream>
#include <vector>

int minHeap::find(int n) {
	for (int i = 1; i <= this->length; i++) {
		if (this->heap[i]->getVal()== n) {
			return i;
		}
	}
	return 0;
}
void minHeap::shuffleUp(int index) {
	//If the frequency of the parent index is larger than the current index swap the two
	while ((*this->heap[index] < *this->heap[index / 2]) && (index / 2 >= 1)) {
		std::swap(this->heap[index], this->heap[index / 2]);
		this->swapIndices(this->heap[index], this->heap[index/2]);
		index /= 2;
	}
}
void minHeap::shuffleDown(int index,bool deletionFlag) {
	if (index == 0) {
		return;
	}
	freqNode* temp;
	int minVal;
	//find minimum child, replace current val with in child and repeat until we get a val with no children
	//at that point switch values with the final value and delete the final value
	if (index * 2 > this->length && deletionFlag == true) {
		std::swap(this->heap[index], this->heap[this->length]);
		this->swapIndices(this->heap[index], this->heap[this->length]);
		//Needs to shuffle up the exchanges value in case it is smaller than its parent
		this->shuffleUp(index);
		freqNode* temp = this->heap[this->length];
		this->heap.pop_back();
		delete temp;
	} 
	else if (index * 2 == this->length) {
		std::swap(this->heap[index], this->heap[index * 2]);
		this->swapIndices(this->heap[index], this->heap[index*2]);
		this->shuffleDown(index * 2, deletionFlag);
	}
	else if(index * 2 < this->length){
		//This is the case wher both children exist so we need to swap with the smaller child
		int nextIndex;
		if (*this->heap[index * 2] <= *this->heap[index * 2 + 1]) {
			nextIndex = index * 2;
		}
		else {
			nextIndex = index * 2 + 1;
		}
		//Check if nextIndex is smaller than current Value
		if (*this->heap[index] < *this->heap[nextIndex]) {
			return;
		}
		std::swap(this->heap[index], this->heap[nextIndex]);
		this->swapIndices(this->heap[index], this->heap[nextIndex]);
		this->shuffleDown(nextIndex, deletionFlag);
	}
}
minHeap::minHeap() {
	freqNode first(0.0);
	first.setIndex(0);
	std::vector<freqNode*> cur;
	cur.push_back(&first);
	this->heap = cur;
	this->length = 0;
}
void minHeap::insert(freqNode* Node) {
	Node->setIndex(this->length+1);
	this->heap.push_back(Node);
	this->length += 1;
	int index = this->length;
	this->shuffleUp(index);

}
int minHeap::peep() {
	return this->heap[1]->getVal();
}
int minHeap::pop() {
	int minVal = this->heap[1]->getVal();
	delete this->heap[1];
	this->heap[1] = new freqNode(0, INT_MAX);
	this->shuffleDown(1,true);
	this->length -= 1;
	return minVal;
}
void minHeap::deleteVal(int val) {
	int index = this->find(val);
	if (index == 0) {
		return;
	}
	//Pseudo infinity, would write custom infinity comparator for real implementation
	this->heap[index] = &freqNode(0, INT_MAX);
	this->shuffleDown(index,true);
	this->length -= 1;

}

bool minHeap::empty() {
	return this->length == 0;
}

int minHeap::getLength() {
	return this->length;
}

void minHeap::printHeap() {
	std::cout << "[";
	for (auto i = this->heap.begin(); i != this->heap.end(); i++) {
		std::cout << (*i)->getVal() << " "<< (*i)->getFreq() << " " << (*i)->getIndex() << ",";
	}
	std::cout << "]\n";
}

void minHeap::swapIndices(freqNode* a, freqNode* b)
{
	int temp = a->getIndex();
	a->setIndex(b->getIndex());
	b->setIndex(temp);
}

void minHeap::maintainHeap(int index)
{
	this->shuffleDown(index,false);//
}
