/**********************************************************
Area of polygon 
**********************************************************/

#include<stdio.h>
#include<conio.h>
#include<math.h>

/*prototype of user-defined functions*/
void get_corners(char file[], float x[], float y[]);
float polygon_area(float x[],float y[],int k);
void output_corners(char file1[],float x[],float y[],int k);

/*main() method*/
void main()
{
/*declaration*/
char file[20];
float x[7],y[7];
clrscr();
/*prompt user to enter a file name*/
printf("Enter a file:");
/*read file name*/
scanf("%s",file);
/*cll user-defined function by passing the arguments*/
get_corners(file,x,y);
getch();
}
/***************** get_corners()**************************/
void get_corners(char file[], float x[], float y[])
{
FILE *fp;/*declare a file pointer*/
/*declaration and initilization*/
char file1[20];
int k =0,j=0,c=0;
float i,area;
/*open file in read mode*/
fp = fopen(file,"r");
/*check file pointer*/
if(fp==NULL)
{
 /*if fp==NULL,show a message*/
printf("file not found");
return;
}
/*if fp  is not null, enter into the else() part*/
else
{
 /*fscanf() is used to read data from file*/
while(fscanf(fp,"%f",&i)==1)
  {
   c = c+1; /*increment the c by 1*/
   if(c%2!=0)/*check c*/
   {
    /*if c is even, enter into the loop*/
    x[k]= i;/*assign the value of 'i' into the x[] array*/
    k++;/*increse the value of k by 1*/
   }
   /*else() part will execute when c is even*/
   else
   {
     y[j] = i;/*assign the value of 'i' into y[] array*/
     j++;/*increase the value of 'j' by 1*/
   }
  }
  /*call user-defined function by passing three arguments and result store in 'area'*/
  area= polygon_area(x,y,k);
  /*printf() statement is used to show the area of a polygon*/
  printf("Area of polygon = %.2f",area);

  /*prompt user to enter the file name to write the data*/
  printf("\nEnter a file name to write the data:");
  scanf("%s",&file1);/*scan file name from user*/
  /*call user-defined function by passing four arguments*/
  output_corners(file1,x,y,k);
  fclose(fp);/*close the file pointer fp*/
}
}
/************* polygon_area() **********************/
float polygon_area(float x[],float y[],int k)
{
 /*declartion and initilization*/
 float sum = 0.0,a,a1;
 int i;
 /******** logic to compute the area of a polygon***********/
 /*for() loop is used to initilized the value from 0-(k-1)*/
 for(i=0;i<(k-1);i++)
 {
  /*compute the sum of the polygon*/
  sum = sum + ((x[i+1]+x[i])*(y[i+1]-y[i]));
 }
 a1 = abs(sum);/*compute mod */
 a = a1/2;/*divide abs(sum) by 2 to calculate the area of polygon*/
 return a; /*return area 'a' to the called function*/
}
/************* output_corners()********************/
void output_corners(char file1[],float x[],float y[],int k)
{
 FILE *fp1;/*declare a file pointer*/
 int i,j;
 fp1 = fopen(file1,"w");/*open a file in write mode*/
 /*print character in the file using fprint()*/
 fprintf(fp1,"X\tY\n");
 fprintf(fp1,"------------------");
 /*for() loop is used to initilize value from 0-(k-1)*/
 for( i = 0;i<k;i++)
 {
  /*write data to the file using fprintf()*/
  fprintf(fp1,"\n%.2f\t%.2f",x[i],y[i]);
 }
 /*show a message to user*/
 printf("data is written into the file");
 fclose(fp1);/*close file*/
}
