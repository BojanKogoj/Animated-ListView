/*
 * ACustomListItem.h
 *
 *  Created on: 17. avg. 2015
 *      Author: Bojan
 */

#ifndef ACUSTOMLISTITEM_H_
#define ACUSTOMLISTITEM_H_

#include <bb/cascades/CustomListItem>
#include <bb/cascades/TranslateTransition>
#include <bb/cascades/FadeTransition>

//#include "AAnimationType.h"

using namespace bb::cascades;

class ACustomListItem: public bb::cascades::CustomListItem
{
    Q_OBJECT
    Q_ENUMS(AAnimationType)
public:
    enum AAnimationType
    {
        SLIDE_LEFT, FADE
    };

    ACustomListItem();
    virtual ~ACustomListItem();

private:
    static int countIndex;
    int itemIndex;
    AAnimationType m_animationType;
    TranslateTransition *translateItem;
    FadeTransition *fadeItem;
    void animateSlideIn();
    void animateFadeIn();

private slots:
    void onTransitionEnded();
    void onCreationCompleted();

};

#endif /* ACUSTOMLISTITEM_H_ */
