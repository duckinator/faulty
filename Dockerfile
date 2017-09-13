FROM ubuntu:16.04

ENV USE_DEFAULT_MAKE_CONFIG true

RUN apt-get update \
    && DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential git libsdl2-dev gcc-mingw-w64-x86-64 mercurial \
    && rm -rf /var/lib/apt/lists/*

COPY util/docker-cross-compile-sdl2.sh /tmp/
RUN /tmp/docker-cross-compile-sdl2.sh

ENTRYPOINT ["make"]
