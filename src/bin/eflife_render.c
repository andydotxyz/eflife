#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <Evas.h>

#include "eflife_private.h"

void
eflife_life_render(Evas_Object *win)
{
   Evas_Coord ww, wh, cw, ch;
   Evas_Object *rect;
   int x, y;

   evas_object_geometry_get(win, NULL, NULL, &ww, &wh);
   cw = ww / eflife_board_size;
   ch = wh / eflife_board_size;

   for (y = 0; y < eflife_board_size; y++)
     for (x = 0; x < eflife_board_size; x++)
       {
          rect = evas_object_rectangle_add(win);
          if (eflife_board[y * eflife_board_size + x])
            evas_object_color_set(rect, 32, 32, 32, 255);
          else
            evas_object_color_set(rect, 255, 255, 255, 255);

          evas_object_resize(rect, cw, ch);
          evas_object_move(rect, x * cw, y * ch);
          evas_object_show(rect);
       }
}

