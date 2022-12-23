//==================================================================================
// This program locates search words in a 14x14 word puzzle 
//==================================================================================
#include<iostream>
#include<iomanip>
#include<string>
#include<cassert>
using namespace std; 
//=============================== Function Declaration =============================
const int M = 14; 
void readPuzzle( char puzzle[M][M] ); 
void printPuzzle( char puzzle[M][M] ); 
bool search_up(char puzzle[M][M], int r, int c, string word, int i); 
bool search_upRight(char puzzle[M][M], int r, int c, string word, int i); 
bool search_right(char puzzle[M][M], int r, int c, string word, int i); 
bool search_downRight(char puzzle[M][M], int r, int c, string word, int i); 
bool search_down(char puzzle[M][M], int r, int c, string word, int i); 
bool search_downLeft(char puzzle[M][M], int r, int c, string word, int i); 
bool search_left(char puzzle[M][M], int r, int c, string word, int i); 
bool search_upLeft(char puzzle[M][M], int r, int c, string word, int i); 
void printCoordinate(char puzzle[M][M], string word); 

//=============================== Main Function =====================================
int main ( void ) 
{
	char puzzle[M][M]; 
	int n; 
	string word; 

	//read and print word grid 
	readPuzzle(puzzle); 
	printPuzzle(puzzle); 
	cout << endl << endl; 

	//read in number of words 
	cin >> n;  
	cout << n << endl; 
	
	for (int i=0; i<n; i++)
	{
		cin >> word; 
    cout << word << " is ";
    printCoordinate(puzzle, word); 
	  cout << endl;  
		//cout << boolalpha << check;  
	} 
	return 0; 
}

//================================ Function Definitions ===============================

//================================================
//readPuzzle
//This function reads in the puzzle grid
//PARAMETERS: 
//      puzzle: a 2D array 
//RETURN: none 
//================================================
void readPuzzle( char puzzle[M][M] )
{
	for ( int i = 0; i < M; i++ )
		for ( int j = 0; j < M; j++ )
			cin >> puzzle[i][j];
}

//================================================
//printPuzzle
//This function prints the puzzle grid
//PARAMETERS: 
//      puzzle: a 2D array that stores the puzzle
//RETURN: none but prints the 2D array
//================================================
void printPuzzle( char puzzle[M][M] )
{
	for ( int i = 0; i < M; i++ )
	{
		for ( int j = 0; j < M; j++ )
		{
			cout << setw(5) << puzzle[i][j]; 
		}
		cout << endl;
	}
}


//================================================
//search_up
//This function recursively check if the word 
//can be found going up 
//PARAMETERS: 
//      puzzle: a 2D array that stores the puzzle
//      r: row number
//      c: column number 
//      word: the search word 
//      i: word index
//RETURN: 
//      a Boolean value. True if word is found 
//      going up. False if otherwise 
//================================================ 
bool search_up(char puzzle[M][M], int r, int c, string word, int i) 
{
  //Bound checking
  if (r>=14 || r<0) return false; 
  if (i==word.length()) return true;
  if (puzzle[r][c] == word[i])
    return search_up(puzzle, r-1, c, word, i+1);
  return false;
}

//================================================
//search_upRight
//This function recursively check if the word 
//can be found going up and to the right
//PARAMETERS: 
//      puzzle: a 2D array that stores the puzzle
//      r: row number
//      c: column number 
//      word: the search word 
//      i: word index
//RETURN: 
//      a Boolean value. True if word is found 
//      going up to the right. False if otherwise 
//================================================ 
bool search_upRight(char puzzle[M][M], int r, int c, string word, int i)
{
  //Bound checking
   if (r>=14 || r<0) return false; 
   if (i==word.length()) return true;
   if (puzzle[r][c] == word[i])
     return search_upRight(puzzle, r-1, c+1, word, i+1);
  return false; 
}

//================================================
//search_right
//This function recursively check if the word 
//can be found going right 
//PARAMETERS: 
//      puzzle: a 2D array that stores the puzzle
//      r: row number
//      c: column number 
//      word: the search word  
//      i: word index
//RETURN: 
//      a Boolean value. True if word is found 
//      going right. False if otherwise 
//================================================ 
bool search_right(char puzzle[M][M], int r, int c, string word, int i)
{
  //Bound checking
   if (r>=14 || r<0) return false; 
   if (i==word.length()) return true;
   if (puzzle[r][c] == word[i])
     return search_right(puzzle, r, c+1, word, i+1);
  return false; 
}

//================================================
//search_downRight
//This function recursively check if the word 
//can be found going down and to the right 
//PARAMETERS: 
//      puzzle: a 2D array that stores the puzzle
//      r: row number
//      c: column number 
//      word: the search word 
//      i: word index
//RETURN: 
//      a Boolean value. True if word is found 
//      going down to the right. False if otherwise 
//================================================ 
bool search_downRight(char puzzle[M][M], int r, int c, string word, int i)
{
  //Bound checking
   if (r>=14 || r<0) return false; 
   if (i==word.length()) return true; 
   if (puzzle[r][c] == word[i])
     return search_downRight(puzzle, r+1, c+1, word, i+1);
  return false; 
}

