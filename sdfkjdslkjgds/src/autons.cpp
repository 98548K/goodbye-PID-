
#include "vex.h"

using namespace vex;


void right_red() {
    Reset_Both_Sides(47);
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
    Reset_Both_Sides(47);
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
    Reset_Both_Sides(47);
    Clamp.set(true);
    Drivetrain.driveFor(-22,inches);
    Clamp.set(false);
    intake.spin(reverse);
    Drivetrain.turnFor(40,degrees);
    Drivetrain.driveFor(10,inches); 
    Drivetrain.turnFor(90,degrees);
    //Drivetrain.driveFor(12,inches);
}

void left_blue() {
    Reset_Both_Sides(47);
    Clamp.set(true);
    Drivetrain.driveFor(-21,inches);
    Clamp.set(false);
    intake.spin(reverse);
    Drivetrain.turnFor(40,degrees);
    Drivetrain.driveFor(12,inches); 
    Drivetrain.turnFor(100,degrees);
    //Drivetrain.driveFor(14,inches);
}

void skills_auton() {
    Reset_Both_Sides(47);
    intake.spinFor(-1500,degrees,false);
    wait (1,sec);
    Drivetrain.driveFor(13,inches);
    Drivetrain.turnFor(45,degrees);
    Clamp.set(true);
    Drivetrain.driveFor(-13,inches);
    Clamp.set(false);
    Drivetrain.turnFor(-95,degrees);
    intake.spin(reverse);
    Drivetrain.driveFor(18,inches);
    Drivetrain.turnFor(85,degrees);
    Drivetrain.driveFor(-7,inches);
    Clamp.set(true);
    Drivetrain.driveFor(5,inches);
}

void right_blue_elims() {
    
}

void right_red_elims() {
    
}

void left_red_elims() {
    
}

void left_blue_elims() {
    
}