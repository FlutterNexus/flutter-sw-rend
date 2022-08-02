//
// Created by schectman on 8/1/22.
//

#ifndef INCLUDE_SW_PIXEL_BUFFER_H_
#define INCLUDE_SW_PIXEL_BUFFER_H_

#include <cstdint>

#include <flutter_linux/flutter_linux.h>
#include <gtk/gtk.h>

typedef struct _SwPixelBuffer { // extends FlPixelBufferTexture
  FlPixelBufferTexture parent_instance;
  uint8_t* buffer;
  int64_t width;
  int64_t height;
} SwPixelBuffer;

typedef struct { // extends FlPixelBufferTextureClass
  FlPixelBufferTextureClass parent_class;
} SwPixelBufferClass;

SwPixelBuffer* sw_pixel_buffer_new(int64_t width, int64_t height);
void sw_pixel_buffer_dispose(SwPixelBuffer* buffer);
void sw_pixel_buffer_draw_rect(SwPixelBuffer* buffer, const uint8_t* pixels, int64_t x, int64_t y, int64_t width, int64_t height);

inline int64_t sw_pixel_buffer_get_id(SwPixelBuffer* buffer) {
  return (int64_t)(&buffer->parent_instance);
}

#endif //INCLUDE_SW_PIXEL_BUFFER_H_
