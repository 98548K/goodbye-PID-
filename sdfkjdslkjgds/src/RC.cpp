
#include "vex.h"
#include "iostream"

using namespace vex;

#include "vex.h"
bool Clamping = false;
bool elevate = false;
bool tier_1 = false;
bool notstuck = true;
bool RemoteControlCodeEnabled = true;
// define variables used for controlling motors based on controller inputs
bool DrivetrainLNeedsToBeStopped_Controller1 = true;
bool DrivetrainRNeedsToBeStopped_Controller1 = true;

int rc_auto_loop_function_Controller1() {
  // process the controller input every 20 milliseconds
  // update the motors based on the input values
  bool Controller1RightShoulderControlMotorsStopped = true;
  while(true) {
    if(RemoteControlCodeEnabled) {
      // calculate the drivetrain motor velocities from the controller joystick axies
      // left = Axis3
      // right = Axis2
    claw_tracking.setPosition(10,degrees);
      if (Controller1.ButtonR1.pressing()) {
        //while (claw_tracking.position(degrees) <= 70) {
          claw_mech.spin(forward);
      /*}
      wait (.1,sec);
      claw_mech.spin(forward);
      claw_mech.stop(hold);*/
      Controller1RightShoulderControlMotorsStopped = false;
      }
       else if (Controller1.ButtonR2.pressing()) {
        claw_mech.spin(reverse);
        Controller1RightShoulderControlMotorsStopped = false;

      } else if (!Controller1RightShoulderControlMotorsStopped) {
        claw_mech.stop(hold);
        // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
        Controller1RightShoulderControlMotorsStopped = true;
      }

      int drivetrainLeftSideSpeed = Controller1.Axis3.position();
      int drivetrainRightSideSpeed = Controller1.Axis2.position();

      // check if the value is inside of the deadband range
      if (drivetrainLeftSideSpeed < 5 && drivetrainLeftSideSpeed > -5) {
        // check if the left motor has already been stopped
        if (DrivetrainLNeedsToBeStopped_Controller1) {
          // stop the left drive motor
          LeftDriveSmart.stop();
          // tell the code that the left motor has been stopped
          DrivetrainLNeedsToBeStopped_Controller1 = false;
        }
      } else {
        // reset the toggle so that the deadband code knows to stop the left motor nexttime the input is in the deadband range
        DrivetrainLNeedsToBeStopped_Controller1 = true;
      }
      // check if the value is inside of the deadband range
      if (drivetrainRightSideSpeed < 5 && drivetrainRightSideSpeed > -5) {
        // check if the right motor has already been stopped
        if (DrivetrainRNeedsToBeStopped_Controller1) {
          // stop the right drive motor
          RightDriveSmart.stop();
          // tell the code that the right motor has been stopped
          DrivetrainRNeedsToBeStopped_Controller1 = false;
        }
      } else {
        // reset the toggle so that the deadband code knows to stop the right motor next time the input is in the deadband range
        DrivetrainRNeedsToBeStopped_Controller1 = true;
      }
      
      // only tell the left drive motor to spin if the values are not in the deadband range
      if (DrivetrainLNeedsToBeStopped_Controller1) {
        LeftDriveSmart.setVelocity(drivetrainLeftSideSpeed, percent);
        LeftDriveSmart.spin(forward);
      }
      // only tell the right drive motor to spin if the values are not in the deadband range
      if (DrivetrainRNeedsToBeStopped_Controller1) {
        RightDriveSmart.setVelocity(drivetrainRightSideSpeed, percent);
        RightDriveSmart.spin(forward);
      }
      if (Controller1.ButtonUp.pressing()) {
      notstuck = true;
      if (notstuck == true) {
      claw_mech.setVelocity(100, pct);
      while (claw_tracking.position(degrees) >= 270){
            claw_mech.spin(reverse);
          }
          wait (.1,sec);
          claw_mech.spinFor(140,degrees);
          claw_mech.stop(hold);
      }
    }
    if (Controller1.ButtonRight.pressing()) {
        //emergency code

        /*notstuck = false;
        wait (.1,sec);
        claw_mech.spinFor(140,degrees);
        claw_mech.stop(hold);*/

        while (claw_tracking.position(degrees) <= 11){
            claw_mech.spin(forward);
          }
          wait (.1,sec);
          claw_mech.stop(hold); 
    }
    // Clamp toggle
    if (Controller1.ButtonY.pressing()) {
      if (Clamping == true){
        Clamping = false;
        wait(.22, sec);
      }
       else if (Clamping == false){
        Clamping = true;
        wait(.22, sec);
      }
    }
    Clamp.set(Clamping);

    // Color sort 

    // Descore mech toggle    
  if (Controller1.ButtonB.pressing()) {
      if (elevate == false){
        elevate = true;
        wait(.1, sec);
      }
       else if (elevate == true){
        elevate = false;
        wait(.1, sec);
      }
    }
    descore_mech.set(elevate);

    // Elevation toggle
  /*if (Controller1.ButtonDown.pressing()) {
      if (tier_1 == false){
        claw_mech.setVelocity(100,pct);
        while (claw_tracking.position(degrees) >= 10){
            claw_mech.spin(reverse);
          }
          wait (.1,sec);
          claw_mech.spinFor(240,degrees);
          claw_mech.stop(hold);
          elevation.set(true);
          claw_mech.spinFor(-140,degrees);
          claw_mech.stop(hold);
          tier_1 = true;
      }
       else if (tier_1 == true){
        tier_1 = false;
        wait(.1, sec);
      }
    }
    elevation.set(tier_1);*/

    // Intake Spinner
    if (Controller1.ButtonL1.pressing()) {
        intake.spin(reverse);
        // insert function here
    }else if (Controller1.ButtonL2.pressing()) {
      intake.spin(forward);
    }else if (true){
      intake.stop();
    }
    }
    // wait before repeating the process
    wait(20, msec);
  }
  return 0;
}

void vexcodeInit( void ) {
  //task rc_auto_loop_task_Controller1(rc_auto_loop_function_Controller1);
}
