#include "mv_h.h"

void mem_init(void)
{
  
 mem_heap=(char*)malloc(MAX_HEAP);
 if(!mem_heap)
     perror("malloc(size_t ) error!\n");
mem_brk=(char*) mem_heap;
mem_max_addr=(char*)(mem_brk+MAX_HEAP);
//printf("1:mem_init()\n");
}

static void* mem_sbrk(int incr)
{
  char* old_brk=mem_brk;

  if(incr < 0|| ((mem_brk+incr) > mem_max_addr))
  { 
    perror("memory ran out!\n");
    return (void*)-1;
  }
  mem_brk=mem_brk+incr;
// printf("mem_sbrk\n");
  return (void*)old_brk;
}

int mm_init(void)
{


 // printf("jinru mm_init()\n");
  if((heap_listp=mem_sbrk(4*WSIZE))==(void*)-1)
       return -1;
   PUT(heap_listp,0);
   PUT(heap_listp+(1*WSIZE),PACK(DSIZE,1));
   PUT(heap_listp+(2*WSIZE),PACK(DSIZE,1));
   PUT(heap_listp+(3*WSIZE),PACK(WSIZE,0));
   heap_listp+=2*WSIZE;

   if(extend_heap(CHUNKSIZE/WSIZE)==NULL)
     return -1;
 // printf("ebp:\t%d\n",heap_listp);
  return 0;
}

static  void* extend_heap(size_t words)
{

 void* bp;
 size_t size;

 size=(words%2) ? (words+1)*WSIZE:words*WSIZE;
// printf("size:\t%d\n",size);
 bp=mem_sbrk(size);
 if(bp==(void*)-1)
   return NULL;
 PUT(HDRP(bp),PACK(size,0));
 PUT(FTRP(bp),PACK(size,0));
 PUT(NEXT_BLKP(bp),PACK(0,1));

// printf("extend_heap()\n");
 
 return coalesce(bp);
}

void mm_free(void* bp)
{
  size_t size=GET_SIZE(HDRP(bp));
  PUT(HDRP(bp),PACK(size,0));
  PUT(FTRP(bp),PACK(size,0));
  coalesce(bp);

}

static void* coalesce(void* bp)
{

 // printf("coalesce\n");
  size_t prev_alloc=GET_ALLOC(FTRP(PREV_BLKP(bp)));
  size_t next_alloc=GET_ALLOC(HDRP(NEXT_BLKP(bp)));
  size_t size=GET_SIZE(HDRP(bp));

  if(prev_alloc&&next_alloc)
     return bp;
  else if(prev_alloc&&!next_alloc)
  {
    size+=GET_SIZE(HDRP(NEXT_BLKP(bp)));
    PUT(HDRP(bp),PACK(size,0));
    PUT(FTRP(bp),PACK(size,0));
    
  }
  else if(!prev_alloc&&next_alloc)
  {
    size+=GET_SIZE(HDRP(PREV_BLKP(bp)));
    PUT(FTRP(bp),PACK(size,0));
    PUT(HDRP(PREV_BLKP(bp)),PACK(size,0));
    bp=PREV_BLKP(bp);
  }
  else
  {
    size+=GET_SIZE(HDRP(PREV_BLKP(bp)))+GET_SIZE(FTRP(NEXT_BLKP(bp)));
    PUT(HDRP(PREV_BLKP(bp)),PACK(size,0));
    PUT(FTRP(NEXT_BLKP(bp)),PACK(size,0));
    bp=PREV_BLKP(bp);
  }
  
  return bp;
}
  
void* mm_malloc(size_t size)
{

  
  size_t asize;
  size_t extendsize;
  char* bp;

  if(size==0)
     return NULL;

  if(size<=DSIZE)
    asize=DSIZE;
  else
    asize=DSIZE*((size+(DSIZE)+(DSIZE-1))/DSIZE);
  
 // printf("size:\t%d\n",asize);
  if((bp=find_fit(asize))!=NULL)
  {
    place(bp,asize);
    return bp;
  }
  extendsize=MAX(asize,CHUNKSIZE);

  if((bp=extend_heap(extendsize/WSIZE))==NULL)
     return NULL;
  place(bp,asize);

  return bp;
}

static void* find_fit(size_t asize)
{
  char* bp=heap_listp+DSIZE;
  size_t size;
  do
  {
    if(((char*)bp)>=mem_brk);
        break;
    size=GET_SIZE(HDRP(bp));
    if(!GET_ALLOC(bp))
      if(size>=asize)
           return bp;
    bp=bp+size;
  }while(1);
 
  return NULL;
};
 
static void place(void* bp,size_t asize)
{
 
 // size=GET_SIZE(HDRP(bp))-asize;
 if((asize+2*DSIZE) > GET_SIZE(HDRP(bp)))
     return;
 size_t size=GET_SIZE(HDRP(bp))-asize;
 PUT(FTRP(bp),PACK(size,0));
 PUT(HDRP(bp),PACK(asize,1));
 PUT(HDRP(NEXT_BLKP(bp)),PACK(size,0));

 return;
}
/*

static void* find_fit(size_t asize)
{

// printf("find_fit\n");
void *bp;
for(bp=heap_listp;GET_SIZE(HDRP(bp))>0;bp=NEXT_BLKP(bp))
    {
     if(!GET_ALLOC(HDRP(bp))&&(asize<=GET_SIZE(HDRP(bp)))){
     return bp;
     }
    }
     return NULL;
}


static void place(void* bp,size_t asize)
{

 // printf("place\n");
  size_t csize=GET_SIZE(HDRP(bp));
  if((csize-asize)>=(2*DSIZE))
  {
    PUT(HDRP(bp),PACK(asize,1));
    PUT(FTRP(bp),PACK(asize,1));
    bp=NEXT_BLKP(bp);
    PUT(HDRP(bp),PACK(csize-asize,0));
    PUT(FTRP(bp),PACK(csize-asize,0));
  }
  else
  {
    PUT(HDRP(bp),PACK(csize,1));
    PUT(FTRP(bp),PACK(csize,1));
  }
}



*/









