#ifndef TERM_H
# define TERM_H

#include <stdint.h>
#include <stddef.h>
#include <limine.h>

// right now screen is 1024x768

# define TERMH 96
# define TERMW 127

typedef struct cursor{
	int	x;
	int	y;
} _cursor;


typedef struct terminal{
	 struct limine_framebuffer *buffer;
	_cursor cursor;
	int		def_color;
}	_terminal;

void	draw_square(struct limine_framebuffer *framebuffer, uint32_t size, uint32_t color);
void	draw_rectangle(struct limine_framebuffer *framebuffer, uint32_t width, uint32_t hight, uint32_t color);
int		k_put_char(uint8_t c, int use_default, int color);
int		init_terminal(struct limine_framebuffer *buffer);
int		k_put_str(char *str);
int		set_curser(int x, int y);
void	put_nbr(uint64_t nbr, uint8_t format);
void 	*memcpy(void *dest, const void *src, size_t n);
#endif