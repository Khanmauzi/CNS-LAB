#include <bits/stdc++.h>
using namespace std;
int r=0;
int c=0;



void show(int mat[][5]){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cout<<mat[i][j]<<"\t";
		}
		cout<<endl;
	}
}



void printd(vector<string>v){
	cout<<"Douplet for encryption are : "<<endl;
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<endl;
	}
}
void getans(int mat[][5],int n){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if(mat[i][j]==n){
				r=i;
				c=j;
				break;
			}
		}
	}
}
void getdec(int mat[][5],vector<string>v,vector<string>&dec){
	string temp,ans;
	int r1,r2,c1,c2;
	for(int i=0;i<v.size();i++){
		temp=v[i];
		ans="";
		r=0;
		c=0;
		r1=0;
		c1=0;
		r2=0;
		c2=0;
		int n1=temp[0]-'a';
		int n2=temp[1]-'a';
		getans(mat,n1);
		r1=r;
		c1=c;
		r=0;
		c=0;
		getans(mat,n2);
		r2=r;
		c2=c;
		//cout<<r1<<r2<<c1<<c2<<endl;
		if(r1==r2){
			// belong to same row
			c1=(c1+1)%5;
			c2=(c2+1)%5;
			char ch='a'+mat[r1][c1];
			ans=ans+ch;
			ch='a'+mat[r2][c2];
			ans=ans+ch;
		}
		else if(c1==c2){
			r1=(r1+1)%5;
			r2=(r2+1)%5;
			char ch='a'+mat[r1][c1];
			ans=ans+ch;
			ch='a'+mat[r2][c2];
			ans=ans+ch;
		}
		else if(r1!=r2&&c1!=c2){
			int k=r1;
			r1=r2;
			r2=k;
			char ch='a'+mat[r1][c1];
			ans=ans+ch;
			ch='a'+mat[r2][c2];
			ans=ans+ch;
		}
		dec.push_back(ans);
	}
}


void showdec(vector<string>v){
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<endl;
	}
}

int main(){
	string s;
	cout<<"enter the key: ";
	cin>>s;
	int mat[5][5]={0};
	int alph[26]={0};
	int k='q'-'a';
	alph[k]=1;
	int i=0;int j=0;
	for(int l=0;l<s.length();l++){
		int k=s[l]-'a';
		//cout<<k<<i<<j<<endl;
		if(alph[k]==1)
			continue;
		else{
			mat[i][j++]=k;
			alph[k]=1;
			if(j==5){
				i=i+1;
				j=0;
			}
		}
	}
	for(int l=0;l<26;l++){
		if(alph[l]==1){
			continue;
		}
		else{
			alph[l]=1;
			mat[i][j++]=l;
			if(j==5){
				i=i+1;
				j=0;
			}
		}
	}
	cout<<"***************************************************************************************"<<endl;
	show(mat);
	cout<<"****************************************************************************************"<<endl;
	cout<<"enter the text to be encrypted : ";
	cin>>s;
	int l=s.length();
	/*string en="";
	for(int i=0;i<l-1;i++){
		if(s[i]!=s[i+1])
			en=en+s[i];
		else{
			en=en+s[i]+'x';
		}
	}
	l=en.length();
	if(l&1){	// odd length input
		en=en+'z';
	}
	cout<<en<<endl;*/
	vector<string>v;
	string temp;
	i=0;
	char a,b;
	while(i<l){
		temp="";
		a=s[i++];
		if(i==l){
			b='z';
		} else{
			b=s[i++];
		}
		if(a!=b){
			temp=temp+a+b;
			//cout<<temp<<endl;
			v.push_back(temp);
		}
		else if(a==b){
			temp=temp+a+'x';
			//cout<<temp<<endl;
			v.push_back(temp);
			i--;
		}
	}
	printd(v);
	cout<<"************************************************************************************************"<<endl;
	vector<string>dec;
	getdec(mat,v,dec);
	cout<<"************************************************************************************************"<<endl;
	cout<<"decrypted text are : "<<endl;
	showdec(dec);
	cout<<"**************************************************************************************************"<<endl;

	return 0;
}



/* TEST CASES
c157238@uselab103:~/Documents/c157238/Playcipher$ g++ playcipher.cpp -o play
c157238@uselab103:~/Documents/c157238/Playcipher$ ./play
enter the key: hii
***************************************************************************************
7	8	0	1	2	
3	4	5	6	9	
10	11	12	13	14	
15	17	18	19	20	
21	22	23	24	25	
****************************************************************************************
enter the text to be encrypted : hello
Douplet for encryption are : 
he
lx
lo
************************************************************************************************
************************************************************************************************
decrypted text are : 
di
wm
mk

***********************************************************************************************

c157238@uselab103:~/Documents/c157238/Playcipher$ ./play
enter the key: chikosowkya
***************************************************************************************
2	7	8	10	14	
18	22	24	0	1	
3	4	5	6	9	
11	12	13	15	17	
19	20	21	23	25	
****************************************************************************************
enter the text to be encrypted : founadkdorkaorkahrnalfirmkdkrpajrmdlaridkdlals
Douplet for encryption are : 
fo
un
ad
kd
or
ka
or
ka
hr
na
lf
ir
mk
dk
rp
aj
rm
dl
ar
id
kd
la
ls
************************************************************************************************
************************************************************************************************
decrypted text are : 
ij
mv
gs
gc
bz
ag
bz
ag
mo
yp
dn
no
hp
cg
lr
gb
ln
lt
pb
fc
gc
sp
td
**************************************************************************************************
c157238@uselab103:~/Documents/c157238/Playcipher$ 
