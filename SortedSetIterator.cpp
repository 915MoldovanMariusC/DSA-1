#include "SortedSetIterator.h"
#include <exception>

using namespace std;

SortedSetIterator::SortedSetIterator(const SortedSet& m) : multime(m)
{
	//TODO - Implementation
	this->current = 0;
}


void SortedSetIterator::first() {
	//TODO - Implementation
	this->current = 0;
}


void SortedSetIterator::next() {
	//TODO - Implementation
	if (this->current >= this->multime.length)
		throw exception();
	this->current++;
}


TElem SortedSetIterator::getCurrent()
{
	//TODO - Implementation
	if (this->current >= this->multime.length)
		throw exception();
	return this->multime.elements[this->current];
}

bool SortedSetIterator::valid() const {
	//TODO - Implementation
	if (this->current < this->multime.length)
		return true;
	return false;
}

