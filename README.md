# fractol — Interactive Fractal Renderer in C

## Overview

**fractol** is a real-time fractal exploration program written in C using the **MLX42 graphics library**.

The project renders mathematically generated fractals such as the **Mandelbrot**, **Julia**, and **Burning Ship** sets while supporting smooth zooming, continuous navigation, and dynamic color animation.

Rather than performing naive full-frame recomputation, this implementation separates **fractal computation**, **color mapping**, and **rendering**, enabling responsive interaction even at deep zoom levels.

The project focuses on:

* Real-time rendering architecture
* Incremental computation pipelines
* Cache-efficient memory layout
* Continuous color animation without recomputation
* Mouse-centered infinite zoom navigation

---

## Repository Structure

```
.
├── include
│   └── fractol.h
├── libft
├── MLX42
├── srcs
│   ├── color
│   │   ├── palette.c
│   │   └── smooth_color.c
│   ├── events
│   │   ├── events.c
│   │   └── hooks.c
│   ├── fractals
│   │   ├── burning_ship.c
│   │   ├── computing.c
│   │   ├── computing_utils.c
│   │   ├── julia.c
│   │   └── mandelbrot.c
│   ├── main.c
│   ├── parse.c
│   └── utils
│       ├── error.c
│       └── math_utils.c
├── Makefile
└── README.md
```

---

## Design Philosophy

The renderer is structured around **separation of responsibilities**:

### Computation Layer

Responsible only for calculating escape-time values (`μ`) for each pixel.

### Color Layer

Transforms precomputed mathematical results into visual output using palette functions.

### Rendering Layer

Writes pixels directly into the framebuffer for maximum performance.

### Event System

Handles input, animation timing, zooming, and navigation independently of computation.

This architecture allows recoloring and animation **without recomputing fractals**, dramatically improving responsiveness.

---

## Rendering Pipeline

```
User Input
     ↓
Camera / State Update
     ↓
Fractal Computation (μ buffer)
     ↓
Palette Mapping
     ↓
Direct Framebuffer Write
```

Key principle:

> **Compute once, recolor infinitely.**

Fractal escape values are stored in a dedicated buffer and reused for animation and palette changes.

---

## Supported Fractals

### Mandelbrot Set

Classic escape-time fractal generated from complex plane iteration.

### Julia Set

User-defined complex constants allow exploration of related fractal families.

### Burning Ship

Non-linear variant producing highly detailed structures.

---

## Real-Time Features

### Smooth Infinite Zoom

* Mouse-centered zoom interpolation
* Continuous zoom in/out
* Stable navigation across deep magnification levels

### View Navigation

* Arrow-key movement
* Zoom-aware camera translation

### Progressive Rendering

Fractal computation is performed incrementally by rows per frame:

* Prevents frame freezing
* Maintains UI responsiveness
* Enables interactive exploration during computation

---

## Color System

Coloring uses cosine-based palettes inspired by GPU shader techniques:

```
color(t) = a + b * cos(2π(c * t + d))
```

Features include:

* Multiple palette modes
* Continuous palette shifting
* Dynamic color scaling
* Time-based animation mode

### Time Animation

Colors evolve smoothly over time without fractal recomputation:

* Escape values remain unchanged
* Only palette phase shifts
* Near-zero computational cost

---

## Performance Techniques

### Direct Framebuffer Access

Pixels are written via direct memory assignment instead of per-pixel API calls:

```c
pixels[i] = colour;
```

Eliminates rendering overhead and enables real-time updates.

---

### Incremental Computation

Only portions of the image are computed per frame, avoiding blocking renders.

---

### Cache-Aware Data Layout

Frequently accessed rendering data is grouped to improve CPU cache locality, reducing visible redraw latency during progressive rendering.

---

### Decoupled Compute & Recolor

Zooming recomputes fractals, while palette changes trigger recoloring only.

---

## Controls

| Key / Action | Function           |
| ------------ | ------------------ |
| Mouse Scroll | Zoom in / out      |
| Arrow Keys   | Move view          |
| C            | Change palette     |
| A / D        | Shift colors       |
| W / S        | Adjust color scale |
| ESC          | Exit               |

---

## Build & Usage

### Build

```bash
make
```

### Run

```bash
./fractol mandelbrot
./fractol burning_ship
./fractol julia <real> <imag>
```

Example:

```bash
./fractol julia -0.8 0.156
./fractol julia -0.4 0.6
./fractol julia 0.285 0.01
./fractol julia -0.70176 -0.3842
./fractol burning_ship
./fractol mandelbrot
```

---

## Memory Management

* No global variables
* Explicit ownership of allocated buffers
* Deterministic cleanup on exit
* Safe reallocation during window resize

Validated to avoid leaks and invalid memory access.

---

## Technical Skills Demonstrated

* Real-time graphics programming in C
* Event-driven rendering loops
* Complex number mathematics
* Escape-time fractal algorithms
* Incremental rendering strategies
* CPU cache locality awareness
* Direct framebuffer manipulation
* Animation without recomputation
* Modular architecture design
* Performance-oriented systems programming

---
