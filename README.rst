===========
edisondrone
===========

A quadcopter drone using the Intel Edison platform.

Building
--------

The following commands can be used to build:

.. code-block:: bash

    git clone https://github.com/greghaynes/edisondrone.git
    cd edisondrone
    git submodule init
    git submodule update
    cmake -Dtest=on .
    make


Running Tests
-------------

Make sure the code was built with `-Dtest=on` passed to the `cmake` command
(see Building section for an example). You can then run:

    ./edisondrone-test
