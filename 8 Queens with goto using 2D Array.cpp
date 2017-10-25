#include <iostream>
using namespace std;

int main() {
   int q[8][8] = {0};
   int r = 0, c = 0;
   q[r][c] = 1;

nextCol:
   ++c;
   if (c>7)goto print;
   r = -1;

nextRow:
   
   ++r;
   if (r>7) goto backtrack;

   for(int i=1;i<c+1;i++){
      if (q[r][c-i]==1)
         goto nextRow;
	}
   
   for (int i = 1; i<=c; i++){ 
      if(c-i<0 || r-i<0)break;   
      if (q[r-i][c-i]==1)goto nextRow;
   }
   
   for (int i = 1; i<=c; i++){ 
  	  if(c-i<0 || r+i>7) break;   
	  if (q[r+i][c-i]==1)
         goto nextRow;
   }
   // Place a queen in the current square (2D version only)
	q[r][c]=1;
	
   goto nextCol;

backtrack:
	--c;
   if (c<0)return 0;
      

  	for(int i=0;i<8;i++){
  		if(q[i][c]==1){
  			r=i;
  			break;
  		}
  	}
  	
	q[r][c]=0;
	

   goto nextRow;

print:
   static int numSolutions = 0;
   cout << "Solution #" << ++numSolutions << ":\n";
   for(int i=0; i<8;i++){
   	for(int j=0; j<8;j++){
   		cout<<q[i][j];
   	}
   	cout<<endl;
   }
   cout<<endl;
   
   goto backtrack;
}
