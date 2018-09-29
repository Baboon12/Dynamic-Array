#include "sequence2.h"
#include <iostream>
using namespace CISP430_A2;
using namespace std;

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

void sequence::advance()
{
	// check to see if the current index is an item
	if (is_item()){
		// if it is then advance to the next index.
		// this is so that it does not advance to the end of an empty array.
		current_index++;
	}
}

void sequence::insert(const value_type &entry)
{
	if(used >= capacity){
		// caclulate capacity + 10%
		// we have to cast the number here from size_t to double in order to do
		// the floating point calc.
		double amount_increase = 0.10 * static_cast<double>(capacity);
		// add the increased amount to the capacity.
		size_t replace_capacity = capacity + static_cast<size_t>(amount_increase);
		// since for arrays with 0-9 elements we will get replace capcities less than
		// 1, we replace that with 1 so that we can still have one more slot for the new element.
		if(replace_capacity == 0){
			replace_capacity = 1;
		}
		// then resize with new capacity.
		resize(capacity + replace_capacity);
	}
	// in the case that the array is empty,

	if (used == 0)
	{
		// make the first data slot the entry.
		data[0] = entry;
		// then increment the amount used by 1.
		used++;
		// and end the function
		return;
	}
	// start from the end of the entered data. keep moving everything one slot
	// to the right, until we get to the current index where we will insert the new number.
	for(size_t i=used; i > current_index; i--){
		// put in the data stored in each index before the i index.
		data[i] = data[i - 1];
	}
	// insert the new data at the index just after the current index.
	data[current_index] = entry;
	// add one to the amount used.
	used += 1;

}
void sequence::attach(const value_type &entry)
{
	// this is the spot that the new value will be attached at.
	size_t attach_index = current_index + 1;
	// check to see if we are beyond allocated memory for the array
	if(used >= capacity){
		// caclulate capacity + 10%
		// we have to cast the number here from size_t to double in order to do
		// the floating point calc.
		double amount_increase = 0.10 * static_cast<double>(capacity);
		// add the increased amount to the capacity.
		size_t replace_capacity = capacity + static_cast<size_t>(amount_increase);
		// since for arrays with 0-9 elements we will get replace capcities less than
		// 1, we replace that with 1 so that we can still have one more slot for the new element.
		if(replace_capacity == 0){
			replace_capacity = 1;
		}
		// then resize with new capacity.
		resize(capacity + replace_capacity);
	}
	// in the case that the array is empty,
	if (used == 0)
	{
		// make the first data slot the entry.
		data[0] = entry;
		// then increment the amount used by 1.
		used++;
		// and end the function
		return;
	}
	// if the current index is beyond the array data,
	if (current_index == used){
		// then put the entry into the last
		data[used] = entry;
		used++;
		return;
	}
	// start from the end of the entered data. keep moving everything one slot
	// to the right, until we get to the attach index where we will insert the new number.
	for(size_t i=used; i > attach_index; i--){
		// put in the data stored in each index before the i index.
		data[i] = data[i - 1];
	}
	// insert the new data at the index just after the current index.
	data[attach_index] = entry;
	// change the current index to the attach_index;
	current_index = attach_index;
	// add one to the amount used.
	used += 1;

}

void sequence::remove_current()
{
	value_type* data_replace = new value_type[capacity];
	// the slot one past the current index, this will be the new current index.
	size_t past_current = current_index + 1;
	// add each datum from the old array into the new array
	// until we get to the current index.
	if(!is_item()){
		// if we are currently at nothing, there is nothing to remove.
		return;
	}
	for(size_t i = 0; i < current_index; i++) {
		data_replace[i] = data[i];
	}
	// start copying from one past the current_index.
	// this effectively makes a copy of the previous data set without the value originally
	// pointed to by the current pointer.
	for(size_t j = past_current; j < used; j++){
		// since the new array is one less, the array indexes are
		// one minus that on the old array.
		data_replace[j-1] = data[j];
	}
	// delete the data pointed to by the class pointer.
	delete [] data;
	// reassign the class pointer to the new array with less items in it.
	data = data_replace;
	// decrement the total used by 1, since we removed an item.
	used--;
}

void sequence::resize(size_type new_capacity){
	if(new_capacity > used){
		// allocate a new array with the capacity specified in the parameter.
		value_type* larger_data = new value_type[new_capacity];
		// put each datum into the new, larger array
		for(size_t i = 0; i < used; i++){
			larger_data[i] = data[i];
		}
		// delete the data from the original array.
		delete [] data;
		// assign the array pointer to the new, larger array.
		data = larger_data;
		// set the capacity to the new size
		capacity = new_capacity;
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

sequence::value_type sequence::current() const
{
	if(is_item())
		return data[current_index];
	else
		return 0;
}

sequence::~sequence()
{
	// deletes whatever stored data is in the heap, pointed to by this pointer.
	delete [] data;
}

