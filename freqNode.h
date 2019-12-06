#pragma once
class freqNode
{
private:
	float val;
	int freq;
	int index;
public:
	freqNode(float val);
	freqNode(float val,int freq);
	int getFreq();
	float getVal();
	void setIndex(int index);
	int getIndex();
	void incrementFreq();
	// < overloading
	bool operator < (const freqNode& node);
	//<= overloading
	bool operator <= (const freqNode& node);
	//Looks like I need to define the major 5
	//Copy constructor
	freqNode(const freqNode& node);
	//Copy assignment
	void operator = (const freqNode& node);
	//Move assignment
	freqNode& operator = (freqNode&& node) noexcept;
	//Move Initializer
	freqNode(freqNode&& node) noexcept;
};

