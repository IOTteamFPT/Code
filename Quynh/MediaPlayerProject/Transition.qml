/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.0
import QtQuick.Window 2.2
import QtGraphicalEffects 1.0
import QtPositioning 5.8

Item {
    id: item1
    visible: true
    width: 700
    height: 300

    Rectangle {
        id: page
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent
        objectName: "page"
        signal pagenext(string picnext)
        signal pageprevious(string picprevious)
        signal showit(string pic1, string pic2, string pic3)
        color: "#16487c"
        property int time: 500
        onPageprevious: {
                    if (rect3.x == user3.x) {
                        page.state = 'right3'
                        user0.picpath = picprevious}
                    else if (rect3.x == user2.x) {
                        page.state = 'right2'
                        user4.picpath = picprevious}
                    else if(rect3.x == user1.x) {
                        page.state = 'right1'
                        user3.picpath = picprevious}
                    else if(rect3.x == user0.x) {
                        page.state = 'right0'
                        user2.picpath = picprevious}
                    else if(rect3.x == user4.x){
                        page.state = 'right4';
                        user1.picpath = picprevious}
        }

        onPagenext: {
                        if (rect1.x == user1.x) {
                            page.state = 'left1'
                            user4.picpath = picnext}
                        else if (rect1.x == user2.x) {
                            page.state = 'left2'
                            user0.picpath = picnext}
                        else if(rect1.x == user3.x) {
                            page.state = 'left3'
                            user1.picpath = picnext}
                        else if(rect1.x == user0.x) {
                            page.state = 'left0'
                            user3.picpath = picnext}
                        else if(rect1.x == user4.x) {
                            page.state = 'left4'
                            user2.picpath = picnext}
        }

        onShowit:  {user1.picpath = pic1
                    user2.picpath = pic2
            user3.picpath = pic3
            page.state = 'reset'

        }

        Rectangle {
            id: user0
            property string picpath
            x: rect0.x; y:rect0.y
            width: 100; height: 100
            gradient: Gradient {
                GradientStop {
                    position: 0.296
                    color: "#ffffff"
                }

                GradientStop {
                    position: 1
                    color: "#000000"
                }
            }
            Image {
                anchors.fill: parent
                source: user0.picpath
            }
        }

        Rectangle {
            id: user1
            property string picpath
            x: rect1.x; y: rect1.y
            width: 100; height: 100
            gradient: Gradient {
                GradientStop {
                    position: 0.296
                    color: "#b7ddf6"
                }

                GradientStop {
                    position: 1
                    color: "#000000"
                }
            }
            Image {
                anchors.fill: parent
                source: user1.picpath
            }
        }

        Rectangle {
            property string picpath
            id: user2
            x: rect2.x; y: rect2.y
            width: 100; height: 100
            gradient: Gradient {
                GradientStop {
                    position: 0.296
                    color: "#b7ddf6"
                }

                GradientStop {
                    position: 1
                    color: "#000000"
                }
            }
            Image {
                anchors.fill: parent
                source: user2.picpath
            }
        }

        Rectangle {
            id: user3
            property string picpath
            x: rect3.x; y: rect3.y
            width: 100; height: 100
            gradient: Gradient {
                GradientStop {
                    position: 0.296
                    color: "#b7ddf6"
                }

                GradientStop {
                    position: 1
                    color: "#000000"
                }
            }
            Image {
                anchors.fill: parent
                source: user3.picpath
            }
        }

        Rectangle {
            id: user4
            property string picpath
            x:rect4.x; y:rect4.y
            width: 100 ; height: 100
            gradient: Gradient {
                GradientStop {
                    position: 0.296
                    color: "#b7ddf6"
                }

                GradientStop {
                    position: 1
                    color: "#000000"
                }
            }
            Image {
                anchors.fill: parent
                source: user4.picpath
            }
        }

        Rectangle {
            id: rect1
            x: 271
            width: 100; height: 100;
            color: "Transparent"; border.color: "Gray"; radius: 1
            visible: false
            anchors.top: rect2.top
            anchors.topMargin: 0
            anchors.right: rect2.left
            anchors.rightMargin: 29
        }

        Rectangle {
            id: rect2
            x: 270
            anchors { verticalCenter: parent.verticalCenter; }
            width: 100; height: 100
            color: "Transparent"; border.color: "Gray"; radius: 1
            anchors.horizontalCenterOffset: 0
            visible: false
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenterOffset: 0
        }

        Rectangle {
            id: rect3
            width: 100
            height: 100
            color: "Transparent"; border.color: "Gray"; radius: 1
            visible: false
            anchors.top: rect2.top
            anchors.topMargin: 0
            anchors.left: rect2.right
            anchors.leftMargin: 31
        }

        Rectangle {
            id: rect0
            x: 136
            y: 0
            width: 100
            height: 100
            color: "#16487c"
            radius: 1
            visible: true
            border.color: "#00000000"
            anchors.topMargin: 0
            anchors.top: rect2.top
            anchors.rightMargin: 164
            anchors.right: rect2.left
        }

        Rectangle {
            id: rect4
            x: -4
            y: -5
            width: 100
            height: 100
            color: "#16487c"
            radius: 1
            anchors.left: rect2.right
            border.color: "#00000000"
            anchors.topMargin: 0
            anchors.leftMargin: 164
            anchors.top: rect2.top
            visible: true
        }

        states: [
            State {
                name: "reset"
                PropertyChanges { target: user1; x: rect1.x; y: rect1.y }
                PropertyChanges { target: user2; x: rect2.x; y: rect2.y }
                PropertyChanges { target: user3; x: rect3.x; y: rect3.y  }
                PropertyChanges { target: user4; x: rect4.x; y: rect4.y  }
                PropertyChanges { target: user0; x: rect0.x; y: rect0.y  }
            },
            State {
                name: "left1"
                PropertyChanges { target: user4; x: rect3.x; y: rect3.y }
                PropertyChanges { target: user1; x: rect0.x; y: rect0.y }
                PropertyChanges { target: user2; x: rect1.x; y: rect1.y }
                PropertyChanges { target: user3; x: rect2.x; y: rect2.y  }
                PropertyChanges { target: user0; x: rect4.x; y: rect4.y  }
            },
            State {
                name: "left2"
                PropertyChanges { target: user4; x: rect2.x; y: rect2.y }
                PropertyChanges { target: user2; x: rect0.x; y: rect0.y }
                PropertyChanges { target: user3; x: rect1.x; y: rect1.y  }
                PropertyChanges { target: user0; x: rect3.x; y: rect3.y  }
                PropertyChanges { target: user1; x: rect4.x; y: rect4.y  }
            },
            State {
                name: "left3"
                PropertyChanges { target: user1; x: rect3.x; y: rect3.y }
                PropertyChanges { target: user2; x: rect4.x; y: rect4.y }
                PropertyChanges { target: user3; x: rect0.x; y: rect0.y  }
                PropertyChanges { target: user4; x: rect1.x; y: rect1.y  }
                PropertyChanges { target: user0; x: rect2.x; y: rect2.y  }
            },
            State {
                name: "left4"
                PropertyChanges { target: user1; x: rect2.x; y: rect2.y }
                PropertyChanges { target: user2; x: rect3.x; y: rect3.y }
                PropertyChanges { target: user3; x: rect4.x; y: rect4.y  }
                PropertyChanges { target: user4; x: rect0.x; y: rect0.y  }
                PropertyChanges { target: user0; x: rect1.x; y: rect1.y  }
            },
            State {
                name: "left0"
                PropertyChanges { target: user1; x: rect1.x; y: rect1.y }
                PropertyChanges { target: user2; x: rect2.x; y: rect2.y }
                PropertyChanges { target: user3; x: rect3.x; y: rect3.y  }
                PropertyChanges { target: user4; x: rect4.x; y: rect4.y  }
                PropertyChanges { target: user0; x: rect0.x; y: rect0.y  }
            },
            State {
                name: "right0"
                PropertyChanges { target: user2; x: rect1.x; y: rect1.y }
                PropertyChanges { target: user3; x: rect2.x; y: rect2.y }
                PropertyChanges { target: user1; x: rect0.x; y: rect0.y  }
                PropertyChanges { target: user0; x: rect4.x; y: rect4.y }
                PropertyChanges { target: user4; x: rect3.x; y: rect3.y  }
            },
            State {
                name: "right1"
                PropertyChanges { target: user2; x: rect0.x; y: rect0.y }
                PropertyChanges { target: user3; x: rect1.x; y: rect1.y }
                PropertyChanges { target: user1; x: rect4.x; y: rect4.y  }
                PropertyChanges { target: user0; x: rect3.x; y: rect3.y }
                PropertyChanges { target: user4; x: rect2.x; y: rect2.y  }
            },
            State {
                name: "right2"
                PropertyChanges { target: user2; x: rect4.x; y: rect4.y }
                PropertyChanges { target: user3; x: rect0.x; y: rect0.y }
                PropertyChanges { target: user1; x: rect3.x; y: rect3.y  }
                PropertyChanges { target: user0; x: rect2.x; y: rect2.y }
                PropertyChanges { target: user4; x: rect1.x; y: rect1.y  }
            },
            State {
                name: "right3"
                PropertyChanges { target: user2; x: rect3.x; y: rect3.y }
                PropertyChanges { target: user3; x: rect4.x; y: rect4.y }
                PropertyChanges { target: user1; x: rect2.x; y: rect2.y  }
                PropertyChanges { target: user0; x: rect1.x; y: rect1.y }
                PropertyChanges { target: user4; x: rect0.x; y: rect0.y  }
            },
            State {
                name: "right4"
                PropertyChanges { target: user2; x: rect2.x; y: rect2.y }
                PropertyChanges { target: user3; x: rect3.x; y: rect3.y }
                PropertyChanges { target: user1; x: rect1.x; y: rect1.y  }
                PropertyChanges { target: user0; x: rect0.x; y: rect0.y }
                PropertyChanges { target: user4; x: rect4.x; y: rect4.y  }
            }
        ]
        transitions: [
            Transition {
                from: "*"; to: "left1"
                 PropertyAnimation {targets: user1
                                    properties: "x,y"; duration : page.time }
                 PropertyAnimation {targets: user2
                                    properties: "x,y"; duration : page.time }
                 PropertyAnimation {targets: user3
                                    properties: "x,y"; duration : page.time }
                 PropertyAnimation {targets: user4
                                    properties: "x,y"; duration : page.time }
            },
            Transition {
                from: "*"; to: "left0"
                 PropertyAnimation {targets: user1
                                    properties: "x,y"; duration : page.time }
                 PropertyAnimation {targets: user2
                                    properties: "x,y"; duration : page.time }
                 PropertyAnimation {targets: user3
                                    properties: "x,y"; duration : page.time }
                 PropertyAnimation {targets: user0
                                    properties: "x,y"; duration : page.time }
            },
            Transition {
                from: "*"; to: "left2"
                 PropertyAnimation {targets: user4
                                    properties: "x,y"; duration : page.time }
                 PropertyAnimation {targets: user2
                                    properties: "x,y"; duration : page.time }
                 PropertyAnimation {targets: user3
                                    properties: "x,y"; duration : page.time }
                 PropertyAnimation {targets: user0
                                    properties: "x,y"; duration : page.time }
            },
            Transition {
                from: "*"; to: "left3"
                PropertyAnimation {targets: user1
                                   properties: "x,y"; duration : page.time }
                PropertyAnimation {targets: user4
                                   properties: "x,y"; duration : page.time }
                PropertyAnimation {targets: user3
                                   properties: "x,y"; duration : page.time }
                PropertyAnimation {targets: user0
                                   properties: "x,y"; duration : page.time }
            },
            Transition {
                from: "*"; to: "left4"
                 PropertyAnimation {targets: user1
                                    properties: "x,y"; duration : page.time }
                 PropertyAnimation {targets: user2
                                    properties: "x,y"; duration : page.time }
                 PropertyAnimation {targets: user4
                                    properties: "x,y"; duration : page.time }
                 PropertyAnimation {targets: user0
                                    properties: "x,y"; duration : page.time }
            },
            Transition {
                from: "*"; to: "right0"
                 PropertyAnimation {targets: user3
                                    properties: "x,y"; duration : page.time }
                 PropertyAnimation {targets: user2
                                    properties: "x,y"; duration : page.time }
                 PropertyAnimation {targets: user4
                                    properties: "x,y"; duration : page.time }
                 PropertyAnimation {targets: user0
                                    properties: "x,y"; duration : page.time }
            },
            Transition {
                from: "*"; to: "right1"
                 PropertyAnimation {targets: user3
                                    properties: "x,y"; duration : page.time }
                 PropertyAnimation {targets: user1
                                    properties: "x,y"; duration : page.time }
                 PropertyAnimation {targets: user4
                                    properties: "x,y"; duration : page.time }
                 PropertyAnimation {targets: user0
                                    properties: "x,y"; duration : page.time }
            },
            Transition {
                from: "*"; to: "right2"
                 PropertyAnimation {targets: user1
                                    properties: "x,y"; duration : page.time }
                 PropertyAnimation {targets: user2
                                    properties: "x,y"; duration : page.time }
                 PropertyAnimation {targets: user4
                                    properties: "x,y"; duration : page.time }
                 PropertyAnimation {targets: user0
                                    properties: "x,y"; duration : page.time }
            },
            Transition {
                from: "*"; to: "right3"
                 PropertyAnimation {targets: user3
                                    properties: "x,y"; duration : page.time }
                 PropertyAnimation {targets: user2
                                    properties: "x,y"; duration : page.time }
                 PropertyAnimation {targets: user1
                                    properties: "x,y"; duration : page.time }
                 PropertyAnimation {targets: user0
                                    properties: "x,y"; duration : page.time }
            },
            Transition {
                from: "*"; to: "right4"
                 PropertyAnimation {targets: user3
                                    properties: "x,y"; duration : page.time }
                 PropertyAnimation {targets: user2
                                    properties: "x,y"; duration : page.time }
                 PropertyAnimation {targets: user4
                                    properties: "x,y"; duration : page.time }
                 PropertyAnimation {targets: user1
                                    properties: "x,y"; duration : page.time }
            }
        ]
    }
}
