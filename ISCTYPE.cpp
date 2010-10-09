// libstd / ISCTYPE.cpp
// xyn9 <xyn9.mail@gmail.com>
// (CC) Attribution-NonCommercial-ShareAlike; http://creativecommons.org/licenses/by-nc-sa/3.0/





// Tiny C Runtime Library
// By Mike_V
// http://www.codeproject.com/KB/library/tlibc.aspx
// based on:
// LIBCTINY - Matt Pietrek 2001
// MSDN Magazine, January 2001
// http://www.wheaty.net/downloads.htm


//
#include <windows.h>
#include <ctype.h>


//
#ifdef __cplusplus
extern "C"
#endif
//
int iswctype(wint_t c, wctype_t type)
{
	WORD ret;
	GetStringTypeW(CT_CTYPE1, (LPCWSTR)&c, 1, &ret);
	if ((ret & type) != 0)
		return 1;
	return 0;
}





//
