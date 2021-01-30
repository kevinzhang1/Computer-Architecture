#include <stdio.h>
int main(int argc, char * argv[])
{

typedef union float_32 {
  float float_value_in_32_bits;
  int floating_value_as_int;
  struct sign_exp_mantissa{
    unsigned int mantissa: 23;
    unsigned int exponent:  8;
    unsigned int     sign:  1;
  } f_bits;
  struct single_bits {
    unsigned  b0 :1; 
    unsigned  b1 :1;
    unsigned  b2 :1;
    unsigned  b3 :1;
    unsigned  b4 :1;
    unsigned  b5 :1;
    unsigned  b6 :1;
    unsigned  b7 :1;
    unsigned  b8 :1;
    unsigned  b9 :1;
    unsigned  b10:1;
    unsigned  b11:1;
    unsigned  b12:1;
    unsigned  b13:1;
    unsigned  b14:1;
    unsigned  b15:1;
    unsigned  b16:1;
    unsigned  b17:1;
    unsigned  b18:1;
    unsigned  b19:1;
    unsigned  b20:1;
    unsigned  b21:1;
    unsigned  b22:1;
    unsigned  b23:1;
    unsigned  b24:1;
    unsigned  b25:1;
    unsigned  b26:1;
    unsigned  b27:1;
    unsigned  b28:1;
    unsigned  b29:1;
    unsigned  b30:1;
    unsigned  b31:1;
  } bit;
} float_32;
  float f1, f2;
  float_32 F1, F2, hardware, sum;
  char bit_string[43];
  int scan=1;
  while(scan==1){
    printf("Please enter two positive floating point values each with:\n    - no more than 6 significant digits\n    - a value between   +   10**37 and 10**-37\n\nEnter Float 1:  ");
    scan=scanf("%f", &f1);
    F1.float_value_in_32_bits=f1;
    printf("Enter Float 2:  ");
    scan=scanf("%f", &f2);
    F2.float_value_in_32_bits=f2;
    if(scan != 1) {break;}
    printf("\n\nOriginal pattern of Float 1: ");
    for(int i = 0; i < 42; i++) {bit_string[i] = ' ';}
    bit_string[42] = '\0';
    bit_string[0] = F1.bit.b31?'1':'0';
    bit_string[2] = F1.bit.b30?'1':'0';
    bit_string[3] = F1.bit.b29?'1':'0';
    bit_string[4] = F1.bit.b28?'1':'0';
    bit_string[5] = F1.bit.b27?'1':'0';
    bit_string[7] = F1.bit.b26?'1':'0';
    bit_string[8] = F1.bit.b25?'1':'0';
    bit_string[9] = F1.bit.b24?'1':'0';  
    bit_string[10] = F1.bit.b23?'1':'0';
    bit_string[12] = F1.bit.b22?'1':'0';
    bit_string[13] = F1.bit.b21?'1':'0';  
    bit_string[14] = F1.bit.b20?'1':'0';
    bit_string[16] = F1.bit.b19?'1':'0';
    bit_string[17] = F1.bit.b18?'1':'0';
    bit_string[18] = F1.bit.b17?'1':'0';
    bit_string[19] = F1.bit.b16?'1':'0';
    bit_string[21] = F1.bit.b15?'1':'0';
    bit_string[22] = F1.bit.b14?'1':'0';
    bit_string[23] = F1.bit.b13?'1':'0';
    bit_string[24] = F1.bit.b12?'1':'0';
    bit_string[26] = F1.bit.b11?'1':'0';
    bit_string[27] = F1.bit.b10?'1':'0';
    bit_string[28] = F1.bit.b9?'1':'0';
    bit_string[29] = F1.bit.b8?'1':'0';
    bit_string[31] = F1.bit.b7?'1':'0';
    bit_string[32] = F1.bit.b6?'1':'0';
    bit_string[33] = F1.bit.b5?'1':'0';
    bit_string[34] = F1.bit.b4?'1':'0';
    bit_string[36] = F1.bit.b3?'1':'0';
    bit_string[37] = F1.bit.b2?'1':'0';
    bit_string[38] = F1.bit.b1?'1':'0';
    bit_string[39] = F1.bit.b0?'1':'0';
    printf("%s\nOriginal pattern of Float 2: ", bit_string);
    for(int i = 0; i < 42; i++) {bit_string[i] = ' ';}
    bit_string[42] = '\0';
    bit_string[0] = F2.bit.b31?'1':'0';
    bit_string[2] = F2.bit.b30?'1':'0';
    bit_string[3] = F2.bit.b29?'1':'0';
    bit_string[4] = F2.bit.b28?'1':'0';
    bit_string[5] = F2.bit.b27?'1':'0';
    bit_string[7] = F2.bit.b26?'1':'0';
    bit_string[8] = F2.bit.b25?'1':'0';
    bit_string[9] = F2.bit.b24?'1':'0';  
    bit_string[10] = F2.bit.b23?'1':'0';
    bit_string[12] = F2.bit.b22?'1':'0';
    bit_string[13] = F2.bit.b21?'1':'0';  
    bit_string[14] = F2.bit.b20?'1':'0';
    bit_string[16] = F2.bit.b19?'1':'0';
    bit_string[17] = F2.bit.b18?'1':'0';
    bit_string[18] = F2.bit.b17?'1':'0';
    bit_string[19] = F2.bit.b16?'1':'0';
    bit_string[21] = F2.bit.b15?'1':'0';
    bit_string[22] = F2.bit.b14?'1':'0';
    bit_string[23] = F2.bit.b13?'1':'0';
    bit_string[24] = F2.bit.b12?'1':'0';
    bit_string[26] = F2.bit.b11?'1':'0';
    bit_string[27] = F2.bit.b10?'1':'0';
    bit_string[28] = F2.bit.b9?'1':'0';
    bit_string[29] = F2.bit.b8?'1':'0';
    bit_string[31] = F2.bit.b7?'1':'0';
    bit_string[32] = F2.bit.b6?'1':'0';
    bit_string[33] = F2.bit.b5?'1':'0';
    bit_string[34] = F2.bit.b4?'1':'0';
    bit_string[36] = F2.bit.b3?'1':'0';
    bit_string[37] = F2.bit.b2?'1':'0';
    bit_string[38] = F2.bit.b1?'1':'0';
    bit_string[39] = F2.bit.b0?'1':'0';
  printf("%s\n", bit_string);
    if(F1.f_bits.exponent==F2.f_bits.exponent) {
    F1.f_bits.exponent+=1;
    F2.f_bits.exponent+=1;
    sum.f_bits.exponent=F1.f_bits.exponent;
    sum.f_bits.mantissa=(F1.f_bits.mantissa+F2.f_bits.mantissa)>>1;
    sum.bit.b22=1; 
  } else if(F1.f_bits.exponent>F2.f_bits.exponent) {
    F2.f_bits.mantissa>>=1;
    F2.bit.b22=1;
    int i=F1.f_bits.exponent-F2.f_bits.exponent-1;
    if(i>24) {i=24;}
    F2.f_bits.mantissa>>=i-1;
    if(F2.bit.b0==1) {F2.f_bits.mantissa=(F2.f_bits.mantissa>>1)+1;}
    else {F2.f_bits.mantissa>>=1;}
    sum.f_bits.exponent=F1.f_bits.exponent;
    sum.f_bits.mantissa=F1.f_bits.mantissa+F2.f_bits.mantissa;
  } else {
  F1.f_bits.mantissa>>=1;
    F1.bit.b22=1;
    int i=F2.f_bits.exponent-F1.f_bits.exponent-1;
    if(i>24) {i=24;}
    F1.f_bits.mantissa>>=i-1;
    if(F1.bit.b0==1) {F1.f_bits.mantissa=(F1.f_bits.mantissa>>1)+1;}
    else {F1.f_bits.mantissa>>=1;}
    sum.f_bits.exponent=F2.f_bits.exponent;
    sum.f_bits.mantissa=F2.f_bits.mantissa+F1.f_bits.mantissa;
  }
  if(F1.f_bits.exponent==254 || F2.f_bits.exponent==254) {
  sum.f_bits.exponent=255;
  sum.f_bits.mantissa=0;
  }
    for(int i = 0; i < 42; i++) {bit_string[i] = ' ';}
    bit_string[42] = '\0';
    bit_string[0] = sum.bit.b31?'1':'0';
    bit_string[2] = sum.bit.b30?'1':'0';
    bit_string[3] = sum.bit.b29?'1':'0';
    bit_string[4] = sum.bit.b28?'1':'0';
    bit_string[5] = sum.bit.b27?'1':'0';
    bit_string[7] = sum.bit.b26?'1':'0';
    bit_string[8] = sum.bit.b25?'1':'0';
    bit_string[9] = sum.bit.b24?'1':'0';  
    bit_string[10] = sum.bit.b23?'1':'0';
    bit_string[12] = sum.bit.b22?'1':'0';
    bit_string[13] = sum.bit.b21?'1':'0';  
    bit_string[14] = sum.bit.b20?'1':'0';
    bit_string[16] = sum.bit.b19?'1':'0';
    bit_string[17] = sum.bit.b18?'1':'0';
    bit_string[18] = sum.bit.b17?'1':'0';
    bit_string[19] = sum.bit.b16?'1':'0';
    bit_string[21] = sum.bit.b15?'1':'0';
    bit_string[22] = sum.bit.b14?'1':'0';
    bit_string[23] = sum.bit.b13?'1':'0';
    bit_string[24] = sum.bit.b12?'1':'0';
    bit_string[26] = sum.bit.b11?'1':'0';
    bit_string[27] = sum.bit.b10?'1':'0';
    bit_string[28] = sum.bit.b9?'1':'0';
    bit_string[29] = sum.bit.b8?'1':'0';
    bit_string[31] = sum.bit.b7?'1':'0';
    bit_string[32] = sum.bit.b6?'1':'0';
    bit_string[33] = sum.bit.b5?'1':'0';
    bit_string[34] = sum.bit.b4?'1':'0';
    bit_string[36] = sum.bit.b3?'1':'0';
    bit_string[37] = sum.bit.b2?'1':'0';
    bit_string[38] = sum.bit.b1?'1':'0';
    bit_string[39] = sum.bit.b0?'1':'0';
    printf("Bit pattern of result      : %s", bit_string);
    hardware.float_value_in_32_bits=f1+f2;
    printf("\n\nEMULATED FLOATING RESULT FROM PRINTF ==>>> %.6f\n", sum.float_value_in_32_bits);
    printf("HARDWARE FLOATING RESULT FROM PRINTF ==>>> %.6f\n\n", hardware.float_value_in_32_bits);
  }
  return 0;
}