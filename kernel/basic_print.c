#include "general.h"

void	draw_square(struct limine_framebuffer *framebuffer, uint32_t size, uint32_t color){
	uint32_t *ptr = framebuffer->address;
	for (size_t i = 0; i < size; i++)
		for (size_t j = 0; j < size; j++)
			ptr[i * framebuffer->width + j] = color;
	return ;
}

void	draw_rectangle(struct limine_framebuffer *framebuffer, uint32_t width, uint32_t hight, uint32_t color){
	uint32_t *ptr = framebuffer->address;
	for (size_t i = 0; i < hight; i++)
		for (size_t j = 0; j < width; j++)
			ptr[i * framebuffer->width + j] = color;
	return ;
}