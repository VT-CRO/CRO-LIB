.. _testing guide:

How To Write Tests
==================

Testing Basics
^^^^^^^^^^^^^^

Unit tests are located in the `test` directory which contains its own subfolders.
The folder structure of the `test` directory should look like:

| test
| ├── embedded
| │   └── ...
| └── modules
|     └── ...

the `embedded` directory contains all unit tests for hardware-dependent components (motors, sensors, etc.),
while the `modules` directory contains all unit tests without a hardware dependency (e.g. PID, math libraries, etc.).

If you create a new folder for your test, be sure to prefix it with `test_` so that PlatformIO can find it.

[TODO: How to run tests, process for running hardware vs. software tests]

Generating Mocks
^^^^^^^^^^^^^^^^

For certain features, it may be helpful to generate mocks to aid in testing.