
// Programmer: Daniel Shrewsbury
// Compiler(s) used: VC++ 2010 Express
//

#include <iostream>
#include <string>
#include <stack>
#include <fstream>
using namespace std;

struct tracker
{
  int count;
  char symbol;
};

int main()
{
   std::stack<tracker> mystack;
   tracker track[100];

   cout << "Lab 8a, by Daniel Shrewsbury" << endl;
   cout << "This tests a custom made stack templated class." << endl;
   char buf[1000];
   char buf2[50];
   falseChar;
   string file1;
   tracker test1;
   int lineNumba = 1;
   bool getOut = true;
   bool noOpen = true;

   cout << "Please enter the name of the file: ";
   getline(cin, file1);

   cout << endl;
   strcpy(buf2, file1.c_str());
  
  // open the input file
  ifstream fin;

  fin.open(buf2);
  if (!fin.good()) throw "I/O error";  
  
  while (fin.good())
  {
    // read the line
    string line;
    getline(fin, line);
    strcpy(buf, line.c_str());
    if (buf[0] == 0) continue;

    for(int i = 0; i < 1000; i++)
    {
      if(buf[i] == '(')
      {
        track[i].symbol = '(';
        track[i].count = lineNumba;
        mystack.push(track[i]);
      }
      else if(buf[i] == '{')
      {
        track[i].symbol = '{';
        track[i].count = lineNumba;
        mystack.push(track[i]);
      }
      else if(buf[i] == '[')
      {
        track[i].symbol = '[';
        track[i].count = lineNumba;
        mystack.push(track[i]);
      }
      else if(buf[i] == '/' && buf[i + 1] == '*')
      {
        track[i].symbol = '/';
        track[i].count = lineNumba;
        mystack.push(track[i]);
      }

      if(buf[i] == ')')
      {
        if(mystack.empty() == true)
        {
          noOpen = false;
          false char = ')';
          break;
        }

        test1 = mystack.top();
     
        if(test1.symbol != '(')
        {
         getOut = false;
         break;
        }
        mystack.pop();
      }
      else if(buf[i] == '}')
      {
        if(mystack.empty() == true)
        {
          noOpen = false;
          false char = '}';
          break;
        }
        test1 = mystack.top();
     
        if(test1.symbol != '{')
        {
         getOut = false;
         break;
        }
        mystack.pop();
      }
      else if(buf[i] == ']')
      {
        if(mystack.empty() == true)
        {
          noOpen = false;
          false char = ']';
          break;
        }

        test1 = mystack.top();
     
        if(test1.symbol != '[')
        {
         getOut = false;
         break;
        }
        mystack.pop();
      }
      else if(buf[i] == '/' && buf[i - 1] == '*')
      {
        if(mystack.empty() == true)
        {
          noOpen = false;
          false char = '/';
          break;
        }

        test1 = mystack.top();
     
        if(test1.symbol != '/')
        {
         getOut = false;
         break;
        }
        mystack.pop();
      }
     
    }
    if(getOut == false || noOpen == false) break;
    lineNumba++;
  }
  fin.close();

  if(test1.symbol == '(' && getOut == false)
  {
    cout << "Opening parenthesis found in line " << test1.count << " of " << buf2 << endl;
    cout << "But no matching closing parenthesis found." << endl;
  }
  else if(test1.symbol == '{' && getOut == false)
  {
    cout << "Opening curly brace found in line " << test1.count << " of " << buf2 << endl;
    cout << "But no matching curly brace found." << endl;
  }
  else if(test1.symbol == '[' && getOut == false)
  {
    cout << "Opening square bracket found in line " << test1.count << " of " << buf2 << endl;
    cout << "But no matching square bracket found." << endl;
  }
  else if(test1.symbol == '/' && getOut == false)
  {
    cout << "Opening comment offset found in line " << test1.count << " of " << buf2 << endl;
    cout << "But no matching comment offset found." << endl;
  }

  if(noOpen == false)
  {
    if(falseChar == ')')
    {
      cout << "closing parenthesis found in line " << lineNumba << " of " << buf2 << endl;
      cout << "But no matching opening parenthesis." << endl;
    }
    else if(falseChar == '}')
    {
      cout << "closing curly brace found in line " << lineNumba << " of " << buf2 << endl;
      cout << "But no matching opening curly brace." << endl;
    }
    else if(falseChar == ']')
    {
      cout << "closing square bracket found in line " << lineNumba << " of " << buf2 << endl;
      cout << "But no matching opening square bracket." << endl;
    }
    else if(falseChar == '/')
    {
      cout << "closing comment offsets found in line " << lineNumba << " of " << buf2 << endl;
      cout << "But no matching opening comment offsets." << endl;
    }

  }

  if(mystack.empty() == true && getOut == true)
  {
    cout << "No mismatches found by my preprocessor in " << buf2 << endl;
  }

}