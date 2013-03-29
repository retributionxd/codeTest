#include <iostream>
#include <string>
using namespace std;


int main()
{


  int dashesArray[9];

  
  dashesArray[0]=
  string theString;

  cin >>theString;

  int noOfDashes=0;
  for(string::iterator i=theString.begin();i<theString.end();++i)
  {
     noOfDashes+=dashesArray[*(i)];
    
   }

  cout << noOfDashes<<endl;

}
