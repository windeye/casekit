#ifndef  __MINHEAP_TEMPLATE_H_
#define  __MINHEAP_TEMPLATE_H_

template<class _T> 
typedef struct minheap 
{
    _T **p;
    unsigned a,n;
}min_heap_t;

void	 min_heap_ctor(min_heap_t* s);
void	 min_heap_dtor(min_heap_t* s);
void	 min_heap_elem_init(struct event* e);
int	     min_heap_elt_is_top(const struct event *e);
int	     min_heap_elem_greater(struct event *a, struct event *b);
int	     min_heap_empty(min_heap_t* s);
unsigned min_heap_size(min_heap_t* s);
struct event*  min_heap_top(min_heap_t* s);
int	     min_heap_reserve(min_heap_t* s, unsigned n);
int	     min_heap_push(min_heap_t* s, struct event* e);
struct event*  min_heap_pop(min_heap_t* s);
int	     min_heap_erase(min_heap_t* s, struct event* e);
void	 min_heap_shift_up_(min_heap_t* s, unsigned hole_index, struct event* e);
void	 min_heap_shift_down_(min_heap_t* s, unsigned hole_index, struct event* e);

#endif  //__MINHEAP_TEMPLATE_H_
