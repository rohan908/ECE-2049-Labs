/************** ECE2049 DEMO CODE ******************/
/**************  13 March 2019   ******************/
/***************************************************/

#include <msp430.h>
#include <stdlib.h>

/* Peripherals.c and .h are where the functions that implement
 * the LEDs and keypad, etc are. It is often useful to organize
 * your code by putting like functions together in files.
 * You include the header associated with that file(s)
 * into the main file of your project. */
#include "peripherals.h"
#define MAX_SIZE 32;

// Function Prototypes
void swDelay(char numLoops);
void creatRandomArray(void);

// Declare globals here
int size = 4;
int simon_array[MAX_SIZE];
int user_array[MAX_SIZE];


// compare array function to compare if 2 arrays are the same
bool compareArray(int arr1[], int arr2[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
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



    // randomize array
    for (int i = 0; i < size; i++) {
        simon_array[i] = (rand() % 4) + 1;
    }


    bool displayText(string texttodisplay){
        Graphics_clearDisplay(&g_sContext); // Clear the display
        Graphics_drawStringCentered(&g_sContext, texttodisplay, AUTO_STRING_LENGTH, 48, 15, TRANSPARENT_TEXT);
    }


    while (1)    // Forever loop
    {
        switch (state) {
        case WELCOME: // Display welcome screen
            displayText("SIMON")
            currKey = getKey();
            if(currKey = '*'){
                displayText("1");
                //delay
                displaytext("2");
                //delay
                displaytext("3");
                //display start 3...2...1... countdown
                state = PLAYSEQUENCE;
            }
        break;

        case PLAYSEQUENCE: // Play Sequence

            // randomize all entries
            for (int i = 0; i < size; i++) {
                array[i] = (rand() % 4) + 1;
            }
            // add an entry
            array[size] = (rand() % 4) + 1;
            size++;

            for (int i = 0; i < size; i++) {
            if(ledArray[i] = 1){
                // turn on LED 1 and sound buzzer
                }
            else if(ledArray[i] = 2){
                // turn on LED 2 and sound buzzer
                }

            else if(ledArray[i] = 3){
                // turn on LED 3 and sound buzzer
                }
            else
                // turn on LED 4 and sound buzzer
            }
        break;

        case CHECKINPUT: // Check Player Input
             Graphics_clearDisplay(&g_sContext); // Clear the display
             while(i = 0; i < size){
                 currKey = getKey();
                 if (currKey = '1'){
                     Graphics_drawStringCentered(&g_sContext, "1", AUTO_STRING_LENGTH, (30 + i), 15, TRANSPARENT_TEXT); //Display 1
                     user_array[i] = currKey;
                     i++;
                 }
                 else if (currKey = '2'){
                     Graphics_drawStringCentered(&g_sContext, "2", AUTO_STRING_LENGTH, (30 + i), 15, TRANSPARENT_TEXT); //Display 2
                     user_array[i] = currKey;
                     i++;
                 }
                 else if (currKey = '3'){
                     Graphics_drawStringCentered(&g_sContext, "3", AUTO_STRING_LENGTH, (30 + i), 15, TRANSPARENT_TEXT); //Display 3
                     user_array[i] = currKey;
                     i++;
                 }
                 else if (currKey = '4'){
                     Graphics_drawStringCentered(&g_sContext, "4", AUTO_STRING_LENGTH, (30 + i), 15, TRANSPARENT_TEXT); //Display 4
                     user_array[i] = currKey;
                     i++;
                 }
                 else{
                     //print an error
                 }


             }

            if(compareArray(simon_array, user_array, size)){
                if(size = max_size){
                    state = WIN
                }else{
                    state = PLAYSEQUENCE;
                }
            }else{
                state = //switch to lose state
            }


        break;

        case WIN: //Player WIN
            Graphics_clearDisplay(&g_sContext); // Clear the display
            Graphics_drawStringCentered(&g_sContext, "YOU WIN", AUTO_STRING_LENGTH, 48, 15, TRANSPARENT_TEXT); //Display YOU WIN
        break;

    }
    }
}
