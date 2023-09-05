#include <stdint.h>

#include "eecs388_lib.h"

/*
  
  
   Task 1.4: Build and deploy/upload the code as is
   
   Task 1.5: Try out debugging. See lab sheet. 
   
   Task 2.1: Review the files eecs388_lib.h and eecs388_lib.c. On vscode, it will usually be on the file browser pane on the left

   Task 2.2: Implement RGB blinky. 

   - set red, green, and blue LEDs for output mode, using the gpio_mode() function
   - in the main loop, turn on/off a different LED at each iteration. 
      for example, 
      at 1st iteration
         turn on RED led
	      delay 500 ms 
	      turn off RED led
	      delay 300 ms.
	   at 2nd iteration
	      do the same but for GREEN led
	   at 3rd iteration
	      do the same but for BLUE led
	   at 4th iteration
	      back to RED led. 
	   ...
   
   - for extra marks, modify your code so that it also flashes the WHITE color
      so sequence would be something like this: RED -> BLUE -> GREEN -> WHITE
*/

int main()
{
   //created gpio var to represent current color output
   int gpio;

   //created iteration var to represent the current iteration
   int iteration = 0;

   //the following three open up all led pins for output
   gpio_mode(RED_LED, OUTPUT);
   gpio_mode(BLUE_LED, OUTPUT);
   gpio_mode(GREEN_LED, OUTPUT);
   
   //starts a permanent while loop
   while(1)
   {  
      //begins a switch case that checks what iteration the loop is on
      switch(iteration){
         //if the iterator is at 0, run the following
         case 0:
            //set gpio to the red led
            gpio = RED_LED;
            //ends switch
            break;

         //if the iterator is at 1, run the following
         case 1:
            //set gpio to green led
            gpio = GREEN_LED;
            //ends switch
            break;

         //if iterator is at 2, run the following
         case 2:
            //set the gpio to blue led
            gpio = BLUE_LED;
            //ends switch
            break;

         //if the iterator is at 3, run the following
         case 3:
            //this case is a special one (requires all to be on)

            //turns on all led
            gpio_write(RED_LED, ON); 
            gpio_write(BLUE_LED, ON); 
            gpio_write(GREEN_LED, ON);

            //delay
            delay(500);          

            //turns off all led
            gpio_write(RED_LED, OFF); 
            gpio_write(BLUE_LED, OFF); 
            gpio_write(GREEN_LED, OFF);  
            
            //delay
            delay(300);
            
            //increment iterator
            iteration++;
            
            //this line skips to the next iteration of the loop 
            continue;

         //if iterator is at 4, run the following
         case 4:
            //reset iterator
            iteration = 0;
            //set gpio to redled
            gpio = RED_LED;
            //ends switch
            break;
      }
      //turns on the current gpio color
      gpio_write(gpio, ON); 
      //delay
      delay(500);      
      //turns off the current gpio color    
      gpio_write(gpio, OFF); 
      //delay
      delay(300);

      //increments iterator var to next iteration
      iteration++;
   }
}
