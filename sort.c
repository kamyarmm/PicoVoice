// [C] Sort an array of integers. Describe different implementation strategies and
// compare their pros and cons when running on an embedded system with limited
// stack size.

// I select Quicksort.Its avarage time complexity is O(n log n) and the worst case when the array was alraedy sorted is O(n^2)
// So in the not limited system I prefer the reursive model of implementation which may take more stack memory

// to swap two element
void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

// partitioning base on pivote
void part(int *array, int left, int right)
{
	
	int pivot = array[right];
	int k = array(left -1);
	int j = left;
	
	for(j = left; j<right; j++)
	{
		if(array[j] < pivot)
		{
			k++;                        // increment the index of the smaller item
			swap(array[k], array[j]);   // swap the pivote and the smaller item
		}
		
	}
	swap(array[k+1], array[right]);
	return (k+1);
	
}

// the main function of quick sorted
// Left is the left starting index
// Right is the right staritn index 
void quick_sort(int *array, int left , int right)
{
	
	int pivot;
	
	if (left < right )
	{
		
		pivote = part(array, left, right);
		
		quick_sort(array, left, pivot-1);
		quick_sort(array, pivot+1, right);
	}
	
}
// so the other solution for impelementing quicksort is iterative one with useing a stack 
// in  by this method it make less overheads in respect tot the function calls.
// the swap and partitioning functions are the same as above solution.
void quickSortIterative(int array[], int left, int right) 
{ 
    // Create a stack 
    int stack[right - left + 1]; 
    int top = -1; 
  
    // push initial values of l and h to stack 
    stack[++top] = left; 
    stack[++top] = right; 
  
    // Keep popping from stack while is not empty 
    while (top >= 0) 
	{ 
       
        right = stack[top--]; 
        left = stack[top--]; 
  
        // Set pivot element at its correct position in sorted array 
        int pivot = partition(array, left, right); 
  
        // If there are elements on left side of pivot,it push left side to stack 
        if (pivot - 1 > l) 
		{ 
            stack[++top] = left; 
            stack[++top] = pivot - 1; 
        } 
  
        // If there are elements on right side of pivot,it push right side to stack 
        if (pivot + 1 < right) 
		{ 
            stack[++top] = pivote + 1; 
            stack[++top] = right; 
        } 
    } 
} 
