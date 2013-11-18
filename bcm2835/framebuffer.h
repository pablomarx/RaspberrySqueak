#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

extern void fb_init(int depth);

extern unsigned int screenbase, screensize, screendepth;
extern unsigned int fb_x, fb_y, pitch;

#endif	/* FRAMEBUFFER_H */
