#include "stdafx.h"

#include <conio.h>

int main() 
{
	TSimpleContainer<int> container;
	container.Insert({ 10, 5, 2, 51 });

	for (int value : container)
	{
		printf("%d ", value);
	}

	_getch();

	return 0;
}