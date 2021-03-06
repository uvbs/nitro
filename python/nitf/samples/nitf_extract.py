#!/usr/bin/env python 

"""
 * =========================================================================
 * This file is part of NITRO
 * =========================================================================
 * 
 * (C) Copyright 2004 - 2010, General Dynamics - Advanced Information Systems
 *
 * NITRO is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public 
 * License along with this program; if not, If not, 
 * see <http://www.gnu.org/licenses/>.
 *
 *
"""

from nitf import *
import os, sys, logging, glob

logging.basicConfig(level=logging.INFO, stream=sys.stdout,
                    format='%(asctime)s %(levelname)s %(message)s')


def extract_image(subheader, index, imageReader, outDir=None, baseName=None):
    window = SubWindow()
    window.numRows = subheader['numRows'].intValue()
    window.numCols = subheader['numCols'].intValue()
    window.bandList = range(subheader.getBandCount())
    nbpp = subheader['numBitsPerPixel'].intValue()
    bandData = imageReader.read(window)
    
    if not outDir: outDir = os.getcwd()
    if not baseName: baseName = os.path.basename(os.tempnam())
    
    outNames = []
    for band, data in enumerate(bandData):
        outName = '%s_%d__%d_x_%d_%d_band_%d.out' % (
             baseName, index, window.numRows, window.numCols, nbpp, band)
        outName = os.path.join(outDir, outName)
        f = open(outName, 'wb')
        f.write(data)
        f.close()
        outNames.append(outName)
        logging.info('Wrote band data to file %s' % outName)
    return outNames



def extract_images(fileName, outDir=None):
    if not outDir: outDir = os.getcwd()
    if not os.path.exists(outDir): os.makedirs(outDir)
    
    handle = IOHandle(fileName)
    reader = Reader()
    record = reader.read(handle)
    logging.info('Dumping file: %s' % fileName)
    
    for i, segment in enumerate(record.getImages()):
        logging.info('--- Image [%d] ---' % i)
        imReader = reader.newImageReader(i)
        extract_image(segment.subheader, i, imReader, outDir, os.path.basename(fileName))
    handle.close()


if __name__ == '__main__':
    for arg in sys.argv[1:]:
        if os.path.isfile(arg):
            extract_images(arg)
        elif os.path.isdir(arg):
            map(extract_images, glob.glob(os.path.join(arg, '*.ntf')) + glob.glob(os.path.join(arg, '*.NTF')))


