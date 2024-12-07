
#include "vex.h"

using namespace vex;



int current_time = 0;


void usercontrol(void) {
  
  task rc_auto_loop_task_Controller1(rc_auto_loop_function_Controller1);
  // User control code here, inside the loop
  while (1) {
    claw_mech.setVelocity(100, pct);
    intake.setVelocity(100, pct);
    Drivetrain.setDriveVelocity(100, pct);
    claw_tracking.setPosition(0,degrees);
    color_sort.set(false);
    LeftDriveSmart.setVelocity(100, pct);
    RightDriveSmart.setVelocity(100,pct);
    //internal timer
    current_time = current_time + 1;
    wait (.9,sec);

    //Optical1.setLightPower(100,pct);
    //Optical1.objectDetected(blue_detected);
    //Drivetrain.setStopping(coast);
  if (current_time == 1) {
    if (Clamping == false){
        Clamping = false;
        wait(.22, sec);
      }
      Clamp.set(Clamping);
  }

  else if (current_time == 10) {
    //Controller1.rumble("--");
  }
  else if (current_time == 20) {
    //Controller1.rumble("--");
  }
  else if (current_time == 30) {
    //Controller1.rumble("--");
  }
  else if (current_time == 40) {
    //Controller1.rumble("--");
  }
  else if (current_time == 50) {
    //Controller1.rumble("--");
  }
  else if (current_time == 60) {
    //Controller1.rumble("--");
  }
  else if (current_time == 70) {
    //Controller1.rumble("--");
  }
  else if (current_time == 80) {
    //Controller1.rumble("--");
  }
  else if (current_time == 90) {
    //Controller1.rumble("--");
  }
  else if (current_time == 100) {
    //Controller1.rumble("--");
  }
  else if (current_time == 105) {
    Controller1.Screen.print("over time >:(");
  }

  
    wait(.1, sec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
   }
}