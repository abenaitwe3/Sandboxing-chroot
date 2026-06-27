#include <unistd.h>

int main() {
chroot("/tmp/jail");
chdir("/");
execl("/busybox", "sh", (char*)NULL);
return 0;
}

