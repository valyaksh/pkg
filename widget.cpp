
#include "widget.h"
#include "ui_widget.h"

QColor main_color;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{


    //ui->setupUi(this);
    grLayout = new QGridLayout(this);
    qApp->installEventFilter(this);
    grLayout->setAlignment(Qt::AlignLeft);
    setMinimumSize(890,500);
    setMaximumSize(890, 500);
    cbLeft = new QComboBox();
    cbCenter = new QComboBox();
    cbRight = new QComboBox();
    cbLeft->addItems(slLeft);
    cbCenter->addItems(slCenter);
    cbRight->addItems(slRight);
    cbLeft->setCurrentIndex(-1);
    cbRight->setCurrentIndex(-1);
    cbCenter->setCurrentIndex(-1);


    GradientLabel = new QLabel(this);
    grLayout->addWidget(GradientLabel, 1,1,2,7);
    colorRectangle = new QLabel(this);
    grLayout->addWidget(colorRectangle, 3,1,1,7);
    colorRectangle->setStyleSheet("QLabel{background-color:rgb(0,0,0);border:0px solid black;}");
    colorRectangle->setMinimumSize(850,40);
    colorRectangle->setMaximumSize(850,40);

    grLayout->addWidget(cbLeft,5,2,1,2);
    grLayout->addWidget(cbCenter,5,4,1,2);
    grLayout->addWidget(cbRight,5,6,1,2);


    lbLeftFirst = new QLabel("R:");
    lbLeftSecond = new QLabel("G:");
    lbLeftThird = new QLabel("B:");

    leLeftFirst = new  QSpinBox(this);
    leLeftSecond = new QSpinBox(this);
    leLeftThird = new QSpinBox(this);
    leLeftFirst->setRange(0,255);
    leLeftSecond->setRange(0,255);
    leLeftThird->setRange(0,255);
    leLeftFirst->setFixedWidth(250);
    leLeftSecond->setFixedWidth(250);
    leLeftThird->setFixedWidth(250);
    grLayout->addWidget(lbLeftFirst, 6,2);
    grLayout->addWidget(leLeftFirst, 6,3);
    grLayout->addWidget(lbLeftSecond, 7, 2);
    grLayout->addWidget(leLeftSecond, 7,3);
    grLayout->addWidget(lbLeftThird, 8, 2);
    grLayout->addWidget(leLeftThird, 8,3);


    lbCenterFirst = new QLabel("X:");
    lbCenterSecond = new QLabel("Y:");
    lbCenterThird = new QLabel("Z:");

    leCenterFirst = new QSpinBox(this);
    leCenterSecond = new QSpinBox(this);
    leCenterThird = new QSpinBox(this);
    leCenterFirst->setRange(0,96);
    leCenterSecond->setRange(0,108);
    leCenterThird->setRange(0,100);

    leCenterFirst->setFixedWidth(250);
    leCenterSecond->setFixedWidth(250);
    leCenterThird->setFixedWidth(250);

    grLayout->addWidget(lbCenterFirst, 6,4);
    grLayout->addWidget(leCenterFirst, 6,5);
    grLayout->addWidget(lbCenterSecond, 7, 4);
    grLayout->addWidget(leCenterSecond, 7,5);
    grLayout->addWidget(lbCenterThird, 8, 4);
    grLayout->addWidget(leCenterThird, 8,5);


    lbRightFirst = new QLabel("H:");
    lbRightSecond = new QLabel("S:");
    lbRightThird = new QLabel("L:");

    leRightFirst = new QSpinBox(this);
    leRightSecond = new QSpinBox(this);
    leRightThird = new QSpinBox(this);
    leRightFirst->setRange(0,359);
    leRightSecond->setRange(0,255);
    leRightThird->setRange(0,100);

    leRightFirst->setFixedWidth(250);
    leRightSecond->setFixedWidth(250);
    leRightThird->setFixedWidth(250);

    grLayout->addWidget(lbRightFirst, 6,6);
    grLayout->addWidget(leRightFirst, 6,7);
    grLayout->addWidget(lbRightSecond, 7, 6);
    grLayout->addWidget(leRightSecond, 7,7);
    grLayout->addWidget(lbRightThird, 8, 6);
    grLayout->addWidget(leRightThird, 8,7);



    cbLeft->setCurrentText("RGB");
    cbCenter->setCurrentText("XYZ");
    cbRight->setCurrentText("HSL");

    setLayout(grLayout);


    sliderLeft = new QSlider(this);
    sliderCenter = new QSlider(this);
    sliderRight = new QSlider(this);

    sliderLeft->setOrientation(Qt::Horizontal);
    sliderRight->setOrientation(Qt::Horizontal);
    sliderCenter->setOrientation(Qt::Horizontal);
    sliderLeft->setRange(0, 255);
    sliderCenter->setRange(0, 255);
    sliderRight->setRange(0, 255);
    grLayout->addWidget(sliderLeft, 4, 2, 1, 2);
    grLayout->addWidget(sliderCenter, 4, 4, 1, 2);
    grLayout->addWidget(sliderRight, 4, 6, 1, 2);

    connect(sliderLeft, SIGNAL(valueChanged(int)), this, SLOT(red_change()));
    connect(sliderCenter, SIGNAL(valueChanged(int)), this, SLOT(red_change()));
    connect(sliderRight, SIGNAL(valueChanged(int)), this, SLOT(red_change()));

    connect(leLeftFirst, SIGNAL(editingFinished()), this, SLOT(changed_LeftFirst()));
    connect(leLeftSecond, SIGNAL(editingFinished()), this, SLOT(changed_LeftSecond()));
    connect(leLeftThird, SIGNAL(editingFinished()), this, SLOT(changed_LeftThird()));

    connect(leCenterFirst, SIGNAL(editingFinished()), this, SLOT(changed_CenterFirst()));
    connect(leCenterSecond, SIGNAL(editingFinished()), this, SLOT(changed_CenterSecond()));
    connect(leCenterThird, SIGNAL(editingFinished()), this, SLOT(changed_CenterThird()));


    connect(leRightFirst, SIGNAL(editingFinished()), this, SLOT(changed_RightFirst()));
    connect(leRightSecond, SIGNAL(editingFinished()), this, SLOT(changed_RightSecond()));
    connect(leRightThird, SIGNAL(editingFinished()), this, SLOT(changed_RightThird()));

}

