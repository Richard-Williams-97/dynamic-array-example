#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct produce
{
	int quant;
	string desc;
	double price;
};

produce* allocateMem(produce*, int, int);
double accumulator(produce*, int);

int main()
{
	string in;

	int dex = 0;
	int length = 5;
	int increase = 5;

	produce* prodBlock = new produce[length];

	do 
	{
		cout << "enter quant" << endl;
		cin >> in;
		if (dex >= length)
		{
			prodBlock = allocateMem(prodBlock, length, increase);
		}
		(prodBlock+dex)->quant = stoi(in);
		cout<< (prodBlock + dex)->quant<<endl;

		if ((prodBlock+dex)->quant > 0)
		{
			cout << "Enter Description" << endl;
			cin >> (prodBlock+dex)->desc;

			cout << "Enter Price" << endl;
			cin >> in;
			(prodBlock+dex)->price = stod(in);
		}

		dex++;
		


	} while ((prodBlock+dex-1)->quant > 0);

	double totalprice = accumulator(prodBlock, dex);
	double tax = totalprice * .10;

	printf("Quantity    description    price");


	printf("SUBTOTAL %10f", totalprice);
	printf("tax      %10f", tax);

	totalprice += tax;

	printf("TOTAL    %10f", totalprice);


}

produce* allocateMem(produce* before, int size, int increase)
{
	produce* newBlockptr;

		newBlockptr = new produce[size + increase];
		for (int i = 0; i < size; i++)
		{
			newBlockptr[i] = before[i];
		}
		delete[] before;

	return newBlockptr;
}

double accumulator(produce* in, int dex)
{
	double val=0;
	
	for (int i = 0; i < dex + 1; i++)
	{
		val += ((in + i)->quant)*((in + i)->price);
	}
	
	return val;
}