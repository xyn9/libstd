// libstd / istdigit.cpp
// xyn9 <xyn9.mail@gmail.com>
// (CC) Attribution-NonCommercial-ShareAlike; http://creativecommons.org/licenses/by-nc-sa/3.0/





// Tiny C Runtime Library
// By Mike_V
// http://www.codeproject.com/KB/library/tlibc.aspx
// based on:
// LIBCTINY - Matt Pietrek 2001
// MSDN Magazine, January 2001
// http://www.wheaty.net/downloads.htm
// 08/12/06 (mv)


//
#include <windows.h>
#include <ctype.h>


//
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


int isdigit(int c)		{return (c >= '0' && c <= '9');}
int iswdigit(wint_t c)	{return iswctype(c, _DIGIT);}
int _ismbcdigit(int c)	{return isdigit(c);}


//
#ifdef __cplusplus
} // EXTERN_C_END
#endif // __cplusplus





//
