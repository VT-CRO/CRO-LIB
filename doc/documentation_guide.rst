.. _documentation guide:

How To Write Documentation
==========================

Documentation for this project is written with reStructuredText and API documentation is generated using Doxygen and Sphinx.

When implementing a new feature, it is important to provide adequate documentation so other members of the team know how to use your code.

Documenting Your Code
^^^^^^^^^^^^^^^^^^^^^^^^^

In this section, we detail how to comment your code so that it can be read by Doxygen.

First, you need to document your code with Doxygen comment blocks. Commenting syntax isn't covered here, but can be read about at: https://www.doxygen.nl/manual/docblocks.html#docstructure.

However, there are a few guidelines to follow for documenting. Make sure to include a header comment on all .hpp files you create (refer to other code for examples). It should include the following information:

- Author(s)
- Last Modified Date
- A brief description (a 1-sentence overview of what the file is)
- A longer description (if needed)

Additionally, document classes, structs, functions, etc. with the following information:

- A brief description (a 1-sentence overview of what the object is)
- A longer description (if needed)
- Parameters
- Exceptions (if applicable)
- Return Values (if applicable)

If you use any formulas or algorithms that may need clarification, be sure to cite the source for future reference. A link to the original document/article is sufficient.

After commenting your code, you need to add extra files sos that it can be found on the documentation website.
First, navigate to `doc/api`. The structure of this folder follows the structure of the `include` directory.
Simply navigate to the correct folder for your module (or create it if necesesary) and create a new .rst file following the template below:

.. code-block:: rst

    .. _[your module name]
    [Your Module Name]
    ==================
    .. doxygenfile:: path/to/your/module.hpp
   :project: VTCRO-LIB
   :allow-dot-graphs:       .. Optional to enable dependency and call graphs

The path listed above is relative to the `include` directory, where all the header files are located.

Writing Guides
^^^^^^^^^^^^^^

Sphinx also allows the creation of custom pages, such as this one that contain additional documentation not generated from code.
The following resources can help familiarize you with writing documentation with reStructuredText:

- https://www.sphinx-doc.org/en/master/usage/restructuredtext/basics.html
- https://docutils.sourceforge.io/docs/user/rst/quickref.html

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

To build the documentation, navigate to the doc directory and run the following command: ``doxygen && make html``.
The following command allows you to rebuild the documentation whenever a file is changed: ``sphinx-autobuild . _build/html``.
The generated documentation can be viewed by opening ``_build/html/index.html`` via a web browser.