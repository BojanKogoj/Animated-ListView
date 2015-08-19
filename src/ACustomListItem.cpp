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
    itemIndex = countIndex;
    m_animationType = FADE;
    connect(this, SIGNAL(creationCompleted()), this, SLOT(onCreationCompleted()));

    if (m_animationType == FADE)
        setOpacity(0);

}

ACustomListItem::~ACustomListItem()
{
    // TODO Auto-generated destructor stub
}

void ACustomListItem::onTransitionEnded()
{
    if (m_animationType == SLIDE_LEFT)
        translateItem->deleteLater();
    if (m_animationType == FADE)
        fadeItem->deleteLater();

    /* When we come to the end of animation, remove indexes. They are only used for delay, and
     *  if you add more elements you should not wait for animation to start
     *  */
    if (itemIndex == countIndex - 1) {
        countIndex = 0;
    }
}

void ACustomListItem::animateSlideIn()
{
    bb::device::DisplayInfo display;
    int translate = OrientationSupport::instance()->orientation() ? display.pixelSize().height() : display.pixelSize().width();

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

void ACustomListItem::animateFadeIn()
{
    fadeItem = new FadeTransition();
    fadeItem->setDuration(400);
    fadeItem->setFromOpacity(0);
    fadeItem->setToOpacity(1);
    fadeItem->setDelay(50 * ACustomListItem::countIndex++);

    connect(fadeItem, SIGNAL(ended()), this, SLOT(onTransitionEnded()));
    addAnimation(fadeItem);
    fadeItem->play();

}

/*AAnimationType ACustomListItem::animationType()
 {
 return m_animationType;
 }*/

void ACustomListItem::onCreationCompleted()
{
//qDebug() << m_animationType;
    if (m_animationType == SLIDE_LEFT)
        animateSlideIn();
    else if (m_animationType == FADE)
        animateFadeIn();

}
