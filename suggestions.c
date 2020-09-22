#include <stdio.h>
#include <string.h>

//GLOBAL VARIABLES
//Array that contains the possible friend suggestions unordered (Other users who arent friends with the selected user)
  char friendsSuggestions[5][80];
//The array containing facebook users
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

//The total number of facebook users (Note it can be less than 6)
  int numOfUsers;

//The total number of friends for each user (Note that less than 4 friends can be provided for each facebook user)
  int numFriendsPerUser[6];
//The index of the Facebook user(+1) which the user selects to get suggestions for
  int wanted_user;
  
//This function takes in nothing and returns z, the number of suggestions for the selected user
int AskForSuggestions()
{
    //Declare a 2d array "FriendsofSelectedUser" of dimensions 4 and 80, it will store the friends of the selected user
    //Thats why the first index is 4 as the max number of friends is 4, and the second index is 80 to fit the names
    char FriendsofSelectedUser[4][80];
    
    //Prompt the user to enter the number of the user they want suggestions for
    printf("\n\nInput the Facebook user to which you want to provide friends suggestions:\n");
    
    //Declare and initialize the loop counter (j) to 0
    //Declare and initialize a counter (a) to 1 which we will use to label the users
    int j = 0, a = 1;
    
    //loop until all the users are printed with a number labeling them
    while (j<numOfUsers)
        {
            printf("(%d) %s\n", a, users[j]);
            j++;
            a++;
        }
    //Take user input for the number of the user and place it in the global variable "wanted_user"
    scanf("%d", &wanted_user);





    //The following is to place the friends of selected user into the array FriendsofSelectedUser
    
    //declare a loop counter and initialize it to 0
    int counter = 0;
    
    //check which user we want to copy the friends of into the array
    //if wanted user = 1 then its friendsUser1 we are copying and so on
    /*So using the following switch statement we check which friends we are copying and
    once we know we use a while loop to copy the friends into the new array, using the
    function strcpy, we inceremnt the counter by 1 every time we copy a friend to ensure
    that it terminates at 4 friends. After we copy the friends of the selected user we
     break out of the switch statement*/
    switch(wanted_user){

        case 1: while (counter<4)
        {
            strcpy(FriendsofSelectedUser[counter], friendsUser1[counter]);
            counter++;
        }break;
        case 2: while (counter<4)
        {
            strcpy(FriendsofSelectedUser[counter], friendsUser2[counter]);
            counter++;
        }break;
        case 3: while (counter<4)
        {
            strcpy(FriendsofSelectedUser[counter], friendsUser3[counter]);
            counter++;
        }break;
        case 4: while (counter<4)
        {
            strcpy(FriendsofSelectedUser[counter], friendsUser4[counter]);
            counter++;
        }break;
        case 5: while (counter<4)
        {
            strcpy(FriendsofSelectedUser[counter], friendsUser5[counter]);
            counter++;
        }break;
        case 6: while (counter<4)
        {
        strcpy(FriendsofSelectedUser[counter], friendsUser6[counter]);
        counter++;
        }break;

        default: break;
     }

    
    //The following is to populate the array "friendsSuggestions" with users who aren't friends with the selected user
    //Declare and initialize the loop counters to 0
    int k =0, z=0;
    
    /*
    The following nested loop iterates over all the inputed users(for loop) 
    and compares them to the friends of the selected user(while loop), 
    (If statement) if they aren't a friend of the selected user and 
    they also aren't the actual selected user, then its added to the array "friendsSuggestions"
    The other if statement makes sure that we compared it to all the friends before eventually
    adding it to the array "friendsSuggestions", then we assign k=0 so we test a new user
    */
    for (int i = 0; i < numOfUsers; i++)
    {
        while (k<4)
        {
            if ((strcmp(users[i], FriendsofSelectedUser[k])!=0) && (strcmp(users[i], users[wanted_user-1])!=0))
             {
                if (k<3)
                 {
                    k++;
                 }
                else if (k==3)
                      {
                        strcpy(friendsSuggestions[z++], users[i]);
                        k++;
                      }
             }
            else break;
        }
        k=0;
    }



//return z, the number of names in the array friendsSuggestions
return z;
}