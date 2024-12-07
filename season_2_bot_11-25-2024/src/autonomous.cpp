#include "vex.h"

void autonomous(void) {
  
  Optical1.setLightPower(100, pct);
  Optical2.setLightPower(100, pct);
  //Drivetrain.setStopping(coast);
  color_sort.set(false);
  Inertial1.calibrate();
  if (auton == 1) {
    skills_auton();
  }
  else if (auton == 2) {
    left_blue();
  }
  else if (auton == 3) {
    left_red();
  }
  else if (auton == 4) {
    left_blue_elims();
  }
  else if (auton == 5) {
    left_red_elims();
  }
  else if (auton == 6) {
    right_blue();
  }
  else if (auton == 7) {
    right_red();
  }
  else if (auton == 8) {
    right_blue_elims();
  }
  else if (auton == 9) {
    right_red_elims();
  }
  else {
    //skills_auton();
    //left_blue();
    //left_red();
    //left_blue_elims();
    //left_red_elims();
    //right_blue();
    //right_red();
    //right blue_elims();
    //right_red_elims();
    
    
    /*setPosition(70.86614,-70.86614,0);
    driveTo(0,0,100,forward);*/

    //Reset_Both_Sides(20);

    left_blue();

    //reset claw rotation
    //claw_mech.setVelocity(100,pct);

    //left_red();
    
  }

  
} 