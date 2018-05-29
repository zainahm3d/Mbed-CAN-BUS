#include "mbed.h"
CAN can1(PA_11, PA_12);
DigitalOut led1(LED1);
char counter = 0;
int main() {
  printf("start\n");

  can1.frequency(250000);
  can1.mode(CAN::Normal);

  while (1) {
    if (can1.write(CANMessage(1337, &counter, 1))) {
      printf("sent\n");
    } else {
      printf("error\n");
    }
    counter++;
    led1 = !led1;
    wait_ms(200);
  }
}
