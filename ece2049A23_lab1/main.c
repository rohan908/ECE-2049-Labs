/************** ECE2049 DEMO CODE ******************/
/**************  13 March 2019   ******************/
/***************************************************/

#include <msp430.h>
#include <stdlib.h>
#include <stdbool.h>

/* Peripherals.c and .h are where the functions that implement
 * the LEDs and keypad, etc are. It is often useful to organize
 * your code by putting like functions together in files.
 * You include the header associated with that file(s)
 * into the main file of your project. */
#include "peripherals.h"
#define MAX_SIZE 32

// Function Prototypes
void swDelay(char numLoops);

// Declare globals here
int size = 4;
int simon_array[MAX_SIZE];
int user_array[MAX_SIZE];
int value = 1;
char currKey;


// compare array function to compare if 2 arrays are the same
bool compareArray(int arr1[], int arr2[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
      }
      return true;
    }
    return true;
}

// Main
void main(void)

{

    WDTCTL = WDTPW | WDTHOLD;    // Stop watchdog timer. Always need to stop this!!
                                 // You can then configure it properly, if desired

    initLeds();

    configDisplay();
    configKeypad();



    while (1)    // Forever loop
    {

        int i;
        switch (value) {
        case 1: // Display welcome screen
            Graphics_clearDisplay(&g_sContext); // Clear the display
            Graphics_drawStringCentered(&g_sContext, "SIMON", AUTO_STRING_LENGTH, 48, 15, TRANSPARENT_TEXT);

            currKey = getKey();
            if(currKey == '*'){
                Graphics_clearDisplay(&g_sContext); // Clear the display
                Graphics_drawStringCentered(&g_sContext, "1", AUTO_STRING_LENGTH, 48, 15, TRANSPARENT_TEXT);
                //delay
                Graphics_drawStringCentered(&g_sContext, "2", AUTO_STRING_LENGTH, 48, 15, TRANSPARENT_TEXT);
                //delay
                Graphics_drawStringCentered(&g_sContext, "3", AUTO_STRING_LENGTH, 48, 15, TRANSPARENT_TEXT);
                //display start 3...2...1... count down
                //change state
            }


            break;

        case 2: // Play Sequence


            // randomize all entries
            for (i = 0; i < size; i++) {
                simon_array[i] = (rand() % 4) + 1;
            }
            // add an entry
            simon_array[size] = (rand() % 4) + 1;
            size++;

            for (i = 0; i < size; i++) {
            if(simon_array[i] == 1){
                // turn on LED 1 and sound buzzer
                }
            else if(simon_array[i] == 2){
                // turn on LED 2 and sound buzzer
                }

            else if(simon_array[i] == 3){
                // turn on LED 3 and sound buzzer
                }
            else
                // turn on LED 4 and sound buzzer
                return true;

            }

            break;

        case 3: // Check Player Input
                Graphics_clearDisplay(&g_sContext); // Clear the display
                i = 0;
                while(i < size){
                 currKey = getKey();
                 if (currKey == '1'){
                     Graphics_drawStringCentered(&g_sContext, "1", AUTO_STRING_LENGTH, (30 + i), 15, TRANSPARENT_TEXT); //Display 1
                     user_array[i] = currKey;
                     i++;
                 }
                 else if (currKey == '2'){
                     Graphics_drawStringCentered(&g_sContext, "2", AUTO_STRING_LENGTH, (30 + i), 15, TRANSPARENT_TEXT); //Display 2
                     user_array[i] = currKey;
                     i++;
                 }
                 else if (currKey == '3'){
                     Graphics_drawStringCentered(&g_sContext, "3", AUTO_STRING_LENGTH, (30 + i), 15, TRANSPARENT_TEXT); //Display 3
                     user_array[i] = currKey;
                     i++;
                 }
                 else if (currKey == '4'){
                     Graphics_drawStringCentered(&g_sContext, "4", AUTO_STRING_LENGTH, (30 + i), 15, TRANSPARENT_TEXT); //Display 4
                     user_array[i] = currKey;
                     i++;
                 }
                 else{
                     //print an error
                 }


                }

                if(compareArray(simon_array, user_array, size)){
                if(size == MAX_SIZE){
                    //do stuff
                }else{
                    //do stuff
                }
                }else{
                 //switch to lose state
                }
             break;

        case 4: //Player WIN
            break;

        }
    }
}
