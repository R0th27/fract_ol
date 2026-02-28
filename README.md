# fractol — Interactive Fractal Renderer in C

## Overview

**fractol** is a real-time fractal rendering engine written in **C** using the **MLX42 graphics library**.

The project renders mathematically generated fractals such as the **Mandelbrot**, **Julia**, and **Burning Ship** sets while supporting infinite zoom, dynamic palettes, and progressive background computation.

Rather than performing naive full-frame recomputation, this implementation separates **fractal computation**, **color mapping**, and **rendering**, enabling responsive interaction even at deep zoom levels.

The project focuses on:

* Real-time rendering architecture
* Incremental computation pipelines
* Cache-efficient memory layout
* Continuous color animation without recomputation
* Mouse-centered infinite zoom navigation

## Features

* Engine-style modular architecture
* Mandelbrot fractal
* Julia fractal (custom parameters)
* Burning Ship fractal
* Infinite mouse-centered zoom (double precision limit)
* Smooth rendering with progressive background computation
* Multiple cosine-based color palettes
* Recoloring **without recomputation**
* Real-time palette switching
* Colour shifting & scaling
* Window resizing
* Arrow-key navigation
* Reset controls (position & colour)
* ESC to exit cleanly

---

## Repository Structure

```bash
.
├── include
│   └── fractol.h
├── libft
├── MLX42
└── srcs
│   ├── coloring
│   │   ├── palette.c
│   │   └── smooth_color.c
│   ├── computing
│   │   ├── computing.c
│   │   └── computing_utils.c
│   ├── events
│   │   ├── events.c
│   │   ├── hooks.c
│   │   └── reset.c
│   ├── fractals
│   │   ├── burning_ship.c
│   │   ├── julia.c
│   │   └── mandelbrot.c
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

The renderer is structured around **separation of responsibilities** layering and **engine + plugin** model:

### Computation Layer

Responsible only for calculating escape-time values (`μ`) for each pixel.

### Color Layer

Transforms precomputed mathematical results into visual output using palette functions.

### Rendering Layer

Writes pixels directly into the framebuffer for maximum performance.

### Event System

Handles input, animation timing, zooming, and navigation independently of computation.

This architecture allows recoloring and animation **without recomputing fractals**, dramatically improving responsiveness.

### Model

```
Core Engine
 ├── Fractal plugins
 ├── Colour palette plugins
 ├── Event system
 └── Progressive renderer
```

This architecture allows addition of new fractals or palettes independently.

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

```bash
./fractol mandelbrot
```

### Julia Set

User-defined complex constants allow exploration of related fractal families.

```bash
./fractol julia -0.8 0.156
./fractol julia -0.4 0.6
./fractol julia 0.285 0.01
./fractol julia -0.70176 -0.3842
```

### Burning Ship

Non-linear variant producing highly detailed structures.

```bash
./fractol burning_ship
```

---

## Real-Time Features

### Smooth Infinite Zoom (Double Precision Limit)

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
     * Gradient
     * Psychedelic
     * Aurora
     * Ocean-style palettes
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

| Key / Mouse  | Action         |
| ------------ | -------------- |
| Mouse Scroll | Zoom at cursor |
| Arrow Keys   | Move view      |
| A / D        | Colour shift   |
| W / S        | Colour scale   |
| T            | Toggle palette |
| P            | Reset position |
| C            | Reset colours  |
| ESC          | Exit program   |

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
