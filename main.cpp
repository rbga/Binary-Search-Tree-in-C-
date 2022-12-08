
#include <iostream>
using namespace std;



class BSTN      //Create Binary Search Tree Node (BSTN) Class
{
	int key;    //Storage for each nodes
	BSTN * L;   //Class pointer for Left L
	BSTN * R;   //Class pointer for Right R
	
    public:
	    BSTN();                     //Constructor Declaration
	    BSTN(int);                  //Parametered Constructor Declaration
	    BSTN * ins(BSTN *, int);    //Class pointer for INSERT Function Declaration
	    void orderit(BSTN *);       //Inorder traversal Function resulting in ordered list of the node Declaration
	    int min(BSTN *);            //Int Function for Minimum Value function Declaration
	    int max(BSTN *);            //Int Function for Maximum Value function Declaration
};



BSTN :: BSTN()  	//Constructor definition
	  : key(0)  	//Constructor key pointer
	  , L(NULL) 	//Constructor L pointer
	  , R(NULL) 	//Constructor R pointer
{
}



BSTN :: BSTN (int val)   	//Parametered Constructor definition
{
	key = val;          	//Store into key
	L = R = NULL;       	//Set L and R to Null
}



BSTN * BSTN :: ins(BSTN * root, int val)    		//Insert Function definition
{
	if (!root) 
	{
		return new BSTN(val);               	//If no root, insert as first value
    	}                            
                                            		//Begin Data Insertion. Small values on L, vice versa
                                            
	if (val > root -> key)                  	//If Values greater than root
	{
		root -> R = ins(root -> R, val);    	//Insert recursively into R leaf nodes
	}
	
	else if (val < root -> key)             	//If Values lesser than root
	{
		root -> L = ins(root -> L, val);    	//Insert recursively into L leaf nodes
	}
	
	return root;
}



void BSTN :: orderit(BSTN * root)           			//Inorder function definition
{
	if (!root)                              		//End if no root
	{
		return;
	}
	
	
	
	orderit(root -> L);                                 	//Recursively Call orderit for L leaves
	
	cout << "\n Element is = " << root -> key << endl;  	//Print Key Value
	
	orderit(root -> R);                                 	//Recursively Call orderit for R leaves
}



int BSTN :: min(BSTN * root)                //Minimum Function definition
{
    if (!root)
    {
        cout << "\n Wrong Root" << endl;    //Print Wrong Root
    }
    
    if(root -> L == NULL)                   //If Left of root is NULL   
    {
            return root -> key;             //Then that is MIN, return key
    }    
   
    return min(root -> L);                  //(else) recursively call Left of Root in MIN function
    
}



int BSTN :: max(BSTN * root)                //Minimum Function definition
{
    if (!root)
    {
        cout << "\n Wrong Root" << endl;    //Print Wrong Root
    }
    
    if (root -> R == NULL)                  //If Right of root is NULL   
    {
        return root -> key;                 //Then that is MAX, return key
    }

        return max(root -> R);              //(else) recursively call Right of Root in MAX function
}



// Driver code
int main()
{
	BSTN b;                                            //Create Class Object BSTN
	BSTN * root = NULL;                                //Initialise root as NULL
	root = b.ins(root, 1);                             //Inset Root value and store as Root
	
	for (int i = 20; i != 0; i--)                      //Add Numbers in a for loop
	{
	    b.ins(root, i);
	}

    	cout << "\n The In Ordered Traversal of the current Binary Tree" << endl;
	b.orderit(root);    //Calling orderit
	                    
	                    //Max and Min function
	cout << "\n Max of Nodes using Max Recursive function is " << b.max(root) << endl;
	cout << "\n Min of Nodes using Min Recursive function is " << b.min(root) << endl;
	return 0;
}
