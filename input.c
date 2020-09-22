#include <stdio.h>
#include <string.h>


/*
  This method asks the user to provide as input the friends
  of a Facebook user.
  
  Input: 
  friends, contain the names of friends provided as input
  
  Output:
  Returns the number of friends provided as input. Note that
  a user may decide to input less than 6 friends. 
 */


//GLOBAL VARIABLES
//The array containing facebook users
char users[6][80];
/*Integer variable that we increment every time "inputFriends" is called, because 
  we need it to print out the friends of which user are we asking for now we couldn't 
  use i because it increments inside the while loop, while j only increments when we 
  call the function*/
int j = -1;
//This function takes in the array of friends of the selected user and fills it up and returns the number of friends provided for the user
int inputFriends(char friends[][80])
{
  //Declare the loop counter and initialize it to 0
  int i=0;
  //increment j by 1 so that we print out the right user name when promoting the user to enter the friends
  j++;
  
  //Loop, asking for input(friend of the user) until you reach 4 friends which is the max allowed 
  while(i< 4){
      printf("Insert friend %d for %s", i+1, users[j]);
      //Store the friend inputed in the array of friends of the current user
      fgets(friends[i],80,stdin);

      /*
        Checks whether a carriage return symbol was provided as input, so if the user presses enter 
        on an empty line we know he has no more users to input and we break out of the loop
      */
      if(friends[i][0] == '\n')
          break;
      //increment the number of friends inputed by 1
      i++;
  }
    //return the number of friends inputed for the user
    return (i);
}

