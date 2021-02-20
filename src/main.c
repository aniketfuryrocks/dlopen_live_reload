#include "./include/main.h"
#include "./include/colors.h"
#include <stdio.h>
#include <dlfcn.h>
#include <unistd.h>

void callback(void *lib) {
    void (*print)(char *);
    print = dlsym(lib, "print");
    print("Hello");
}

int main() {
    for (;;) {
        {
            int status = load_lib("./lib.so", callback);
            if (status == 1)
                printf(RED "Failed to load\n" RESET);
        }
        printf(GRN"\n------\nPress enter to reload\n------\n" RESET);
        if (getchar() == 'q')
            return 0;
        fflush(stdout);
    }
}

int load_lib(char *file, void (*callback)(void *)) {
    void *my_lib = dlopen(file, RTLD_LAZY);
    if (my_lib == NULL) {
        printf(RED "----------\nError opening\n" RESET);
        return 1;
    }
    printf(CLR);
    callback(my_lib);
    //close
    dlclose(my_lib);
    return 0;
}
