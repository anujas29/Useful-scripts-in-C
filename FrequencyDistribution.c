/**********************************************************
frequency distribution table of accident report held in cities
**********************************************************/

#include<stdio.h>
#include<conio.h>

/*prototype of user-defined functions*/
void get_acc_data(char file[], float x[], float y[]);

/*main() method*/
void main()
{
/*declaration*/
char file[20];
float city[100],acc_no[200];
clrscr();
/*prompt user to enter a file name (accident.txt)*/
printf("Enter a file:");
/*read file name*/
scanf("%s",file);
/*cll user-defined function by passing the arguments*/
get_acc_data(file,city,acc_no);
getch();
}
/************** get_acc_data()********************/
void get_acc_data(char file[], float city[], float acc_no[])
{
FILE *fp;/*declare a file pointer*/
/*declaration and initilization*/
char file1[20];

int a1=0,a2=0,a3=0,a4=0,a5=0;
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
    city[k]= i;/*assign the value of 'i' into the city[] array*/
    k++;/*increse the value of k by 1*/
   }
   /*else() part will execute when c is even*/
   else
   {
     acc_no[j] = i;/*assign the value of 'i' into acc_no[] array*/
     j++;/*increase the value of 'j' by 1*/
   }
  }
      fclose(fp);/*close the file pointer fp*/
}
/*for() loop is used to initilize the value from 0-(k-1)*/
for(i=0;i<k;i++)
{
 /*checks the number of accident in the cities and execute the proper condition*/
 /*if the accident no is greater than equal to 100 and less than equal to 199*/
 if(acc_no[i]>=100 && acc_no[i]<=199)
 a1 = a1+1; /*count the number of accident*/
 /*if the accident no is greater than equal to 200 and less than equal to 299*/
 else if(acc_no[i]>=200 && acc_no[i]<=299)
 a2 = a2+1;/*count the number of accident*/
 /*if the accident no is greater than equal to 300 and less than equal to 399*/
 else if(acc_no[i]>=300 && acc_no[i]<=399)
 a3 = a3+1; /*count the number of accident*/
 /*if the accident no is greater than equal to 400 and less than equal to 499*/
 else if(acc_no[i]>=400 && acc_no[i]<=499)
 a4 = a4+1; /*count the number of accident*/
 /*if the accident no is greater than equal to 500*/
 else
 a5 = a5+1; /*count the number of accident*/

}
//*printf() statement is used to show the frequency table of accident*/
printf("\n100-199= %d\n200-299= %d\n300-399= %d\n400-499= %d\n>500=  %d",a1,a2,a3,a4,a5);
}
