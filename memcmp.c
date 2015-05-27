// memcmp.c / libstd
// xyn9 <xyn9.mail@gmail.com>
// (CC) Attribution-NonCommercial-ShareAlike; http://creativecommons.org/licenses/by-nc-sa/3.0/





// Tiny C Runtime Library
// By Mike_V
// http://www.codeproject.com/KB/library/tlibc.aspx
// based on:
// LIBCTINY - Matt Pietrek 2001
// MSDN Magazine, January 2001
// http://www.wheaty.net/downloads.htm
// 08/13/06 (mv)


#include <stddef.h>

int memcmp(const void *b1, const void *b2, size_t n){
  //
  const unsigned char *p1 = (const unsigned char*)b1;
  const unsigned char *p2 = (const unsigned char*)b2;
  size_t i;
  //
  if(! n){ return 0; }
  for(i=0; i<n; i++){
  	if (p1[i] != p2[i])
  		return p1[i]-p2[i];
  }
  //
  return 0;
}





//
