#include<bits/stdc++.h>
using namespace std;

// Finds inverse of a (mod b)
int get_inverse( int a, int m )
{
	int b = m;
	a = a%b;
	
	int xold = 1, x = 0, xnew;
	
	while( b>1 )
	{
		int q = (a/b);
		int r = (a%b);
		
		xnew = xold - (q*x);
		xold = x;
		x = xnew;
		
		a = b;
		b = r;
	}
	
	x = x%m;
	
	if(x<0)
		x += m;
	
	return x;
}

int gcd(int x, int y)
{
	if( x==0 )
		return y;
	if( y==0 )
		return x;
	int r = x%y;
	while(r!=0)
	{
		x = y;
		y = r;
		r = x%y;
	}
	
	return y;
}

int getAns(vector<int> p, vector<int> r)
{
	int n = p.size();
	
	for( int i=0;i<n;i++ )
		for( int j=i+1;j<n;j++ )
			if( gcd( p[i], p[j] ) != 1 )
				return -1;
	
	int prod = 1;
	for(int i=0;i<n;i++)
		prod *= p[i];
	
	int ans = 0;
	for( int i=0;i<n;i++ )
	{
		int pp = prod/p[i];
		ans += r[i] * get_inverse(pp, p[i]) * pp;
	}
	
	return ans%prod;
}

int main()
{
	int n;
	cout<<"Enter n (number of coprime numbers) : ";
	cin>>n;
	
	vector<int> p(n), r(n);
	
	cout<<"Enter the coprime numbers and their residues (pi and ri) : \n";
	
	for( int i=0;i<n;i++ )
		cin>>p[i]>>r[i];
	
	cout<<"";
	
	int ans = getAns(p, r);
	
	if( ans == -1 )
		cout<<"\nThe numbers given are not coprime\n";
	else
		cout<<"\nAnswer = "<<ans<<endl;
	
	return 0;
}



/***********************************************  TEST CASES  ****************************************************

c157238@uselab104:~/Documents/c157238/Chinese Remainder Theorem$ ./crtEnter n (number of coprime numbers) : 3
Enter the coprime numbers and their residues (pi and ri) : 
3 1
5 2
7 3 

Answer = 52

--------------------------------------------------------------------------------------------------------------------

c157238@uselab104:~/Documents/c157238/Chinese Remainder Theorem$ ./crt
Enter n (number of coprime numbers) : 3
Enter the coprime numbers and their residues (pi and ri) : 
5 7
6 11
7 19

Answer = 47

----------------------------------------------------------------------------------------------------------------------

c157238@uselab104:~/Documents/c157238/Chinese Remainder Theorem$ ./crt
Enter n (number of coprime numbers) : 4
Enter the coprime numbers and their residues (pi and ri) : 
2 7
3 13      
7 19
11 31

Answer = 229

-------------------------------------------------------------------------------------------------------------------------

