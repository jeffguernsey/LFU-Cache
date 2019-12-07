#pragma once
#include "LFUCache.h"
#include "minHeap.h"
#include "freqNode.h"
#include <iostream>
#include <unordered_map>

LFUCache::LFUCache(int capacity)
{
	this->capacity = capacity;
	this->heap = new minHeap();
	this->hashMap = new std::unordered_map<float, freqNode*>;
	this->size = 0;
}

bool LFUCache::put(float val)
{
	//Search for val in the cache
	std::unordered_map<float, freqNode*>::iterator it = this->hashMap->find(val);
	//If not found, insert it into the cache
	if (it == this->hashMap->end()) {
		this->input(val);
	}
	//If found increment the frequency and maintain the heap invariant
	else {
		it->second->incrementFreq();
		this->heap->maintainHeap(it->second->getIndex());
	}
	return true;
}

bool LFUCache::containsVal(float val)
{
	std::unordered_map<float, freqNode*>::iterator it = this->hashMap->find(val);
	return it != this->hashMap->end();
}

float LFUCache::peep()
{
	return this->heap->peep();
}

void LFUCache::input(float val)
{
	//Check if the cache is full, if so delete the least frequent element
	if (this->size == this->capacity){
		//Remove the smallest freq element from the cache and the hashMap
		int removedVal = this->heap->pop();
		this->hashMap->erase(removedVal);
		//Insert the new val into the cache with freq 1
		freqNode* temp = new freqNode(val);
		this->heap->insert(temp);
		this->hashMap->insert({ val, temp });
	}
	else {
		//Insert the new val into the cache with freq 1
		this->size += 1;
		freqNode* temp = new freqNode(val);
		this->heap->insert(temp);
		this->hashMap->insert({ val, temp });
	}
}
