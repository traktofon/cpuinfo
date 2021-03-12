#include <hwloc.h>
#include <stdio.h>

void exit_usage(int exitcode) {
    fprintf(stderr, "Usage: cpuinfo [ socket | core | thread ]\n"
                    "Print the number of CPU objects in the system. Default is core.\n");
    exit(exitcode);
}

int main(int argc, char* argv[])
{
    hwloc_topology_t topology;
    hwloc_obj_type_t objtype;
    int nb;

    if (argc == 1) {
        objtype = HWLOC_OBJ_CORE;
    } else if (argc == 2) {
        if (strcmp(argv[1], "socket") == 0) {
            objtype = HWLOC_OBJ_SOCKET;
        } else if (strcmp(argv[1], "core") == 0) {
            objtype = HWLOC_OBJ_CORE;
        } else if (strcmp(argv[1], "thread") == 0) {
            objtype = HWLOC_OBJ_PU;
        } else {
            exit_usage(9);
        }
    } else {
        exit_usage(9);
    }

    hwloc_topology_init(&topology);
    hwloc_topology_load(topology);
    nb = hwloc_get_nbobjs_by_type(topology, objtype);
    printf("%d\n", nb);
    hwloc_topology_destroy(topology);
    return 0;
}

