#include <stdio.h>
#include "myBank.h"

int main(){

double amount;
char input;

int acc; //will represent our account.
int flag=1; //Will indicate if we contiue the loop.
while(flag){

amount=0;
acc=0;
printf("Please choose a transaction type:\n");
printf("O-Open account\n");
printf("B-Balance inquiry\n");
printf("D-Deposit \n");
printf("W-Withrawl \n");
printf("C-Close account\n");
printf("I-Interest\n");
printf("P-Print\n");
printf("E-Exit\n");
scanf("%c",&input);
while((getchar()) != '\n');
switch (input){
	case 'O': //create account.
	{
		printf("Please enter amount for deposit:");
		if(scanf("%lf", &amount)==1){
			if(amount<0){
				printf("Cannot deposit negative amount\n");
				while((getchar()) != '\n');
				break;
			}
			acc=create_account(amount);
		if(acc==-1){
			printf("No accounts available");
			while((getchar()) != '\n');
			}
		else {
			printf("New account number is: %d \n",acc);
			while((getchar()) != '\n');
		}
		}
		else {
			printf("Failed to read the amount\n");
			while((getchar()) != '\n');
		}
		}
		break;
	
	case 'B': {//check balance. 
		printf("Please enter account number: ");
		if(scanf("%d",&acc)==1 ){
			if(acc<901 || acc>950){
				printf("Invalid account number\n");
				while((getchar()) != '\n');
				break;
				}
			if(check_balance(acc)==-1){
				printf("This account is closed \n");
				while((getchar()) != '\n');
		}	
		else	{
			printf("The balance of account number %d is: %.2f 			\n",acc,check_balance(acc));
			while((getchar()) != '\n');
		}
		
		}
		else {
			printf("Failed to read the account number\n");
			while((getchar()) != '\n');
		}
	break;
	}
	case 'D':{//deposit.

		printf("Please enter account number: ");
		if(scanf("%d",&acc)==1){
			if(acc<901 || acc>950){
				printf("Invalid account number\n");
				while((getchar()) != '\n');
				break;
				}
			
			if(check_balance(acc)==-1){
				printf("This account is closed \n");
				while((getchar()) != '\n');
			}
			else 	{
				printf("Amount to be deposited?");
				if(scanf("%lf",&amount)==1){
					if(amount<0){
						printf("Cannot deposit a negative amount\n");
						while((getchar()) != '\n');
						break;
					}
					deposit(acc,amount);
					printf("Successfully deposited, new balance is: 				%.2f\n",check_balance(acc));
					while((getchar()) != '\n');
				}
				else {
					printf("Failed to read amount");
					while((getchar()) != '\n');
		}
	}
}
	else {
		printf("Failed to read account number\n");
		while((getchar()) != '\n');
		}
	break;
	} 
	
	case 'W': {//withrawl
		printf("Please enter account number: ");
		if(scanf(" %d",&acc)==1){
				if(acc<901 || acc>950){
					printf("Invalid account number\n");
					while((getchar()) != '\n');
					break;
				}
			if(check_balance(acc)==-1){
				printf("This account is closed \n");
				while((getchar()) != '\n');
			}
			else {
				printf("Please enter the amount to withraw: ");
				if(scanf(" %lf",&amount)==1){
				if(withrawl(acc,amount)==-1){
					printf("Cannot withraw more than the balance\n");
					while((getchar()) != '\n');
					}
				else {
		printf("The new balance is:%2f\n",check_balance(acc));
		while((getchar()) != '\n');}
							}
				else {
					printf("Failed to read amount");
					while((getchar()) != '\n');
					}
				}
					}
		else {
			printf("Failed to read the account number\n");
			while((getchar()) != '\n');}
			
	break;
	} 
	case 'C': {//close acc.
		printf("Please enter account number: ");
		if(scanf(" %d",&acc)==1){
			if(acc<901 || acc>950){
				printf("Invalid account number\n");
				while((getchar()) != '\n');
				break;
				}
			if(close_acc(acc)==-1){
				printf("This account is already closed\n");
				while((getchar()) != '\n');}
			else {
				printf("Closed account number %d\n",acc);
				while((getchar()) != '\n');
			}
		}
		else {
			printf("Failed to read the account number\n");
			while((getchar()) != '\n');}
		break;
	}
	case 'I': {//add interest to all accs.
		printf("Please enter interest rate: ");
		if(scanf(" %lf",&amount)==1){
			if(amount<=0){
				printf("Invalid interest rate\n");
				while((getchar()) != '\n');
				break;
			}
			add_intrest(amount);
			while((getchar()) != '\n');
		}
		else {
			printf("Failed to read the interest rate\n");
			while((getchar()) != '\n');
			break;
		}
		break;
	}
	case 'P': {// print all open accs and balance.
		print_open_accs();
		while((getchar()) != '\n');
		break;
	}
	case 'E':{
		close_all();
		flag=0;
	
		break; //close all accs and leave program.
	}
	default: {
	printf("Invalid transaction type\n");
	}
	break;
	
}

}
return 0;
}
