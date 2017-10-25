#include <iostream>
using namespace std;

int main() {
   while (true) {
      beginLoop:
		  string outcome;
	      cout << "Enter the race outcome: ";
	      cin >> outcome;
	      if(outcome=="done")return 0;
      
      int numTeams = 0;       
      int scores['Z'+1] = {}; 
      int counts['Z'+1] = {}; 
      
	  for (int i = 0; i < outcome.length(); ++i) { 
         if(scores[outcome[i]]==0)++numTeams;
         scores[outcome[i]] = scores[outcome[i]]+(i+1);
         counts[outcome[i]] = ++counts[outcome[i]];
      }
      

      equalTeams:
	      for (int i = 'A'; i <'Z'+1; i++){
				if(counts[i]!=0){
					if(counts[outcome[0]]!=counts[i]){
						cout<<"This is an invalid race input"<<endl;
						goto beginLoop;
					}
				}	
			}

		cout<<"There are "<<numTeams<<" teams."<<endl;
		cout<<"There are "<<counts[outcome[0]]<<" runners on each team."<<endl;
		double average =scores[outcome[0]]/(counts[outcome[0]]*1.0);
		char winner=outcome[0];
		for(int i=0; i<'Z'+1;i++){
			if(scores['A'+i]!=0){
				cout<<(char)('A'+i)<<": "<<scores['A'+i]/(counts['A'+i]*1.0)<<endl;
				if(average>scores['A'+i]/(counts['A'+i]*1.0)){
					average=scores['A'+i]/(counts['A'+i]*1.0);
					winner = 'A'+i;
				}
			}
		}
		cout<<"The winning team is team "<<winner<<" with a score of "<<average;

	cout<<endl;

   }
   return 0;
}
