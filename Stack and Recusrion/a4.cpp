/*
** David Teng
**  a4.cpp
**
**
**  Reads a sequence of integers (in the range of int's) from standard in;
**  It is interpreted as two lists, separated by a single 0
**/
#include <iostream>
#include <stack>
#include <fstream>
#include <string>
using namespace std;

//-------------------Function Declaration-------------------
//sortStack is for sorting stack whenever the program reads in a data
//from the file
stack <int> sort(stack <int> &list);
//Finding the largest element in List1 but does not occur in List2,
//else continue searching for the next largest element in List1 that
//doesn't exist in List2
//If no such number is found, then return '0' back to main to signify that
//there is no such number and main function should print out "NONE"
void findMax (stack <int> &L1, stack<int> &L2);
//Deleting the stack
void Destroy(stack<int>&finishedStack);

int main()
{
    //Initializing Variables
     int number = 0 ;
     int data = 0;
     //Checking it is the beginning of list 2
     bool List1 = true;
     //File names
     string filesname; 
     //Creating two integer stacks
     stack <int> list1;
     stack <int> list2;
     //Stack for storing ascending stack after sorting
     stack <int> descendingList1;
     stack <int> descendingList2;
     //ifstream to read in data from the file
     ifstream fin;
    
     cout << "Enter a file name with .txt extensions: ";
     cin>> filesname;
     //Opening files
     //test3 output 3: error->output 9 which exists in both L1&L2->Should say NONE
     //Due to repetitions of the same number in the list
     fin.open (filesname.c_str());
     //Check if the file is properly opened or not
     if (fin.fail())
     {
        cerr << "File is not opened properly!\n";
        exit(1); 
     }
     //Reading in files while it is not reaching eof
     while ( !(fin.eof()) )
     {
        //reading data from the files
        fin >> data;
        number = data;
        //Eliminating to read duplicate value of the last element in the list
        if (fin.eof())
            break;
        //Pushing list 1 onto the stack
        if ( number != 0 && List1 == true)
        {
            list1.push(number);
        }
        //pushing list 2 onto the stack
        else
        {
            if( number != 0 )
            {
                list2.push(number);
            }
            //List1 is false when List2 is true
            List1 =false;
        }
     }
     //Building Ascending Stack for List1 and List2
    descendingList1 = sort(list1);
    descendingList2 = sort (list2);  
     //Finding Max of the element in L1 that do not exist in L2
     findMax(descendingList1,descendingList2);
     //Clearing out the stack
     Destroy(descendingList1);
     Destroy(descendingList2);
     Destroy(list1);
     Destroy(list2); 
}

//----------------------Function Definitions----------------------
//Void function that will sort the stack in descending order for which the top of the 
//stack will be the largest element on the stack
//Reference from this website:https://www.geeksforgeeks.org/sort-stack-using-temporary-stack/
stack <int> sort(stack <int> &list)
{
    //Temproary stack for storing integer element
    stack <int> tmpList;
    //While the stack is not empty continue to sort
    while ( !(list.empty()) )
    {
        //Remove the first element
        int temp = list.top();
        list.pop();
        //This while loop resulting in ascending order of stack based on given
        //list stack that is passed in as function parameter
        while(!(tmpList.empty()) && (tmpList.top() > temp) )
        {
            list.push(tmpList.top());
            tmpList.pop();
        }
        tmpList.push(temp);
    }
    //Returning entire tmplist in ascending order
    return tmpList;
}
//Finding the maximum number in List 1 that do not exist in list 2
void findMax (stack <int> &L1, stack<int> &L2)
{
	int repeat = 0;
    //Base Cases for the recursive Function of findMax
    //if L1 is empty then automatically output NONE since it doesnot contain anything
    if (L1.empty())
    {
        cout << "NONE" << endl;
    }
	else 
	{
	   //If L1 is not empty and L2 is empty, it implies that L1 stack.top() contains the largest
	    //number exclusive to L1 only
	    if ( L2.empty() && !(L1.empty()) )
	    {
	        //Print out the largest number in L1
	        cout << L1.top() << endl;
	    }
	    //If the L1 list contains the largest number on the top of the stack then
	    //print out the largest number
	    else if( L1.top() > L2.top() )
	    {
	        cout << L1.top() << endl;
	    }
	    //Recursive function calls
	    //If the largest number is not exclusive for L1 then pop L1 and L2 since 
	    //and search for the next largest element in L1
	    else if (  L1.top() == L2.top() )
	    {
            //Repeat variable stores L2.top() as a reference for the deletion of L1.top()
	    	repeat = L2.top();
	       	L1.pop();
	        L2.pop();
	        //While L1 is not empty and if there is a series of repetition of the same large number
	        //in L1 and exists in L2 as well then pop the same element until no further repeat is found
	        while( ! (L1.empty()) )
	        {
	        	//If L1 contains a series of 9 on the top of the stack and it is equate to the maximum number in L2,
	        	//then pop until it is no longer on the stack
	        	if (L1.top()==repeat)
	        	{
	        		L1.pop();
	        	}
	        	//If there isn't any repetition then break ouf of the loop
	        	else 
	        	{
	        		break;
	        	}

	        }
	        findMax(L1,L2);
	    }
	    //If L2.top() contains an element that is larger than L1 then pop
	    //until L2.top number has smaller or equal to L1.top() number
	    else if (L2.top() > L1.top())
	    {
	        L2.pop();
	        findMax(L1,L2);
	    }   
	}  
}
//Pop all the elements in the stack
void Destroy(stack<int>&finishedStack)
{
    //While the stack is not empty pop the element
    while (!(finishedStack.empty()))
    {
        finishedStack.pop();
    }
}

