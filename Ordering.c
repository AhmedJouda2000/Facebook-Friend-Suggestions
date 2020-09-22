#include <stdio.h>
#include <string.h>



//GLOBAL VARIABLES
//Array that contains the possible friend suggestions unordered (Other users who arent friends with the selected user)
  char friendsSuggestions[5][80];
//The array containing facebook users
  char users[6][80];
//The total number of friends for each user (Note that less than 4 friends can be provided for each facebook user)
  int numFriendsPerUser[6];
//The index of the Facebook user(+1) which the user selects to get suggestions for
  int wanted_user;

//This function takes in the number of possible suggestions for the selected user
int ordering(int NumberOfSuggestions)
{
    //Assign the NumberOfSuggestions to "z" for ease of use
    int z = NumberOfSuggestions;
    
    //Populate the following array with the number of friends of the suggested friends
    //initialize the array to get rid of the junk values
    int numFriendsOfSuggestions[5] = {-1,-1,-1,-1,-1};
    
    
    int x=0; //this counter will increment the new array as we fill it
    size_t y; //declare the inner loop counter, its declared outside the loop for further use later

    //these nested loops iterate z times (number of suggestions) and compares it to the users array
    //once a friend suggestion is matched with the user array then we copy the number of friends of that user into the new array
    for (size_t w = 0; w < z; w++)
      {
        for (y = 0; y < 6; y++)
          {
            if (strcmp(friendsSuggestions[w], users[y])==0)
             {
                numFriendsOfSuggestions[x++] = numFriendsPerUser[y];
             }
          }

      }   
    

    //using selection sort order suggestions according to number of their friends and if 
    //they have the same number of friends order alphabetically 
    
    //declare "l" & "m" which are loop counters
    //declare "maxindex" which is needed as a marker in insertion sort
    //declare "swap" which will be used to swap elements in an array
    int l, m, maxIndex, swap;
    //declare a char array of size 80 which will be used to swap strings in an array when ordering
    char strswap[80];

    //selection sort compares pairs of elements for more efficiency and therefore orders the array
    //It divides and conquers, it finds the max in each sub array
    //The following orders the array in descending order as we want the user with the most friends to be first
    for (l = 0; l < 4; l++)
      {
        maxIndex = l;
        for (m = l+1; m < 5; m++)
          {
            //This checks who has more friends
            if (numFriendsOfSuggestions[maxIndex] < numFriendsOfSuggestions[m])
             {
                maxIndex = m;
             }
            //This checks if they have the same number of friends and then if they do it orders them alphabetically 
            else if (numFriendsOfSuggestions[maxIndex] == numFriendsOfSuggestions[m])
                  {
                    if (strcmp(friendsSuggestions[maxIndex], friendsSuggestions[m])>0)
                     {
                        maxIndex = m;
                     }
                  }
          }
        //This swaps the numbers in the numFriendsOfSuggestions array to order them
        swap = numFriendsOfSuggestions[maxIndex];
        numFriendsOfSuggestions[maxIndex] = numFriendsOfSuggestions[l];
        numFriendsOfSuggestions[l] = swap;

        //This swaps the actual user suggestions accordingly to order them too
        strcpy(strswap, friendsSuggestions[maxIndex]);
        strcpy(friendsSuggestions[maxIndex], friendsSuggestions[l]);
        strcpy(friendsSuggestions[l], strswap);
      }

      //Print out the ordered suggestions for the selected user
      printf("\n\nSuggested Friends for %s \n%s\n%s", users[wanted_user-1], friendsSuggestions[0], friendsSuggestions[1]);


return 0;
}