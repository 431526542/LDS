#include <iostream>
#include "CBST.h"

enum MY_TYPE
{
	TYPE_1 = 4,
	TYPE_2 = 5,
	TYPE_3 = 6
};

int main()
{
	
	CBST<int, int> bstint;
	
	bstint.insert(make_bstpair(100,0));
	bstint.insert(make_bstpair(150, 0));
	bstint.insert(make_bstpair(50, 0));

	CBST<int, int>::iterator bstiter = bstint.begin();
	bstiter = bstint.find(150);

	return 0;
}