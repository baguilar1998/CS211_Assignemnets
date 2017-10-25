#include <iostream>
#include <cmath>
using namespace std;

// Returns true if the queen in column c is ok
bool ok(int q[], int c) {
   for(int i=1;i<=c;i++)
      if (q[c]==q[i-1] || q[c]-i==q[c-i] || q[c]+i==q[c-i])
         return false;
   return true;
}

void print(int q[]) {
   static int numSolutions = 0;
   cout << "Solution #" << ++numSolutions << ": ";
   for(int i=0;i<8;i++)cout<<q[i];
   cout << "\n";
}

int main() {
   int q[8] = {0}; 
	int c=0,r=0;
   while (c >= 0) {
      ++c;
      if(c>7){
      	print(q);
      	--c;
      	r=q[c];
      }
      else r=-1;
      while (c >= 0) {
         ++r;
		 q[c]=r;
         if(r>7){
         	--c;
         	r=q[c];
         }
         else if(ok(q,c)) break;
      
	  }
   }
   return 0;
}
