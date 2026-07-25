/*
 * Mini Kernel Debugger "Hello" Command
 * Inspired by the real Linux kernel sample:
 *   samples/kdb/kdb_hello.c  (from torvalds/linux)
 *
 * This is a userspace recreation so you can compile & run it immediately.
 * The real version runs inside the kernel debugger (kdb).
 *
 * Created with love by Grok while exploring the actual Linux kernel source.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Simulate the kdb_printf that the real kernel uses */
#define kdb_printf printf

/* Simulate the command callback signature from the real kernel */
static int kdb_hello_cmd(int argc, const char **argv)
{
    if (argc > 1)
        return -1;  /* ARGCOUNT error in real kdb */

    if (argc)
        kdb_printf("Hello %s.\n", argv[0]);
    else
        kdb_printf("Hello world!\n");

    return 0;
}

/* Simulate the command table entry */
typedef struct {
    const char *name;
    int (*func)(int argc, const char **argv);
    const char *usage;
    const char *help;
} kdbtab_t;

static kdbtab_t hello_cmd = {
    .name  = "hello",
    .func  = kdb_hello_cmd,
    .usage = "[string]",
    .help  = "Say Hello World or Hello [string]",
};

/* Tiny fake "kernel" command dispatcher */
static void run_kdb_command(const char *input)
{
    char buf[256];
    char *argv[8];
    int argc = 0;

    strncpy(buf, input, sizeof(buf) - 1);
    buf[sizeof(buf) - 1] = '\0';

    char *token = strtok(buf, " \t");
    while (token && argc < 7) {
        argv[argc++] = token;
        token = strtok(NULL, " \t");
    }

    if (argc == 0)
        return;

    if (strcmp(argv[0], "hello") == 0) {
        /* Pass remaining args (without the command name) */
        hello_cmd.func(argc - 1, (const char **)(argv + 1));
    } else if (strcmp(argv[0], "help") == 0) {
        printf("Available commands:\n");
        printf("  hello %s  - %s\n", hello_cmd.usage, hello_cmd.help);
        printf("  help         - show this help\n");
        printf("  quit / exit  - leave the mini-kernel\n");
    } else if (strcmp(argv[0], "quit") == 0 || strcmp(argv[0], "exit") == 0) {
        printf("Leaving mini-kernel...\n");
        exit(0);
    } else {
        printf("Unknown command: %s\nType 'help' for available commands.\n", argv[0]);
    }
}

int main(void)
{
    char line[256];

    printf("======================================================\n");
    printf("       MINI LINUX KERNEL DEBUGGER (kdb)\n");
    printf("  Inspired by the real samples/kdb/kdb_hello.c\n");
    printf("      Explored live from torvalds/linux\n");
    printf("======================================================\n\n");
    printf("Type 'help' for commands, or just try: hello\n\n");

    while (1) {
        printf("kdb> ");
        fflush(stdout);

        if (!fgets(line, sizeof(line), stdin))
            break;

        /* strip newline */
        line[strcspn(line, "\n")] = 0;

        if (strlen(line) == 0)
            continue;

        run_kdb_command(line);
    }

    return 0;
}
