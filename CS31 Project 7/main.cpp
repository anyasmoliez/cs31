//
//  main.cpp
//  BeatThat
//
//Anya Smolentseva 305503018

#include <iostream>
#include <cassert>
#include "Die.h"
#include "Player.h"
#include "Board.h"
#include "BeatThat.h"


void clearScreen( );

int main()
{
    using namespace cs31;
    using namespace std;
    
 /*   clearScreen();
    
    BeatThat game;
    std::string action, message = "(r)oll (q)uit: ";
    std::cout << message;
        
    do
    {
        getline( cin, action );
        while (action.size() == 0)
        {
            getline( cin, action );  // no blank entries allowed....
        }
        switch (action[0])
        {
            default:   // if bad move, nobody moves
                cout << '\a' << endl;  // beep
                continue;
            case 'Q':
            case 'q':
                return 0;
            case 'r':
            case 'R':
                game.humanPlay();
                game.computerPlay();
                game.endTurn();
                cout << game.display( message ) << endl;
                break;
        }
    } while( !game.isGameOver() );
    cout << game.endingMessage() << endl; */
    
  /*  Player p; //testing that player class works
    assert(p.getRoundsWon() == 0);   // testing that initially 0 rounds are won
    p.wonARound();
    assert(p.getRoundsWon() == 1);   // testing that after winning a round, getRoundsWon is updated correctly
    p.roll();                          
    Die d1; d1.setValue(3);
    Die d6; d6.setValue(4);
    p.roll(d1, d6);                   
    assert(p.largestDie().getValue() == 4); //testing that largest Die and getting value of die works
    assert(p.smallestDie().getValue() == 3); //testing that smallest Die works correctly */

   /* Player q; 
    Die d3;
    d3.setValue(3);
    Die d32;
    d32.setValue(3);
    q.roll(d3, d32);
    assert(q.largestDie().getValue() == 3); //testing that largestDie works when values of die are the same
    assert(q.smallestDie().getValue() == 3); //testing that smallestDie works when values of die are the same */

    Board b; //testing that board class works
    b.setHumanRoundsWon(4);
    b.setComputerRoundsWon(1);
    b.markHumanAsWinner();
    b.setTurnsLeft(0);
    assert(b.getHumanRoundsWon() == 4); //testing that correctly gets human rounds won
    assert(b.getComputerRoundsWon() == 1); //testing that correctly gets computer rounds won
    assert(b.getTurnsLeft() == 0); //testing that correctly gets how many turns left
    assert(b.didHumanWin()); //testing that human won because 4>1
    assert(!b.didComputerWin()); //testing that computer lost
    assert(b.isGameOver()); //testing that game is over since there is a wnner 

    BeatThat g;
    Die d1;
    d1.setValue(1);
    Die d2;
    d2.setValue(2);
    Die d3;
    d3.setValue(3);
    Die d4;
    d4.setValue(4);
    Die d5;
    d5.setValue(5);
    Die d6;
    d6.setValue(6);
    g.humanPlay(d1, d1);
    g.computerPlay(d3, d3); //computer won this round
    g.endTurn();
    g.humanPlay(d6, d5);
    g.computerPlay(d2, d1); //human won this round
    g.endTurn();
    g.humanPlay(d1, d1);
    g.computerPlay(d1, d1); //tie
    g.endTurn();
    g.humanPlay(d3, d2);
    g.computerPlay(d2, d3); //tie
    g.endTurn();
    g.humanPlay(d3, d3);
    g.computerPlay(d3, d3); //tie
    g.endTurn();
    assert(g.turnsLeft() == 0); //testing that that turns left is 0 after 5 rounds
    assert(g.isGameOver()); //testing that game is over since turns left is 0
    assert(g.determineGameOutcome() == cs31::BeatThat::TIEDGAME); //testing that game results in tie because rounds won is equal
    assert(g.getHuman().getRoundsWon() == 1); //testing that human won 1 round (tie doesn't count as win)
    assert(g.getComputer().getRoundsWon() == 1); //testing that computer won 1 round

    

   


    


    cerr << "yay!" << endl;



    return( 0 );
}


///////////////////////////////////////////////////////////////////////////
//  clearScreen implementations
///////////////////////////////////////////////////////////////////////////

// DO NOT MODIFY OR REMOVE ANY CODE BETWEEN HERE AND THE END OF THE FILE!!!
// THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++ UNDER LINUX.

// Note to Xcode users:  clearScreen() will just write a newline instead
// of clearing the window if you launch your program from within Xcode.
// That's acceptable.

#ifdef _MSC_VER  //  Microsoft Visual C++

#include <windows.h>

void clearScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD upperLeft = { 0, 0 };
    DWORD dwCharsWritten;
    FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
                               &dwCharsWritten);
    SetConsoleCursorPosition(hConsole, upperLeft);
}

#else  // not Microsoft Visual C++, so assume UNIX interface

#include <cstring>

void clearScreen()  // will just write a newline in an Xcode output window
{
    using namespace std;
    static const char* term = getenv("TERM");
    if (term == nullptr  ||  strcmp(term, "dumb") == 0)
    {
        cout << endl << endl << endl << endl << endl << endl << endl << endl;;
    }
    else
    {
        static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
        cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
    }
}

#endif


