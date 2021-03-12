cpuinfo
=======

A small C program for getting the number of CPU sockets, cores, or threads.
Depends on the [hwloc](https://www.open-mpi.org/projects/hwloc/) library.

Only tested to work on Linux.


Installation
------------

Compile with `make`. Edit the `Makefile` if necessary.
Move the resulting binary `cpuinfo` to wherever you like.


Usage
-----

```
Usage: cpuinfo [ socket | core | thread ]
Print the number of CPU objects in the system. Default is core.
```

