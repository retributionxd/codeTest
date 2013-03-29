#include <iostream>
using namespace std;

typedef struct
{

 int x;
  int y;

} point;
 
int main()
{

  int grid[3][3];
  int playerId;
  int opponentId;
  point playerPositions[3];
  point opponentPositions[3];
  point zeroPositions[3];

  bool foundPlayerId=false;
  bool foundOpponentId=false;
  bool foundZeroes=false;


   int playerCounter=0;
   int opponentCounter=0;
   int zeroesCounter=0;
   for(int i=0;i<3;i++)
   {

         for(int j=0;j<3;j++)
        {
                
              cin >>grid[i][j];


         } 


   } 


   cin >> playerId;


  opponentId=playerId==1?2:1;


   for(int i=0;i<3;i++)
   {

         for(int j=0;j<3;j++)
        {
                
                  if(grid[i][j]==playerId)
                  {
                   foundPlayerId=true;
                    playerPositions[playerCounter].x=j;
                    playerPositions[playerCounter].y=i;
                    playerCounter++;
                    
                 }
                 
                 else if(grid[i][j]==opponentId)
                {
                    foundOpponentId=true;
                    opponentPositions[opponentCounter].x=j;
                    opponentPositions[opponentCounter].y=i;
                    opponentCounter++;


                }  
                else
                {
                 
                  
                    foundZeroes=true;
                    zeroPositions[zeroesCounter].x=j;
                    zeroPositions[zeroesCounter].y=i;
                    zeroesCounter++;

                  }
         

              } 


   } 
  

      if(!foundPlayerId) //initial move
       {



                 //check if centre is occupied
                      
                    if(grid[1][1]==0)
                     {
                              //OUTPUT POSITION
                             
                               
                     }



         }


   



}
