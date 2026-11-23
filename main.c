#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct header {
    size_t size;
    struct header *next;
} header;

typedef struct allocator {
    void *mem;
    size_t size;
    header *free_header;
} allocator;

void *get_mem_from_os(size_t s){
    void *ptr = VirtualAlloc(
        NULL,
        s,
        MEM_RESERVE | MEM_COMMIT,
        PAGE_READWRITE
    );

    if(ptr == NULL){
        printf("could not get mem from the OS \n");
    }

    return ptr;
}

int allocator_init(allocator *a,size_t s){
    if(s <= sizeof(header) || a == NULL){
        return 0;
    }
    void *ptr = get_mem_from_os(s);
    if(ptr == NULL){
        return 0;
    }

    header *h = (header*)ptr;
    h->size = s - sizeof(header);
    h->next = NULL;

    a->mem = ptr;
    a->size = s;
    a->free_header = h;

    return 1;
}

void *my_malloc(size_t size, size_t align,void *ptr){
    
}

int main(){


    return 0;
}