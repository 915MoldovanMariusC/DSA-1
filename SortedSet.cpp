#include "SortedSet.h"
#include "SortedSetIterator.h"

SortedSet::SortedSet(Relation r) {
	//TODO - Implementation
	this->relation = r;
	this->elements = new TComp[1];
	this->capacity = 1;
	this->length = 0;
}


bool SortedSet::add(TComp elem) {
	//TODO - Implementation
	if (this->capacity == this->length) {
		TComp* aux = new TComp[2 * this->capacity];
		for (int i = 0; i < this->length; i++) {
			aux[i] = this->elements[i];
		}
		delete[] this->elements;
		this->capacity *= 2;
		this->elements = aux;
	}
	for (int i = 0; i < this->length; i++) {
		if (this->elements[i] == elem)
			return false;
	}
	bool sorted = false;
	while (!sorted) {
		sorted = true;
		for (int i = 0; i < this->length - 1; i++) {
			if (this->relation(this->elements[i], this->elements[i + 1])) {
				sorted = false;
				TComp aux = this->elements[i];
				this->elements[i] = this->elements[i + 1];
				this->elements[i + 1] = aux;
			}
		}
	}
	return true;
}


bool SortedSet::remove(TComp elem) {
	//TODO - Implementation
	for (int i = 0; i < this->length; i++) {
		if (this->elements[i] == elem) {
			for (int j = i; j < this->length - 1; j++) {
				this->elements[j] = this->elements[j + 1];
			}
			this->length--;
			return true;

		}
	}
	return false;
}


bool SortedSet::search(TComp elem) const {
	//TODO - Implementation
	for (int i = 0; i < this->length; i++) {
		if (this->elements[i] == elem)
			return true;
	}
	return false;
}


int SortedSet::size() const {
	//TODO - Implementation
	return this->length;
	return 0;
}



bool SortedSet::isEmpty() const {
	//TODO - Implementation
	if (length <= 0)
		return true;
	return false;
}

SortedSetIterator SortedSet::iterator() const {
	return SortedSetIterator(*this);
}


SortedSet::~SortedSet() {
	//TODO - Implementation
	delete[] this->elements;
}


