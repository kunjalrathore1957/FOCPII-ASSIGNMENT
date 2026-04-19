#include <iostream>
using namespace std;
int main() {
	int L,R,X=1;
	cin >> L>>R;
	for(int i=L;i<=R;i++){
      X^i;
	}    
	if(X/2==0){cout<<"\n even";}
	else 
{cout<<"\n odd";}
return 0;
}
