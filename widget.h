#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtWidgets>
#include <QPixmap>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QGridLayout *grLayout;
private:

    double XYZ_X = 0;
    double XYZ_Y = 0;
    double XYZ_Z = 0;

    double getX() const;
    double getY() const;
    double getZ() const;
    void setX(double);
    void setY(double);
    void setZ(double);

    void paintEvent(QPaintEvent *event);
    void color_convertation_from_QColor();
    void color_convertation_from_XYZ();

    QSlider *sliderLeft;
    QSlider *sliderRight;
    QSlider *sliderCenter;
    QLabel *colorRectangle;

    Ui::Widget *ui;
    QComboBox *cbLeft;
    QComboBox *cbCenter;
    QComboBox *cbRight;
    QStringList slLeft = {"RGB"};
    QStringList slCenter = {"XYZ"};
    QStringList slRight = {"HSL"};

    QLabel *GradientLabel;


    QSpinBox *leLeftFirst;
    QSpinBox *leLeftSecond;
    QSpinBox *leLeftThird;
    QLabel *lbLeftFirst;
    QLabel *lbLeftSecond;
    QLabel *lbLeftThird;


    QSpinBox *leCenterFirst;
    QSpinBox *leCenterSecond;
    QSpinBox *leCenterThird;

    QLabel *lbCenterFirst;
    QLabel *lbCenterSecond;
    QLabel *lbCenterThird;


    QSpinBox *leRightFirst;
    QSpinBox *leRightSecond;
    QSpinBox *leRightThird;

    QLabel *lbRightFirst;
    QLabel *lbRightSecond;
    QLabel *lbRightThird;

public slots:

    bool eventFilter(QObject *watched, QEvent *event);


    void changed_LeftFirst();
    void changed_LeftSecond();
    void changed_LeftThird();

    void changed_CenterFirst();
    void changed_CenterSecond();
    void changed_CenterThird();


    void changed_RightFirst();
    void changed_RightSecond();
    void changed_RightThird();

    void setTexteverywhere();
    void red_change();

    void setSlider();
    QColor getPixelAt(int x, int y);

};
#endif // WIDGET_H
