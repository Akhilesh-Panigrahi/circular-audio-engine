# High-Performance Circular Audio Playlist Engine

A robust, production-ready C++ core engine designed to model media playlist behavior using a custom **Doubly Circular Linked List** topology.

This project demonstrates:

- Efficient bidirectional traversal
- Strict object encapsulation
- Deterministic memory management
- Scalable architecture for performance-critical or embedded media systems

---

## Table of Contents

- [Overview](#overview)
- [Architecture](#architecture)
- [Core Components](#core-components)
- [Features](#features)
- [Traversal Mechanics](#traversal-mechanics)
- [Complexity Analysis](#complexity-analysis)
- [Project Structure](#project-structure)
- [Build & Run](#build--run)
- [Example Usage](#example-usage)
- [Design Highlights](#design-highlights)
- [Future Improvements](#future-improvements)
- [License](#license)

---

## Overview

Traditional playlist systems often rely on linear data structures that require boundary checks or resets when reaching the beginning or end of the list.

This project eliminates those limitations using a **Circular Doubly Linked List**, enabling seamless infinite playback in both directions with constant-time traversal.

```text
   [ Song 1 ] <=======> [ Song 2 ]
       ^                     ^
       |                     |
       v                     v
   [ Song N ] <=======> [ Song 3 ]
```

The system is designed with a lightweight playback controller (`MusicPlayer`) layered on top of a memory-safe linked list engine (`CircleDLinkedList`).

---

## Architecture

### Core Design Principles

#### Circular Topology

The playlist wraps automatically, allowing:

- Infinite forward traversal
- Infinite backward traversal
- No boundary condition checks
- Constant-time cursor movement

---

#### Encapsulation-Driven Design

Node creation is strictly controlled by the linked list implementation to prevent pointer misuse and unsafe external manipulation.

---

#### Cursor-Based Traversal

The engine maintains a dedicated playback cursor, eliminating the need to search for the active song during playback operations.

---

## Core Components

### `Song`

Represents the media entity stored in the playlist.

#### Responsibilities

- Stores metadata:
  - `songTitle`
  - `singerName`
- Supports formatted console output using overloaded stream operators

---

### `DNode`

The internal storage unit of the circular linked list.

#### Responsibilities

- Stores:
  - `Song data`
  - `next`
  - `prev`
- Tracks active heap allocations using:

```cpp
static int activeNodes;
```

This helps detect memory leaks during debugging and testing.

---

### `CircleDLinkedList`

The underlying engine powering the playlist.

#### Responsibilities

- Constant-time insertion/removal
- Circular pointer stitching
- Safe bidirectional traversal
- Memory cleanup
- Cursor tracking

---

### `MusicPlayer`

The high-level client-facing playback interface.

#### Exposed Operations

```cpp
play()
next()
previous()
addSong()
removeSong()
print()
```

The `MusicPlayer` delegates all low-level operations to `CircleDLinkedList`.

---

## Features

- Circular doubly linked list implementation
- Constant-time playlist traversal
- Efficient insertion/removal relative to cursor
- Memory-safe node management
- Recursive playlist diagnostics
- Leak tracking via active node counter
- Object-oriented modular architecture
- Production-ready code organization

---

## Traversal Mechanics

The project includes a specialized recursive printing system capable of traversing the playlist without helper functions or auxiliary storage.

### Recursive Diagnostic Printer

```cpp
void print(bool forward = true, int count = -1) {
    if (empty()) {
        std::cout << "Playlist is empty." << std::endl;
        return;
    }

    if (count == -1) {
        count = size();
    }

    if (count == 0) {
        std::cout << std::endl;
        return;
    }

    std::cout << playlist.getCurrentSong();

    if (forward) {
        playlist.advance();
    } else {
        playlist.retreat();
    }

    print(forward, count - 1);

    // Restore original traversal state during stack unwinding
    if (forward) {
        playlist.retreat();
    } else {
        playlist.advance();
    }
}
```

### Advantages

- Zero heap allocation during traversal
- Preserves cursor state automatically
- Cleaner recursion-driven diagnostics
- No helper methods required

---

## Complexity Analysis

| Operation | Time Complexity | Space Complexity | Description |
|---|---|---|---|
| `addSong()` | `O(1)` | `O(1)` | Immediate insertion relative to cursor |
| `removeSong()` | `O(1)` | `O(1)` | Removes current node and reconnects neighbors |
| `next()` / `previous()` | `O(1)` | `O(1)` | Cursor pointer reassignment |
| `print()` | `O(N)` | `O(N)` | Recursive traversal using call stack |

---

## Project Structure

```text
.
├── main.cpp
├── Song.h
├── Song.cpp
├── DNode.h
├── DNode.cpp
├── CircleDLinkedList.h
├── CircleDLinkedList.cpp
├── MusicPlayer.h
├── MusicPlayer.cpp
└── README.md
```

---

## Build & Run

### Requirements

- C++11 or higher
- g++ compiler

---

### Compile

```bash
g++ -std=c++11 main.cpp -o AudioEngine
```

---

### Run

#### Linux / macOS

```bash
./AudioEngine
```

#### Windows

```bash
AudioEngine.exe
```

---

## Example Usage

```cpp
MusicPlayer player;

player.addSong("Blinding Lights", "The Weeknd");
player.addSong("Bohemian Rhapsody", "Queen");
player.addSong("Lose Yourself", "Eminem");

player.play();

player.next();
player.play();

player.previous();
player.play();

player.print();
```

---

## Design Highlights

### Friend-Class Encapsulation

```cpp
friend class CircleDLinkedList;
```

Only the linked list implementation can create or manipulate nodes directly.

#### Benefits

- Prevents raw pointer exposure
- Improves memory safety
- Enforces strict abstraction boundaries

---

### Deterministic Memory Management

The project manually controls:

- Allocation
- Deallocation
- Pointer rewiring
- Circular stitching

This provides a deeper understanding of low-level systems programming and data structure engineering.

---

### Real-Time Playback Cursor

The cursor acts as the active playback position.

#### Advantages

- No traversal search required
- Instant next/previous operations
- Constant-time playback updates

---

## Future Improvements

### Thread-Safe Playback

Add mutex protection around traversal operations:

```cpp
advance()
retreat()
```

This prevents race conditions during asynchronous playback or UI updates.

---

### Smart Pointer Migration

Replace raw pointers with:

- `std::unique_ptr`
- `std::weak_ptr`

to modernize ownership and eliminate manual deletion logic.

---

### Shuffle Engine

Implement a Fisher-Yates-inspired shuffle algorithm optimized for circular pointer-based structures without breaking playlist continuity.

---

### Additional Planned Features

- Playlist persistence
- Repeat modes
- Audio streaming integration
- Queue management
- Search and filtering
- CLI / GUI frontend

---

## Educational Value

This project demonstrates:

- Circular linked lists
- Advanced pointer manipulation
- Recursion-based traversal
- Memory management
- Encapsulation and abstraction
- Systems-level C++ engineering

---

## License

This project is open-source and available under the MIT License.
