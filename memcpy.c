// memcpy.c / libstd
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

void *memcpy(void *_dst, const void *_src, size_t _size){
  //
  char *dst = (char*)_dst;
  const char *src = (char*)_src;
  size_t i;
  //
  for(i=0; i<_size; i++){
  	dst[i] = src[i];
  }
  //
  return _dst;
}





//
