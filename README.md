<h1 align=center>💻 FdF</h1>
<p align="center">
  <img src="img/fdf.png?raw=true" alt="FdF Project Image"/>
</p>

## About
>This project This project is about representing a landscape as a 3D object
>in which all surfaces are outlined in lines.

[Subject FdF Project 42](FDF.pdf)

The FdF program displays a 3D mesh of an object in a window based on a provided 2D map.

## Features
- **Description**: Displays a 3D image using MiniLibX, where points are connected by lines to create a mesh-like representation.
- **Feature**: Allows visualization of a 3D image with interactive controls for translation, rotation, zoom, and projection changes.
- **How to Use**: Run the program with a map file that defines the 3D object.

## Setup

**Clone the Repository**:

```bash
git clone https://github.com/J0hann3/fdf.git
cd fdf
make
```

## Usage

- Run the program with the map file as first argument
```bash
./fdf <map.fdf>
```
- The map file should have the `.fdf` extension
- The map file contains numbers representing the height at each point:
	- 0 represents a neutral height.
	- Positive numbers (>0) raise the point above the neutral plane.
	- Negative numbers (<0) lower the point below the neutral plane.
```
0 0 1 2 3 4 5 6 7 8 9
0 0 0 1 2 3 4 5 6 7 8
0 0 0 0 1 2 3 4 5 6 7
0 0 0 0 0 1 2 3 4 5 6
0 0 0 0 0 0 1 2 3 4 5
0 0 0 0 0 0 0 1 2 3 4
0 0 0 0 0 0 0 0 1 2 3
0 0 0 0 0 0 0 0 0 1 2
0 0 0 0 0 0 0 0 0 0 1
```
- Controls in the Window:
	- Zoom: + / -
	- Rotation:
		- Left/Right: a / d
		- Up/Down: w / s
	- Translation:
		- Left/Right: Left Arrow / Right Arrow
		- Up/Down: Up Arrow / Down Arrow
	- Projection: Switch between projections using i and p

## New Notion

### MiniLibX

