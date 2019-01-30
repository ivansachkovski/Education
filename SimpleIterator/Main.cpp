#include "stdafx.h"

#include <conio.h>

int main() 
{
	TSimpleContainer<int> container(10);
	container.Insert(10);
	container.Insert(5);
	container.Insert(9);
	container.Insert(7);

	for (int value : container)
	{
		printf("%d ", value);
	}

	_getch();

	return 0;
}