
// Programmer: Dan Shrewsbury
// Compiler(s) used: VC++ 2010 Express


// includes 
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <cstring>

// class definition 
class animal
{
  public:
  char text[128]; // a yes/no question Or an animal name
  animal* yes; //pointer to next node if question is answered YES
  animal* no; // pointer to next node if question is answered NO
}; // if "yes and "no" are 0, then "text" is an animal name


// function prototype 
void deleteTree(animal*); // write this! 


int main() 
{ 

    cout << "Lab 14" << endl;
    cout << "Programmer: Dan Shrewsbury " << endl;
    cout << "Editor used: XP Notepad " << endl;
    cout << "Compiler used: VC++ 2010 Express " << endl;

  // initialize a "top" pointer named "animal* top" 
  animal* top = new animal;
  // set "top" to a newly created node; set its text to "elephant", pointers to 0 
  char yesNo; 
  strcpy(top->text, "elephant"), top->yes = 0, top->no = 0;
  char invite = 'N';
  // start a "while" loop that runs each cycle of the program 
  while(true)
  {
    // invite the user to think of an animal which it will try to guess 
    cout << "Would you like to think of an animal that I will try and guess? (N for no, anything else for yes)" << endl;
    cin >> invite;
    cin.ignore(1000, 10);
    // await the user's response, and break out of the loop if he declines
     if(invite == 'N' || invite == 'n') break; 

    // declare a pointer "p" to traverse the tree, and initialize it to "top"
    animal* p = top; 
    // start a loop to traverse the binary tree 
    while(true)
    {

      // if p->yes is 0... 
      if(p->yes == 0)
      {
        char guessedAnimalRes = 'N';
        //...print p->text as the guessed animal 
        cout << "Was the animal you were thinking of a " << p->text << "? (Y for yes N for no)" << endl;
        cin >> guessedAnimalRes;
        cin.ignore(1000, 10);
        // ask user if this is correct 
        // if correct, brag and break from loop 

        if(guessedAnimalRes == 'Y' || guessedAnimalRes == 'y')
        {
          cout << "Ha, I knew I'd guess the answer. You are no match for me. " << endl;
          break;
        }
        else if(guessedAnimalRes == 'N' || guessedAnimalRes == 'n')
        {
    
          char a[128];
         // ask user what animal he was thinking of...
         cout << "What animal were you thinking of?" << endl;
         cin.getline(a, 128);
        
          
          //...store in "char a[128]" 
          // ask what yes/no question differentiates "p->text" from "a"... 
          char q[128];
          cout << "What yes/no question differentiates a " << p->text << " from a " << a << "?"<< endl;
          cin.getline(q, 128);
          cin.ignore(0, 10);
          
          
          
        
       
        
        
          //...store in "char q[128]" 
          // ask which response is correct for "a" -- yes or no... 
          
          cout << "Which response is correct for " << a << ",(Y for yes, or N for no? " << endl;
          cin >> yesNo;    //...store in "char yesNo"
          cin.ignore(1000, 10); 

         
          // create two new nodes, names "y" and "n" 
          animal* y = new animal;
          animal* n = new animal;
         
         
          // if the correct response for "a" is yes... 
          if(yesNo == 'Y' || yesNo == 'y')
          {
 
            // copy "a" into y->text 
            strcpy(y->text, a);       
            // copy p->text into n->text
            strcpy(n->text, p->text); 
    
          }
          else if(yesNo == 'N' || yesNo == 'n')               // else if the correct response is no... 
          {     
            strcpy(n->text, a);             // copy "a" into n->text  
            strcpy(y->text, p->text);    // copy p->text into y->text
          }

          // copy "q" into p->text 
         strcpy(p->text, q);
            
          // set y->yes, n->yes, y->no, and n->no to 0 
           y->yes = 0; 
           n->yes = 0; 
           y->no = 0; 
           n->no = 0;
               
          // set p->yes to y and p->no to n
          p->yes = y, p->no = n; 
     
          // break from loop 
          break;
       }
      }
      else  // else if p->yes is not 0 
      {
          //  print p->text as a question
          cout << p->text << endl; 
          //     ask for a yes/no reply... 
          cout << "Please enter Y for yes or N for no." << endl;
          cin >> yesNo;        //...store in "char yesNo" 
          cin.ignore(1000, 10);
         
          if(yesNo == 'Y' || yesNo == 'y')     // if "yes", set p to p->yes
            p = p->yes;
          else
            p = p->no;         // else set p to p->no                 
       }
        
      
    }
  }
  // reclaim memory 
  deleteTree(top); 
}

void deleteTree(animal* a)
{
    if(a == 0) return;
   
    deleteTree(a->yes);
    deleteTree(a->no);
    delete a;
     
}