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
    
    if(!bGameOver)
    {
        InitGame();
    }
    else {
        PrintLine(Input);
        if(Input.Equals(HiddenWord, ESearchCase::IgnoreCase))
        {
            PrintLine(TEXT("You have won!"));
        }
        else {
            if(HiddenWord.Len() != Input.Len())
            {
                PrintLine(FString::Printf(TEXT("the hidden word is %i letters long, you lost"), HiddenWord.Len()));
            }     
            EndGame();  
        }

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
    HiddenWord = TEXT("SigmaGrindset"); //move out of function
    Lives = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Welcome to Bulls and Cows"));
    PrintLine(TEXT("Press enter to continue..."));
    PrintLine(FString::Printf(TEXT("Guess the %i letter word"), HiddenWord.Len()));
    PrintLine(TEXT("The hidden word is: %s"), *HiddenWord);

}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("The game is over, you have Lost!"));
    PrintLine(TEXT("Press enter to play again..."));

}
