 /*
   to read a 8 bit unsigned integer, interchange the adjacent bits i.e D0 with D1, D2 with D3….. D6 with D7. Display the final number.
  
  Input: 0xAA
  
   Output: 0x55
   */
   #include <stdio.h>
  
 unsigned char swap_adjacent_bits(unsigned char num) {
     unsigned char swapped = 0;
     swapped |= (num & 0x01) << 1;
     swapped |= (num & 0x02) >> 1;
     swapped |= (num & 0x04) << 1;
     swapped |= (num & 0x08) >> 1;
     swapped |= (num & 0x10) << 1;
     swapped |= (num & 0x20) >> 1;
     swapped |= (num & 0x40) << 1;
     swapped |= (num & 0x80) >> 1;
     return swapped;
 }

 int main() {

      unsigned char num;
     int result;

     printf("Enter an 8-bit unsigned integer (0-255): ");
     while ((result = scanf("%hhu", &num)) != 1) {
         printf("Invalid input. Please enter an 8-bit unsigned integer (0-255): ");
         while (getchar() != '\n'); // Clear the input buffer
     }

     unsigned char swapped_num = swap_adjacent_bits(num);
     printf("Input: 0x%X\n", num);
     printf("Output: 0x%X\n", swapped_num);

     return 0;
}
