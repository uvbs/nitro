/* =========================================================================
 * This file is part of xml.lite-c++
 * =========================================================================
 *
 * (C) Copyright 2004 - 2014, MDA Information Systems LLC
 *
 * xml.lite-c++ is free software; you can redistribute it and/or modify
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

#ifndef __XML_LITE_XERCES_XML_READER_H__
#define __XML_LITE_XERCES_XML_READER_H__

#include "xml/lite/xml_lite_config.h"

#if defined(USE_XERCES)

#include <string>
#include <io/StringStream.h>
#include <io/OutputStream.h>
#include <io/InputStream.h>
#include <sys/Mutex.h>
#include <mt/CriticalSection.h>
#include "xml/lite/XMLException.h"
#include "xml/lite/ContentHandler.h"
#include "xml/lite/Attributes.h"
#include "xml/lite/NamespaceStack.h"
#include "xml/lite/XMLReaderInterface.h"
#include "xml/lite/UtilitiesXerces.h"
#include <except/Error.h>

namespace xml
{
namespace lite
{

/*!
 *  \class XMLReaderXerces
 *  \brief SAX 2.0 XML Parsing class, replaces 1.0 Parser class
 *
 *  Provide the API for SAX-driven parsing.  We are using
 *  the Expat C Parser underneath, and wiring it to
 *  generic event calls, via the content handler.
 */
class XMLReaderXerces : public XMLReaderInterface
{

private:

    XercesContext mCtxt;    //! this must be the first member listed
    std::auto_ptr<SAX2XMLReader>        mNative;
    std::auto_ptr<XercesContentHandler> mDriverContentHandler;
    std::auto_ptr<XercesErrorHandler>   mErrorHandler;

public:

    //! Constructor.  Creates a new XML parser
    XMLReaderXerces();

    //! Destructor.
    ~XMLReaderXerces()
    {
    }

    static const char* MEM_BUFFER_ID()
    {
        return "XMLReaderXerces";
    }

    /*!
     *  This method returns a reference to the content handler.
     *  \return content handler
     */
    xml::lite::ContentHandler *getContentHandler()
    {
        return mDriverContentHandler->retrieveXMLLiteContentHandler();
    }

    /*!
     *  This method should be handed a new-allocated ContentHandler.
     *  It will set this internally.
     *  \param handler  The content handler to pass
     */
    void setContentHandler(xml::lite::ContentHandler* handler)
    {
        mDriverContentHandler->setXMLLiteContentHandler(handler);
    }

    void parse(io::InputStream& is, int size = io::InputStream::IS_END);
    
    //! Method to create an xml reader
    void create();

    //! Method to destroy an xml reader
    void destroy();

    std::string getDriverName() const { return "xerces"; }

private:

    void write(const sys::byte *b, sys::Size_T len)
    {
        throw xml::lite::XMLException(Ctxt("Im not sure how you got here!"));
    }
};

}
}

#endif
#endif
