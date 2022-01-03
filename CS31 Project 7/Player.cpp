//
//  Player.cpp
//  BeatThat
//Anya Smolentseva 305503018
#include "RandomNumber.h"
#include "Player.h"
#include "Die.h"

#include <iostream>

namespace cs31
{
    // Each Player has two six-sided dies and tracks how many rounds have been won
    Player::Player() : mDie1( 6 ), mDie2( 6 ), mRoundsWon(0)
    {
        
    }
    
    void Player::roll( Die d1, Die d2 )
    {
        // cheating...
        mDie1 = d1;
        mDie2 = d2;
    }

    //  randomly rolls each of the Player's die
    void Player::roll( )
    {
        
        mDie1.roll();
        mDie2.roll();


    }
    
    // trivial getter
    Die Player::getDie1() const
    {
        return( mDie1 );
    }

    // trivial getter
    Die Player::getDie2( ) const
    {
        return( mDie2 );
    }
    
    
    void Player::wonARound( ) //increments mRoundsWon when called
    {
        mRoundsWon += 1;
        
    }

    
    int  Player::getRoundsWon( ) const
    {
        
        return( mRoundsWon );
    }

    // TODO: identify and return the die with the largest value
    Die  Player::largestDie( ) const
    {
        if (mDie1.getValue() > mDie2.getValue()) //compares values of the 2 die and returns the larger of the values
            return(mDie1);
        else if (mDie1.getValue() < mDie2.getValue())
            return(mDie2);
        else
            return(mDie1);
    }

    // TODO: identify and return the die with the largest value
    Die  Player::smallestDie( ) const
    {
        if (mDie1.getValue() > mDie2.getValue()) //compares values of the 2 die and returns the smaller of the values
            return(mDie2);
        else if (mDie1.getValue() < mDie2.getValue())
            return(mDie1);
        else
            return(mDie2);
        
    }

    // for testing purposes
    std::string Player::whatWasRolled()
    {
        std::string s = "";
        s += "Die1: ";
        s += std::to_string( mDie1.getValue() );
        s += " Die2: ";
        s += std::to_string( mDie2.getValue() );
        return( s );
    }
    
    

}
