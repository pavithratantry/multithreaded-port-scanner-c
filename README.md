# Multithreaded Port Scanner in C

A simple yet powerful multithreaded TCP port scanner written in C. It uses POSIX threads and low-level socket programming to scan a range of ports on a target IP address.

## 🔧 Features

- Scans a user-defined range of ports on any IP
- Uses POSIX threads for parallel scanning
- Lightweight and fast
- Written entirely in C

## 🧠 What I Learned

- Socket programming using `socket()` and `connect()`
- Network structures like `sockaddr_in`
- Multithreading with `pthread_create()` and `pthread_join()`
- Memory management in C

## 🖥️ How to Run

### 1. Compile
```bash
gcc port_scanner.c -o port_scanner -lpthread
```

### 2. Run
```bash
./port_scanner <IP_ADDRESS> <START_PORT> <END_PORT>
```

### Example
```bash
./port_scanner 127.0.0.1 20 80
```
## 🛡️ Disclaimer
This tool is for educational purposes only. Do not use it to scan networks without permission.

