/**********************************************************
*sort array using selection sort in ascending order       *
**********************************************************/

#include<stdio.h>
#include<conio.h>

/*prototype of user defined function*/
void selection_sort(int arr[],int n);
/*main() function*/
void main()
{
 /*declaration */
 int n, arr[20],i;
 clrscr();
 /*prompt user to enter the limit of an array*/
 printf("Enter limit of an array(<20):");
 scanf("%d",&n);
 /*for() loop is used to initilized value from 0-(n-1)*/
 for(i=0;i<n;i++)
 {
   /*prompt user to enter element*/
   printf("Enter element[%d]:",i);
   scanf("%d",&a[i]);/*read input from user*/
 }
 selection_sort(arr,n);/*call user-defined function by passing arguments*/
 getch();
}

/*defination of user-defined function*/
void selection_sort(int arr[],int n)
{
 /*declaration*/
 int i,j,temp;
 /*for() loop to initilized values from 0-(n-1)*/
 for(i=0;i<n;i++)
 {
  /*for() loop to initilizes values from 1-(n-1)*/
  for(j=i+1;j<n;j++)
  {
    /*if() statement is used to check the two consecutive element*/
    if(arr[i]>arr[j])
    {
	 /*if the previous element is greater than the current element enter into the if() loop*/
     temp = arr[i]; /*a temporay variable is used to assign the value of arr[]*/
     arr[i]=arr[j];/*assign the value of current(arr[j]) to the previous(arr[i])*/
     arr[j]=temp;/*assign the value of temp into the current position (arr[j])*/
    }
  }
 }
 /*display a message*/
 printf("After sorting array is:\n");
 /*for() loop is used to initilize values from 0-(n-1)*/
 for(i=0;i<n;i++)
  /*printf() is used to print the elements of array(arr[]) in the ascending order*/
  printf("%d\t",arr[i]);
}
