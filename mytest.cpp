#include <iostream>
#include "sequence2.h"

using namespace std;
using namespace CISP430_A2;
void printSeq(sequence mySeq);

int main()
{
	sequence original; // A sequence that we'll copy.
	for(double i = 0; i < 60; i++){
		original.attach(i);
	}
	printSeq(original);
	cout << "original's current is " << original.current();
	sequence copy(original);
	cout << "copy's current is " << copy.current();
	printSeq(copy);
}

void printSeq(sequence mySeq)
{
	for (mySeq.start(); mySeq.is_item(); mySeq.advance())
		{
			cout << mySeq.current() << endl;
		}
}
