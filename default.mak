# libstd / default.mak
# xyn9 <xyn9.mail@gmail.com>
# (CC) Attribution-NonCommercial-ShareAlike; http://creativecommons.org/licenses/by-nc-sa/3.0/





#
PROJ = libstd


OBJS = \
# 	_crt0cw.obj \
  _cltoargv.obj \
  _gettcs.obj \
  _putts.obj \
#
  CRT0TCON.OBJ \
  CRT0TWIN.OBJ \
  DLLCRT0.OBJ \
  PRINTF.OBJ SPRINTF.OBJ \
    ALLOC.OBJ ALLOCSUP.OBJ \
    ISCTYPE.obj  istspace.obj istdigit.obj istalpha.obj \
    ATOL.obj STRUPLWR.obj STRICMP.obj \
    newdel.obj INITTERM.OBJ \
  purevirt.obj \
  memcpy.obj memcmp.obj memset.obj memmove.obj \

RELEASEOBJS = ALLOC2.OBJ 
DEBUGOBJS = 

CPPS = \
# 	_crt0cw.cpp \
  _cltoargv.cpp \
  _gettcs.c \
  _putts.c \
#
  CRT0TCON.cpp \
  CRT0TWIN.cpp \
  DLLCRT0.cpp \
  PRINTF.cpp SPRINTF.cpp \
    ALLOC.cpp ALLOCSUP.cpp \
    ISCTYPE.cpp  istspace.cpp istdigit.cpp istalpha.cpp \
    ATOL.cpp STRUPLWR.cpp STRICMP.cpp \
    newdel.cpp INITTERM.cpp \
  purevirt.cpp \
  memcpy.c memcmp.c memset.c memmove.c \

RELEASECPPS = ALLOC2.CPP
DEBUGCPPS = 

CC = CL
CC_OPTIONS = /c /W4 /D WIN32_LEAN_AND_MEAN


!ifdef MT
PROJ = $(PROJ)_mt
!endif

!ifdef DEBUG

PROJ = $(PROJ)_d

CPPS = $(CPPS) $(DEBUGCPPS)
OBJS = $(OBJS) $(DEBUGOBJS)
CC_OPTIONS = $(CC_OPTIONS) /Zi

!ifdef MT
CC_OPTIONS = $(CC_OPTIONS) /MTd
!endif

#
!else

CPPS = $(CPPS) $(RELEASECPPS)
OBJS = $(OBJS) $(RELEASEOBJS)
# CC_OPTIONS = $(CC_OPTIONS) /O1 Oy /Zl
CC_OPTIONS = $(CC_OPTIONS) /O1

!ifdef MT
CC_OPTIONS = $(CC_OPTIONS) /MT
!endif

!endif


!ifdef UNICODE
PROJ = $(PROJ)_u
CC_OPTIONS = $(CC_OPTIONS) /D UNICODE
!endif


$(PROJ).LIB: $(OBJS)
    LIB /OUT:$(PROJ).lib $(OBJS)

clean:
  -del *.obj
  -del *.lib

$(OBJS) : $(CPPS)
    $(CC) @<<
  $(CC_OPTIONS)
  $(CPPS)
<<
