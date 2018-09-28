#include "sequence2.h"
#include <iostream>
using namespace CISP430_A2;


using std::cout;
using std::cin;
using std::endl;

// note: we have only have to define the default parameter in the
// prototype in the class; not the implementation.
sequence::sequence(size_type entry)
{
	// allocate the user entered amount of variables in the array
	data = new value_type[entry];
	// and store the amount alloted in the "capacity" section
	capacity = entry;
	// at this point, the amount of the alloted capacity and the current index
	// will be zero, so we set those to zero.
	used = 0;
	// initialize the current_index
	current_index = 0;
	// the sequence has been constructed, and variables initialized.
}

sequence::sequence(const sequence& entry)
{
	// use overloaded assignment operation to initialize this object. 
	*this = entry;
	// just use assignment operation
}

void sequence::start()
{
	// go back to the first data point.
	current_index = 0;
}

void sequence::attach(const value_type &entry)
{
	if(size() < capacity){
		for(size_t i=used; i > current_index; i--){
			
		}
	}
}
void sequence::operator =(const sequence& copySeq)
{
	// check for self-assignment.
	// if the address of the of the current object is the same
	// as the current assignment, end the function.
	if(this == &copySeq){
		return;
	}
	// delete original data that pointer points to
	delete [] data;
	// allocate a new amount of data that is the same as is
	// in the sequence being copied.
	data = new value_type[copySeq.capacity];
	// put each datum into the new array
	for(size_t i = 0; i < copySeq.used; i++){
		// each index of this object's new array gets the data from the copying object.
		data[i] = copySeq.data[i];
	}
	// assign the amount used from the one being assigned to the current
	used = copySeq.used;
	// assign the capacity
	capacity = copySeq.capacity;
	// assign the current index
	current_index = copySeq.current_index;
}

sequence::size_type sequence::size() const
{
	return used;
}




bool sequence::is_item() const
{
	// check to see if the index has gone beyond the stored information.
	if(current_index >= used){
		// if it has, then the item currently pointed at is not an item.
		return false;
	}
	else {
		// if it hasn't, then the current item pointed at is an item.
		return true;
	}
}


/*
void sequence::popArray(const double nums[], size_t amount)
{
	for(size_t i = 0; i < amount; i++){
		data[i] = nums[i];
	}
	used = amount;
}
void sequence::dispArray()
{
	for(size_t i = 0; i < used; i++){
		cout << data[i] << endl;
	}
}
*/



sequence::~sequence()
{
	// deletes whatever stored data is in the heap, pointed to by this pointer.
	delete [] data;
}

