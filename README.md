# FlySkyArduinoBuggy
Use a FlySky or Turnigy receiver connected to an Arduino and motor shield to drive two servos.

This code builds uses the excellent [FlySky i-bus library](https://gitlab.com/timwilkinson/FlySkyIBus) by Tim Wilkinson.

Connect the servos to your arduino, pins 9 and 10 for pwm, and 5V/Gnd. You'll need to connect the receiver to Gnd and 5v, as well as RX (pin 0).

In the future I may migrate to the [delfy22 iBus_Arduino](https://github.com/delfy22/iBus_Arduino) library which could support telemetry. Additionally I'd like to have some of the other channels control some digital outputs etc.
