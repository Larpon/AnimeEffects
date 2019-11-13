#include "gui/InfoWidget.h"
#include "gui/KeyCommandMap.h"
#include "XC.h"

namespace gui
{

InfoWidget::InfoWidget(ViaPoint& aViaPoint, GUIResources& aResources, KeyCommandMap &aKeyCommandMap,
					   const QSize& aSizeHint, QWidget* aParent)
    : QWidget(aParent)
    , mViaPoint(aViaPoint)
    , mResources(aResources)
	, mKeyCommandMap(aKeyCommandMap)
    , mSizeHint(aSizeHint)
{

    updateGeometry();

}

void InfoWidget::resizeEvent(QResizeEvent* aEvent)
{
    QWidget::resizeEvent(aEvent);
    updateGeometry();
}

void InfoWidget::updateGeometry()
{
    const int width = this->size().width();
    int height = 0;
}

} // namespace gui
