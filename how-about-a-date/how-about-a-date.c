//
//  how-about-a-date.c
//  how-about-a-date
//
//  Created by Shana Moore on 11/16/17.
//  Copyright © 2017 Shana Moore. All rights reserved.

/*The entire purpose of the program is to test a single string entry from the
 keyboard for the possibility that the entry is a valid date. Other than taking a
 single string from the user at the keyboard, and reporting the validity (as
 described below), the entire program should be written as a single function that
 returns true (1) if the date is valid and false (0) if it is not valid.
 The program should accomplish testing the keyboard entry and take one of two
 actions based on the validity of the entry.
 1. If the entry is NOT a valid date the program should tell the user that
 the date is not valid.
 2. If the entry is a valid date the program should notify the user that
 the date is valid.*/


#include <stdio.h>

// create new data type to create multiple date structures
typedef struct {
    int month;
    int day;
    int year;
} Date;

int validateDate(Date date_input); //function prototype

int main(void) {
    // declare variables with appropriate data type
    Date date_input;

    // output msg to screen
    printf("Welcome to my Date Checker Project!\nEnter the date to test as: MM/DD/YY format\n");
    
    // receive user input
    scanf("%d/%d/%d", &date_input.month, &date_input.day, &date_input.year);
    
    // output result: 1 = true, 0 = false
    printf("%s Date\n", validateDate(date_input) ? "Valid" : "Invalid");
    return 0;
}

int validateDate(Date date_input){
    //check year
    if(date_input.year >=1 && date_input.year <=99){
        //check month
        if(date_input.month >= 1 && date_input.month <=12){
            //check days
            if((date_input.day >= 1 && date_input.day <=31)&&(date_input.month==1 || date_input.month==3 || date_input.month==5 || date_input.month==8)){
                //date is valid
                return 1;
            } else if((date_input.day >= 1 && date_input.day <=30)&&(date_input.month==4 || date_input.month==6 || date_input.month==9 || date_input.month==11)){
                //date is valid
                return 1;
            } else if((date_input.day >= 1 && date_input.day <=28)&&(date_input.month==2)){
                // date is valid
                return 1;
            } else if((date_input.day == 29 && date_input.month ==2)&&(date_input.year%400==0 || (date_input.year%4==0 && date_input.year%100!=0))){
                // date is valid. Happy Leap Year!
                return 1;
            } else
            {
                // day is not valid
                return 0;
            }
        }
        else
        {
            // month is not valid
            return 0;
        }
    }
    else
    {
        // year is not valid
        return 0;
    }
}
