#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <Evas.h>

#include "eflife_private.h"

Evas_Object **_eflife_cells;

void
eflife_render_init(Evas_Object *win)
{
   Evas_Object *rect;
   int x, y, i;

   _eflife_cells = calloc(1, sizeof(Evas_Object *) * EFLIFE_BOARD_WIDTH * EFLIFE_BOARD_HEIGHT);

   for (y = 0; y < EFLIFE_BOARD_HEIGHT; y++)
     for (x = 0; x < EFLIFE_BOARD_WIDTH; x++)
       {
          i = y * EFLIFE_BOARD_WIDTH + x;
          rect = evas_object_rectangle_add(win);
          evas_object_show(rect);

          _eflife_cells[i] = rect;
       }

   eflife_render_layout(win);
}

void
eflife_render_layout(Evas_Object *win)
{
   Evas_Coord ww, wh;
   double cw, ch;
   Evas_Object *rect;
   int x, y, i;

   evas_object_geometry_get(win, NULL, NULL, &ww, &wh);
   cw = (double) ww / EFLIFE_BOARD_WIDTH;
   ch = (double) wh / EFLIFE_BOARD_HEIGHT;

   for (y = 0; y < EFLIFE_BOARD_HEIGHT; y++)
     for (x = 0; x < EFLIFE_BOARD_WIDTH; x++)
       {
          i = y * EFLIFE_BOARD_WIDTH + x;
          rect = _eflife_cells[i];

          // the little +1 here will avoid tearing as we layout non-multiple sizes
          evas_object_resize(rect, cw + 1, ch + 1);
          evas_object_move(rect, x * cw, y * ch);
       }
}

void
eflife_render_refresh(Evas_Object *win EINA_UNUSED)
{
   Evas_Object *rect;
   int x, y, i;

   for (y = 0; y < EFLIFE_BOARD_HEIGHT; y++)
     for (x = 0; x < EFLIFE_BOARD_WIDTH; x++)
       {
          i = y * EFLIFE_BOARD_WIDTH + x;
          rect = _eflife_cells[i];
          if (eflife_board[i])
            evas_object_color_set(rect, 32, 32, 32, 255);
          else
            evas_object_color_set(rect, 255, 255, 255, 255);

       }
}

