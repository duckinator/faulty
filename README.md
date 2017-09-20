# Faulty

A game about a robot who just wants to go home.

## Running

Windows: run `faulty.exe`. There are no dependencies.

Linux: install SDL2, then run the `faulty` executable.

## Building

1. Install Docker.
2. Install GNU Make.
2. Run `make` (or `gmake`).

It handles creating an image capable of generating builds for all platforms, and only does so when necessary.

Any arguments you pass to `make` outside of Docker are passed through.
