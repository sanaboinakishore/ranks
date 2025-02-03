#include<stdio.h>
#include<string.h>
float bal_amt = 500;
int passcode = 2025;
void deposit();
void withdrawl();
void balance();
void pinchange();
int main() {
printf("-----------------------------\n");
printf("             ATM                      \n");
printf("----------------------------\n");
char name [100];
int pin, attempts = 3; // Limit PIN attempts
printf("Enter your name:  ");
scanf(" %[^\n]", name);
while (attempts > 0) {
printf("Enter your PIN:  ");
scanf("%d",  &pin);
if (pin == passcode)  {
int choice;
printf("\n1. Deposit\n2. Withdraw\n3. Balance Enquiry\n4. Change PIN\nEnter choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
       deposit();
break;
case 2:
withdrawl();
break;
case 3:
balance();
break;
case 4:
pinchange();
break;
default:
printf("Invalid choice! Please select between 1 to 4.\n");
}
return 0; // Exit after a successful transaction
} else {
attempts--;
printf("Incorrect PIN! Attempts remaining: %d\n", attempts);
}
}
printf("Too many incorrect attempts! Access locked.\n");
return 1;
}
 void deposit() {
float amt;
printf("Enter the amount to deposit: ");
scanf("%f", &amt);
if (amt > 0) {
bal_amt += amt;
printf("Deposited successfully! New Balance: %.2f\n", bal_amt);
} else {
printf("Invalid amount! Deposit must be greater than zero.\n");
}
}
void withdrawl() {
float amt;
printf("Enter withdrawal amount: ");
scanf("%f", &amt);
if (amt > 0 && amt <= bal_amt) {
bal_amt -= amt;
printf("Withdrawal successful! Remaining Balance: %.2f\n", bal_amt);
} else if (amt > bal_amt) {
printf("Insufficient funds! Available Balance: %.2f\n", bal_amt);
} else {

printf("Invalid amount! Please enter a positive value.\n");
}
}
 void balance() {
printf("Current Balance: %.2f\n", bal_amt);
}
 void pinchange() {
int old_pin, new_pin;
printf("Enter current PIN: ");
scanf("%d", &old_pin);
if (old_pin == passcode) {
printf("Enter new 4-digit PIN: ");
scanf("%d", &new_pin);
if (new_pin >= 1000 && new_pin <= 9999) {
passcode = new_pin;
printf("PIN changed successfully!\n");
} else {
printf("Invalid PIN! Please enter a 4-digit number.\n");
}
} else {
printf("Incorrect PIN! PIN change failed.\n");
}
}
