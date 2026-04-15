
**Team: Chiranth D Nandi (PES2UG24AM048) · Danyl Bince (PES2UG24AM050)**
**PPT PRESENTATION is in the PDF file named 'MultiContainerRuntime (1).pdf' & the SCREENSHOTS are in 'screenshots.pdf'**
A lightweight container runtime built on Linux namespaces, with a kernel module for memory enforcement and CFS scheduling experiments.

#commands

### Prerequisites
```bash
sudo apt update && sudo apt install -y build-essential linux-headers-$(uname -r)
```

### Build & Load
```bash
make all               # builds: engine, cpu_hog, memory_hog, io_pulse, monitor.ko
sudo insmod monitor.ko
ls -l /dev/container_monitor
```

### Prepare Filesystems
```bash
mkdir rootfs-base
wget https://dl-cdn.alpinelinux.org/alpine/v3.20/releases/x86_64/alpine-minirootfs-3.20.3-x86_64.tar.gz
sudo tar -xzf alpine-minirootfs-3.20.3-x86_64.tar.gz -C rootfs-base
sudo cp cpu_hog memory_hog io_pulse rootfs-base/
sudo cp -a rootfs-base rootfs-alpha && sudo cp -a rootfs-base rootfs-beta
mkdir -p logs
```

### Run
```bash
# Terminal 1
sudo ./engine supervisor ./rootfs-base

# Terminal 2
sudo ./engine start alpha ./rootfs-alpha /cpu_hog --nice 10
sudo ./engine start beta  ./rootfs-beta  /cpu_hog --nice -5
```

### CLI
```bash
sudo ./engine ps            # list containers
sudo ./engine logs alpha    # view logs
sudo ./engine stop alpha    # stop container
```

### Teardown
```bash
# Ctrl+C in Terminal 1
sudo rmmod monitor
```

---

## Architecture

**Isolation.** Each container gets three Linux namespaces — `CLONE_NEWPID`, `CLONE_NEWUTS`, and `CLONE_NEWNS` — combined with `chroot()` to redefine the filesystem root. The host kernel is still shared; a kernel exploit affects all containers simultaneously.

**Supervisor.** A long-running supervisor reaps zombie children, routes logs, serves CLI commands, and enforces memory limits. `clone()` (not `fork()`) creates containers with new namespaces. The `waitpid()` loop retries until it returns 0 because Linux may coalesce multiple `SIGCHLD` signals.

**IPC.** Container stdout/stderr flows through pipes into a bounded buffer, then to a logger thread. CLI control uses a UNIX domain socket at `/tmp/mini_runtime.sock` with fixed-size request/response structs. Keeping the two channels separate avoids message framing complexity.

**Kernel memory monitor.** RSS is read via `get_mm_rss()` directly from `mm_struct` on a kernel timer. Crossing the soft limit logs a warning; crossing the hard limit fires `send_sig(SIGKILL, task, 1)` with `force=1`, bypassing signal blocking. A spinlock (not mutex) protects the monitored list because the timer runs in softirq context and cannot sleep.

**Scheduler.** CFS assigns CPU time proportional to each task's weight, derived from its nice value. A container at nice −5 (weight 6,273) received ~10–15× more CPU than one at nice +10 (weight 110). I/O-bound processes stay responsive without priority elevation because voluntary sleeping keeps their `vruntime` low.

---

## Design Decisions

**Namespace scope.** Only PID, UTS, and mount namespaces are used. Network namespaces require virtual Ethernet pairs, bridge interfaces, and IP routing — plumbing that doesn't contribute to the core objectives.

**Event loop.** A `select()`-based loop suffices at a maximum of 32 containers (≤33 fds). `epoll` would add ~150 lines with no measurable benefit at this scale.

**Bounded buffer.** A mutex and condition variables are used over a lock-free ring buffer. Lock-free structures require architecture-specific memory barriers and are hard to verify correct; for log throughput, the simpler approach is entirely adequate.

**Wire protocol.** Fixed-size packed C structs sent raw over the UNIX socket give zero serialization overhead and no external dependencies. Forward-compatibility is not a concern for an internal tool.
