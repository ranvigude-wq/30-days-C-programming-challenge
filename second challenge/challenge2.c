#include<stdio.h>
int main(){
int distance,mileage,fuelrequired,fuelcost,fuelprice;
printf("enter the distance:");
scanf("%d",&distance);
printf("enter the mileage:");
scanf("%d",&mileage);
printf("enter the fuelprice:");
scanf("%d",&fuelprice);
fuelrequired=(distance/mileage);
fuelcost=(fuelrequired*fuelprice);
printf("total fuelrequired=%d\n",fuelrequired);
printf("total fuelcost=%d\n",fuelcost);
return 0;
}
