#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "eflife_private.h"

static int gen = 0;

int *eflife_board, *eflife_board_prev;
static int *_eflife_board_1, *_eflife_board_2;

void
eflife_board_init()
{
   _eflife_board_1 = calloc(1, sizeof(int) * EFLIFE_BOARD_WIDTH * EFLIFE_BOARD_HEIGHT);
   _eflife_board_2 = calloc(1, sizeof(int) * EFLIFE_BOARD_WIDTH * EFLIFE_BOARD_HEIGHT);

   // glide
   _eflife_board_1[16 + 1 * EFLIFE_BOARD_WIDTH] = 1;
   _eflife_board_1[17 + 2 * EFLIFE_BOARD_WIDTH] = 1;
   _eflife_board_1[18 + 2 * EFLIFE_BOARD_WIDTH] = 1;
   _eflife_board_1[16 + 3 * EFLIFE_BOARD_WIDTH] = 1;
   _eflife_board_1[17 + 3 * EFLIFE_BOARD_WIDTH] = 1;

   // oscilate
   _eflife_board_1[22 + 15 * EFLIFE_BOARD_WIDTH] = 1;
   _eflife_board_1[23 + 15 * EFLIFE_BOARD_WIDTH] = 1;
   _eflife_board_1[24 + 15 * EFLIFE_BOARD_WIDTH] = 1;

   // block
   _eflife_board_1[32 + 15 * EFLIFE_BOARD_WIDTH] = 1;
   _eflife_board_1[33 + 15 * EFLIFE_BOARD_WIDTH] = 1;
   _eflife_board_1[32 + 16 * EFLIFE_BOARD_WIDTH] = 1;
   _eflife_board_1[33 + 16 * EFLIFE_BOARD_WIDTH] = 1;

   eflife_board = _eflife_board_1;
   eflife_board_prev = _eflife_board_2;
}

int
eflife_board_sum_around(int x, int y)
{
   int sum = 0;
   int i, max;

   max = EFLIFE_BOARD_WIDTH * EFLIFE_BOARD_HEIGHT;

   i = x - 1 + ((y - 1) * EFLIFE_BOARD_WIDTH);
   if (i >= 0)
     sum += eflife_board[i];
   i++;
   if (i >= 0)
     sum += eflife_board[i];
   i++;
   if (i >= 0)
     sum += eflife_board[i];

   i = x - 1 + (y * EFLIFE_BOARD_WIDTH);
   if (i >= 0)
     sum += eflife_board[i];
   i += 2;
   if (i < max)
     sum += eflife_board[i];

   i = x - 1 + ((y + 1) * EFLIFE_BOARD_WIDTH);
   if (i < max)
     sum += eflife_board[i];
   i++;
   if (i < max)
     sum += eflife_board[i];
   i++;
   if (i < max)
     sum += eflife_board[i];

   return sum;
}

void
eflife_board_nextgen()
{
   int *work;
   int x, y, i, n;
   gen++;

   if (eflife_board == _eflife_board_1)
     work = _eflife_board_2;
   else
     work = _eflife_board_1;

   for (y = 0; y < EFLIFE_BOARD_HEIGHT; y++)
     for (x = 0; x < EFLIFE_BOARD_WIDTH; x++)
       {
          i = y * EFLIFE_BOARD_WIDTH + x;

          n = eflife_board_sum_around(x, y);
          if (eflife_board[i])
            {
               if (n > 3 || n < 2)
                 work[i] = 0;
               else
                 work[i] = 1;
            }
          else
            {
               if (n == 3)
                 work[i] = 1;
               else
                 work[i] = 0;
            }
       }

   eflife_board_prev = eflife_board;
   eflife_board = work;
}

