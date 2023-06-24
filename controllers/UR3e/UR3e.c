#include <webots/robot.h>
#include <webots/keyboard.h>
#include <webots/motor.h>
#include <math.h>

#define TIME_STEP 64
#define MAX_VELOCITY 1.0
#define MAX_POSITION_CHANGE 0.1

// Function to clamp a value within a specified range
double clamp(double value, double min, double max) {
  if (value < min)
    return min;
  if (value > max)
    return max;
  return value;
}

int main(int argc, char **argv) {
  wb_robot_init();

  // Get motor devices
  WbDeviceTag shoulderPanMotor = wb_robot_get_device("shoulder_pan_joint");
  WbDeviceTag shoulderLiftMotor = wb_robot_get_device("shoulder_lift_joint");
  WbDeviceTag elbowLiftMotor = wb_robot_get_device("elbow_joint");
  WbDeviceTag wrist1Motor = wb_robot_get_device("wrist_1_joint");
  WbDeviceTag wrist2Motor = wb_robot_get_device("wrist_2_joint");
  WbDeviceTag wrist3Motor = wb_robot_get_device("wrist_3_joint");

  // Enable keyboard input
  wb_keyboard_enable(TIME_STEP);

  while (wb_robot_step(TIME_STEP) != -1) {
    int key = wb_keyboard_get_key();

    if (key == WB_KEYBOARD_UP) {
      // Move shoulder_pan_joint clockwise
      double currentPosition = wb_motor_get_target_position(shoulderPanMotor);
      double newPosition = currentPosition + MAX_POSITION_CHANGE;
      newPosition = clamp(newPosition, -M_PI, M_PI);
      wb_motor_set_position(shoulderPanMotor, newPosition);
    } else if (key == WB_KEYBOARD_DOWN) {
      // Move shoulder_pan_joint counterclockwise
      double currentPosition = wb_motor_get_target_position(shoulderPanMotor);
      double newPosition = currentPosition - MAX_POSITION_CHANGE;
      newPosition = clamp(newPosition, -M_PI, M_PI);
      wb_motor_set_position(shoulderPanMotor, newPosition);
    } else if (key == WB_KEYBOARD_LEFT) {
      // Move shoulder_lift_joint clockwise
      double currentPosition = wb_motor_get_target_position(shoulderLiftMotor);
      double newPosition = currentPosition + MAX_POSITION_CHANGE;
      newPosition = clamp(newPosition, -M_PI, M_PI);
      wb_motor_set_position(shoulderLiftMotor, newPosition);
    } else if (key == WB_KEYBOARD_RIGHT) {
      // Move shoulder_lift_joint counterclockwise
      double currentPosition = wb_motor_get_target_position(shoulderLiftMotor);
      double newPosition = currentPosition - MAX_POSITION_CHANGE;
      newPosition = clamp(newPosition, -M_PI, M_PI);
      wb_motor_set_position(shoulderLiftMotor, newPosition);
    } else if (key == 'A' || key == 'a') {
      // Move elbow_joint clockwise
      double currentPosition = wb_motor_get_target_position(elbowLiftMotor);
      double newPosition = currentPosition + MAX_POSITION_CHANGE;
      newPosition = clamp(newPosition, -M_PI, M_PI);
      wb_motor_set_position(elbowLiftMotor, newPosition);
    } else if (key == 'D' || key == 'd') {
      // Move elbow_joint counterclockwise
      double currentPosition = wb_motor_get_target_position(elbowLiftMotor);
      double newPosition = currentPosition - MAX_POSITION_CHANGE;
      newPosition = clamp(newPosition, -M_PI, M_PI);
      wb_motor_set_position(elbowLiftMotor, newPosition);
    } else if (key == 'Q' || key == 'q') {
      // Move wrist_1_joint clockwise
      double currentPosition = wb_motor_get_target_position(wrist1Motor);
      double newPosition = currentPosition + MAX_POSITION_CHANGE;
      newPosition = clamp(newPosition, -M_PI, M_PI);
      wb_motor_set_position(wrist1Motor, newPosition);
    } else if (key == 'E' || key == 'e') {
      // Move wrist_1_joint counterclockwise
      double currentPosition = wb_motor_get_target_position(wrist1Motor);
      double newPosition = currentPosition - MAX_POSITION_CHANGE;
      newPosition = clamp(newPosition, -M_PI, M_PI);
      wb_motor_set_position(wrist1Motor, newPosition);
    } else if (key == 'Z' || key == 'z') {
      // Move wrist_2_joint clockwise
      double currentPosition = wb_motor_get_target_position(wrist2Motor);
      double newPosition = currentPosition + MAX_POSITION_CHANGE;
      newPosition = clamp(newPosition, -M_PI, M_PI);
      wb_motor_set_position(wrist2Motor, newPosition);
    } else if (key == 'C' || key == 'c') {
      // Move wrist_2_joint counterclockwise
      double currentPosition = wb_motor_get_target_position(wrist2Motor);
      double newPosition = currentPosition - MAX_POSITION_CHANGE;
      newPosition = clamp(newPosition, -M_PI, M_PI);
      wb_motor_set_position(wrist2Motor, newPosition);
    } else if (key == 'X' || key == 'x') {
      // Move wrist_3_joint clockwise
      double currentPosition = wb_motor_get_target_position(wrist3Motor);
      double newPosition = currentPosition + MAX_POSITION_CHANGE;
      newPosition = clamp(newPosition, -M_PI, M_PI);
      wb_motor_set_position(wrist3Motor, newPosition);
    } else if (key == 'V' || key == 'v') {
      // Move wrist_3_joint counterclockwise
      double currentPosition = wb_motor_get_target_position(wrist3Motor);
      double newPosition = currentPosition - MAX_POSITION_CHANGE;
      newPosition = clamp(newPosition, -M_PI, M_PI);
      wb_motor_set_position(wrist3Motor, newPosition);
    } else if (key == WB_KEYBOARD_ALT) {
      // Stop all joints
      wb_motor_set_velocity(shoulderPanMotor, 0.0);
      wb_motor_set_velocity(shoulderLiftMotor, 0.0);
      wb_motor_set_velocity(elbowLiftMotor, 0.0);
      wb_motor_set_velocity(wrist1Motor, 0.0);
      wb_motor_set_velocity(wrist2Motor, 0.0);
      wb_motor_set_velocity(wrist3Motor, 0.0);
    }
  }

  wb_robot_cleanup();

  return 0;
}
