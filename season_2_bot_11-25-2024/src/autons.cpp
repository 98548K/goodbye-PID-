#include "vex.h"

void right_red() {
    Clamp.set(true);
    Drivetrain.driveFor(-22,inches);
    Clamp.set(false);
    intake.spin(reverse);
    Drivetrain.turnFor(-40,degrees);
    Drivetrain.driveFor(10,inches); 
    Drivetrain.turnFor(-90,degrees);
    Drivetrain.driveFor(12,inches);
}

void left_red() {
    Clamp.set(true);
    Drivetrain.driveFor(-22,inches);
    Clamp.set(false);
    intake.spin(reverse);
    Drivetrain.turnFor(40,degrees);
    Drivetrain.driveFor(10,inches); 
    Drivetrain.turnFor(90,degrees);
    Drivetrain.driveFor(12,inches);
}

void right_blue() {
    Clamp.set(true);
    Drivetrain.driveFor(-22,inches);
    Clamp.set(false);
    intake.spin(reverse);
    Drivetrain.turnFor(40,degrees);
    Drivetrain.driveFor(10,inches); 
    Drivetrain.turnFor(90,degrees);
    Drivetrain.driveFor(12,inches);
}

void left_blue() {
    Clamp.set(true);
    Drivetrain.driveFor(-21,inches);
    Clamp.set(false);
    intake.spin(reverse);
    Drivetrain.turnFor(40,degrees);
    Drivetrain.driveFor(12,inches); 
    Drivetrain.turnFor(100,degrees);
    Drivetrain.driveFor(14,inches);
}

void skills_auton() {
  
}

void right_blue_elims() {
    
}

void right_red_elims() {
    
}

void left_red_elims() {
    
}

void left_blue_elims() {
    
}