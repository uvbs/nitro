/* =========================================================================
 * This file is part of io-c++ 
 * =========================================================================
 * 
 * (C) Copyright 2004 - 2014, MDA Information Systems LLC
 *
 * io-c++ is free software; you can redistribute it and/or modify
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
 * License along with this program; If not, 
 * see <http://www.gnu.org/licenses/>.
 *
 */

#include <import/except.h>
#include <import/io.h>
using namespace except;
using namespace io;
using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <in file> <out file>\n", argv[0]);
        return -1;
    }

    try
    {
        FileInputStream iStream(argv[1]);
        FileOutputStream oStream(argv[2]);
        StringStream sStream;

        iStream.streamTo(sStream);
        sStream.streamTo(oStream);

        iStream.close();
        oStream.close();
    }
    catch (Throwable& t)
    {
        cerr << "Caught throwable: " << t.toString() << endl;
    }

    catch (...)
    {
        cerr << "Caught unknown exception" << endl;
    }
    return 0;
}
