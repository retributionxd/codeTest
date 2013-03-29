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


int copyBigNumber(ul* source,  ul**destination,ul sourceDigits)
{

   for(int i=0;i<sourceDigits;i++)
   {
        (*destination)[i]=source[i];

   }

   return sourceDigits;
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
          
void printBigNumber(ul* bigNumber,int noOfDigits)
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

 ul* memoFact[101];
 ul memoFactDigits[101];

    for(int i=0;i<101;i++)
    {

       memoFact[i]=(ul*)malloc(sizeof(ul)*1000);
      memoFactDigits[i]=0;        
 
    }  
  

     memoFactDigits[0]=storeBigNumber(&memoFact[0],1);
     memoFactDigits[1]=storeBigNumber(&memoFact[1],1);


       for(int i=2;i<101;i++)
      {

           ul* temp=(ul*)malloc(sizeof(ul)*DIGITS);


             ul tempDigits=copyBigNumber(memoFact[i-1],&temp,memoFactDigits[i-1]);
                tempDigits=multiplyBigNumberWithInt(&temp,i,tempDigits);

            memoFactDigits[i]=copyBigNumber(temp,&memoFact[i],tempDigits);                 
          

           }



       int noOfTestCases;

       cin >>noOfTestCases;

 
      for(int i=0;i<noOfTestCases;i++)
        {
              ul theNumber;
              cin>>theNumber;
             printBigNumber(memoFact[theNumber],memoFactDigits[theNumber]);
           

          }
      

  

}



