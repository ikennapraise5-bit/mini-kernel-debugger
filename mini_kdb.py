#!/usr/bin/env python3
"""
Mini Linux Kernel Debugger (kdb)
Inspired by the real samples/kdb/kdb_hello.c from torvalds/linux
Created by Grok after live-exploring the Linux kernel source.
"""

def kdb_hello_cmd(args):
    if len(args) > 1:
        print("Too many arguments")
        return
    if args:
        print(f"Hello {args[0]}.")
    else:
        print("Hello world!")

def main():
    print("=" * 54)
    print("       MINI LINUX KERNEL DEBUGGER (kdb)")
    print("  Inspired by the real samples/kdb/kdb_hello.c")
    print("      Explored live from torvalds/linux")
    print("=" * 54)
    print("\nType 'help' for commands, or just try: hello\n")

    while True:
        try:
            line = input("kdb> ").strip()
        except EOFError:
            break
        if not line:
            continue

        parts = line.split()
        cmd = parts[0].lower()
        args = parts[1:]

        if cmd == "hello":
            kdb_hello_cmd(args)
        elif cmd == "help":
            print("Available commands:")
            print("  hello [string]  - Say Hello World or Hello [string]")
            print("  help            - show this help")
            print("  quit / exit     - leave the mini-kernel")
        elif cmd in ("quit", "exit"):
            print("Leaving mini-kernel...")
            break
        else:
            print(f"Unknown command: {cmd}")
            print("Type 'help' for available commands.")

if __name__ == "__main__":
    main()
