// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Welcome to Bulls and Cows"));
    PrintLine(TEXT("Press enter to continue..."));
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    FString HiddenWord = TEXT("SigmaGrindset"); //move out of function

    PrintLine(TEXT("Guess the " + FString::FromInt(HiddenWord.Len()) + " letter word"));

    PrintLine(Input);

    if(Input.Equals(HiddenWord, ESearchCase::IgnoreCase))
    {
        PrintLine(TEXT("You have won!"));
    }
    else {
        PrintLine(TEXT("You have Lost!"));
    }

}