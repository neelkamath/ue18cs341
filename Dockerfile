FROM ubuntu
WORKDIR /app
RUN apt-get update && apt-get install -y g++ gdb fish && rm -rf /var/lib/apt/lists/*
RUN fish -c "alias compile 'gcc -Wall -pedantic -Wextra -g *.c' && funcsave compile"
ENTRYPOINT fish
