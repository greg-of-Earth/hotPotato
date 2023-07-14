//Calderon, Gregory

/******** Instructor's Feedback Do NOT DELETE

check feedback.md

*********/
#include <iostream>
#include <ctime>
#include "node.h"
#include "linkedList.h"
#include <limits>
using namespace std;


void ShowMenu();
int GetNumPlyrs();
int MinNumPasses();
void PlayGame();
int GenerateNumPasses(int, int);
void ClearBfr(string);

enum MainMenu {
  PLAY =1,
  QUIT,
};

const string menuOptionsStr= "\nPlay Game\nQuit\nChoose option: ";

int main() {
  srand(time(NULL));
  ShowMenu();
  return 0;
} 

// output menu
void ShowMenu() {
  int option = -1;
  
  do {
    cout << menuOptionsStr;
    cin >> option;
    switch(option) {
      case PLAY:
        PlayGame();
        break;
      case QUIT:
        cout << "\nPROGRAM TERMINATED\n" << endl;
        break;
      default:
        ClearBfr("\nINVALID SELECTION.\n");
        break;
    }
  }while(option != QUIT);
}

// clear input buffer
void ClearBfr(string errorMsg) {
  cout << errorMsg;
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// ask for number of players 
// post: return number of players
int GetNumPlyrs() {
  int numPlyrs = -1;

  cout << "Enter number of players (minimum integer value 2): ";
  cin >> numPlyrs;
  while(numPlyrs <  2) {
    ClearBfr("\nINVALID SELECTION\n\nEnter minimium number of players (integer value greater or equal to 2): ");
    cin >> numPlyrs;   
  }
  ClearBfr("");
  return numPlyrs;
}

// ask for minim number of passes
// post: return minimum passes
int MinNumPasses() {
  int minPasses = -1;
   cout << "Enter minimium number of passes (integer value greater or equal to 2): ";
   cin >> minPasses; 
  
  while(minPasses < 2) {
    ClearBfr("\nERROR. INVALID SELECTION\n\nEnter minimium number of passes (integer value greater or equal to 2): ");
    cin >> minPasses;   
   
  }
  ClearBfr("");
  return minPasses;
}


// generate list and play game 
// post: list and all nodes are deleted 
void PlayGame() {
  int numPlyrs = -1;
  int minPasses = -1;
  
  LinkedList gameList;
  numPlyrs = GetNumPlyrs();
  minPasses = MinNumPasses();
  // for every round: GenerateNumPasses
  // traverse the list and delete the node while restructuring list
  // print the winner: last one left in list 
  // deallocate memory 

  try { 
      gameList.AddNode(numPlyrs); //build linked list  
    // do-while loop to go through rounds while more than 1 player left 
    do {
      int numPasses = GenerateNumPasses(minPasses, gameList.GetLength());      
      // display number of passes such that they are always greater than min # of passes user entered 
      if(numPasses == 0) {
        cout << "\nnumber of passes: " << gameList.GetLength();
      }else {
      cout << "\nnumber of passes: " << numPasses + gameList.GetLength(); 
      }
      
      int data = -1;
      data = gameList.TraverseList(numPasses); // pass the potato 
      cout << "\nplayer eliminated: #" << data << endl; // display who potato lands on
      gameList.DeleteNode(data); // delete node with potato and restructure list
    }while (gameList.GetLength() != 1);  
    cout << "\nWinner: #";
    gameList.Print(); 
  }catch(bad_alloc& e) {
    gameList.ExceptionHandling("ORIGINAL");
  }
}

//generate a unique number n with range 0-(length-1). this ensures we only ever loop through list one time no matter the number of passes
  int GenerateNumPasses(int minPasses, int length) {
    return (rand() + minPasses)%length;
}

/*
TEST CASES:
Play Game
Quit
Choose option: 1
Enter number of players (minimum integer value 2): 5
Enter minimium number of passes (integer value greater or equal to 2): 0

ERROR. INVALID SELECTION

Enter minimium number of passes (integer value greater or equal to 2): 2

number of passes is: 2
player eliminated is: #3

number of passes is: 4
player eliminated is: #4

number of passes is: 2
player eliminated is: #2

number of passes is: 1
player eliminated is: #1

Winner is: 5 

Play Game
Quit
Choose option: 1
Enter number of players (minimum integer value 2): A

ERROR. INVALID SELECTION

Enter minimium number of players (integer value greater or equal to 2): 1

ERROR. INVALID SELECTION

Enter minimium number of players (integer value greater or equal to 2): 0

ERROR. INVALID SELECTION

Enter minimium number of players (integer value greater or equal to 2): 5
Enter minimium number of passes (integer value greater or equal to 2): a

ERROR. INVALID SELECTION

Enter minimium number of passes (integer value greater or equal to 2): 5

number of passes is: 2
player eliminated is: #3

number of passes is: 3
player eliminated is: #2

number of passes is: 2
player eliminated is: #1

number of passes is: 1
player eliminated is: #5

Winner is: 4 

Play Game
Quit
Choose option: 1
Enter number of players (minimum integer value 2): 1

ERROR. INVALID SELECTION

Enter minimium number of players (integer value greater or equal to 2): 5
Enter minimium number of passes (integer value greater or equal to 2): 5

number of passes is: 2
player eliminated is: #3

number of passes is: 2
player eliminated is: #1

number of passes is: 2
player eliminated is: #5

number of passes is: 1
player eliminated is: #4

Winner is: 2 

Play Game
Quit
Choose option: 2

PROGRAM TERMINATED

*/