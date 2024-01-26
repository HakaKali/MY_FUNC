unsigned int my_write(int fd, const void *buf, unsigned int size) {
    unsigned int ret;

    asm volatile
    (
        "movq %1, %%rax\n"   // System call number for write (1)
        "movq %2, %%rdi\n"   // File descriptor (1 for stdout)
        "movq %3, %%rsi\n"   // Buffer address
        "movq %4, %%rdx\n"   // Size of data to write
        "syscall\n"
        : "=a" (ret)
        : "0" ((long)1), "g" ((long)fd), "g" ((long)buf), "g" ((long)size)
        : "rdi", "rsi", "rdx", "memory"
    );
return ret;
}

int main(int argc, char **argv) {
    char msg[] = "Hello world!\n";
    
    my_write(1, msg, 13);
    
    return 0;
}
