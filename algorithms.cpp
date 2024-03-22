#include "./algorithms.h"

void minSort(sf::RenderWindow& window, int* arrayPtr, int arraySize) {
	int currentMin;
	int tmp;
	for (int i = 0; i < arraySize; i++) 
	{
		currentMin = arrayPtr[i];
		for (int j = i; j < arraySize; j++)
		{
			if (currentMin > arrayPtr[j])
			{
				tmp = arrayPtr[i];
				arrayPtr[i] = arrayPtr[j];
				arrayPtr[j] = tmp;	
			}
		}
	}
}



