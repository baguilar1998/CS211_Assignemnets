#include <iostream>
using namespace std;

int main(){
	int num = 1;
	int square =0;
	while(num!=0){
		square=num*num;
		if((square%10)%2==1 && ((square/10)%10)%2==1){break;}
		++num;
	}
	
	//There is no right answer to this problem, but a random number will be displayed due to an overflow
	cout<<"The number of the perfect square is: "<<num<<endl;
	return 0;
}
