// libstd / memset.c
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

void *memset(void *_dst, int val, size_t _size){
	//
	char *realdst = (char*)_dst;
	size_t i;
	//
	for (i=0; i<_size; i++){
		realdst[i] = (char)val;
	}
	//
	return _dst;
}
