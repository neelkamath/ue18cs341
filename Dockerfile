FROM ubuntu
WORKDIR /app
RUN apt-get update && apt-get install -y g++ gdb fish && rm -rf /var/lib/apt/lists/*
RUN fish -c "alias my-gcc 'gcc -Wall -pedantic -Wextra -g *.c' && funcsave my-gcc"
RUN fish -c "alias my-g++ 'g++ -Wall -pedantic -Wextra -g *.cpp' && funcsave my-g++"
ENTRYPOINT fish
