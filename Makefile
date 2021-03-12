CFLAGS = -O

CFLAGS += $(shell pkg-config --cflags hwloc)
LDFLAGS += $(shell pkg-config --libs hwloc)

cpuinfo: cpuinfo.c
	cc $(CFLAGS) -o $@ $< $(LDFLAGS)

.PHONY: clean
clean:
	rm -f cpuinfo

