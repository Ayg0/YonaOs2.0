#ifndef TERM_H
# define TERM_H

#include <stdint.h>
#include <stddef.h>
#include <limine.h>

// right now screen is 1024x876

typedef struct cursor{
	int	x;
	int	y;
} _cursor;


typedef struct screen{
	 struct limine_framebuffer *buffer;
	_cursor cursor;
	int		def_color;
}	_screen;

void	draw_square(struct limine_framebuffer *framebuffer, uint32_t size, uint32_t color);
void	draw_rectangle(struct limine_framebuffer *framebuffer, uint32_t width, uint32_t hight, uint32_t color);
int		k_put_char(uint8_t c, int use_default, int color);
int		init_screen(struct limine_framebuffer *buffer);
int		k_put_str(char *str);
int		set_curser(int x, int y);
#endif