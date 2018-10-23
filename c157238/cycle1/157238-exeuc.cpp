#include <bits/stdc++.h>
#include <gmp.h>
using namespace std;
char* exgcdfunc(mpz_t a,mpz_t b,mpz_t x,mpz_t y)
{
	//gmp_printf("a=%Zd\n",(a));
	//gmp_printf("b=%Zd\n",(b));
	char *ch;
	mpz_t temp,zero;
	mpz_init(temp);
	mpz_init(zero);
	if(mpz_cmp(a,b)<0)
	{
		return exgcdfunc(b,a,x,y);
	}
	if(!mpz_cmp(zero,b))
	{
		mpz_set_ui(y,0);
		mpz_set_ui(x,1);
		return mpz_get_str(ch,10,a);
	}
	mpz_t x1,y1;
	mpz_init(x1);
	mpz_init(y1);
	mpz_set(temp,b);
	mpz_fdiv_q(y,a,b);
	mpz_fdiv_r(b,a,b);
	mpz_set(a,temp);
	ch=exgcdfunc(a,b,x1,y1);
	mpz_mul(y,y,y1);
	mpz_sub(y,x1,y);
	mpz_set(x,y1);
	return ch;
}
int main()
{
	mpz_t a,b,ans,one,x,y;
	clock_t start_time,end_time;
	char *ch;
	mpz_init(a);
	mpz_init(b);
	mpz_init(x);
	mpz_init(y);
	mpz_init(ans);
	mpz_init(one);
	mpz_set_ui(one,1);

	gmp_printf("TEST CASE 1:\n");
	mpz_set_str(a,"35",10);
	mpz_set_str(b,"15",10);
	gmp_printf("a=%Zd\n",(a));
	gmp_printf("b=%Zd\n",(b));
	start_time=clock();
	ch=exgcdfunc(a,b,x,y);
	end_time=clock();
	mpz_set_str(ans,ch,10);
	gmp_printf("gcd=%Zd\n",(ans));
	gmp_printf("timeElapsed=%f\n",(end_time-start_time)/(float)CLOCKS_PER_SEC);	
	mpz_set_str(ans,ch,10);
	gmp_printf("gcd=%Zd\n",(ans));
	if(mpz_cmp(a,b)<0)
		gmp_printf("x=%Zd,y=%Zd\n",(y),x);
	else
		gmp_printf("x=%Zd,y=%Zd\n",(x),y);

	gmp_printf("TEST CASE 1:\n");
	mpz_set_str(a,"35111111111111111111111111",10);
	mpz_set_str(b,"152222222222222222222222222222",10);
	gmp_printf("a=%Zd\n",(a));
	gmp_printf("b=%Zd\n",(b));
	start_time=clock();
	ch=exgcdfunc(a,b,x,y);
	end_time=clock();
	mpz_set_str(ans,ch,10);
	gmp_printf("gcd=%Zd\n",(ans));
	gmp_printf("timeElapsed=%f\n",(end_time-start_time)/(float)CLOCKS_PER_SEC);	
	mpz_set_str(ans,ch,10);
	gmp_printf("gcd=%Zd\n",(ans));
	if(mpz_cmp(a,b)<0)
		gmp_printf("x=%Zd,y=%Zd\n",(y),x);
	else
		gmp_printf("x=%Zd,y=%Zd\n",(x),y);

	gmp_printf("TEST CASE 1:\n");
	mpz_set_str(a,"3512122345345345612316421121645845453465107447584747",10);
	mpz_set_str(b,"152555555578641245381144485454121247841212041547525125454",10);
	gmp_printf("a=%Zd\n",(a));
	gmp_printf("b=%Zd\n",(b));
	start_time=clock();
	ch=exgcdfunc(a,b,x,y);
	end_time=clock();
	mpz_set_str(ans,ch,10);
	gmp_printf("gcd=%Zd\n",(ans));
	gmp_printf("timeElapsed=%f\n",(end_time-start_time)/(float)CLOCKS_PER_SEC);	
	mpz_set_str(ans,ch,10);
	gmp_printf("gcd=%Zd\n",(ans));
	if(mpz_cmp(a,b)<0)
		gmp_printf("x=%Zd,y=%Zd\n",(y),x);
	else
		gmp_printf("x=%Zd,y=%Zd\n",(x),y);
}

// c++ exgcd.cpp -lgmp -o exgcd
