all: send receive

send: send.c
	gcc send.c -o send
	
receive: receive.c
	gcc receive.c -o receive
	
clean:
	rm send receive
