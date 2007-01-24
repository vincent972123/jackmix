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

#ifndef JACK_VOLUMESLIDER_H
#define JACK_VOLUMESLIDER_H

#include <qframe.h>
#include <qstring.h>
#include "common.h"
#include "dbvolcalc.h"

namespace JackMix {

class VolumeSlider : public QFrame, public dB2VolCalc {
Q_OBJECT
public:
	/**
		\param name name of the Channel
		\param value initial volume value
		\param dir the direction to slide
		\param p the parent QWidget
		\param showlabel wether to show a label with the name
		\param showvalue wether to show the value as a number
	*/
	VolumeSlider( QString name, float value, Direction dir, QWidget* p, bool showlabel=true, bool showvalue=false, const char* =0 );
	~VolumeSlider();
signals:
	void valueChanged( QString, float );
private slots:
	void iValueChanged( float );
private:
	QString _name;
	bool _showlabel, _showvalue;
};

class VolumeKnob : public QFrame, public dB2VolCalc {
Q_OBJECT
public:
	VolumeKnob( QString, float, QWidget*, bool showlabel=true, const char* =0 );
	~VolumeKnob();
signals:
	void valueChanged( QString, float );
private slots:
	void iValueChanged( float );
private:
	QString _name;
};

};

#endif
