#include <iostream>
using namespace std;

int sum(int a[],int size){
	int sum=0;
	for(int i=0;i<size;i++){
		sum+=a[i];
	}
	return sum;
}

void print(int a[],int size){
	static int solutions =1;
	cout<<"Solution #"<<solutions<<endl;
	for(int i=0;i<size;i++){
		if(a[i]==0)break;
		cout<<a[i];
	}
	cout<<endl;
	solutions++;
}

int main(){
	int n=0,k=0,c=0;
	
	cout<<"How many steps are in the staircase? : ";
	cin>>n;
	
	cout<<"How many steps can you skip as most? : ";
	cin>>k;
	
	cout<<endl;
	
	int *staircase = new (nothrow) int[n];
	for(int i=0;i<n;i++)staircase[i]=0;
	
	staircase[0]=1;
	
	while(c>=0){		
		if(sum(staircase,n)==n) print(staircase,n);
		if(c==n-1)c=c-1;
		++c;
		
		while(c>=0){
			staircase[c]++;
			if(staircase[c]>k){
				staircase[c]=0;
				--c;
			}else break;
		}
	}	
	
	return 0;
}
