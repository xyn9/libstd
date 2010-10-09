// libstd / initterm.cpp
// xyn9 <xyn9.mail@gmail.com>
// (CC) Attribution-NonCommercial-ShareAlike; http://creativecommons.org/licenses/by-nc-sa/3.0/



//==========================================
// LIBCTINY - Matt Pietrek 2001
// MSDN Magazine, January 2001
// http://www.wheaty.net/downloads.htm
//==========================================
#include <windows.h>
#include <malloc.h>
#include "initterm.h"

#pragma data_seg(".CRT$XCA")
_PVFV __xc_a[] = { NULL };


#pragma data_seg(".CRT$XCZ")
_PVFV __xc_z[] = { NULL };

#pragma data_seg()  /* reset */

#pragma comment(linker, "/merge:.CRT=.data")


//
void __cdecl _initterm(_PVFV *_pfbegin, _PVFV *_pfend)
{
    /*
     * walk the table of function pointers from the bottom up, until
     * the end is encountered.  Do not skip the first entry.  The initial
     * value of _pfbegin points to the first valid entry.  Do not try to
     * execute what _pfend points to.  Only entries before _pfend are valid.
     */
    while ( _pfbegin < _pfend )
    {
        // if current table entry is non-NULL, call thru it.
        if ( *_pfbegin != NULL )
            (**_pfbegin)();
        ++_pfbegin;
    }
}

static _PVFV * pf_atexitlist = 0;
static unsigned max_atexitlist_entries = 0;
static unsigned cur_atexitlist_entries = 0;

void __cdecl _atexit_init(void)
{
    max_atexitlist_entries = 32;
    pf_atexitlist = (_PVFV *)calloc( max_atexitlist_entries,
                                     sizeof(_PVFV*) );
}

int __cdecl atexit (_PVFV func )
{
    if ( cur_atexitlist_entries < max_atexitlist_entries )
    {
        pf_atexitlist[cur_atexitlist_entries++] = func;
        return 0;
    }

    return -1;
}

void __cdecl _doexit( void )
{
    if ( cur_atexitlist_entries )
    {
        _initterm(  pf_atexitlist,
                    // Use ptr math to find the end of the array
                    pf_atexitlist + cur_atexitlist_entries );
    }
}
