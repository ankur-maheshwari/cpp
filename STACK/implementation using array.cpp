/////// FACK CHECK -> RECURSION USES STACK /////////////

#include <climits>                    

class StackUsingArray {
	int *data;                        // private
	int nextIndex;
	int capacity;	

	public :
	StackUsingArray(int totalSize) {
		data = new int[totalSize];                // public 
		nextIndex = 0;
		capacity = totalSize;
	}
	int size() {
		return nextIndex;
	}

	bool isEmpty() {                          // check whether stack is empty or not
		/*
		if(nextIndex == 0) {
			return true;
		}
		else {
			return false;
		}
		*/  //////////////// OR ////////////
		return nextIndex == 0;
	}
	void push(int element) {                   // push elements in stack
		if(nextIndex == capacity) {
			cout << "Stack full " << endl;
			return;
		}
		data[nextIndex] = element;
		nextIndex++;
	}
	int pop() {                              // POP elements from stack
		if(isEmpty()) {
			cout << "Stack is empty " << endl;
			return INT_MIN;	
		}
		nextIndex--;
		return data[nextIndex];
	}

	int top() {                        // top of the element
		if(isEmpty()) {
			cout << "Stack is empty " << endl;
			return INT_MIN;	
		}
		return data[nextIndex - 1];
	}
};
#include <iostream>
#include <climits>
using namespace std;
int main() {
	StackUsingArray s(4);
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);


	cout << s.top() << endl;

	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;

	cout << s.size() << endl;

	cout << s.isEmpty() << endl;
}

