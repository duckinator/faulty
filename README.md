# Faulty

A game about a robot who just wants to go home.

## Running

Windows: run `faulty.exe`. There are no dependencies.

Linux: install SDL2, then run the `faulty` executable.

## Building

All of the build instructions assume you're using Manjaro Linux.

They'll probably work on any ArchLinux-based distro, but I haven't
confirmed that.

Build requirements:

* GNU Make
* GCC
* SDL 2
* GCC cross-compiler setup, if you're building for Windows from Linux

### Native Linux builds

```
$ sudo pacman -S base-devel sdl2
$ make linux
```

### Windows builds, from Linux

Cross-compiling for Windows requires a mingw cross-compiling toolchain,
and you can (kind of) test it using Wine.

First, install `yaourt` (or equivalent), then:

```
$ yaourt -S base-devel sdl2 wine mingw-w64 mingw-w64-sdl2 mingw-w64-sdl2_gfx mingw-w64-sdl2_image mingw-w64-sdl2_mixer mingw-w64-sdl2_net
``

There's also an `mingw-w64-sdl2_ttf`, but hopefully that's not needed
because it has a circular dependency.


