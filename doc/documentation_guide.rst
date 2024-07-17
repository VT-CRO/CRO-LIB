.. _documentation guide:

How To Write Documentation
==========================

Documentation for this project is written with reStructuredText and API documentation is generated using Doxygen and Sphinx.

When implementing a new feature, it is important to provide adequate documentation so other members of the team know how to use your code.

Documenting Your Code
^^^^^^^^^^^^^^^^^^^^^^^^^

In this section, we detail how to comment your code so that it can be read by Doxygen.

After commenting your code, you need to add extra files sos that it can be found on the website.
All you need to do is navigate to `doc/api`. The structure of this folder follows the structure of the `include` directory.
Simply navigate to the correct folder for your module (or create it if necesesary) and create a new .rst file following the template below:

.. ```
.. [Your Module Name]
.. ==================
.. .. doxygenfile:: path/to/your/module.hpp
..    :project: VTCRO-LIB
.. ```

The path listed above is relative to the `include` directory.

Writing Guides
^^^^^^^^^^^^^^

[TODO]

Previewing Documentation
^^^^^^^^^^^^^^^^^^^^^^^^

The documentation shown on this site reflects the most recent code on the `release` branch of the `VTCRO-LIB` repo.
If your local branch contains any new documentation not on `release`, you can build the documentation locally.
You only need to install the following:

- python-venv
- doxygen
- sphinx
- breathe
- sphinx-rtd-theme

[TODO: Add steps in the dockerfile to set this up automatically]. The last 3 dependencies should just be installed using pip.

To build the documentation, navigate to the doc directory and run the following command: `make html`.
The following command allows you to rebuild the documentation whenever a file is changed: `sphinx-autobuild . _build/html`.
The generated documentation can be viewed by opening `_build/html/index.html` via a web browser.