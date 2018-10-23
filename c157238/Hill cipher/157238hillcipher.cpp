#include <stdio.h>
#include <assert.h>
#include <gmp.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>


using namespace std;
int size=0;
void generate(char key[],int matrix[][3],int size){
	int cnt=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			matrix[i][j]=(int)key[cnt++]-65;

		}
	}
}
void print(int matrix[][3],int val[],int size){
	for(int i=0;i<size;i++){
		cout<<"|"<<"\t";
		for(int j=0;j<size;j++){
            if(i<3&&j<3)
			cout<<matrix[i][j]<<"\t";
            else
            cout<<" "<<"\t";
		}
		cout<<"|"<<"\t"<<"|"<<"\t"<<val[i]<<"\t"<<"|";
		cout<<endl;
	}
}
void print1(float matrix[][3],int val[],int size){
	for(int i=0;i<size;i++){
		cout<<"|"<<"\t";
		for(int j=0;j<size;j++){
			cout<<matrix[i][j]<<"\t";
		}
		cout<<"|"<<"\t"<<"|"<<"\t"<<val[i]<<"\t"<<"|";
		cout<<endl;
	}
}
void getval(int val[],char inputstr[],int size){
	for(int i=0;i<size;i++){
		val[i]=(int)inputstr[i]-65;
	}
}
void getencryption(int matrix[][3],int val[],int encrypt[],int size){
	int i=0;
    int temp=0;
    while(i<size&&temp<size){
        for(int k=0;k<3;k++){
    		int sum=0;
            int l=temp;
    		for(int j=0;j<3;j++){
    			sum=sum+matrix[k][j]*val[l++];
    		}
    		encrypt[i++]=sum%26;
    	}
        temp=temp+3;
    }

}

void printencryption(int encrypt[],int size){
	for(int i=0;i<size;i++){
		cout<<(char)(encrypt[i]+65);
	}
	cout<<endl;
}

void show(int encrypt[],int n){
    for(int i=0;i<n;i++){
        cout<<encrypt[i]<<"  ";
    }
    cout<<endl;
}

//************************************************************CALCULATE DETERMINANT OF MATRIX**************************************************
void getCofactor(int mat[][3], int temp[][3], int p, int q, int n)
{
    int i = 0, j = 0;
 
    // Looping for each element of the matrix
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            //  Copying into temporary matrix only those element
            //  which are not in given row and column
            if (row != p && col != q)
            {
                temp[i][j++] = mat[row][col];
 
                // Row is filled, so increase row index and
                // reset col index
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}
 
/* Recursive function for finding determinant of matrix.
   n is current dimension of mat[][]. */
int determinantOfMatrix(int mat[][3], int n)
{
    int D = 0; // Initialize result
 
    //  Base case : if matrix contains single element
    if (n == 1)
        return mat[0][0];
 
    int temp[3][3]; // To store cofactors
 
    int sign = 1;  // To store sign multiplier
 
     // Iterate for each element of first row
    for (int f = 0; f < n; f++)
    {
        // Getting Cofactor of mat[0][f]
        getCofactor(mat, temp, 0, f, n);
        D += sign * mat[0][f] * determinantOfMatrix(temp, n - 1);
 
        // terms are to be added with alternate sign
        sign = -sign;
    }
 
    return D;
}

int getmi(int d){
    for(int i=1;i<26;i++){
        int k=d*i;
       // cout<<"k : "<<k<<"  i: "<<i<<endl;
       // cout<<k%26<<endl;
        if(k%26==1)
            return i;
    }
    return 0;
}
void getmati(int m[][3],int inv[][3],int d){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int temp=m[i][j]*d;
            inv[i][j]=temp%26;
        }
    }
} 
void inverseKEYMatrix(int KEY[][3],int INVERSE[][3]){
    int determinant = 0;
    for(int i = 0; i < 3; i++)
        determinant = determinant + (KEY[0][i] * (KEY[1][(i+1)%3] * KEY[2][(i+2)%3] - KEY[1][(i+2)%3] * KEY[2][(i+1)%3]));
    if(determinant == 0) {cout<<"Improper key!"<<endl; exit(1);}

    bool sign = false;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){  
            int temp   = ((KEY[(j+1)%3][(i+1)%3] * KEY[(j+2)%3][(i+2)%3]) - (KEY[(j+1)%3][(i+2)%3] * KEY[(j+2)%3][(i+1)%3]))%26;
            /*if(!sign) temp = -temp;
            sign = !sign;*/
            if(temp<0) temp += 26;
            temp = 26-temp;
            INVERSE[i][j] =(temp);
          }
    }
   /* cout<<"inverse matrix: "<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            cout<<INVERSE[i][j]<<"\t";
        cout<<endl;
    }*/


}

