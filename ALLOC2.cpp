// ALLOC2.cpp / libstd
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
void * __cdecl realloc(void * p, size_t size){
  return (
    p
    ? HeapReAlloc(GetProcessHeap(), 0, p, size)
    : HeapAlloc(GetProcessHeap(), 0, size) // 'p' is 0, and HeapReAlloc doesn't act like realloc() here
  );
}

//
void * __cdecl calloc(size_t nitems, size_t size){
  return HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, nitems * size);
}


//
#ifdef __cplusplus
} // EXTERN_C_END
#endif // __cplusplus





//
