#include <stdio.h>
#include <string.h>

void hexbin_to_hexstr(unsigned char *hexbin, unsigned int binsz, char * hexstr){
  const char * hex = "0123456789ABCDEF";
  unsigned int i;
  unsigned char * in = hexbin;
  char * out = hexstr;
  for( i=0; i<binsz; i++ ){
    out[0] = hex[ (*in>>4) & 0xF ];
    out[1] = hex[ (*in)    & 0xF ];
    in = in + 1;
    out = out+2;
  }
}


void hexstr_to_hexbin(char *hexstr, unsigned int strsize, unsigned char * hexbin){
  char * in = hexstr;
  unsigned char * out = hexbin;
  unsigned int i;
  char  astr[8] = "FFABAFEF";
  char * pos = astr;
  unsigned char binstr[4];
  for(i=0;i<strsize/2;i++){
    sscanf(in, "%2hhx", out);
    in = in + 2;
    out = out + 1;
  }
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
  hexbin_to_hexstr(bin, 4, ascii);
  printf("Ascii: %s  size: %lu  strlen: %lu\n", ascii, sizeof(ascii), strlen(ascii));



  printf("converting Ascii to Binary...\n" );
  char * hexstr = "FFABAFEF";
  unsigned char hexbin[4];
  hexstr_to_hexbin(hexstr, 8, hexbin);
  printf("hexstr: %s  size: %lu  strlen: %lu\n", hexstr, sizeof(hexstr), strlen(hexstr));
  printf("hexbin: " );
  for(i=0; i<sizeof(hexbin); i++){
    printf("%x", hexbin[i]);
  }
  printf("  size: %lu strlen: %lu\n", sizeof(hexbin), strlen(hexbin));

  printf("converting integer to string...\n" );
  unsigned int num = 000124;
  char str[6];
  int pad = 6;
  sprintf(str, "%0*d", pad, num);
  printf("num: %d\n", num);
  printf("str: %s\n", str);



}
