#include <bits/stdc++.h>

using namespace std;

struct MinHeap {
	unsigned size; 
	unsigned capacity; 
	int* arr; 
};


struct MinHeap* createMinHeap(unsigned capacity)
{
	struct MinHeap* minHeap = new MinHeap;
	minHeap->size = 0; 
	minHeap->capacity = capacity;
	minHeap->arr = new int[capacity];
	return minHeap;
}

void swapMinHeapNode(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// The standard minHeapify function.
void minHeapify(struct MinHeap* minHeap, int idx)
{
	int smallest = idx;
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;

	if (left < minHeap->size
		&& minHeap->arr[left] < minHeap->arr[smallest])
		smallest = left;

	if (right < minHeap->size
		&& minHeap->arr[right] < minHeap->arr[smallest])
		smallest = right;

	if (smallest != idx) {
		swapMinHeapNode(&minHeap->arr[smallest],
						&minHeap->arr[idx]);
		minHeapify(minHeap, smallest);
	}
}


int isSizeOne(struct MinHeap* minHeap)
{
	return (minHeap->size == 1);
}


int extractMin(struct MinHeap* minHeap)
{
	int temp = minHeap->arr[0];
	minHeap->arr[0] = minHeap->arr[minHeap->size - 1];
	--minHeap->size;
	minHeapify(minHeap, 0);
	return temp;
}


void insertMinHeap(struct MinHeap* minHeap, int val)
{
	++minHeap->size;
	int i = minHeap->size - 1;
	while (i && (val < minHeap->arr[(i - 1) / 2])) {
		minHeap->arr[i] = minHeap->arr[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	minHeap->arr[i] = val;
}

void buildMinHeap(struct MinHeap* minHeap)
{
	int n = minHeap->size - 1;
	int i;
	for (i = (n - 1) / 2; i >= 0; --i)
		minHeapify(minHeap, i);
}


struct MinHeap* createAndBuildMinHeap(int len[], int size)
{
	struct MinHeap* minHeap = createMinHeap(size);
	for (int i = 0; i < size; ++i)
		minHeap->arr[i] = len[i];
	minHeap->size = size;
	buildMinHeap(minHeap);
	return minHeap;
}


int minCost(int len[], int n)
{
	int cost = 0; 

	struct MinHeap* minHeap = createAndBuildMinHeap(len, n);


	while (!isSizeOne(minHeap)) {
		int min = extractMin(minHeap);
		int sec_min = extractMin(minHeap);

		cost += (min + sec_min); 

		insertMinHeap(minHeap, min + sec_min);
	}

	
	return cost;
}

int main()
{
	int len[] = { 8, 3, 7, 9 };
	int size = sizeof(len) / sizeof(len[0]);
	cout << "Total minimum cost for connecting ropes is "
		<< minCost(len, size);
	return 0;
}