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

## How To Contribute

### Step 1: Cloning the Repository

Clone this repository.

### Step 2: Implementing A Feature

Choose a feature to implement and create a local branch for your feature. Refer to the style guide for details on acceptable coding practices.

When you have made progress on your feature, be sure to push your local branch.

### Step 3: Add Unit Tests

Implement a unit test for your feature. Refer to the testing guide for details on how to write good tests.

### Step 4: Write Documentation about your Feature

Please write detailed documentation about your feature here. We use doxygen as a document builder.

### Step 5: Submit Your Pull Request

After completing, testing, and documenting your feature, submit a pull request with your finalized changes.

Ensure your code passes all CI checks before submitting your pull request. You can check the status of your commits by checking the Actions tab in the GitHub web browser.

When you submit your pull request, request review from your lead, as this will be required for merging to the development branch.

### Reporting and Fixing Issues

If you encounter any issues, please report them by opening an issue on GitHub.

When reporting an issue, please provide the following information:

- A clear and concise description of the expected outcome.
- A clear and consise description of the actual outcome.
- Screenshots or other visual aids if applicable.
- Development environment details (OS version, gcc version, python version, etc.).

Additionally, you can contribute by fixing open issues. If you chose to do so, please add an additional test in the relevant file to show that the issue was resolved. You can then simply proceed by following the steps in the [Pull Request] section.

## TODO:

- Create utility libraries (PID, LERP, MoveTowards, etc.)
- Write unit tests
- Remove any dependencies of modules on roslib and freertos (unless absolutely needed)
- Finish QDC code
- Implement smoothing servo
