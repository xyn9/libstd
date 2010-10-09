// libstd / istalpha.cpp
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


int isalpha(int c){return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');}
int iswalpha(wint_t c){return iswctype(c, _ALPHA);}
int _ismbcalpha(int c){return isalpha(c);}


//
#ifdef __cplusplus
} // EXTERN_C_END
#endif // __cplusplus





//
