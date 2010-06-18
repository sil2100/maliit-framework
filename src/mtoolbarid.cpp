/* * This file is part of meego-im-framework *
 *
 * Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 * Contact: Nokia Corporation (directui@nokia.com)
 *
 * If you have questions regarding the use of this file, please contact
 * Nokia at directui@nokia.com.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License version 2.1 as published by the Free Software Foundation
 * and appearing in the file LICENSE.LGPL included in the packaging
 * of this file.
 */


#include "mtoolbarid.h"

#include <QHash>


MToolbarId::MToolbarId()
    : id(-1)
{
}

MToolbarId::MToolbarId(int id, const QString &service)
    : id(id),
      service(service)
{
}

bool MToolbarId::isValid() const
{
    return id >= 0 && !service.isEmpty();
}

bool MToolbarId::operator==(const MToolbarId &other) const
{
    return (id == other.id) && (service == other.service);
}

bool MToolbarId::operator!=(const MToolbarId &other) const
{
    return !operator==(other);
}

uint qHash(const MToolbarId &id)
{
    return qHash(QPair<int, QString>(id.id, id.service));
}
