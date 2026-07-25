# 🐧 Mini Linux Kernel Debugger

[![CI](https://github.com/ikennapraise5-bit/mini-kernel-debugger/actions/workflows/ci.yml/badge.svg)](https://github.com/ikennapraise5-bit/mini-kernel-debugger/actions/workflows/ci.yml)
[![codecov](https://codecov.io/gh/ikennapraise5-bit/mini-kernel-debugger/graph/badge.svg)](https://codecov.io/gh/ikennapraise5-bit/mini-kernel-debugger)
[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=ikennapraise5-bit_mini-kernel-debugger&metric=alert_status)](https://sonarcloud.io/summary/new_code?id=ikennapraise5-bit_mini-kernel-debugger)

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

## CI, Coverage & Code Quality

This project has a full modern CI pipeline:

| Feature | Tool |
|---------|------|
| Matrix testing | Python 3.10–3.13 + gcc/clang |
| Caching | pip + ccache |
| Coverage | Codecov |
| Deep code quality | **SonarCloud** (SonarQube Cloud) |

### Enabling SonarCloud (one-time setup)

1. Go to [https://sonarcloud.io](https://sonarcloud.io) and sign in with GitHub
2. Import the `mini-kernel-debugger` repository
3. Copy the `SONAR_TOKEN` that SonarCloud gives you
4. In your GitHub repo go to **Settings → Secrets and variables → Actions**
5. Add a new repository secret named `SONAR_TOKEN` with that value

After that, every push will get deep static analysis (bugs, vulnerabilities, code smells, duplications, complexity, etc.).

## Real kernel facts pulled live

- The Linux kernel has a dedicated document for AI coding assistants.
- AI tools **must not** add `Signed-off-by` tags — only humans can.
- Proper attribution uses: `Assisted-by: AGENT_NAME:MODEL_VERSION`
- Rust is first-class: there is a full `rust/kernel` subsystem.
- The MAINTAINERS file alone is >900 KB.

---

Made with curiosity and a direct connection to the source of truth.  
Enjoy hacking! 🚀
