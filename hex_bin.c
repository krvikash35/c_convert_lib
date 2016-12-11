#include <stdio.h>
#include <string.h>

void bin_to_ascii(unsigned char *bin, unsigned int binsz, char * ascii){
  const char * hex = "0123456789ABCDEF";
  unsigned int i;
  unsigned char * in = bin;
  char * out = ascii;
  for( i=0; i<binsz; i++ ){
    out[0] = hex[ (*bin>>4) & 0xF ];
    out[1] = hex[ (*bin)    & 0xF ];
    in = in + 1;
    out = out+2;
  }
}


void ascii_to_bin(){


}

int main(){
  unsigned char bin[] = {0xFF, 0xAB, 0xAF, 0xEF};
  char ascii[8];
  printf("converting Binary to Ascii...\n" );
  int i;
  printf("Bin: ");
  for(i=0;i<sizeof(bin);i++ ){
    printf("%x", bin[i]);
  }
  printf("  size: %lu strlen: %lu\n", sizeof(bin), strlen(bin));
  bin_to_ascii(bin, 4, ascii);
  printf("Ascii: %s  size: %lu  strlen: %lu\n", ascii, sizeof(ascii), strlen(ascii));



  printf("converting Ascii to Binary...\n" );
}
