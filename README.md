# VTCRO-LIB

This library contains a bunch of VTCRO stuff.

## Requirements

- PlatformIO
- Python 3.x
- Teensy 4.1 MCU

## How To Use

To use this library in your own project, include it as a dependency in your project by adding it to the list of `lib_deps` in your `platformio.ini` file via the line:

```
[add the link here]
```

## TODO:

- Create utility libraries (PID, LERP, MoveTowards, etc.)
- Write unit tests
- Remove any dependencies of modules on roslib and freertos (unless absolutely needed)
- Finish QDC code
- Implement smoothing servo
