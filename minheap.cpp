#include<iostream>
#include<string>
#include<deque>

using namespace std;

void displayQueue(const deque<int>& queue)
{
	size_t size = queue.size();
	for(unsigned int i=0; i<size-1; ++i)
		cout << queue[i] << " , ";
	cout << queue[size-1] << '\n';
}


void doMinHeapify(deque<int>& queue, int i)
{
	int largest=i;
	int leftChildIdx=2*i+1;
	int rightChildIdx=2*i+2;
	long size=static_cast<long>(queue.size());

	if(leftChildIdx < size && queue[leftChildIdx]<=queue[largest])
		largest=leftChildIdx;

	if(rightChildIdx < size && queue[rightChildIdx]<=queue[largest])
		largest=rightChildIdx;

	if(largest!=i)
	{
		int temp=queue[i];
		queue[i]=queue[largest];
		queue[largest]=temp;
	}
}

void runMinHeapify(deque<int>& queue)
{
	while(queue.size()!=1)
	{
		size_t size = queue.size();
		for(int i=(size/2)-1; i>=0; --i)
			doMinHeapify(queue, i);
		displayQueue(queue);
		int maxItem=queue.front();
		queue.pop_front();
		cout << "Took the min item = " << maxItem << " from the queue" << endl;
	}
	cout << "Taking the last element left in the queue = " << queue.front() << endl;
	queue.pop_front();
}

int main(int argc, char* argv[])
{
	deque<int> queue;
	int arr[] = { 7, 8, 1, 5, 3, 17, 12, 11, 10, 56, 27 };	
	size_t size = sizeof(arr)/sizeof(arr[0]);
	for(unsigned int i=0; i<size; ++i)
		queue.push_back(arr[i]);

	runMinHeapify(queue);
	return(0);		
}
