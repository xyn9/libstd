// libstd / newdel.cpp
// xyn9 <xyn9.mail@gmail.com>
// (CC) Attribution-NonCommercial-ShareAlike; http://creativecommons.org/licenses/by-nc-sa/3.0/





//
#include <windows.h>


// new
void* __cdecl operator new (size_t _target){
  return HeapAlloc(GetProcessHeap(), 0, _target);
}
void __cdecl operator delete (void *_target){
  HeapFree(GetProcessHeap(), 0, _target);
}


// []
void* __cdecl operator new [] (size_t _size){
  return HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, _size);
}
void __cdecl operator delete [] (void *_target){
  HeapFree(GetProcessHeap(), 0, _target);
}





//
