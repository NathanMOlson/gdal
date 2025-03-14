.. _raster.heif:

================================================================================
HEIF / HEIC -- ISO/IEC 23008-12 High Efficiency Image File Format
================================================================================

.. versionadded:: 3.2

.. shortname:: HEIF

.. build_dependencies:: libheif (>= 1.1), built against libde265

High Efficiency Image File Format (HEIF) is a container format for individual images and image sequences.
The driver has mostly been developed and tested to be able to read images using
the High Efficiency Video Coding (HEVC, ITU-T H.265) codec. Such images are
usually called HEIC (HEVC in HEIF) files, and have the .heic extension.
iOS 11 can generate such files.

libheif 1.4 or later is needed to support images with more than 8-bits per channel.

Later versions of libheif may also support one or more of AVIF (AV1 in HEIF), JPEG, JPEG 2000 and
uncompressed images depending on compile-time options.

The driver can read EXIF metadata (exposed in the ``EXIF`` metadata domain)
and XMP metadata (exposed in the ``xml:XMP`` metadata domain)

The driver will expose the thumbnail as an overview (when its number of bands
matches the number of bands in the full resolution image).

If a file contains several top-level images, they will be exposed as GDAL subdatasets.

AVIF support
------------

Starting with GDAL 3.10, the AVIF_HEIF companion driver to the HEIF driver may
be used to open images encoding with the AVIF (AV1 Image File) codec if the
:ref:`raster.avif` driver is not available and if libheif has been compiled with
support for one of the libraries it support that are able of AV1 decoding
(libaom or libdav1d).


Driver capabilities
-------------------

.. supports_virtualio:: if libheif >= 1.4

.. supports_createcopy::

.. supports_georeferencing::

Georeferencing
--------------

HEIF provides experimental read-only support for GeoHEIF internal referencing,
based on the draft OGC 24-038 design. There is no support for writing
at this time.

This requires at least libheif 1.19.0.

Built hints on Windows
----------------------

* Download source archives for libheif at
  https://github.com/strukturag/libheif and libde265 at
  https://github.com/strukturag/libde265

* Unpack the archives (for example libde265-1.0.5.tar.gz and libheif-1.7.0.tar.gz)

* Build libde265:

    ::

        cd libde265-1.0.5
        mkdir build
        cd build
        cmake -G "Visual Studio 15 2017 Win64" .. -DCMAKE_INSTALL_PREFIX=c:/dev/install-libheif
        cmake --build . --config Release --target install
        cd ..
        copy libde265\de265.h c:/dev/install-libheif/include/libde265
        copy libde265\de265-version.h c:/dev/install-libheif/include/libde265
        cd ..

* Build libheif with libde265 support:

    ::


        cd libheif-1.7.0
        mkdir build
        cd build
        cmake -G "Visual Studio 15 2017 Win64" .. \
            -DCMAKE_INSTALL_PREFIX=c:/dev/install-libheif \
            -DLIBDE265_FOUND=ON \
            -DLIBDE265_CFLAGS=/Ic:/dev/install-libheif/include \
            -DLIBDE265_LIBRARIES=c:/dev/install-libheif/lib/libde265


* Add in GDAL's nmake.local the following lines before building GDAL:

    ::

        HEIF_INC = -Ic:\dev\install-libheif\include
        HEIF_LIB = C:\dev\install-libheif\lib\heif.lib
