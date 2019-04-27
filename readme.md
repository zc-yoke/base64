'''
/*
功能：这是一个base64的编码和解码库
源码来源：https://github.com/littlstar/b64.c
依赖：无外部依赖
下面是代码原库的一个实例
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "b64.h"

int main (void) {
  unsigned char *str = "brian the monkey and bradley the kinkajou are friends";
  char *enc = b64_encode(str, strlen(str));

  printf("%s\n", enc); // YnJpYW4gdGhlIG1vbmtleSBhbmQgYnJhZGxleSB0aGUga2lua2Fqb3UgYXJlIGZyaWVuZHM=

  char *dec = b64_decode(enc, strlen(enc));

  printf("%s\n", dec); // brian the monkey and bradley the kinkajou are friends
  //释放内存
  free(enc);
  //释放内存
  free(dec);
  return 0;
}
'''