/*
    Copyright ( C ) 2004 Arnold Krille <arnold@arnoldarts.de>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation;
    version 2 of the License.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
    Boston, MA 02111-1307, USA.

*/

#include <qdom.h>
#include <iostream>
#include <qfile.h>

//using namespace std;

int main() {
	QDomDocument doc(  "mydocument" );
	QFile file(  "mydocument.xml" );
	if (  !file.open(  IO_ReadOnly ) )
		return 2;
	if (  !doc.setContent(  &file ) ) {
		file.close();
		return 1;
	}
	file.close();

	// print out the element names of all elements that are direct children
	// of the outermost element.
	QDomElement docElem = doc.documentElement();
	std::cout << "1: " << docElem.tagName() <<std::endl;

	QDomElement title = doc.createElement( "title" );
	title.appendChild( doc.createTextNode( "Testseite" ) );
	std::cout << "2:" << std::endl;
	doc.documentElement().appendChild( title );

	std::cout << "3:" << std::endl;

	QDomNode n = docElem.firstChild();
	while (  !n.isNull() ) {
		QDomElement e = n.toElement(); // try to convert the node to an element.
		if (  !e.isNull() ) {
			std::cout << e.tagName() << std::endl; // the node really is an element.
			std::cout << e.text() << " childs:" << e.hasChildNodes() << std::endl;
		}
		n = n.nextSibling();
	}

	std::cout << doc.toString() << std::endl;

	return 0;
}

