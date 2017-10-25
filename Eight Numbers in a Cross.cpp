#include <iostream>
using namespace std;

bool ok(int q[], int c) {
   static int adj[8][5]={
	   {-1},
	   {0,-1},
	   {0,1,-1},
	   {0,2,-1},
	   {1,2,-1},
	   {1,2,3,4,-1},
	   {2,3,5,-1},
	   {4,5,6,-1}
   };
   
   for(int i=1;i<=c;i++){
      if (q[c]==q[i-1])
         return false;
	}
   
   
   for(int i=0;i<8;i++){
   	if(adj[c][i]==-1)break;
   	if(q[c]-1==q[adj[c][i]] || q[c]+1==q[adj[c][i]]) return false;
   }
   
   return true;
}

void print(int q[]) {
   static int numOfSolutions =1;
   cout<<"Solution #"<<numOfSolutions<<endl;
   cout << "  " <<q[1]<<q[4]<< ' '<< endl;
   cout <<" "<< q[0] <<q[2]<<q[5]<<q[7]<< ' '<< endl;
   cout << "  " <<q[3]<<q[6]<< ' '<< endl;
   ++numOfSolutions;
}

void next(int q[], int c) {
   if (c == 8)
      print(q);
   else for (q[c] = 1; q[c] < 9; ++q[c])
      if (ok(q, c))
         next(q, c+1);
}

int main() {
   int q[8];
   next(q, 0);
   return 0;
}
