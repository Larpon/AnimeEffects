#ifndef GUI_InfoWidget_H
#define GUI_InfoWidget_H

#include <QWidget>
#include <QResizeEvent>
#include "util/Signaler.h"
#include "ctrl/Driver.h"
#include "ctrl/FFDParam.h"
#include "gui/GUIResources.h"
#include "gui/MainDisplayMode.h"
#include "gui/MainViewSetting.h"
#include "gui/ViaPoint.h"
#include "gui/tool/tool_ViewPanel.h"
#include "gui/tool/tool_ModePanel.h"
#include "gui/tool/tool_SRTPanel.h"
#include "gui/tool/tool_FFDPanel.h"
#include "gui/tool/tool_BonePanel.h"
#include "gui/tool/tool_PosePanel.h"
#include "gui/tool/tool_MeshPanel.h"

namespace gui
{

class InfoWidget : public QWidget
{
    Q_OBJECT
public:
	InfoWidget(ViaPoint& aViaPoint, GUIResources& aResources, KeyCommandMap& aKeyCommandMap,
               const QSize& aSizeHint, QWidget* aParent);

private:
    virtual QSize sizeHint() const { return mSizeHint; }
    virtual void resizeEvent(QResizeEvent* aEvent);

    MainViewSetting& viewSetting() { return mViaPoint.mainViewSetting(); }
    const MainViewSetting& viewSetting() const { return mViaPoint.mainViewSetting(); }

    void updateGeometry();

    ViaPoint& mViaPoint;
    GUIResources& mResources;
	KeyCommandMap& mKeyCommandMap;
    const QSize mSizeHint;
};

} // namespace gui

#endif // GUI_InfoWidget_H
