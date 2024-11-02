
// HW#: HW1P1 stack application (post-fix evaluation)
// Your name:Anna Mairaj
// Compiler:g++
// File type: client program client1.cpp
//===========================================================

#include "stack.h"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

// Purpose of the program: Evaluate postfix expressions using a stack
// Algorithm: 
// 1. Read the postfix expression from the user.
// 2. Iterate through each character in the expression.
// 3. If the character is a digit, push it onto the stack.
// 4. If the character is an operator, pop the required number of operands from the stack,
//    perform the operation, and push the result back onto the stack.
// 5. After processing the expression, the stack should contain a single result.
// 6. Check for errors like stack overflow/underflow and invalid characters.
// 7. Output the result or an error message.

int main() {
  stack postfixstack; // integer stack
  string expression;  // user entered expression

  cout << "Type a postfix expression: ";
  cin >> expression;

  int i = 0; // character position within expression
  char item; // one char out of the expression

  int box1;  // receive things from pop
  int box2;  // receive things from pop

  while (expression[i] != '\0'){ // til the end of the expression
    try {
      item = expression[i]; // current char

	if (isdigit(item)){
	//convert char to int digit and push to stack
		postfixstack.push(item - '0');
   	} else { 
		int right, left;
              
                if (postfixstack.isEmpty()) throw stack::Underflow();
                postfixstack.pop(right); //pop right operand
		
		if (postfixstack.isEmpty()) throw stack::Underflow();
		postfixstack.pop(left); //pop left operand
			
         
		switch (item) {
                	case '+':
                        	postfixstack.push(left + right);
                                break;
                        case '-':
                                postfixstack.push(left - right);
                                break;
                        case '*':
                                postfixstack.push(left * right);
                                break;
                    default:
                        throw "Invalid character in expression"; // for invalid item
                }
	}

    // Catch exceptions and report problems and quit the program now (exit(1)).
    // Error messages describe what is wrong with the expression.
    }catch (stack::Overflow& e) {
	cerr << e.what() << endl;
        return 1;
    
    } catch (stack::Underflow& e) {
 	cerr << e.what() << endl;
        return 1;
    } catch (char const *errormsg) { // for invalid item case
     	cerr << errormsg << endl;
        return 1;
    }

    //go back to the loop after incrementing i
	i++;

  } // end of while

 
  // After the loop successfully completes:
  // Pop the result and show it.
  try {
  	if (postfixstack.isEmpty()) 
	{
            throw "Error: No result available. Expression might be invalid.";
        }

        int result;
        postfixstack.pop(result);


 
  // Check if anything is left on the stack, an incomplete expression
  // was found so also inform the user.
	 if (!postfixstack.isEmpty()) 
	 {
            throw "Error: Incomplete expression. Stack is not empty after evaluation.";
         }

        cout << "Result: " << result << endl;
    } catch (const stack::Overflow& e) 
	{
        cerr << e.what() << endl;
        return 1;
    } catch (const char* errormsg) 
	{
        cerr << errormsg << endl;
        return 1;
        }
    return 0;
} // end of the program
