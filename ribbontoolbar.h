#ifndef RIBBONTOOLBAR_H
#define RIBBONTOOLBAR_H

#include <QWidget>
#include <QString>
#include <QVector>
#include <QSharedPointer>
#include <QAbstractButton>
#include <QHash>

class QIcon;
class QHBoxLayout;
class QVBoxLayout;
class QTabBar;
class QToolButton;
class QBoxLayout;

class RibbonToolBar : public QWidget
{
    Q_OBJECT

    QHBoxLayout *layout0;
    QVBoxLayout *layout1;
    QHash<QString, QToolButton *> toolBarButtons;
    QHash<QString, QWidget *> containerWidgets;
    QWidget *ribbonUiWidget;
    void insertRibbonWidget();
    QTabBar *tabBar;
public:
    explicit RibbonToolBar(QWidget *parent = 0);
    ~RibbonToolBar();
    void loadStyleSheet(QString &fileName);
    void addRibbonAction(const QString &actionName, const QString &actionIdentifier, const QIcon &icon);
    void addRibbonTab(const QString &tabName, const QString &tabIdentifier);
    void addRibbonAction(const QString &actionName, const QString &actionIdentifier,
                         const QString &tabIdentifier, const QIcon &icon);
signals:

public slots:
    void tabSelectionChanged(int index);
};


void makeMarginSpacingZero(QBoxLayout *layout);
#endif // RIBBONTOOLBAR_H
