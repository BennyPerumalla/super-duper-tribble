PLUGIN_NAME = libvolume_filter_plugin.so

CFLAGS = -Wall -fPIC $(shell pkg-config --cflags vlc)
LDFLAGS = -shared $(shell pkg-config --libs vlc)

SRC = volume_filter.c

all:
	$(CC) $(CFLAGS) $(SRC) -o $(PLUGIN_NAME) $(LDFLAGS)

clean:
	rm -f $(PLUGIN_NAME)
