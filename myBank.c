#include "myBank.h"
#include <stdio.h>
#define bank_size 50

double accounts[bank_size][3];

int create_account(double amount){
	int i=0;
	while(i<=49){
		if(accounts[i][0]==0){//check if acc is available.
		
			accounts[i][0]=1;//account opened.
			accounts[i][1]=amount;
			
		//return i+901;
		break;
		}
	i++;
	}
	if(i==bank_size){
		return -1;
		}
	return i+901;
}
double check_balance(int account_number){
	if(accounts[account_number-901][0]==1){
		return accounts[account_number-901][1];
		}
	else {
		return -1;
	}
}
int deposit(int account_number,double amount){
	if(accounts[account_number-901][0]==1){
		return (accounts[account_number-901][1]+=amount);
		}
	else {
		return -1;
	}
}
int withrawl(int account_number,double amount){
	if(accounts[account_number-901][0]==1 && accounts[account_number-901][1]-amount>=0){
		return (accounts[account_number-901][1]-=amount);
		}
	else {
		return -1;
	}
}
int close_acc(int account_number){
		if(accounts[account_number-901][0]==1){
			accounts[account_number-901][0]=0;//account closed.
		return 1;//1 indicates we have successfully closed the acc.
		}
	else {
		return -1;
	}
}
void add_intrest(double interest){
	int i;
	for(i=0;i<bank_size;i++){
		if(accounts[i][0]==1){
			accounts[i][1]+=((accounts[i][1]*interest)/100);
		}//check if acc is open. 
	}
}
void print_open_accs(){
	int i;
	for(i=0;i<bank_size;i++){
		if(accounts[i][0]==1){ //check if account is open.
		printf("The balance of account number %d is: %0.2f \n", i+901 ,check_balance(i+901));
		}
	}


}
void close_all(){
		int i;
	for(i=0;i<bank_size;i++){
		if(accounts[i][0]==1){ //check if account is open.
		accounts[i][0]=0;
		accounts[i][0]=0;
		}
	}
}
