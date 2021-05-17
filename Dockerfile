FROM ubuntu
WORKDIR /app
RUN apt-get update && apt-get install -y gcc gdb fish && rm -rf /var/lib/apt/lists/*
ENTRYPOINT fish
