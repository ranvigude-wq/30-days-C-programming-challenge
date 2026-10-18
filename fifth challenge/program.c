#include<stdio.h>
#include<math.h>
int main()
{
    int choice,n,i,fact;
    float a,b,c,x,D,r1,r2,real,imag;
    while(1)
    {
        printf("\n ---Equation sloving--- \n");
        printf("1.Linear equation \n");
        printf("2.Factorial \n");
        printf("3.Quadratic \n");
        printf("0.Exit");
        printf("Enter your choice");
        scanf("%d",&choice);
        if(choice==0)
        {
            printf("....");
            break;
        }
        if(choice<=0 || choice>3)
        {
            printf("invalid Try again");
            continue;
        }
        switch(choice)
        {
            case 1:
                printf("Enter the values");
                scanf("%f %f",&a,&b);
                if(a!=0)
                {
                    x=-(b/a);
                    printf("x = %f",x);
                }
                else if(b == 0){
                    printf("infinite solutions \n");
                }
                else
                {
                    printf("No solution \n");
                }
                break;
