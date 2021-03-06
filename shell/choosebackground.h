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

#ifndef CHOOSEBACKGROUND_H
#define CHOOSEBACKGROUND_H

#include <QDialog>
#include <QSvgRenderer>
#include "background.h"

namespace Ui {
class ChooseBackground;
}

class ChooseBackground : public QDialog
{
    Q_OBJECT

    public:
        explicit ChooseBackground(QString currentCommunityBackground = "", QWidget *parent = 0);
        ~ChooseBackground();

    signals:
        void reloadBackgrounds();

        void reloadTimer();

    private slots:
        void on_lineEdit_textChanged(const QString &arg1);

        void on_listWidget_currentRowChanged(int currentRow);

        void on_pushButton_clicked();

        void on_pushButton_2_clicked();

        void on_inbuiltBackground_toggled(bool checked);

        void on_community_toggled(bool checked);

        void on_custom_toggled(bool checked);

        void on_pushButton_3_clicked();

        void on_waitTime_valueChanged(int arg1);

        void on_showLabels_toggled(bool checked);

        void on_licenseInfoButton_clicked();

        void on_stretchStyle_currentIndexChanged(int index);

    private:
        Ui::ChooseBackground *ui;

        QIcon getSvgIcon(QString filename);
        QSettings settings;

        QString license;
};

#endif // CHOOSEBACKGROUND_H
