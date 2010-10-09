// libstd / memmove.c
// xyn9 <xyn9.mail@gmail.com>
// (CC) Attribution-NonCommercial-ShareAlike; http://creativecommons.org/licenses/by-nc-sa/3.0/





// Tiny C Runtime Library
// By Mike_V
// http://www.codeproject.com/KB/library/tlibc.aspx
// based on:
// LIBCTINY - Matt Pietrek 2001
// MSDN Magazine, January 2001
// http://www.wheaty.net/downloads.htm
// 08/13/06 (mv)


#include <stddef.h>

void *memmove(void *dst, const void *src, size_t count)
{
	void *ret = dst;
	if (dst <= src || (char *)dst >= ((char *)src + count))
	{
		// Non-Overlapping Buffers
		// copy from lower addresses to higher addresses
		while (count--)
		{
			*(char*)dst = *(char*)src;
			dst = (char*)dst + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		// Overlapping Buffers
		// copy from higher addresses to lower addresses
		dst = (char*)dst + count - 1;
		src = (char*)src + count - 1;

		while (count--)
		{
			*(char*)dst = *(char*)src;
			dst = (char*)dst - 1;
			src = (char*)src - 1;
		}
	}

	return ret;
}

