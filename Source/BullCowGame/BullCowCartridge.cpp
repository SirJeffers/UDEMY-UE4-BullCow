// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Welcome to Bulls and Cows"));
    PrintLine(TEXT("Press enter to continue..."));

    //init
    HiddenWord = TEXT("SigmaGrindset"); //move out of function
    Lives = HiddenWord.Len();

    PrintLine(TEXT("Guess the " + FString::FromInt(HiddenWord.Len()) + " letter word"));

}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    

    PrintLine(Input);

    if(Input.Equals(HiddenWord, ESearchCase::IgnoreCase))
    {
        PrintLine(TEXT("You have won!"));
    }
    else {
        PrintLine(TEXT("You have Lost!"));
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