#include "freqNode.h"
#include <utility>
#include <iostream>

freqNode::freqNode(float val) {
	this->val = val;
	this->freq = 1;
	this->index = 0;
}
freqNode::freqNode(float val, int freq) {
	this->val = val;
	this->freq = freq;
	this->index = 0;
}
int freqNode::getFreq() {
	return this->freq;
}

float freqNode::getVal() {
	return this->val;
}
void freqNode::setIndex(int index)
{
	this->index = index;
}
int freqNode::getIndex()
{
	return this->index;
}
void freqNode::incrementFreq() {
	this->freq++;

}

bool freqNode::operator<(const freqNode& node)
{
	return freq < node.freq;
}

bool freqNode::operator<=(const freqNode& node)
{
	return freq <= node.freq;
}

freqNode::freqNode(const freqNode& node)
{
	val = node.val;
	freq = node.freq;
	index = node.index;
}

void freqNode::operator=(const freqNode& node)
{
	val = node.val;
	freq = node.freq;
	index = node.index;
}

freqNode& freqNode::operator=(freqNode&& node) noexcept
{
	val = std::move(node.val);
	freq = std::move(node.freq);
	index = std::move(node.index);
	return *this;
}

freqNode::freqNode(freqNode&& node) noexcept
{
	val = std::move(node.val);
	freq = std::move(node.freq);
	index = std::move(node.index);
}
