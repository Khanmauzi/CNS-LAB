#include <gmp.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <time.h>
using namespace std;
void calgcd(mpz_t a,mpz_t b,mpz_t ans){
	//mpz_out_str(stdout,10,b);
	mpz_t temp;
	mpz_init(temp);
	while(1){
		//cout<<"while"<<endl;
		//ans=b;
		int f=mpz_sgn(a);
		if(f==0){
			mpz_set(ans,b);
			break;
		} else {
			mpz_set(temp,a);
			mpz_mod(a,b,a);
			mpz_set(b,temp);
			 
		}
	}
}
int main(){
	char inputstr[1024];
	mpz_t n1,n2;
	mpz_t ans;
	mpz_init(ans);
	mpz_set_ui(ans,0);
	mpz_init(n1);
	mpz_init(n2);
	mpz_set_ui(n1,0);
	mpz_set_ui(n2,0);
	int flag;
	printf("enter first number: \n");
	scanf("%1023s",inputstr);
	flag=mpz_set_str(n1,inputstr,10);			// convert string to base 10 integer
	assert(flag==0);							// if flag is not equal to then something went wrong 
	memset(inputstr,0,sizeof(inputstr));		// clear input buffer to take the input again
	printf("enter the second number: \n" );
	scanf("%1023s",inputstr);
	flag=mpz_set_str(n2,inputstr,10);
	//printf("%d,%d",n1,n2);
	//mpz_out_str(stdout,10,n1);					//to print mpz_int value;
	 clock_t start = clock();					//time when the function is called
	calgcd(n1,n2,ans);
	//ans = calgcd(n1,n2);
	 clock_t stop = clock();					// time whnn execution is completed
     double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;		// time taken to calculate the gcd
	cout<<"GCD of given number is "<<endl;
	mpz_out_str(stdout,10,ans);
	cout<<endl;
	cout<<"Time elasped is (in ms) : "<<elapsed<<endl;

}


/* 
********************************************Testcases***********************************************
first input 					second input 			GCD 			Time of execution(in millisecond)
9									4					1					0.004

607									907					1					0.017
30271								50221				1					0.025
123456789							987654321			9					0.005
12									-6					6					0.012
-999								-786				3					0.008
111111111							222222222			111111111			0.01
147852369852147						369852147852369		3					0.015
789456123							65					1					0.005


