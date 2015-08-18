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

using namespace bb::cascades;

class ACustomListItem: public bb::cascades::CustomListItem
{
    Q_OBJECT
public:
    ACustomListItem();
    virtual ~ACustomListItem();
private:
    static int countIndex;
    int itemIndex;
    TranslateTransition *translateItem;
private slots:
    void onTransitionEnded();

};

#endif /* ACUSTOMLISTITEM_H_ */
