// ALLOC.cpp / libstd
// xyn9 <xyn9.mail@gmail.com>
// (CC) Attribution-NonCommercial-ShareAlike; http://creativecommons.org/licenses/by-nc-sa/3.0/





// LIBCTINY - Matt Pietrek 2001
// MSDN Magazine, January 2001
// http://www.wheaty.net/downloads.htm


//
#include <windows.h>
#include <malloc.h>


//
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


//
void * __cdecl malloc(size_t size)
{
    return HeapAlloc( GetProcessHeap(), 0, size );
}
//
void __cdecl free(void * p)
{
    HeapFree( GetProcessHeap(), 0, p );
}


//
#ifdef __cplusplus
} // EXTERN_C_END
#endif // __cplusplus





//
