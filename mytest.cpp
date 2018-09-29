#include <iostream>
#include "sequence2.h"

using namespace std;
using namespace CISP430_A2;

int main()
{
	sequence mySequence;
	mySequence.attach(1);
	mySequence.attach(2);
	mySequence.attach(3);
	mySequence.attach(4);
	for (mySequence.start(); mySequence.is_item(); mySequence.advance())
	{
		cout << mySequence.current() << endl;
	}
	return 0;
}
