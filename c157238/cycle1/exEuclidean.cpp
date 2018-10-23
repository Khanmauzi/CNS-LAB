#include <gmp.h>
#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;
long int calgcd(mpz_t a,mpz_t b,long int *x,long int *y){
	 int f=mpz_sgn(a);
	 if (f == 0)
	    {
	        *x = 0;
	        *y = 1;
	        return  mpz_get_ui(b);
	    }
 
    long int x1, y1; // To store results of recursive call
    mpz_t temp;
	mpz_init(temp);
	mpz_set(temp,a);
	mpz_mod(a,b,a);
	mpz_set(b,temp);
    long int gcd = calgcd(a, b, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    mpz_div(temp,b,a);
    long int t=mpz_get_ui(temp);
    *x = y1 - (t) * x1;
    *y = x1;
 
    return gcd;
}



int main(){
	mpz_t n1,n2;
	mpz_init(n1);
	mpz_init(n2);
	long int x,y;
	gmp_randstate_t state;
	mp_bitcnt_t n;
	gmp_randinit_mt (state);
	mpz_rrandomb(n1,state,64);
	mpz_out_str(stdout,10,n1);
	cout<<endl;
	mpz_rrandomb(n2,state,64);
	mpz_out_str(stdout,10,n2);
	cout<<endl;
	clock_t start = clock();		
	long int ans = calgcd(n1,n2,&x,&y);
	clock_t stop = clock();
	double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
	cout<<"GCD is : "<<ans;
	//mpz_out_str(stdout,10,ans);
	cout<<endl;
	cout<<"Time of execution(in ms) is : "<<elapsed<<endl;


}