/****************************************
 *
 *   theShell - Desktop Environment
 *   Copyright (C) 2019 Victor Tran
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * *************************************/

#ifndef TRANSFERSLISTMODEL_H
#define TRANSFERSLISTMODEL_H

#include <debuginformationcollector.h>
#include <QAbstractListModel>
#include <BluezQt/ObexManager>
#include <BluezQt/ObexSession>
#include <BluezQt/ObexFileTransfer>
#include <BluezQt/ObexObjectPush>
#include <BluezQt/ObexTransfer>
#include <QIcon>
#include <QStyledItemDelegate>
#include <QPainter>
#include <QFileInfo>
#include <tnotification.h>

class CancelWatcher : public QObject
{
    Q_OBJECT
    public:
        CancelWatcher(QObject* parent = nullptr) : QObject(parent) {};

    signals:
        void cancelled();

    public slots:
        void cancelRequested() {
            emit cancelled();
        }
};

class TransfersListModel : public QAbstractListModel
{
        Q_OBJECT

    public:
        explicit TransfersListModel(BluezQt::ObexManager* mgr, QObject *parent = T_QOBJECT_ROOT);

        // Basic functionality:
        int rowCount(const QModelIndex &parent = QModelIndex()) const override;

        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

        void pushTransfer(BluezQt::ObexTransferPtr transfer, bool incoming);

    private:
        BluezQt::ObexManager* mgr;
        QList<BluezQt::ObexTransferPtr> transfers;
};

class TransfersDelegate : public QStyledItemDelegate
{
    Q_OBJECT

    public:
        TransfersDelegate(QWidget *parent = 0);
        void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
        QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // TRANSFERSLISTMODEL_H
