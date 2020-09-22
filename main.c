#include <stdio.h>
#include <string.h>
#include "prototypes.h"

//GLOBAL VARIABLES
//The array containing Facebook users
  char users[6][80];

//Friends for User 1
  char friendsUser1[4][80];
//Friends for User 2
  char friendsUser2[4][80];
//Friends for User 3
  char friendsUser3[4][80];
//Friends for User 4
  char friendsUser4[4][80];
//Friends for User 5
  char friendsUser5[4][80];
//Friends for User 6
  char friendsUser6[4][80];

//The total number of Facebook users (Note it can be less than 6), intialise it to 0
  int numOfUsers =0;

//The total number of friends for each user (Note that less than 4 friends can be provided for each facebook user)
  int numFriendsPerUser[6];
  
//The function to provide users as input
int inputFacebookUsers();
int main(void)
{

  // invoke here the function to provide users as input
  //The function "inputFacebookUsers" returns the number of users inputed, so assign that to the global variable numOfUSers
   numOfUsers = inputFacebookUsers();

  //print out the number of Facebook users that have been provided as input
   printf("%d Facebook users have been provided as input",numOfUsers);

  //Call the function AskForSuggestions which returns the number of possible suggestions for the selected user, store that in the integer variable "NumberOfSuggestions"
   int NumberOfSuggestions = AskForSuggestions();
  //Call the function "ordering" with the parameter "NumberOfSuggestions"
   ordering(NumberOfSuggestions);

  return 0;
}


/*
  This function asks the users to provide a list of Facebook users.
  For each Facebook users it will be necessary to add a set of friends
 */
int inputFacebookUsers(){
    int i=0;
    //Allow the loop to iterate a maximum of 6 times because we are allowed a maximum of 6 users
    while(i< 6){
        //Prompt the user to input a Facebook user
        printf("%s", "Insert a Facebook user:\n");
        //fgets reads a line of text so its better than scanf and scanf doesnt perform bound checking
        //you cant read a space using scanf
        fgets(users[i],80,stdin);
        /*
          Checks whether a carriage return symbol was provided as input, so if the user presses enter 
          on an empty line we know he has no more users to input and we break out of the loop
         */
        if(users[i][0] == '\n')
            break;
            //Add a new line
            printf("\n");
        //For each iteration call the function "inputFriends" passing with it the array that stores the friends of that user
        /*The function "inputFriends" then returns the number of friends of that user so we assign that to the array "NumFriendsPerUser" 
          in the same index of the user then break out of the switch*/
        switch(i){
            case 0: numFriendsPerUser[i]= inputFriends(friendsUser1);
                    break;
            case 1: numFriendsPerUser[i]= inputFriends(friendsUser2);
                    break;
            case 2: numFriendsPerUser[i]= inputFriends(friendsUser3);
                    break;
            case 3: numFriendsPerUser[i]= inputFriends(friendsUser4);
                    break;
            case 4: numFriendsPerUser[i]= inputFriends(friendsUser5);
                    break;
            case 5: numFriendsPerUser[i]= inputFriends(friendsUser6);
            default: break;
        }
        
        //print a couple of empty lines
        printf("\n\n");
        //increment i (counter) by 1 as we just added a user
        i++;
    }
    //return i, which is the number of users inputed
    return i;
}