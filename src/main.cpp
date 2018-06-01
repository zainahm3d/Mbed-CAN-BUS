#include "mbed.h"
CAN can1(PA_11, PA_12);
DigitalOut led1(LED1);
char counter = 0;

int main() {
  can1.frequency(250000);
  can1.mode(CAN::Normal);
  printf("%s\n", "awake");
  while (1) {
    CANMessage msg;
    // msg.id = 3;
    // msg.data[2] = 9;
    // can1.write(msg);
    // led1 = !led1;
    // wait_ms(1);

    if (can1.read(msg)) {
      led1 = !led1;
      printf("%s", "ID ");
      printf("%d", int(msg.id));
      printf(" Format ");
      printf("%d ", msg.format);
      printf("     ");
      for (int i = 0; i < msg.len; i++) {
        printf("%d ", msg.data[i]);
      }
      printf("\n");
    }
  }
}
