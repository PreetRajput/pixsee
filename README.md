# pixsee

pixsee is a minimal image viewer written in C using SDL3 and stb_image.  
It demonstrates the full image rendering pipeline: file decoding in system memory, texture upload to GPU memory, and real-time rendering to a window.

This project is intentionally low-level and avoids abstractions to make the rendering process explicit and educational.

---

## Features

- Image decoding using `stb_image`
- Explicit CPU → GPU texture upload
- SDL3 window, renderer, and texture pipeline
- Event-driven render loop
- Minimal dependencies
- No image processing shortcuts or helpers

---

## Pipeline Overview

1. Image file is read from disk
2. Image is decoded into raw RGB pixels (CPU / RAM)
3. GPU texture is created
4. Pixel data is uploaded to GPU memory
5. Texture is rendered every frame
6. Front/back buffer swap displays the image

---

## Dependencies

- SDL3 (MinGW build)
- stb_image.h
- GCC (MinGW, x86_64)

---

## Build (Windows, MinGW64)

From the project root:

```bash
gcc main.c \
 -ISDL3-3.4.0/x86_64-w64-mingw32/include \
 SDL3-3.4.0/x86_64-w64-mingw32/lib/libSDL3.dll.a \
 -o pixsee# pixsee

after the compilation must add the SDL3.dll file to the same folder as the main.c
SDL3-3.4.0/x86_64-w64-mingw32/bin/SDL3.dll

for the display of window
./pixsee ${pathOfImage}
