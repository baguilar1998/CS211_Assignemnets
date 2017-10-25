#include <iostream>
using namespace std;

bool ok(int q[], int c) {
   for(int i=1;i<=c;i++)
      if (q[c]==q[i-1] || q[c]-i==q[c-i] || q[c]+i==q[c-i])
         return false;
   return true;
}

// This function should return the number of solutions for the given board size.
int nqueens(int n) {
   int *a;
   a= new (nothrow) int[n];
   for(int i=0;i<n;i++) a[i]=0;
   
   int c=0,r=0,solutions=0;
   while (c >= 0) {
      ++c;
      if(c>=n){
      	++solutions;
      	--c;
      	r=a[c];
      }
      else r=-1;
      while (c >= 0) {
         ++r;
		 a[c]=r;
         
         if(r>=n){
         	--c;
         	r=a[c];
         }
         else if(ok(a,c)) break;
      
	  }
   }
   
   delete []a;
   return solutions;
}

int main() {
   int n = 12;
   for (int i = 1; i <= n; ++i)
      cout << "There are " << nqueens(i) << " solutions to the " << i << " queens problem.\n";
   return 0;
}
   
