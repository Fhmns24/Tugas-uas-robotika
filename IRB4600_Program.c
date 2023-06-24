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
  WbDeviceTag LINK1_TRANSFORM = wb_robot_get_device("A motor");
  WbDeviceTag LINK2_TRANSFORM = wb_robot_get_device("B motor");
  WbDeviceTag LINK3_TRANSFORM = wb_robot_get_device("C motor");
  WbDeviceTag LINK4_TRANSFORM = wb_robot_get_device("D motor");
  WbDeviceTag LINK5_TRANSFORM = wb_robot_get_device("E motor");
  WbDeviceTag LINK6_TRANSFORM = wb_robot_get_device("F motor");

  // Enable keyboard input
  wb_keyboard_enable(TIME_STEP);

  while (wb_robot_step(TIME_STEP) != -1) {
    int key = wb_keyboard_get_key();

    if (key == WB_KEYBOARD_UP) {
      // Move axis_1_joint clockwise
      double currentPosition = wb_motor_get_target_position(LINK1_TRANSFORM);
      double newPosition = currentPosition + MAX_POSITION_CHANGE;
      newPosition = clamp(newPosition, -M_PI, M_PI);
      wb_motor_set_position(LINK1_TRANSFORM, newPosition);
    } else if (key == WB_KEYBOARD_DOWN) {
      // Move axis_1_joint counterclockwise
      double currentPosition = wb_motor_get_target_position(LINK1_TRANSFORM);
      double newPosition = currentPosition - MAX_POSITION_CHANGE;
      newPosition = clamp(newPosition, -M_PI, M_PI);
      wb_motor_set_position(LINK1_TRANSFORM, newPosition);
    } else if (key == WB_KEYBOARD_LEFT) {
      // Move axis_2_joint clockwise
      double currentPosition = wb_motor_get_target_position(LINK2_TRANSFORM);
      double newPosition = currentPosition + MAX_POSITION_CHANGE;
      newPosition = clamp(newPosition, -M_PI, M_PI);
      wb_motor_set_position(LINK2_TRANSFORM, newPosition);
    } else if (key == WB_KEYBOARD_RIGHT) {
      // Move axis_2_joint counterclockwise
      double currentPosition = wb_motor_get_target_position(LINK2_TRANSFORM);
      double newPosition = currentPosition - MAX_POSITION_CHANGE;
      newPosition = clamp(newPosition, -M_PI, M_PI);
      wb_motor_set_position(LINK2_TRANSFORM, newPosition);
    } else if (key == 'A' || key == 'a') {
      // Move axis_3_joint clockwise
      double currentPosition = wb_motor_get_target_position(LINK3_TRANSFORM);
      double newPosition = currentPosition + MAX_POSITION_CHANGE;
      newPosition = clamp(newPosition, -M_PI, M_PI);
      wb_motor_set_position(LINK3_TRANSFORM, newPosition);
    } else if (key == 'D' || key == 'd') {
      // Move axis_3_joint counterclockwise
      double currentPosition = wb_motor_get_target_position(LINK3_TRANSFORM);
      double newPosition = currentPosition - MAX_POSITION_CHANGE;
      newPosition = clamp(newPosition, -M_PI, M_PI);
      wb_motor_set_position(LINK3_TRANSFORM, newPosition);
    } else if (key == 'Q' || key == 'q') {
      // Move axis_4_joint clockwise
      double currentPosition = wb_motor_get_target_position(LINK4_TRANSFORM);
      double newPosition = currentPosition + MAX_POSITION_CHANGE;
      newPosition = clamp(newPosition, -M_PI, M_PI);
      wb_motor_set_position(LINK4_TRANSFORM, newPosition);
    } else if (key == 'E' || key == 'e') {
      // Move axis_4_joint counterclockwise
      double currentPosition = wb_motor_get_target_position(LINK4_TRANSFORM);
      double newPosition = currentPosition - MAX_POSITION_CHANGE;
      newPosition = clamp(newPosition, -M_PI, M_PI);
      wb_motor_set_position(LINK4_TRANSFORM, newPosition);
    } else if (key == 'Z' || key == 'z') {
      // Move axis_5_joint clockwise
      double currentPosition = wb_motor_get_target_position(LINK5_TRANSFORM);
      double newPosition = currentPosition + MAX_POSITION_CHANGE;
      newPosition = clamp(newPosition, -M_PI, M_PI);
      wb_motor_set_position(LINK5_TRANSFORM, newPosition);
    } else if (key == 'C' || key == 'c') {
      // Move axis_5_joint counterclockwise
      double currentPosition = wb_motor_get_target_position(LINK5_TRANSFORM);
      double newPosition = currentPosition - MAX_POSITION_CHANGE;
      newPosition = clamp(newPosition, -M_PI, M_PI);
      wb_motor_set_position(LINK5_TRANSFORM, newPosition);
    } else if (key == 'X' || key == 'x') {
      // Move axis_6_joint clockwise
      double currentPosition = wb_motor_get_target_position(LINK6_TRANSFORM);
      double newPosition = currentPosition + MAX_POSITION_CHANGE;
      newPosition = clamp(newPosition, -M_PI, M_PI);
      wb_motor_set_position(LINK6_TRANSFORM, newPosition);
    } else if (key == 'V' || key == 'v') {
      // Move axis_6_joint counterclockwise
      double currentPosition = wb_motor_get_target_position(LINK6_TRANSFORM);
      double newPosition = currentPosition - MAX_POSITION_CHANGE;
      newPosition = clamp(newPosition, -M_PI, M_PI);
      wb_motor_set_position(LINK6_TRANSFORM, newPosition);
    } else if (key == WB_KEYBOARD_ALT) {
      // Stop all joints
      wb_motor_set_velocity(LINK1_TRANSFORM, 0.0);
      wb_motor_set_velocity(LINK2_TRANSFORM, 0.0);
      wb_motor_set_velocity(LINK3_TRANSFORM, 0.0);
      wb_motor_set_velocity(LINK4_TRANSFORM, 0.0);
      wb_motor_set_velocity(LINK5_TRANSFORM, 0.0);
      wb_motor_set_velocity(LINK6_TRANSFORM, 0.0);
    }
  }

  wb_robot_cleanup();

  return 0;
}

