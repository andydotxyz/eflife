#ifndef EFLIFE_PRIVATE_H_
# define EFLIFE_PRIVATE_H_

#include <Evas.h>

#define EFLIFE_BOARD_WIDTH 47
#define EFLIFE_BOARD_HEIGHT 31

extern int *eflife_board, *eflife_board_prev;

void eflife_board_init(void);

void eflife_board_nextgen(void);
void eflife_board_run(Evas_Object *win);
void eflife_board_pause_toggle(void);

void eflife_render_init(Evas_Object *win);
void eflife_render_cell_for_coords(Evas_Object *win, Evas_Coord cx, Evas_Coord cy, int *x, int *y);
void eflife_render_layout(Evas_Object *win);
void eflife_render_cell(Evas_Object *win, int x, int y);
void eflife_render_refresh(Evas_Object *win);

#endif
