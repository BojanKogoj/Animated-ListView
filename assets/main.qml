/*
 * Copyright (c) 2011-2015 BlackBerry Limited.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

import bb.cascades 1.3
import bb.data 1.0
import si.adev.acustomlistitem 1.0

Page {
    Container {

        ListView {
            dataModel: myDataModel

            listItemComponents: ListItemComponent {
                type: ""
                ACustomListItem {
                    Container {
                        layout: DockLayout {

                        }
                        verticalAlignment: VerticalAlignment.Fill
                        leftPadding: ui.du(2)
                        Label {
                            text: ListItemData.test
                            verticalAlignment: VerticalAlignment.Center
                            textStyle.fontSize: FontSize.Large
                        }
                    }

                }
            }
        }
    }
    attachedObjects: [
        ArrayDataModel {
            id: myDataModel
        },
        DataSource {
            id: myDataSource
            type: DataSourceType.Xml
            source: "asset:///data.xml"
            onDataLoaded: {
                myDataModel.clear()
                myDataModel.insert(0, data.item);
            }
        }
    ]
    actions: [
        ActionItem {
            title: "Load"
            ActionBar.placement: ActionBarPlacement.Signature
            onTriggered: {
                myDataSource.load();
            }
        },
        ActionItem {
            ActionBar.placement: ActionBarPlacement.OnBar
            title: "Add element"
            onTriggered: {
                myDataModel.insert(3, {
                        "test": "TEST!"
                    });

            }
        }
    ]
}
