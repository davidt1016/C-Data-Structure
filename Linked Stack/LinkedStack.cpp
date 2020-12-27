//============================================================================
// Name        : LinkedStack.cpp
// Author      : David Teng	
// Version     : 1.0
// Copyright   : Your copyright notice
//============================================================================


#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using std::string;
using namespace std;



class StringNode {				        // a node in a list of strings
private:
  string elem;				                // element value
  StringNode* next;				        // next item in the list

  friend class StringLinkedList;		        // provide StringLinkedList access
};

class StringLinkedList {			        // a linked list of strings
public:
  StringLinkedList();				        // empty list constructor
  ~StringLinkedList();			                // destructor
  bool empty() const;				        // is list empty?
  const string& front() const;		                // get front element
  void addFront(const string& e);		        // add to front of list
  void removeFront();				        // remove front item list
 
  void updatesize();							//Mutator function for updating the size
  int size();							    //Accessor Function for accessing the size of the stack
private:
	int sizeofStack;					//Size of the stack 
  StringNode* head;				        // pointer to the head of list
};

StringLinkedList::StringLinkedList()			// constructor
  : head(NULL), sizeofStack(0) { }

StringLinkedList::~StringLinkedList()			// destructor
  { while (!empty()) removeFront(); }

bool StringLinkedList::empty() const			// is list empty?
  { return head == NULL; }

const string& StringLinkedList::front() const		// get front element
  { return head->elem; }


/*Mutator and accessor functions declaration for the size of the stack input by the user*/
/*Mutator function that changes the sizeofStack private variables*/
void StringLinkedList::updatesize()
{
	sizeofStack++;
}
/*Return the value of sizeofStack*/
int StringLinkedList::size()
{
	return sizeofStack;
}


void StringLinkedList::addFront(const string& e) {	// add to front of list
  StringNode* v = new StringNode;			// create new node
  v->elem = e;					        // store data
  v->next = head;					// head now follows v
  head = v;						// v is now the head

  updatesize();					//Updating the linked list size everytime its being called
}



void StringLinkedList::removeFront() {		        // remove front item
  StringNode* old = head;				// save current head
  head = old->next;					// skip over old head
  delete old;						// delete the old head
}


  typedef string Elem;				        // stack element type
    class LinkedStack {				        // stack as a linked list
    public:
      LinkedStack();				        // constructor
      int size() const;				        // number of items in the stack
      bool empty() const;			        // is the stack empty?
      const Elem& top() const;	                        // the top element
      void push(const Elem& e);  		        // push element onto stack
      void pop();		                        // pop the stack
    private:                                	        // member data
      StringLinkedList S;			        // linked list of elements
      int n;					        // number of elements
    };

LinkedStack::LinkedStack()
    : S(), n(0) { }				        // constructor

  bool LinkedStack::empty() const
    { return n == 0; }				        // is the stack empty?



  const Elem& LinkedStack::top() const {
      return S.front();
  }

  void LinkedStack::push(const Elem& e) {	        // push element onto stack
    ++n;
    S.addFront(e);
  }
						        // pop the stack
  void LinkedStack::pop() {
	  --n;
    S.removeFront();
  }


  /*Function Decalarations for printing out the linked list in reverse and in order*/

  void printINORDER(vector<string> input1);
  void printReverse(vector<string> input2);
  
  int main() {

	  //Variable Instantiations and Creating Class Instances
	  StringLinkedList linkedList;
	  string input;
	  /*Creating string vector to store linked list and to print it in forward or reverse direction*/
	  vector <string> Stack;
	  cout << "Please type in strings of characters to populate the stack and press enter twice to end the process:"<< endl;
	
	  do
	  {
		  getline(cin, input);
		  /*Adding keyboard string to the list*/
		  /*Only add charcter that is not NULL and push it onto the vector*/
		  if (input != "\0")
		  {
			  linkedList.addFront(input);
			  //Pushing input string onto the vector array of stings
			  Stack.push_back(input);
		  }
		  /*Keep adding string to the list until NULL character reached*/
	  } 
	  while (input != "\0");
	  
	  /*Output the size of the stack*/
	  cout << endl << "Size of the Stack is: " << linkedList.size() << endl;
	  /*Print out in order and in reverse*/
    cout << "Print Stack in reverse order." << endl;
	  printReverse(Stack);
	  cout << endl;
    cout << "Print Stack in order." << endl;
	  printINORDER(Stack);


	  cout << "Ending the process......." << endl;

	  return EXIT_SUCCESS;
  }

  /*Function Definitions*/
  void printINORDER(vector<string> input1)
  {
	 
	  /*Output the normal version of the stack*/
	  for (int i = 0; i < input1.size(); i++)
	  {
		  cout << input1[i] << endl;
	  }
  }
  void printReverse(vector<string> input2)
  {
	 
	  /*Output the concatenated version of the input string in reverse order*/
	  for (int j = input2.size() - 1; j >= 0; j--)
	  {
		  cout << input2[j] << endl;
	  }
  }