Widget::~Widget()
{
    delete ui;
}

double Widget::getY() const
{
    return XYZ_Y;
}

double Widget::getX() const
{
    return XYZ_X;
}

double Widget::getZ() const
{
    return XYZ_Z;
}

void Widget::setX(double x)
{
    XYZ_X = x;
}

void Widget::setY(double x)
{
    XYZ_Y = x;
}

void Widget::setZ(double x)
{
    XYZ_Z = x;
}


void Widget::changed_LeftFirst()
{
    main_color.setRed(leLeftFirst->text().toInt());
    color_convertation_from_QColor();
    setSlider();
    setTexteverywhere();
}

void Widget::changed_LeftSecond()
{
    main_color.setGreen(leLeftSecond->text().toInt());
    color_convertation_from_QColor();
    setSlider();
    setTexteverywhere();
}

void Widget::changed_LeftThird()
{
    main_color.setBlue(leLeftThird->text().toInt());
    setSlider();
    setTexteverywhere();
}


void Widget::changed_CenterFirst()
{
    setX(lbCenterFirst->text().toDouble());
    color_convertation_from_XYZ();
    setSlider();
    setTexteverywhere();
}

void Widget::changed_CenterSecond()
{
    setY(lbCenterSecond->text().toDouble());
    color_convertation_from_XYZ();

    setSlider();
    setTexteverywhere();
}

void Widget::changed_CenterThird()
{

    setZ(lbCenterThird->text().toDouble());
    color_convertation_from_XYZ();
    setSlider();
    setTexteverywhere();
}


void Widget::changed_RightFirst()
{

    main_color.setHsl(leRightFirst->text().toDouble(),main_color.hslSaturation(), main_color.lightness());
    color_convertation_from_QColor();
    setSlider();
    setTexteverywhere();
}

void Widget::changed_RightSecond()
{
    main_color.setHsl(main_color.hslHue(), leRightSecond->text().toDouble(), main_color.lightness());
    color_convertation_from_QColor();

    setSlider();
    setTexteverywhere();

}

void Widget::changed_RightThird()
{

    main_color.setHsl(main_color.hslHue(), main_color.hslSaturation(), leRightThird->text().toInt());
    color_convertation_from_QColor();

    setSlider();
    setTexteverywhere();
}


