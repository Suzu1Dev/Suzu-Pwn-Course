FROM ubuntu:16.04

RUN apt-get update && apt-get install -y \
    build-essential \
    socat \
    gdb \
    python3 \
    && rm -rf /var/lib/apt/lists/*

RUN useradd -m ctf

WORKDIR /home/ctf

COPY chal.c .
COPY flag.txt .

RUN gcc chal.c -o chal \
    -O0 \
    -g \
    -no-pie \
    -fno-stack-protector

RUN chown root:ctf chal flag.txt && \
    chmod 755 chal && \
    chmod 440 flag.txt

USER ctf

EXPOSE 1337

CMD socat TCP-LISTEN:1337,reuseaddr,fork EXEC:"./chal",stderr
