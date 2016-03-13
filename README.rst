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

.. code-block:: bash

    ./edisondrone-test


Simulator
---------

The Simulator runs a series of generated inputs fed in to the control code and
then outputs data files which can be graphed using a tool like gnuplot.

An example usage:

.. code-block:: bash

    ./edisondrone-simulator > simulator.dat
    gnuplot < simulator/simulator.gnuplot > graph.png

You can then view graph.png in any image viewing tool.
