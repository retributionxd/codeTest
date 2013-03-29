#include <iostream>
#include <cstdlib>
using namespace std;

typedef   unsigned long long int ul;

ul safeValue=50;


int storeBigNumber(ul** bigNumber,ul theNumber)
{

  int numberOfDigits=0;
  while(theNumber>0)
  {
       
        (*bigNumber)[numberOfDigits++]=theNumber%10;
        theNumber=theNumber/10;
       
   }

  return numberOfDigits;
}



int multiplyBigNumberWithInt(ul** bigNumber,ul theNumber,int numberOfDigits)
{





 ul  carry=0;

 int i=0;
 for(i=0;i<numberOfDigits;i++)
 {

  ul temp= (theNumber *  (*bigNumber)[i]  ) +carry;

     (*bigNumber)[i]=temp%10;
        
     carry=temp/10; 
  }                         
         

   
  while(carry>0)
 {
  (*bigNumber)[i++]=carry%10;
  carry=carry/10;
   
 }
  
 
  return i;
}



//input shud be a valid number
int readBigNumberFromConsole(ul** bigNumber)
{

  string number;
  cin>>number;
int index=0 ;
  for( string::iterator i=number.end()-1;i>=number.begin();--i)
  {

      (*bigNumber)[index++]=(*i)-'0';
  }

  return index;
}
          
void printNumber(ul* bigNumber,int noOfDigits)
{


  for(int i=noOfDigits-1;i>=0;i--)
  {

    cout<<bigNumber[i];
     
  }

  cout<<endl;

}

#define DIGITS 1000000






/***BIG NUMBER TEST****/

int main()
{

      ul* temp=(ul*)malloc(sizeof(ul)*DIGITS);
        ul tempNumber;
        ul noOfDigits=0; 
      while(1)
     {

      cout<<"ENTER BIG NUMBER"<<endl;
    noOfDigits= readBigNumberFromConsole(&temp);

     cout<<"ENTER MULTIPLIER"<<endl;
    cin >> tempNumber;

      noOfDigits=multiplyBigNumberWithInt(&temp,tempNumber,noOfDigits);

    cout<<"RESULT IS:  ";
    printNumber(temp,noOfDigits);
 
     }
    return 0;
  
}



