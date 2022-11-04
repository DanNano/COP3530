/*
		Programming Quiz 6 by Daniel Laforce - Max Extract Heap
		COP 3530 - Fall 2022
		Submitted 10/13/2022

*/

#include <iostream>
using namespace std; //Only added part of the includes for Swap function

void Heapify(int arr[], int size, int Sub) //
{
	int large = Sub; //Sets root as largest
	int left = 2 * Sub + 1; //Sets for left sub
	int right = 2 * Sub + 2; //Sets for right sub

	if (left < size && arr[left] > arr[large]) //If the left subtree is larger than the root, makes it the largest
	{
		large = left;
	}
	if (right < size && arr[right] > arr[large]) //If the right is larger, sets that as the largest value
	{
	  large = right;
	}
	if (large != Sub) // If the largest is not the root
	{
		swap(arr[Sub], arr[large]); //Uses swap function to move two indexs.
		Heapify(arr, size, large); //Recursive call to make sure the list is set with largest
	}
}

int* extractMax(int arr[], int size)
{
   // code here
	// main prints the final heap array from 0 to size - 2
	// you don't need to print the array but instead return
	arr[0] = arr[--size]; //Remove largest element
	Heapify(arr, size, 0); //Reorganize the Heap
	return arr;
}
