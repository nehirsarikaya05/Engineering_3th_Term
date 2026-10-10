#include <stdio.h>
#include <stdint.h>
void binary_printer(uint8_t num){
  printf("DECIMAL:%u BINARY:", num);
  for (int i=7; i>=0; i--){
    printf("%u", (num >> i) & 1);
  }
  printf("\n\n");
}
uint8_t radix(uint8_t num){
  num = 0b100000000 - num;
  return num;
}
int main(void){
  uint8_t num = 0; 
  scanf("%hhu", &num);
  binary_printer(num);
  printf("RADIX - TWO'S COMPLEMENT:\n");
  binary_printer(radix(num));
  printf("DIMINISHED RADIX - ONE'S COMPLEMENT:\n");
  binary_printer(radix(num)-1);
}
