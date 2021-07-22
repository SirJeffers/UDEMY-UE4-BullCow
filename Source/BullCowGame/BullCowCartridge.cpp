// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    InitGame();
    //init
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    
    if(bGameOver)
    {
        InitGame();
    }
    else {
        PrintLine(Input);
        ProcessGuess(Input);
    }

    //check if input is isogram
    //if yes win
    //if no
        //remove lives 
    //check for life count > 0
    // if yes
        //guess again and show lives left
    //if no
        //End game or BeginPlay

}

void UBullCowCartridge::InitGame()
{
    HiddenWord = TEXT("penis"); //move out of function
    Lives = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Welcome to Bulls and Cows"));
    PrintLine(TEXT("Press enter to continue..."));
    PrintLine(TEXT("Guess the %i letter word"), HiddenWord.Len());
    PrintLine(FString::Printf(TEXT("you have %i Lives"), Lives)); 
    PrintLine(TEXT("The hidden word is: %s"), *HiddenWord);


}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("press enter to play again"));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{

    if(HiddenWord.Len() != Guess.Len())
    {
        PrintLine(TEXT("the hidden word is %i letters long"), HiddenWord.Len());
        PrintLine(TEXT("%i Lives remaining"), Lives);
        return;
    }

    if(Guess.Equals(HiddenWord, ESearchCase::IgnoreCase))
    {
        PrintLine(TEXT("You have won!"));
        EndGame();
        return;
    }


    if(!IsIsogram(Guess))
    {
        PrintLine(TEXT("your word was not an isogram"));
        PrintLine(TEXT("%i Lives remaining"), Lives);
        return;

    }

    Lives--;
    PrintLine(TEXT("Lose a life! %i remaining"), Lives);
    PrintLine(TEXT("Guess again"));
    if(Lives < 1)
    { 
        PrintLine(TEXT("The game is over, you have Lost!"));
        EndGame();
        return;
    }  
    
}

bool UBullCowCartridge::IsIsogram(FString word) const
{
    for (int32 i = 0; i < word.Len()-1; i++)
    {
        for( int32 j = i+1; j < word.Len(); j++)
        {
            if(word[i]-word[j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}
