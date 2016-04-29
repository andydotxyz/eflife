#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "eflife_private.h"

static int gen = 0;

int eflife_board_1[] =
   {0, 1, 0,
    0, 1, 0,
    0, 1, 0};
int eflife_board_2[] =
   {0, 0, 0,
    1, 1, 1,
    0, 0, 0};

int *eflife_board = eflife_board_1;

void
eflife_life_nextgen()
{
   gen++;

   if (gen % 2 == 0)
     eflife_board = eflife_board_1;
   else
     eflife_board = eflife_board_2;
}

