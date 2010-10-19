// libstd / initterm.h
// xyn9 <xyn9.mail@gmail.com>
// (CC) Attribution-NonCommercial-ShareAlike; http://creativecommons.org/licenses/by-nc-sa/3.0/





// LIBCTINY - Matt Pietrek 2001
// MSDN Magazine, January 2001
// http://www.wheaty.net/downloads.htm

typedef void (__cdecl *_PVFV)(void);
extern _PVFV __xc_a[], __xc_z[];    /* C++ initializers */

void __cdecl _initterm ( _PVFV *_pfbegin, _PVFV *_pfend );
void __cdecl _atexit_init(void);
void __cdecl _doexit( void );





//
