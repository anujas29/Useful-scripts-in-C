/*********************************************************
STACK push(), pop() and retrive() IMPLEMENTATION USING ARRAYS
**********************************************************/
#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5
int top, flag;

/*****************PUSH FUNCTION***************************/
void push (int stack[], int item)
{   
	/*check the top of stack*/
	if (top == (MAX-1))
	flag = 0;
    else
    {   
	flag = 1;/*set flag value to 1*/
	++top;/*increment the top of stack*/
	stack [top] = item; /*push the item into the stack*/
    }
}

/********************POP FUNCTION*************************/
int pop (int stack[])
{
    int n;/* declare a integer variable*/
	/*check the top of  the stack*/
    if (top == -1) /*if the top of stack is -1 enter into the if() loop*/
    {   
	  n = 0; /*set the n=0*/
	  flag = 0;/*set the flag value to 0*/
    }
	/*else() part will execute when the top of stack is not equals to -1*/
    else
    {   
	  flag = 1;/*set the flag value to 1*/
	  n = stack [top]; /*assign the top element of stack into the n variable*/
	  --top;/*decrement the top of stack*/
    }
return n;/*return n to the called function*/
}

/******************RETRIVE FUNCTION***********************/
/*this function is used to retrive the top element of stack without popping out*/
void retrive(int stack[])
{
   /*check the top of stack if it is equal to -1*/
   if(top == -1)
	   /*print a message that stack is empty*/
   printf("\nThe stack is empty");
   else
   /*print the top of element, if top is not equal to -1*/
   printf("\ntop element= %d", stack[top]);
}

/*****************FUNCTION TO DISPLAY STACK***************/
void show (int stack[])
{   
	int j;/*declare a integer j*/
	/*prompt message to user*/
    printf ("\nThe Stack is:\n ");
	/*check the top of stack, if top==-1*/
    if (top == -1)
	/*print a message "empty" */
	printf ("Empty");
	/*else() part will execute when the top of stack is not equal to -1*/
    else
    {   /*for() loop is used to initilize the value from the top of the stack to the 0th element of stack*/
	   for (j=top; j>=0; --j)
	   printf("\n%3d",stack[j]);/*prints the stack values*/
    }
    printf ("\n");/*prints a new line*/
}

/*******************MAIN FUNCTION***********************/
void main()
{
	/*declaration and initilization*/
    int stack [MAX], item;
    int choice;
    clrscr ();
    top = -1;

    do
    { 
	   /*printf() statements is used to show message and prompts user to enter a choice*/
	   printf ("\nMAIN MENU");
	   printf ("\n1.PUSH (Insert)");
	   printf ("\n2.POP  (Delete)");
	   printf("\n3.Retrive");
	   printf ("\n4.Exit (End the Execution)");
	   printf ("\nEnter Your Choice: ");
	   scanf  ("%d", &choice);/*scan choice from user*/
	   /*switch() statement*/
       switch (choice)
       {
	    /*apropriate case will be execute depending on the user choice*/
       case 1:/*case 1 will execute when user will enter 1 option*/
	          /*prompt user to enter an element*/ 
		     printf ("\nEnter an Element to be pushed : ");
		     scanf  ("%d", &item);/*scan element*/
		     push (stack, item);/*call user-defined function by passing arguments*/
		     if (flag)
		     {  
			   printf ("\nAfter Pushing ");
		       show(stack); );/*call user defined function to display stack values*/
		     }
		     else
		     printf ("\nStack overflow");
		     break;
       case 2:/*case 2 will be execute when user enter 2 option*/
	    	 item = pop (stack);/*call user-defined function by passing stack[]*/
		     if (flag)/*if flag is true*/
		     {
			   printf ("\n After Popping: ");/*prints a message*/
		       show(stack);/*call user defined function to display stack values*/
		     }
		    else
		       printf ("\nStack underflow");
		    break;
       case 3:/*case 3 will be execute when user enter 3 option*/
		     retrive(stack);/*call user-defined function by passing stack[]*/
	         break;
       case 4: 
		     exit(0);/*exit from the execution*/
       default:
		     printf ("\nINVALID ENTRY");
       }
    }while (choice != 4);
getch();
}
