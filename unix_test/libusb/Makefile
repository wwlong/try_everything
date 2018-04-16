all: generic_mouse

SRC += ./generic_mouse.c 
generic_mouse: ${SRC}
	g++ $^ -I/usr/include/ -o $@ -lusb-1.0 -I/usr/include/ -I/usr/include/libusb-1.0

clean:
	rm generic_mouse


