/*
Problem statement: Given sequence k = k1 <k2 < … <kn of n sorted keys, with a search probability pi for each key ki . 
Build the Binary search tree that has the least search cost given the access probability for each key? */

#include<iostream>
#define MAX 10
using namespace std;

int find(int,int);
void print(int,int);
int p[MAX],q[MAX],w[10][10],c[10][10],r[10][10],i,j,k,n,m;
char idnt[7][10];


int find(int i,int j)
{
	int min=2000,m,l;//c[i][j];
	for(m=i+1;m<=j;m++)
        if(c[i][m-1]+c[m][j]<min)
        {
			min=c[i][m-1]+c[m][j];
            l=m;
        }
        return l;
}
void print(int i,int j)
{
    if(i<j)
		cout<<idnt[r[i][j]]<<"\n"<<"root"<<endl;
    else
        return;
	
	print(i,r[i][j]-1);
    print(r[i][j],j);    
}

int main()
{

    cout<<"\nEnter a number of identifiers : ";
    cin>>n;
    cout<<"\nEnter identifiers : ";
    for(i=1;i<=n;i++)
    cin>>idnt[i];
    cout<<"\nEnter success probability for identifiers : ";
    for(i=1;i<=n;i++)
    cin>>p[i];
    cout<<"\nEnter failure probability for identifiers : ";
    
	for(i=0;i<=n;i++)
    cin>>q[i];
    cout<<"\n-------------------------------------------\n";
	cout<<"\n\tWeight"<<"\t\t"<<"Cost"<<"\t\t"<<"Root";
        
    for(i=0;i<=n;i++)
    {
        w[i][i]=q[i];
        c[i][i]=r[i][i]=0;
        cout<<"\n\t"<<w[i][i]<<"\t\t"<<c[i][i]<<"\t\t"<<r[i][i];
	}
	cout<<"\n-------------------------------------------\n";
	cout<<"\n\tWeight"<<"\t\t"<<"Cost"<<"\t\t"<<"Root";
    for(i=0;i<n;i++)
    {
        j=i+1;
        w[i][j]= p[j]+q[i]+q[j]; // w(i,j)= p[j]+q[i]+w(i,j-1)
        c[i][j]=w[i][j]+c[i][j-1]+c[j][j]; // c(i,j)= min { c (i,k-1)+c(k+1, j) }+ w(i,j))
         //c[i][j]=q[i]+q[j]+p[j];

        r[i][j]=j;
        cout<<"\n\t"<<w[i][j]<<"\t\t"<<c[i][j]<<"\t\t"<<r[i][j];
    }
    cout<<"\n-------------------------------------------\n";
	cout<<"\n\tWeight"<<"\t\t"<<"Cost"<<"\t\t"<<"Root";        
    for(m=2;m<=n;m++)
    {
        for(i=0;i<=n-m;i++)
        {
            j=i+m;
            w[i][j]=w[i][j-1]+p[j]+q[j];
            k=find(i,j);
            r[i][j]=k;
            c[i][j]=w[i][j]+c[i][k-1]+c[k][j];
            cout<<"\n\t"<<w[i][j]<<"\t\t"<<c[i][j]<<"\t\t"<<r[i][j];
        }
    }
    cout<<"\n-------------------------------------------------------------------------";
	cout<<"\n THE FINAL OBST IS : \n ";
	print(0,n);
	return 0;
}