void Widget::setTexteverywhere()
{
    if (cbLeft->currentText() == "RGB") {
        leLeftFirst->setValue(main_color.red());
        leLeftSecond->setValue(main_color.green());
        leLeftThird->setValue(main_color.blue());
    }

    if (cbCenter->currentText() == "XYZ") {
        leCenterFirst -> setValue(getX());
        leCenterSecond -> setValue(getY());
        leCenterThird -> setValue(getZ());
    }

    if (cbRight->currentText()== "HSL") {
        leRightFirst->setValue(main_color.hslHue());
        leRightSecond->setValue(main_color.hslSaturation());
        leRightThird->setValue(main_color.lightness());
    }
}

void Widget::red_change()
{
    main_color.setRed(sliderLeft->value());
    main_color.setGreen(sliderCenter->value());
    main_color.setBlue(sliderRight->value());
    color_convertation_from_QColor();
    QString r = QString::number(main_color.red());
    QString g = QString::number(main_color.green());
    QString b = QString::number(main_color.blue());
    colorRectangle->setStyleSheet("QLabel{background-color:rgb("+r+
                                  ","+g+","+b+");}");
    setTexteverywhere();
}


void Widget::setSlider()
{
    sliderLeft->setValue(main_color.red());
    sliderCenter->setValue(main_color.green());
    sliderRight->setValue(main_color.blue());
}

QColor Widget::getPixelAt(int x, int y)
{
    return grab(QRect(x, y, 1, 1)).toImage().pixelColor(0,0);
}

double F_RGB_XYZ(double x) {
    if (x>=0.04045) {
        return pow((x+0.055)/1.055, 2.4);
    }
    return x/12.92;
}


void Widget::color_convertation_from_QColor() {

    double Rn = F_RGB_XYZ(main_color.red() / 255.0);
    double Gn = F_RGB_XYZ(main_color.green() / 255.0);
    double Bn = F_RGB_XYZ(main_color.blue() / 255.0);

    double XYZ_X1 = 0.412453*Rn + 0.357580 * Gn + 0.180423 * Bn;
    double XYZ_Y1 = 0.212671*Rn + 0.715160 * Gn + 0.072169 * Bn;
    double XYZ_Z1 = 0.019334*Rn + 0.119193 * Gn + 0.950227 * Bn;

    XYZ_X1*=100.0;
    XYZ_Y1*=100.0;
    XYZ_Z1*=100.0;

    setX(XYZ_X1);
    setY(XYZ_Y1);
    setZ(XYZ_Z1);

}

double F_XYZ_RGB(double x) {
    if (abs(x)<0.0031308) {
        return 12.92 * x;
    }

    return 1.055 * pow(x, 0.41666) - 0.055;
}

void Widget::color_convertation_from_XYZ() {

    double X = getX();
    double Y = getY();
    double Z = getZ();

    double Rn = 3.2404542 * X - 1.5371385 * Y  - 0.4985314 * Z;
    double Gn = -0.9692660 * X + 1.8760108 * Y  + 0.0415560 * Z;
    double Bn = 0.0556434 * X - 0.2040259 * Y  + 1.0572252 * Z;

    Rn/=100.0;
    Gn/=100.0;
    Bn/=100.0;

    double R = F_XYZ_RGB(Rn);
    double G = F_XYZ_RGB(Gn);
    double B = F_XYZ_RGB(Bn);

    R*=255.0;
    G*=255.0;
    B*=255.0;

    main_color.setRed(round(R));
    main_color.setGreen(round(G));
    main_color.setBlue(round(B));

}

void Widget::paintEvent(QPaintEvent *event) {

    QPixmap pix(GradientLabel->width(),GradientLabel->height());
    QPixmap pix2(GradientLabel->width(),GradientLabel->height());
    QPainter painter(&pix);
    QPainter painter2(&pix2);
    QLinearGradient gradl(0,0,pix.width(),0);
    gradl.setColorAt(0,Qt::red);
    gradl.setColorAt(0.18,Qt::yellow);
    gradl.setColorAt(0.36,Qt::green);
    gradl.setColorAt(0.54,Qt::blue);
    gradl.setColorAt(0.8,Qt::darkBlue);
    gradl.setColorAt(1,Qt::magenta);
    painter.setBrush(gradl);
    painter.drawRect(0,0,GradientLabel->width(),GradientLabel->height());
    GradientLabel->setPixmap(pix);
}

bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress && watched == GradientLabel) {
        QMouseEvent* cur = dynamic_cast<QMouseEvent*>(event);
        int x = cur->pos().x() + GradientLabel->x();
        int y = cur->pos().y() + GradientLabel->y();
        main_color = QWidget::grab(QRect(x,y,1,1)).toImage().pixelColor(0,0);
        setTexteverywhere();
        setSlider();
    }

    return false;
}
