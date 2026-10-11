#include <stdio.h>
int main() {
int amount, type, distance;
int discount, delivery, final;
printf("Enter amount: ");
scanf("%d", &amount);
printf("Enter type (1=Student, 2=Regular): ");
scanf("%d", &type);
printf("Enter distance: ");
scanf("%d", &distance);
if (type == 1) {
if (amount >= 2000)
discount = amount * 15 / 100;
else
discount = amount * 10 / 100;
}
else {
if (amount >= 3000)
discount = amount * 8 / 100;
else
discount = 0;
}
if (distance <= 5)
delivery = 40;
else if (distance <= 15)
delivery = 70;
else
delivery = 100;
final = amount - discount + delivery;
printf("Discount = %d\n", discount);
printf("Delivery = %d\n", delivery);
printf("Final Amount = %d\n", final);
return 0;
}
