/*
 * ACustomListItem.cpp
 *
 *  Created on: 17. avg. 2015
 *      Author: Bojan
 */

#include "ACustomListItem.h"
#include <bb/cascades/StockCurve>
#include <bb/device/DisplayInfo>
#include <bb/cascades/OrientationSupport>

using namespace bb::cascades;

int ACustomListItem::countIndex = 0;

ACustomListItem::ACustomListItem()
{
    bb::device::DisplayInfo display;

    int translate = OrientationSupport::instance()->orientation() ? display.pixelSize().height() : display.pixelSize().width();
    itemIndex = countIndex;
    setTranslationX(translate);

    translateItem = new TranslateTransition();
    translateItem->setToX(0);
    translateItem->setFromX(translate);
    translateItem->setDuration(800);
    translateItem->setDelay(50 * ACustomListItem::countIndex++);
    translateItem->setEasingCurve(StockCurve::CircularOut);

    connect(translateItem, SIGNAL(ended()), this, SLOT(onTransitionEnded()));

    addAnimation(translateItem);

    translateItem->play();

}

ACustomListItem::~ACustomListItem()
{
    // TODO Auto-generated destructor stub
}

void ACustomListItem::onTransitionEnded()
{
    translateItem->deleteLater();

    /* When we come to the end of animation, remove indexes. They are only used for delay, and
     *  if you add more elements you should not wait for animation to start
     *  */
    if (itemIndex == countIndex - 1) {
        countIndex = 0;
    }
}
