# C++ Data Structure

### C++ Linked Stack 


Running the makefile for LinkedStack.cpp
```
make LinkedStack
```

Executing the LinkedStack.cpp 
```
./LinkedStack
```

LinkedStack.cpp employs linked list and vector string to perform necessary operations as shown in the source code.

LinkedStack.cpp reads in input strings from the user keyboard continuously until the user presses keyboard enter twice to terminate the process.
The following is the sample inputs and user can type in more as desired and it pushes and adds each strings after the newline to the stack and linkedlist.

###Input:
Hello
How are you?
I am David.

###Output:
Size of the Stack is: 3
Print Stack in reverse order.
I am David.
How are you?
Hello

Print Stack in order.
Hello \n
How are you?\n
I am David.\n
Ending the process.......


### C++ Stack and Recusrion

Running the makefile for a4.cpp
```
make a4
```

Executing the a4.cpp 
```
./a4
```

a4.cpp reads in the test file (ex. test#.txt, where # is numerical value and it indicates the test number) and search for the largest element in List 1 that does not appear in List 2. It should continuously perform this search for the next largest element in List 1 that doesn't appear in List 2 until no such number is found and it should return 0 and the main function should print "None". 
A recursive function is used in findMax() function as shown in the source code a4.cpp, which it continuously compares the top element of two lists.

Note: In each test#.txt file, List 1 and List 2 are separated by a single 0.

###Input:
Enter a file name with .txt extensions: test1.txt

###Output:
5

In test1.txt file, there are two lists. List 1 contains value 1,2,3,4,and 5 whereas List 2 is empty. Hence, the largest element that exists in List 1 and doesnot exist in List 2 is 5.

