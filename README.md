Custom Linux chroot Sandbox Implementation

A custom C implementation utilizing Linux kernel system calls (`chroot` and `chdir`) to construct an isolated sandboxed environment using BusyBox.

Step-by-Step Environment Setup & Execution

 1. Preparing the Jail Directory & Root Filesystem
sudo mkdir -p /tmp/jail/bin
sudo cp /bin/busybox /tmp/jail/busybox

Writing the Sandbox Controller (chroot.c)
#include <unistd.h>

int main() {
    chroot("/tmp/jail");
    chdir("/");
    execl("/busybox", "sh", (char*)NULL);
    return 0;
}

gcc -o chroot chroot.c
sudo ./chroot
