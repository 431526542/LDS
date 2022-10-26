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
	
	bstint.insert(make_bstpair(100, 0));
	bstint.insert(make_bstpair(150, 0));
	bstint.insert(make_bstpair(50, 0));
	bstint.insert(make_bstpair(25, 0));
	bstint.insert(make_bstpair(75, 0));
	bstint.insert(make_bstpair(125, 0));
	bstint.insert(make_bstpair(175, 0));

	CBST<int, int>::iterator iter;
	iter = bstint.find(150);
	iter = bstint.erase(iter);
	iter = bstint.find(100);
	iter = bstint.erase(iter);

	/*
	(*bstiter).first;
	bstiter->first;

	for (bstiter = bstint.begin(); bstiter != bstint.end(); ++bstiter)
	{
		std::cout << bstiter->first << bstiter->second << std::endl;
	}*/

	return 0;
}