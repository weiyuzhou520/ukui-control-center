/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * Copyright (C) 2019 Tianjin KYLIN Information Technology Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */
#ifndef ITEM_LIST_H
#define ITEM_LIST_H

#include <QObject>
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QComboBox>
#include "frameitem.h"

#define CURSIZE 6

class ItemList : public QWidget
{
    Q_OBJECT
public:
    explicit        ItemList(QWidget *parent = nullptr,int itemssize = CURSIZE);
    QStringList     get_list() const;
    FrameItem*   get_item(const int &cur);
    FrameItem*   get_item_by_name(const QString &name);
private:
    QStringList     m_szItemNameList = {tr("Walpaper"),tr("ScreenSaver"),tr("Avatar"),tr("Menu"),tr("Quick Start"),
                                        tr("Tab"),tr("Mouse"),tr("TouchPad"),tr("KeyBoard"),tr("ShortCut"),
                                        tr("Area"),tr("Date/Time"),tr("Default Open"),tr("Notice"),tr("Option"),tr("Peony"),
                                        tr("Boot"),tr("Power"),tr("Editor"),tr("Terminal"),tr("Weather"),tr("Media")};
    int             m_cItemCnt = 0;
    FrameItem    *m_itemWidget[30];
    QPoint          m_startPoint;
    QVBoxLayout     *m_vboxLayout;
signals:

};

#endif // ITEM_LIST_H
