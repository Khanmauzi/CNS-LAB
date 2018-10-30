/* Fermat's Little Theorem */
#include<stdio.h>
#include<gmp.h>
#include<iostream>

using namespace std;

int main(){
	mpz_t a,p,r,m;
	int a1,p1;
	cout<<"Enter the a and p values : ";
	cin>>a1>>p1;
	mpz_inits(a,p,r,m,NULL);
	mpz_set_ui(a,a1);
	mpz_set_ui(p,p1);
	mpz_ui_pow_ui(r,a1,p1);
	gmp_printf("a value is :%Zd\n",a);
	gmp_printf("p value is :%Zd\n",p);
	gmp_printf("a^p value is :%Zd\n",r);
	mpz_sub(r,r,a);
	gmp_printf("a^p-a value is :%Zd\n",r);
	mpz_mod(m,r,p);
	int ans=mpz_sgn(m);
	if(ans==0){
		cout<<"P is a prinme number"<<endl;
	}
	else 
		cout<<" P is not a prime number"<<endl;

	return 0;

}

/* ***********************************************  TEST CASES *******************************************************************8

c157238@uselab121:~/Documents/c157238/Fermat's Little Theorem$ ./a.outEnter the a and p values : 10
11
a value is :10
p value is :11
a^p value is :100000000000
a^p-a value is :99999999990
P is a prinme number


-------------------------------------------------------------------------------------------------------------------------------

c157238@uselab121:~/Documents/c157238/Fermat's Little Theorem$ ./a.out
Enter the a and p values : 2
11
a value is :2
p value is :11
a^p value is :2048
a^p-a value is :2046
P is a prinme number


----------------------------------------------------------------------------------------------------------------------------------

c157238@uselab121:~/Documents/c157238/Fermat's Little Theorem$ ./a.out
Enter the a and p values : 6
30
a value is :6
p value is :30
a^p value is :221073919720733357899776
a^p-a value is :221073919720733357899770
P is a prinme number
