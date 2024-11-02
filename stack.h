
// HW1P1 stack
// Your name: Anna Mairaj
// Compiler: g++
// File type: header file stack.h
//=======================================================

//----- Globally setting up the aliases ----------------

const int MAX = 10; // The MAX number of elements for the stack
                    // MAX is unknown to the client

typedef int el_t;    // the el_t type is integer 
                  // el_t is unknown to the client
//-------------------------------------------------------
class stack {
private:        // to be hidden from the client
  el_t el[MAX]; // el is  an array of el_t's
  int top;      // top is index to the top of stack


public: // available to the client
class Overflow{ 
public:
	const char* what() const {
		return "Error: You have caused the stack to overflow";
}
};

class Underflow{
public:
	const char* what() const {
		return "Error: You have caused the stack to underflow";
}
};

  // prototypes to be used by the client
  // Note that no parameter variables are given

   stack(); // constructor to create an object
  ~stack(); // destructor  to destroy an object

  // PURPOSE: if not full, enters an element at the top;
  //          otherwise throws an exception - Overflow
  // PARAMETER: pass the element to be pushed
  
void push(el_t);
 

  // PURPOSE: if not empty, removes and gives back the top element;
  //          otherwise throws an exception - Underflow
  // PARAMETER: provide variable to receive the popped element (by ref)
  
void pop(el_t&);

  // PURPOSE: if not empty, gives the top element without removing it;
  //          otherwise, throws an exception - Underflow
  // PARAMETER: None
  
void topElem(el_t&);

  // ** Must add good comments for each function - See Notes2A

  // PURPOSE: Check if stack is empty.
  
bool isEmpty();

  // PURPOSE: Check if stack is full.
  
bool isFull();

  // PURPOSE: Display elements from top of stack to bottom.
  
void displayAll() ;

  // PURPOSE: Remove all elements from stack.
  
void clearIt();
};

// Note: semicolon is needed at the end of the header file
