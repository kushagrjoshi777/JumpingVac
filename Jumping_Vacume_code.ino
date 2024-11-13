#include "USBHost_t36.h"
// try this code after removing all usb lines

//initialising usbs (connections) wagera
USBHost myusb;
USBHub hub1(myusb);
USBHIDParser hid1(myusb);
JoystickController joystick1(myusb);
BluetoothController bluet(myusb, true, "0000"); //imp for pairing (first time specially)
//total drivers
USBDriver *drivers[] = {&hub1, &joystick1, &hid1};
#define CNT_DEVICES (sizeof(drivers)/sizeof(drivers[0]))

void setup() {
  Serial.begin(2000000);
  while (!Serial);
  Serial.println("\nPS4 Controller Joystick Test");
  myusb.begin();
}

void loop() {
  myusb.Task();

  if (joystick1.available()) {

    int lY = joystick1.getAxis(1);
    if (joystick1.getButtons()==1) {
      Serial.print("Adding speed of pwm: ");
      Serial.println(lY);
    }
    joystick1.joystickDataClear();
    
    delay(100);
  }
}
