#ifndef ANIMATIONPREVIEWDIALOG_H
#define ANIMATIONPREVIEWDIALOG_H

#include <QtWidgets>

class SpritesTreeWidget;

namespace Ui {
class AnimationPreviewDialog;
}

class AnimationPreviewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AnimationPreviewDialog(QWidget *parent = 0);
    ~AnimationPreviewDialog();

    static AnimationPreviewDialog* instance() { return _instance; }

    void spritesSelectionChanged(SpritesTreeWidget* spritesTreeWidget);

protected:
    void timerEvent(QTimerEvent* event);
    void scanFolder(QTreeWidgetItem* item);

private slots:
    void on_framePerSecondSpinBox_valueChanged(int arg1);
    void on_framesSlider_valueChanged(int value);
    void on_playToolButton_toggled(bool checked);
    void on_prevFrameToolButton_clicked();
    void on_nextFrameToolButton_clicked();
    void on_firstFrameToolButton_clicked();
    void on_lastFrameToolButton_clicked();

private:
    static AnimationPreviewDialog*  _instance;

    Ui::AnimationPreviewDialog*     ui;
    QVector<QPixmap>                _frames;
    int                             _animationTimer;
};

#endif // ANIMATIONPREVIEWDIALOG_H
