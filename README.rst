===========
edisondrone
===========

.. image:: https://travis-ci.org/greghaynes/edisondrone.svg?branch=master
    :target: https://travis-ci.org/greghaynes/edisondrone

.. image:: https://img.shields.io/github/license/greghaynes/edisondrone.svg?style=flat-square
    :target: https://github.com/greghaynes/edisondrone/blob/master/LICENSE

A quadcopter drone using the Intel Edison platform.


Hardware
--------

The brain of the edison drone is an "Intel Edison Compute Module"
(http://amzn.com/B00PTVSS4A). This is plugged in to a Series of SparkFun
Blocks, starting with the Base block. The blocks used are:

 * Base (https://www.sparkfun.com/products/13045)
 * 9 DOF (https://www.sparkfun.com/products/13033)
 * I2C (https://www.sparkfun.com/products/13034)
 * Battery (https://www.sparkfun.com/products/13037)

These blocks snap together and require no additional wiring or soldering. It
is recommended that you attach these with the additional hardware pack
(https://www.sparkfun.com/products/13187).


Compiling
---------

The following commands can be used to build:

.. code-block:: bash

    git clone https://github.com/greghaynes/edisondrone.git
    cd edisondrone
    git submodule init
    git submodule update
    cmake -Dtest=on .
    make


Running
-------

Simply run the `edison-server` binary generated from compilation on the
Edison computer to start the drone. In its current state only debug information
is output and no control is possile.


Tests
-----

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
