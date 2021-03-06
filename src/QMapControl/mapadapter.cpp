/***************************************************************************
 *   Copyright (C) 2007 by Kai Winter   *
 *   kaiwinter@gmx.de   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include "mapadapter.h"

MapAdapter::MapAdapter(const QString& host, const QString& serverPath, const QString& theProjection, int minZoom, int maxZoom)
    :host(host), serverPath(serverPath), Projection(theProjection), min_zoom(minZoom), max_zoom(maxZoom), theImageManager(0)
{
    current_zoom = min_zoom;
    loc = QLocale(QLocale::English);
}

MapAdapter::~MapAdapter()
{
}

QString MapAdapter::getName() const
{
    return name;
}

QString MapAdapter::getHost() const
{
    return host;
}

QString MapAdapter::projection() const
{
    return Projection;
}

int MapAdapter::getMinZoom(const QRectF &) const
{
    return min_zoom;
}

int MapAdapter::getMaxZoom(const QRectF &) const
{
    return max_zoom;
}

int MapAdapter::getAdaptedMinZoom(const QRectF &) const
{
    return 0;
}

int MapAdapter::getAdaptedMaxZoom(const QRectF &) const
{
    return max_zoom > min_zoom ? max_zoom - min_zoom : min_zoom - max_zoom;
}

int MapAdapter::getZoom() const
{
    return current_zoom;
}

int MapAdapter::getAdaptedZoom() const
{
    return max_zoom < min_zoom ? min_zoom - current_zoom : current_zoom - min_zoom;
}

IImageManager* MapAdapter::getImageManager()
{
    return theImageManager;
}

void MapAdapter::setImageManager(IImageManager* anImageManager)
{
    theImageManager = anImageManager;
}

