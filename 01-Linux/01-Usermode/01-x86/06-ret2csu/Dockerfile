FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    gdb \
    gcc \
    binutils \
    python3 \
    python3-pip \
    file \
    checksec \
    socat \
    && pip3 install pwntools \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /chal

COPY chal.c /chal/chal.c

COPY flag /flag

RUN gcc chal.c -o chal \
    -fno-stack-protector \
    -no-pie \
    -O0 \
    -fcf-protection=none \
    -z noexecstack

EXPOSE 35000

CMD socat TCP-LISTEN:35000,reuseaddr,fork EXEC:/chal/chal,stderr
