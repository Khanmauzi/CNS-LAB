#include<stdio.h>
#include<gmp.h>
#include<iostream>

using namespace std;


int main()
{

	mpz_t genp,rop,gcd;
	mpz_t one;
	mpz_t p,q,n,phi,e,d,m,c;
	gmp_randstate_t state;
	gmp_randinit_default(state);
	mpz_inits(one,p,q,gcd,rop,n,phi,e,d,c,m,genp, NULL);			//initializing 
	mpz_urandomb(genp,state,24);				//generating large random number
	mpz_nextprime (p , genp);
	mpz_urandomb(genp,state,24);				//generating larger random number
	mpz_nextprime (q , genp);
	mpz_mul(n,p,q);
	mpz_set_ui(one,1);
	gmp_printf("n: %Zd \np: %Zd\nq: %Zd\n", n,p,q);
	mpz_sub(p,p,one);
	mpz_sub(q,q,one);
	mpz_mul(phi,p,q);
	gmp_printf("phi: %Zd\n", phi);
	mpz_set_ui(e,7);
	while(1)
	{
		mpz_urandomm(e,state,phi);
		//gmp_printf("E generated :{%Zd } \n",e);
		mpz_gcd(gcd,e,phi);
		if(mpz_cmp(one,gcd)==0)
			break;

	}
	char inputStr[1024];		// to take input
	
	gmp_printf("e: %Zd\n", e);				// printing the value of phi
	mpz_invert(d, e, phi);
	gmp_printf("d: %Zd\n", d);
	gmp_printf("Public key :{%Zd , %Zd} \n",e,n);
	gmp_printf("Private key :{%Zd , %Zd} \n",d,n);
	printf ("Enter your number: ");			// taking input from the user
  	scanf("%1023s" , inputStr);
	mpz_set_str(m,inputStr, 10);
	gmp_printf("Plain Text :%Zd\n",m);
	mpz_powm(c,m,e,n);
	gmp_printf("Cipher text :%Zd\n",c);
	mpz_powm(m,c,d,n);
	gmp_printf("Plain Text :%Zd\n",m);
	return 0;

}


/***************************************** TEST CASES *********************************************************

c157238@uselab104:~/Documents$ ./a.out
n: 170530643435221 
p: 12363931
q: 13792591
phi: 170530617278700
e: 92172825869909
d: 96281985134189
Public key :{92172825869909 , 170530643435221} 
Private key :{96281985134189 , 170530643435221} 
Enter your number: 123
Plain Text :123
Cipher text :3889516383001
Plain Text :123

-------------------------------------------------------------------------------------------------------------------

c157238@uselab104:~/Documents$ ./a.out
n: 170530643435221 
p: 12363931
q: 13792591
phi: 170530617278700
e: 92172825869909
d: 96281985134189
PU :{92172825869909 , 170530643435221} 
PR :{96281985134189 , 170530643435221} 
Enter your number: 123456
Plain Text :123456
Cipher text :41590085492348
Plain Text :123456

-----------------------------------------------------------------------------------------------------------------

c157238@uselab104:~/Documents$ ./a.out
n: 170530643435221 
p: 12363931
q: 13792591
phi: 170530617278700
e: 92172825869909
d: 96281985134189
PU :{92172825869909 , 170530643435221} 
PR :{96281985134189 , 170530643435221} 
Enter your number: 123456789
Plain Text :123456789
Cipher text :41540263326088
Plain Text :123456789

