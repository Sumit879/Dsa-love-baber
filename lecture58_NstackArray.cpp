//implementation of N stack in array 
//Approach 2. Time Complexity = O(1) and Space Complexity = (s+n)
//top[] represents the index of the top element and top[] is equal to no. of stack
//next[] has two functioning
    //i. point to next element after stack top
    //ii. points to next of freespot
    //* if there is an element in next[] then it points to next element of the stack top 
    //Otherwise next[] points to next of freespot;

//Approach 1 is faltu, since we are dividing the *arr into given no. of stack and allocating the respective spaces to the individual stack

#include <bits/stdc++.h> 
class NStack
{
    int *arr;
    int* top;
    int* next;
    
    int n, s;
    int freespot;
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        n = N;
        s = S;
        arr = new int[s];
        next =new int[s];
        top = new int[n]; //top = no. of stacks
        
        //initialise top
        for(int i=0; i<n; i++){
            top[i] = -1;
        }
        
        //initialise next
        for(int i=0; i<s; i++){
            next[i] = i + 1;
        }
        
        //update last index value of next to -1
        next[s-1] = -1;
        
        //initialise freespot
        freespot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        //check overflow condition
        if(freespot == -1)
            return false;
        
        //finding index
        int index = freespot;
        
        //insert element in arr
        arr[index] = x;
        
        //update freespot
        freespot = next[index];
        
        //update next
        next[index] = top[m-1];
        
        //update top
        top[m-1] = index;
        
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        //check underflow condition
        if(top[m-1] == -1)
            return -1;
        
        int index = top[m-1];
        
        top[m-1] = next[index];
        
        next[index] = freespot;
        
        freespot = index;
        
        return arr[index];
    }
};


//HW : Do the dry run of Pop operation
// pop is just reverse of push operation