int main(){
	srand(time(NULL));
	char inputstr[1024];
	//char key[1024];
//mpz_t n;
	cout<<"enter the string : ";
	scanf("%1023s",inputstr);
	//cout<<strlen(inputstr)<<endl;
    size=strlen(inputstr);
	char key[10];
	int matrix[3][3];
    int  inv[3][3]; /// TO STORE THE INVERSE OF THE MATRIX
    string Mkey = "GYBNQKURP";
	for(int i=0;i<9;i++){
		//cin>>key[i];

		//int t=rand()%26;
		//cout<<t<<endl;
		key[i]=Mkey[i];
	}
	key[9]='\0';
	cout<<"Auto generated key is : ";
	cout<<key<<endl;
	int val[size];
	int encrypt[size];
	generate(key,matrix,size);             // generate matrix from the key
	getval(val,inputstr,size);
	
	cout<<"*******************    ENCRYPTION   ****************************************"<<endl;
	print(matrix,val,size);

	
	cout<<"*************************************************************************"<<endl;
	
	getencryption(matrix,val,encrypt,size);         //this function will convert the input into hillcipher encryption text 
	
	cout<<endl<<endl;

    cout<<"**********************encryption code is **************************"<<endl<<endl;
    show(encrypt,size);

    cout<<endl<<endl;
	
	cout<<"******************    Ciphertext is :**************************************"<<endl<<endl;
	
	printencryption(encrypt,size);
	
	cout<<endl<<endl;
	
	cout<<"************************************************************************"<<endl<<endl;
	
	cout<<"***************************** DECRYPTION ****************************** "<<endl<<endl;
	
	//int adj[26][26];
    int d=determinantOfMatrix(matrix,3);
    if(d==0){
        cout<<"invalid key, DECRYPTION not possible"<<endl;
    }
    else{
        cout<<"DETERMINANT: "<<d<<endl;
        d=getmi(d);                     //get inverse multiplicative of d
        if(d==0){
            cout<<"multiplicative inverse doesn't exist for the matrix, wrong DECRYPTION"<<endl;
        }
        else{
            cout<<"MULTIPLICATIVE INVERSE OF DETERMINANT: "<<d<<endl;
           // getmati(matrix,inv,d);          // get the matrix inverse
            //print(inv,encrypt,size);
            inverseKEYMatrix(matrix,inv);
            print(inv,encrypt,size);
            getencryption(inv,encrypt,encrypt,size);
            printencryption(val,size);
        }
    }
	
	
	return 0;
}


/******************TEST_CASES*********************************************************************






c157238@uselab104:~/Documents/c157238/Hill cipher$ ./a.out
enter the string : HELLOW
Auto generated key is : GYBNQKURP
*******************    ENCRYPTION   ****************************************
|   6   24  1               |   |   7   |
|   13  16  10              |   |   4   |
|   20  17  15              |   |   11  |
|                           |   |   11  |
|                           |   |   14  |
|                           |   |   22  |
*************************************************************************


**********************encryption code is **************************

19  5  9  8  15  8  


******************    Ciphertext is :**************************************

TFJIPI


************************************************************************

***************************** DECRYPTION ****************************** 

DETERMINANT: 441
MULTIPLICATIVE INVERSE OF DETERMINANT: 25
|   8   5   10              |   |   19  |
|   21  8   21              |   |   5   |
|   21  12  8               |   |   9   |
|                           |   |   8   |
|                           |   |   15  |
|                           |   |   8   |
HELLOW




c157238@uselab104:~/Documents/c157238/Hill cipher$ ./a.out
enter the string : HII
Auto generated key is : GYBNQKURP
*******************    ENCRYPTION   ****************************************
|   6   24  1   |   |   7   |
|   13  16  10  |   |   8   |
|   20  17  15  |   |   8   |
*************************************************************************


**********************encryption code is **************************

8  13  6  


******************    Ciphertext is :**************************************

ING


************************************************************************

***************************** DECRYPTION ****************************** 

DETERMINANT: 441
MULTIPLICATIVE INVERSE OF DETERMINANT: 25
|   8   5   10  |   |   8   |
|   21  8   21  |   |   13  |
|   21  12  8   |   |   6   |
HII

c157238@uselab104:~/Documents/c157238/Hill cipher$ ./a.out
enter the string : THEATTACKONGAZI
Auto generated key is : GYBNQKURP
*******************    ENCRYPTION   ****************************************
|   6   24  1                                               |   |   19  |
|   13  16  10                                              |   |   7   |
|   20  17  15                                              |   |   4   |
|                                                           |   |   0   |
|                                                           |   |   19  |
|                                                           |   |   19  |
|                                                           |   |   0   |
|                                                           |   |   2   |
|                                                           |   |   10  |
|                                                           |   |   14  |
|                                                           |   |   13  |
|                                                           |   |   6   |
|                                                           |   |   0   |
|                                                           |   |   25  |
|                                                           |   |   8   |
*************************************************************************


**********************encryption code is **************************

0  9  13  7  0  10  6  2  2  12  8  19  10  12  25  


******************    Ciphertext is :**************************************

AJNHAKGCCMITKMZ


************************************************************************

***************************** DECRYPTION ****************************** 

DETERMINANT: 441
MULTIPLICATIVE INVERSE OF DETERMINANT: 25
|   8   5   10                                              |   |   0   |
|   21  8   21                                              |   |   9   |
|   21  12  8                                               |   |   13  |
|                                                           |   |   7   |
|                                                           |   |   0   |
|                                                           |   |   10  |
|                                                           |   |   6   |
|                                                           |   |   2   |
|                                                           |   |   2   |
|                                                           |   |   12  |
|                                                           |   |   8   |
|                                                           |   |   19  |
|                                                           |   |   10  |
|                                                           |   |   12  |
|                                                           |   |   25  |
THEATTACKONGAZI