//================================================
//search_down
//This function recursively check if the word 
//can be found going down 
//PARAMETERS: 
//      puzzle: a 2D array that stores the puzzle
//      r: row number
//      c: column number 
//      word: the search word 
//      i: word index
//RETURN: 
//      a Boolean value. True if word is found 
//      going down. False if otherwise 
//================================================ 
bool search_down(char puzzle[M][M], int r, int c, string word, int i)
{
  //Bound checking
   if (r>=14 || r<0) return false; 
   if (i==word.length()) return true;
   if (puzzle[r][c] == word[i])
     return search_down(puzzle, r+1, c, word, i+1);
  return false; 
}

//================================================
//search_downLeft
//This function recursively check if the word 
//can be found going down and to the left  
//PARAMETERS: 
//      puzzle: a 2D array that stores the puzzle
//      r: row number
//      c: column number 
//      word: the search word  
//      i: word index
//RETURN: 
//      a Boolean value. True if word is found 
//      going down to the left. False if otherwise 
//================================================ 
bool search_downLeft(char puzzle[M][M], int r, int c, string word, int i)
{
  //Bound checking
   if (r>=14 || r<0) return false; 
   if (i==word.length()) return true;
   if (puzzle[r][c] == word[i])
     return search_downLeft(puzzle, r+1, c-1, word, i+1);
  return false; 
}

//================================================
//search_left
//This function recursively check if the word 
//can be found going left 
//PARAMETERS: 
//      puzzle: a 2D array that stores the puzzle
//      r: row number
//      c: column number 
//      word: the search word  
//      i: word index
//RETURN: 
//      a Boolean value. True if word is found 
//      going left. False if otherwise 
//================================================ 
bool search_left(char puzzle[M][M], int r, int c, string word, int i)
{
  //Bound checking
   if (r>=14 || r<0) return false; 
   if (i==word.length()) return true;
   if (puzzle[r][c] == word[i])
     return search_left(puzzle, r, c-1, word, i+1);
  return false; 
}

//================================================
//search_upLeft
//This function recursively check if the word 
//can be found going up to the left 
//PARAMETERS: 
//      puzzle: a 2D array that stores the puzzle
//      r: row number
//      c: column number 
//      word: the search word  
//      i: word index
//RETURN: 
//      a Boolean value. True if word is found 
//      going up to the left. False if otherwise 
//================================================ 
bool search_upLeft(char puzzle[M][M], int r, int c, string word, int i)
{
  //Bound checking
   if (r>=14 || r<0) return false; 
   if (i==word.length()) return true;
   if (puzzle[r][c] == word[i])
     return search_upLeft(puzzle, r-1, c-1, word, i+1);
  return false; 
}

//================================================
//printCoordinate
//This function prints the coordinate of the search
// word if it is found 
//PARAMETERS: 
//      puzzle: a 2D array that stores the puzzle
//      word: the search word 
//RETURN: none but prints the coordinates of the 
//        search word if it is found 
//================================================
void printCoordinate(char puzzle[M][M], string word)
{
  bool found = false; 
  for (int row=0; row < M; row++)
    {
    for (int col=0; col < M; col++)
      {
        if(puzzle[row][col] == word[0])
        {
          if (search_up(puzzle, row, col, word, 0))
          {
            cout << "found at (" << row << "," << col << ")" << " going up"; 
            found = true; break; 
          }
          else if (search_upRight(puzzle, row, col, word, 0))
          {
            cout << "found at (" << row << "," << col << ")" << " going up right"; 
            found = true; break; 
          }
          else if (search_right(puzzle, row, col, word, 0))
          {
            cout << "found at (" << row << "," << col << ")" << " going right";  
            found = true; break; 
          }
          else if (search_downRight(puzzle, row, col, word, 0))
          {
            cout << "found at (" << row << "," << col << ")" << " going down right";  
            found = true; break; 
          }
          else if (search_down(puzzle, row, col, word, 0))
          {
            cout << "found at ("<< row << "," << col << ")" << " going down";  
            found = true; break; 
          }
          else if (search_downLeft(puzzle, row, col, word, 0))
          {
            cout << "found at (" << row << "," << col << ")" << " going down left"; 
            found = true; break; 
          }
          else if (search_left(puzzle, row, col, word, 0))
          {
            cout << "found at (" << row << "," << col << ")" << " going left"; 
            found = true; break; 
          }
          else if (search_upLeft(puzzle, row, col, word, 0))
          {
            cout << "found at (" << row << "," << col << ")" << " going up left"; 
            found = true; break; 
          }
        
        } if (found) break;  
      } if (found) break; 
    }
  
  if (found==false) 
    cout << "not found!"; 
}