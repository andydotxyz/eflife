#ifndef EFLIFE_PRIVATE_H_
# define EFLIFE_PRIVATE_H_

#include <Evas.h>

#define eflife_board_size 3
extern int *eflife_board;

void eflife_life_nextgen(void);

void eflife_life_render(Evas_Object *win);

#endif
