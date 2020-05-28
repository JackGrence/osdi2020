#ifndef VARIED
#define VARIED

#include <list.h>
#include "buddy.h"
#include "fixed.h"
#include "tlb.h"

#define VARIED_MAX BUDDY_BLOCK_MIN
#define VARIED_MIN 0x100
#define VARIED_TOKEN_LEN (VARIED_MAX / VARIED_MIN)

struct allocated_node
{
  void *addr;
  struct list_head list;
  enum allocator_type
  {
    buddy,
    fixed
  } type;
};

struct varied_struct
{
  size_t node_token;
  size_t tokens[VARIED_TOKEN_LEN];
  struct list_head chunk_head;
};

void *varied_malloc (size_t size);
#endif /* ifndef VARIED */
