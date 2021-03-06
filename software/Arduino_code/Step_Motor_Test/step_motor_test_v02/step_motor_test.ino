#include <Stepper.h>
unsigned long time; //added for accurate timing
/*-----( Declare Constants, Pin Numbers )-----*/
//---( Number of steps per revolution of INTERNAL motor in 4-step mode )---
#define STEPS_PER_MOTOR_REVOLUTION 32   

//---( Steps per OUTPUT SHAFT of gear reduction )---
#define STEPS_PER_OUTPUT_REVOLUTION 32 * 64  //2048  
 

/*-----( Declare objects )-----*/
// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to

//The pin connections need to be 4 pins connected
// to Motor Driver In1, In2, In3, In4  and then the pins entered
// here in the sequence 1-3-2-4 for proper sequencing
Stepper small_stepper(STEPS_PER_MOTOR_REVOLUTION, 8, 9, 10, 11);
// Stepper small_stepper(STEPS_PER_MOTOR_REVOLUTION, 4, 9, 10, 11);

/*-----( Declare Variables )-----*/
int  Steps2Take;

void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  Serial.begin(9600);
// Nothing  (Stepper Library sets pins as outputs)
}/*--(end setup )---*/

void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
  delay(3*1000); //change the x*1000 part for seconds
  time = millis();
  Serial.println(time/1000.);
  Steps2Take  =  2*STEPS_PER_OUTPUT_REVOLUTION ;  // Rotate CW 1 turn
  small_stepper.setSpeed(500);   
  small_stepper.step(Steps2Take);
  time = millis();
  Serial.println(time/1000.);
  delay(3*1000);
  time = millis();
  Serial.println(time/1000.);
  Steps2Take  =  - 2*STEPS_PER_OUTPUT_REVOLUTION;  // Rotate CCW 1 turn  
  small_stepper.setSpeed(500);  // 700 a good max speed??
  small_stepper.step(Steps2Take);
  time = millis();
  Serial.println(time/1000.);
  delay(10);

}/* --(end main loop )-- */

/* ( THE END ) */
