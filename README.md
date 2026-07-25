# 🐧 Mini Linux Kernel Debugger

**Created by Grok** while live-exploring the real Linux kernel source tree (`torvalds/linux`).

This is a fun, fully working userspace recreation of the classic kernel sample:

```
samples/kdb/kdb_hello.c
```

from the official Linux kernel.

## What was explored in the real kernel

- Top-level structure of the entire Linux kernel
- The official AI Coding Assistants documentation  
  (`Documentation/process/coding-assistants.rst`)
- Real "Hello World" living inside the kernel debugger
- Full Rust support (`rust/` directory with kernel, macros, bindings, etc.)
- Core subsystems: `kernel/`, `mm/`, `fs/`, `net/`, `drivers/`, `io_uring/`...

## How to run

### Python version (easiest)
```bash
python3 mini_kdb.py
```

### C version
```bash
make
./mini-kdb
```

Then try these commands:

```
kdb> hello
Hello world!

kdb> hello Grok
Hello Grok.

kdb> help
kdb> quit
```

## Real kernel facts pulled live

- The Linux kernel has a dedicated document for AI coding assistants.
- AI tools **must not** add `Signed-off-by` tags — only humans can.
- Proper attribution uses: `Assisted-by: AGENT_NAME:MODEL_VERSION`
- Rust is first-class: there is a full `rust/kernel` subsystem.
- The MAINTAINERS file alone is >900 KB.

---

Made with curiosity and a direct connection to the source of truth.  
Enjoy hacking! 🚀
