#include "errordialog.h"
#include "ui_errordialog.h"

ErrorDialog::ErrorDialog(bool started, int errorCount, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ErrorDialog)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::Dialog | Qt::WindowStaysOnTopHint);

    QFile backtrace(QDir::homePath() + "/.tsbacktrace");
    if (backtrace.exists()) {
        backtrace.open(QFile::ReadOnly);
        this->backtrace = backtrace.readAll();
        backtrace.close();
        backtrace.remove();

        ui->backtrace->setPlainText(this->backtrace);
        ui->backtrace->setFont(QFontDatabase::systemFont(QFontDatabase::FixedFont));
    } else {
        ui->debugButton->setVisible(false);
    }

    ui->errorIcon->setPixmap(QIcon(":/icons/error.svg").pixmap(128, 128));
    if (started) {
        if (errorCount >= 3) {
            ui->restartButton->setVisible(false);
            ui->titleLabel->setText(tr("Unfortunately, theShell keeps running into errors. Try to boot-up later."));
            ui->repeatFrame->setVisible(true);
            ui->errorLabel->setVisible(false);
            //ui->errorLabel->setText(tr("theShell keeps running into errors."));
        } else {
            ui->repeatFrame->setVisible(false);
        }
    } else {
        if (errorCount >= 3) {
            ui->restartButton->setVisible(false);
            ui->titleLabel->setText(tr("theShell can't start"));
            ui->repeatFrame->setVisible(true);
            ui->errorLabel->setVisible(false);
        } else {
            ui->repeatFrame->setVisible(false);
            ui->titleLabel->setText(tr("theShell failed to start"));
            ui->errorLabel->setText(tr("theShell wasn't able to start properly."));
            ui->restartButton->setText(tr("Try again"));
        }
    }

    ui->logoutButton->setProperty("type", "destructive");

}

ErrorDialog::~ErrorDialog()
{
    delete ui;
}

void ErrorDialog::on_restartButton_clicked()
{
    emit restart();
}

void ErrorDialog::on_logoutButton_clicked()
{
    emit logout();
}

void ErrorDialog::on_backButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void ErrorDialog::on_debugButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void ErrorDialog::on_saveBacktraceButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Backtrace"), QDir::homePath(), tr("Backtrace (*.bt)"));
    if (fileName != "") {
        QFile f(fileName);
        f.open(QFile::WriteOnly);
        f.write(this->backtrace.toUtf8());
        f.close();

        ui->stackedWidget->setCurrentIndex(0);
    }
}

void ErrorDialog::on_resetTSButton_clicked()
{
    if (QMessageBox::warning(this, tr("Format theShell?"), tr("You're about to format theShell to its default state. All plugged in drives and USB Sticks will also get formatted. Are you sure you wish to do this?"), QMessageBox::Yes | QMessageBox::No, QMessageBox::No) == QMessageBox::Yes) {
        QSettings("theSuite", "theShell").clear();

        ui->resetTSButton->setEnabled(false);
        ui->resetTSButton->setText("Settings reset successfully");
    }
}
