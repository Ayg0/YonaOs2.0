# include "general.h"

// The Limine requests can be placed anywhere, but it is important that
// the compiler does not optimise them away, so, usually, they should
// be made volatile or equivalent.

static volatile struct limine_framebuffer_request framebuffer_request = {
    .id = LIMINE_FRAMEBUFFER_REQUEST,
    .revision = 0
};

// GCC and Clang reserve the right to generate calls to the following
// 4 functions even if they are not directly called.
// Implement them as the C specification mandates.
// DO NOT remove or rename these functions, or stuff will eventually break!
// They CAN be moved to a different .c file.

void *memcpy(void *dest, const void *src, size_t n) {
    uint8_t *pdest = (uint8_t *)dest;
    const uint8_t *psrc = (const uint8_t *)src;

    for (size_t i = 0; i < n; i++) {
        pdest[i] = psrc[i];
    }

    return dest;
}

void *memset(void *s, int c, size_t n) {
    uint8_t *p = (uint8_t *)s;

    for (size_t i = 0; i < n; i++) {
        p[i] = (uint8_t)c;
    }

    return s;
}

void *memmove(void *dest, const void *src, size_t n) {
    uint8_t *pdest = (uint8_t *)dest;
    const uint8_t *psrc = (const uint8_t *)src;

    if (src > dest) {
        for (size_t i = 0; i < n; i++) {
            pdest[i] = psrc[i];
        }
    } else if (src < dest) {
        for (size_t i = n; i > 0; i--) {
            pdest[i-1] = psrc[i-1];
        }
    }

    return dest;
}

int memcmp(const void *s1, const void *s2, size_t n) {
    const uint8_t *p1 = (const uint8_t *)s1;
    const uint8_t *p2 = (const uint8_t *)s2;

    for (size_t i = 0; i < n; i++) {
        if (p1[i] != p2[i]) {
            return p1[i] < p2[i] ? -1 : 1;
        }
    }

    return 0;
}

// Halt and catch fire function.
static void hcf(void) {
    asm ("cli");
    for (;;) {
        asm ("hlt");
    }
}

// The following will be our kernel's entry point.
// If renaming _start() to something else, make sure to change the
// linker script accordingly.
void _start(void) {
    // Ensure we got a framebuffer.
    if (framebuffer_request.response == NULL
     || framebuffer_request.response->framebuffer_count < 1) {
        hcf();
    }

	// Fetch the first framebuffer.
    struct limine_framebuffer *framebuffer = framebuffer_request.response->framebuffers[0];
	uint64_t count = framebuffer->width;
    // Note: we assume the framebuffer model is RGB with 32-bit pixels.
	while (count > 0)	// loop to check what's the resulotion of the screen;
	{
		switch (count % 10)
		{
		case 0:
			draw_square(framebuffer, 20, 0xffffff); // white
			break;
		case 1:
			draw_square(framebuffer, 20, 0xff0000); // red
			break;
		case 2:
			draw_square(framebuffer, 20, 0x0000ff); // blue
			break;
		case 3:
			draw_square(framebuffer, 20, 0x00ff00); // green
			break;
		case 4:
			draw_square(framebuffer, 20, 0xffff00); // yellow
			break;
		case 5:
			draw_square(framebuffer, 20, 0x00ffff); // sky blue
			break;
		case 6:
			draw_square(framebuffer, 20, 0xff00ff); // pink
			break;
		case 7:
			draw_square(framebuffer, 20, 0x660066); // purple
			break;
		case 8:
			draw_square(framebuffer, 20, 0xa0a0a0); // grey
			break;
		case 9:
			draw_square(framebuffer, 20, 0xff7518); // orange
			break;
		default:
			break;
		}	
		count /= 10;
		framebuffer->address += 20;
		draw_square(framebuffer, 20, 0x000000); // black to separate
		framebuffer->address += 20;
	}
	// uncomment me to draw full screen
		// draw_rectangle(framebuffer, 1024, 876, 0xffffff);
	// print_square(framebuffer, 20, 0xFF7518);
    // We're done, just hang...
    hcf();
}