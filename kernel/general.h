#ifndef GENERAL_H
# define GENERAL_H

#include <stdint.h>
#include <stddef.h>
#include <limine.h>

void	draw_square(struct limine_framebuffer *framebuffer, uint32_t size, uint32_t color);
void	draw_rectangle(struct limine_framebuffer *framebuffer, uint32_t width, uint32_t hight, uint32_t color);

#endif