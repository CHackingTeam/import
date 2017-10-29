#include <stdio.h>
#include <stdlib.h>
//#include <malloc.h>

#ifndef MV_H
#define MV_H

#define WSIZE 4
#define DSIZE 8
#define MAX_HEAP (1<<16)
#define CHUNKSIZE (1<<12)

#define MAX(a,b) ((a)>(b))?(a):(b)

#define PACK(size,alloc) ((size)|(alloc))

#define GET(p) (*(unsigned int*)(p))
#define PUT(p,val) (*(unsigned int*)(p)=(val))

#define GET_SIZE(p) (GET(p) & ~0x7)
#define GET_ALLOC(p) (GET(p) & 0x1)

#define HDRP(bp) ((char*)(bp)-WSIZE)
#define FTRP(bp) ((char*)(bp)+GET_SIZE(HDRP(bp))-DSIZE)

#define NEXT_BLKP(bp) ((char*)(bp)+GET_SIZE(((char*)(bp)-WSIZE)))
#define PREV_BLKP(bp) ((char*)(bp)-GET_SIZE(((char*)(bp)-DSIZE)))

static char* mem_heap;
static char* mem_brk;
static char* mem_max_addr;
static char* heap_listp;

int mm_init(void);
void* mm_malloc(size_t size);
void mm_free(void* p);
static void* extend_heap(size_t words);
static void* coalesce(void* bp);
static void* find_fit(size_t ssize);
static void  place(void* bp,size_t asize);

void mem_init(void);
static void *mem_sbrk(int incr);


#endif
