#include<bits/stdc++.h>
using namespace std;
string fx,gx,mx;
void output(string fx)
{
	bool flag=false;
	for(int i=0;i<fx.length();i++)
	{
		if(fx[i]=='1')
		{
			if(flag) cout<<"+";
			cout<<"x^"<<(7-i);
			flag=true;
		}
	}
}
void fastMultiply()
{
	int size=fx.size();
	string ans;
	for(int i=0;i<size;i++)
	{
		ans+="0";
	}
	if(gx[gx.size()-1]=='1')
	{
		//cout<<"here i1="<<gx.size()-1<<endl;
		for(int j=0;j<size;j++) ans[j]=((fx[j]-'0')^(ans[j]-'0'))+'0';
	}
	for(int i=0;i<size-1;i++)
	{
		int flag=fx[0]-'0';
		fx=fx.substr(1,fx.length()-1);
		fx+="0";
		if(flag)  //XOR
		{
			for(int j=0;j<size;j++) fx[j]=((fx[j]-'0')^(mx[j]-'0'))+'0';
		}
		cout<<"multiplied with x^"<<(i+1)<<":"<<" fx="<<fx<<endl;
		if(gx[gx.size()-1-i-1]=='1')
		{
			//cout<<"here i1="<<(gx.size()-1-i-1)<<endl;
			for(int j=0;j<size;j++) ans[j]=((fx[j]-'0')^(ans[j]-'0'))+'0';
		}
	}
	cout<<"f(x)=";output(fx);cout<<"\ng(x)=";output(gx);cout<<"\nProduct=";output(ans);cout<<endl;
}
int main()
{	
	cout<<"Enter Fx : ";
	cin>>fx;
	cout<<"Enter gx : ";
	cin>>gx;
	mx="00011011";
	fastMultiply();
	return 0;

}

/*TEST CASES

Enter Fx : 01101011
Enter gx : 01010011
multiplied with x^1: fx=11010110
multiplied with x^2: fx=10110111
multiplied with x^3: fx=01110101
multiplied with x^4: fx=11101010
multiplied with x^5: fx=11001111
multiplied with x^6: fx=10000101
multiplied with x^7: fx=00010001
f(x)=x^4+x^0
g(x)=x^6+x^4+x^1+x^0
Product=x^7+x^6+x^4+x^1



c157238@uselab103:~/Documents/c157238/fastmult$ ./a.out
Enter Fx : 11001001
Enter gx : 101101110
multiplied with x^1: fx=10001001
multiplied with x^2: fx=00001001
multiplied with x^3: fx=00010010
multiplied with x^4: fx=00100100
multiplied with x^5: fx=01001000
multiplied with x^6: fx=10010000
multiplied with x^7: fx=00111011
f(x)=x^5+x^4+x^3+x^1+x^0
g(x)=x^7+x^5+x^4+x^2+x^1+x^0
Product=x^6+x^3+x^1
c157238@uselab103:~/Documents/c157238/fastmult$ 




