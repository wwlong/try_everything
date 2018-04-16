PROG = api_server
SOURCES = $(PROG).c sqlite3.c db_plugin_sqlite.c ../../mongoose.c
CFLAGS = -W -Wall $(CFLAGS_EXTRA)


ifeq ($(OS), Windows_NT)
  CFLAGS += -lws2_32
  CC = gcc
else
  UNAME_S := $(shell uname -s)
  ifeq ($(UNAME_S), Linux)
    CFLAGS += -ldl -lm -pthread
  endif
endif

all: $(PROG)

$(PROG): $(SOURCES)
	$(CC) $(SOURCES) -o $@ $(CFLAGS)

$(PROG).exe: $(SOURCES)
	cl $(SOURCES) /I.. /MD /Fe$@

test: $(PROG)
	sh unit_test.sh $$(pwd)/$(PROG)

clean:
	rm -rf *.gc* *.dSYM *.exe *.obj *.o a.out $(PROG)


gst-launch-1.0 -v tcpclientsrc host=192.168.5.6 port=5000  ! gdpdepay !  rtph264depay ! avdec_h264 ! videoconvert ! autovideosink sync=false

gst-launch-1.0 -v tcpclientsrc host=192.168.5.6 port=5000  ! gdpdepay !  rtph264depay ! avdec_h264 ! videoconvert ! autovideosink sync=false

ctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev                                           
update_config=1
country=GB

 network={
     ssid="DGSH"
    psk="dgsh2017"
  }
~                           
network={
	ssid="DGSH"
	#psk="dgsh2017"
	psk=abf644e73c8c47c51f4fed4b5de3a4bbeedd01738862373adbeabf451013a465
}
