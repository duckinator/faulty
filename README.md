# Faulty

A game about a robot who just wants to go home.

## Running

Windows: no dependencies.

Linux: requires SDL2.

## Building

For Manjaro Linux, and probably other ArchLinux-based distros:

```
$ sudo pacman -S base-devel mingw-w64-gcc sdl2 wine
$ yaourt -S mingw-w64 mingw-w64-sdl2 mingw-w64-sdl2_gfx mingw-w64-sdl2_image mingw-w64-sdl2_mixer mingw-w64-sdl2_net
``

The mingw stuff is for cross-compiling for Windows, and Wine is for
testing the Windows executables.

There's also an `mingw-w64-sdl2_ttf`, but hopefully that's not needed
because it has a circular dependency.

Requires:

* GNU Make
* GCC
* SDL 2
* GCC cross-compiler setup, if you're building for Windows from Linux
