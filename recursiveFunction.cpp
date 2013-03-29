#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>
#include <stdio.h>
using namespace std;



unsigned long long int arraySize=(1000000000/6)+1;
unsigned long long int memoArray[1000000000/6+1];

unsigned long long int findMax(unsigned long long int param1, unsigned long long int param2,unsigned long long int* amount)
 {
  
 


	 //base case
    if(param1>=param2   )
     {


         (*amount)+=param1;
      
          return 0;
       }
     
      else       
       {

         param2=param1/2;
         unsigned long long int param3=param1/3;
         unsigned long long int param4=param1/4;

         return findMax(param2,param2/2+param2/3+param2/4,amount) + findMax(param3,param3/2+param3/3+param3/4,amount) + findMax(param4,param4/2+param4/3+param4/4,amount);


       } 

}

int main()
{

     unsigned long long int currentValue=0;
    
 


  while (scanf("%llu",&currentValue) != EOF)
  {

        

              
               unsigned long long int amount=0;
         
             findMax(currentValue,currentValue/2+currentValue/3+currentValue/4,&amount);
                    cout<<amount<<endl;



   }


 


return 0;
}
