#ifndef EFLIFE_PRIVATE_H_
# define EFLIFE_PRIVATE_H_

#include <Evas.h>

#define EFLIFE_BOARD_WIDTH 47
#define EFLIFE_BOARD_HEIGHT 31

extern int *eflife_board;

void eflife_board_init(void);

void eflife_board_nextgen(void);

void eflife_render_init(Evas_Object *win);

void eflife_render(Evas_Object *win);

#endif
