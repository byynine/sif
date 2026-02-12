CFLAGS = -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wstrict-prototypes \
         -fsanitize=leak,bounds,address,undefined \
         -fno-sanitize-recover=all \
         -g -fno-omit-frame-pointer

server:
	gcc $(CFLAGS) -o bld/server src/server.c

client:
	gcc $(CFLAGS) -o bld/client src/client.c

main:
	gcc $(CFLAGS) -o bld/main src/main.c

run: bld/main
	@bld/main

clean:
	rm -rf bld
