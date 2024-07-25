.. _contribution guide:

How To Contribute
=================

Adding a New Feature
^^^^^^^^^^^^^^^^^^^^

Step 1: Clone the Repository
----------------------------

Clone the repository into your work directory.
The vtcro development environment which can be obtained here is recommended for use with this project.
The development environment contains all required projects as well as extra tools.

Step 2: Implementing a Feature
------------------------------

After cloning the repo, choose a feature to implement and create a local branch off of `dev` for your feature with a descriptive name.
Refer to the :ref:`style guide` for details on acceptable coding practices.

When you have made progress on your feature, be sure to push your local branch to the remote repository.

Step 3: Add Unit Tests
----------------------

Implement a unit test for your feature.
Refer to :ref:`testing guide` guide for details on how to write good tests.



(generating mocks)

Step 4: Write Documentation
---------------------------

Please write detailed documentation about your feature. Refer to :ref:`documentation guide` for more info.

Step 5: Submit Your Pull Requirements
-------------------------------------

After completing, testing, and documenting your feature, submit a pull request with your finalized changes.

Ensure your code passess all CI checks before submitting your pull request.
You can check the status of your commits by checking the Actions tab in the Github web browser.

After resolving all issues, request review from your lead, as this will be required for merging your code into the `dev` branch.

Reporting and Fixing Issues
^^^^^^^^^^^^^^^^^^^^^^^^^^^

If you encounter any issues while developing or using this library, please report them by opening an issue on Github.

When reporting an issue, please provide the following information:

- A clear and concise description of the expected outcome.
- A clear and consise description of the actual outcome.
- Screenshots or other visual aids if applicable.
- Development environment details (OS version, gcc version, python version, etc.).

Additionally, you can contribute by fixing open issues.
If you chose to do so, please add an additional test in the relevant file to show that the issue was resolved.
You can then simply proceed by following the steps in Step 5 above.