#ifndef GUI_TIMELINEINNERWIDGET_H
#define GUI_TIMELINEINNERWIDGET_H

#include <QWidget>
#include <QAction>
#include <QTreeWidgetItem>
#include "core/TimeLineEvent.h"
#include "ctrl/TimeLineEditor.h"
#include "gui/ViaPoint.h"

namespace gui
{

class TimeLineInnerWidget : public QWidget
{
    Q_OBJECT
public:
    TimeLineInnerWidget(ViaPoint& aViaPoint, QWidget* aParent);

    void setProject(core::Project* aProject);
    void setFrame(core::Frame aFrame);

    void updateCamera(const core::CameraInfo& aCamera);
    void updateLines(QTreeWidgetItem* aTopNode);
    void updateLineSelection(core::ObjectNode* aRepresent);
    bool updateCursor(const core::AbstractCursor& aCursor);
    void updateWheel(QWheelEvent* aEvent);
    void updateProjectAttribute();

    core::Frame currentFrame() const;
    int maxFrame() const;

private:
    class TimeCursor : public QWidget
    {
    public:
        TimeCursor(QWidget* aParent);
        void setCursorPos(const QPoint& aPos, int aHeight);
        void setCurrentFrame(core::Frame frame);
        virtual void paintEvent(QPaintEvent* aEvent);
    private:
        core::Frame mFrame;
    };

    void updateTimeCursorPos();
    void updateSize();
    void updateLinesRecursive(QTreeWidgetItem* aItem);
    virtual void paintEvent(QPaintEvent* aEvent);
    void onTimeLineModified(core::TimeLineEvent& aEvent, bool aUndo);
    void onTreeRestructured(core::ObjectTreeEvent& aEvent, bool aUndo);
    void onProjectAttributeModified(core::ProjectEvent& aEvent, bool aUndo);
    void onContextMenuRequested(const QPoint& aPos);
    void onCopyKeyTriggered(bool);
    void onPasteKeyTriggered(bool);
    void onDeleteKeyTriggered(bool);

    ViaPoint& mViaPoint;
    util::LinkPointer<core::Project> mProject;
    util::SlotId mTimeLineSlot;
    util::SlotId mTreeRestructSlot;
    util::SlotId mProjectAttrSlot;
    QScopedPointer<ctrl::TimeLineEditor> mEditor;
    const core::CameraInfo* mCamera;
    TimeCursor mTimeCursor;

    QAction* mCopyKey;
    QAction* mPasteKey;
    QAction* mDeleteKey;
    core::TimeLineEvent mTargets;
    core::TimeLineEvent mCopyTargets;
    QPoint mPastePos;
    bool mOnPasting;
};

} // namespace gui

#endif // GUI_TIMELINEINNERWIDGET_H
