#include<stdio.h>
int main(){
int mark1, mark2, mark3, mark4, mark5;
float total;
float average;
float percentage;
printf("ENTER THE MARKS FOR 5MARKS\n");
scanf("%d %d %d %d %d",&mark1, &mark2, &mark3, &mark4, &mark5);
total=mark1+mark2+mark3+mark4+mark5;
average=total/5;
percentage=(total/500)*100;
printf("total mark =%f\n",total);
printf("average marks =%f\n",average);
printf("percentage =%f\n",percentage);
return 0;
}
