//******************************************************************
// Logan Hoelscher
// October 29, 2018
// Palidrome Calculator
// 
// The purpose of this program is to read a string from
// a text file and decide whether or not the string is a palindrome.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Input: The input for this program is read from a text file
// "testData.txt"
//
// Output: The program first displays the string in original
// order, then shows the same string in reverse order. Then the
// isPalindrome function is called to test the string for
// a palindrome. Then the program displays whether the string
// is a palindrome or not.
//*****************************************************************

#include <iostream>
#include <fstream>
#include "linkedStackType.h"
#include "linkedQueue.h"
using namespace std;

// creating the queue and the stack
linkedQueueType<char> myQueue;
linkedStackType<char> myStack;

// isPalindrome function declaration
bool isPalindrome(linkedQueueType<char>, linkedStackType<char>);

int main()
{
	int t;	// to hold isPalindrome return value
	char c;	
	string s;	// to hold the string line
	int count = 1;	// to keep track of lines on the file
	string file = "testData.txt";	//name of text file
	fstream inFile;	//file object
	
	// c_str() reads the string as characters
	inFile.open(file.c_str());
		if (inFile.is_open())	//open file
		{
			while (inFile >> s)	// copy line into s
			{
				// initialize the stack and queue
				myStack.initializeStack();
				myQueue.initializeQueue();
				
				// for loop to add characters to the stack and queue
				for (int i = 0; i < s.length(); i++)
				{
					myQueue.addQueue(s[i]);
					myStack.push(s[i]);
				}
				
				// display the contents for the UI
				cout << "Original string: ";
				myQueue.printQueue();
				cout << endl;

				cout << "Reverse string: ";
				myStack.printStack();
				cout << endl;
				
				// set t = the output of isPalindrome()
				// for easy displaying of whether or
				// not the string is a palindrome
				t = isPalindrome(myQueue, myStack);
				if (t == 1)
				{
					cout << "The string is a Palindrome " << endl << endl;
				}
				else
					cout << "The string in not a Palindrome " << endl << endl;

				count++;	//increment count to move to next line

			}
			inFile.close();	// close file
		}
		
	}
	
// isPalindrome function definition	
bool isPalindrome(linkedQueueType<char>, linkedStackType<char>)
{
	//compare the top element of the stack to the front element
	// of the queue, if they are equal, pop the stack and 
	// the queue to move onto the next comparisson. If they
	// are not equal, then the string is not a palindrome
	while(!myQueue.isEmptyQueue() && !myStack.isEmptyStack())
	{
		if(myStack.top() != myQueue.front())
		{
			return false;
		}
		myStack.pop();
		myQueue.deleteQueue();
	}
	
	return true;

}