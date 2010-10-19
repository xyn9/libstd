// libstd / ALLOCSUP.cpp
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
void * __cdecl _nh_malloc(size_t size, int)
{
    return HeapAlloc( GetProcessHeap(), 0, size );
}
//
size_t __cdecl _msize(void * p)
{
    return HeapSize( GetProcessHeap(), 0, p );
}


//
#ifdef __cplusplus
} // EXTERN_C_END
#endif // __cplusplus





//
