/****************************************************************************
 **
 ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
 ** All rights reserved.
 ** Contact: Nokia Corporation (qt-info@nokia.com)
 **
 ** This file is part of the QtCore module of the Qt Toolkit.
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
 **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor
 **     the names of its contributors may be used to endorse or promote
 **     products derived from this software without specific prior written
 **     permission.
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
 ** $QT_END_LICENSE$
 **
 ****************************************************************************/

#ifndef XQVIBRA_H
#define XQVIBRA_H

// INCLUDES
#include <QObject>

// FORWARD DECLARATIONS
class XQVibraPrivate;

// CLASS DECLARATION
class XQVibra : public QObject
{
    Q_OBJECT

public:
    static const int InfiniteDuration = 0;
    static const int MaxIntensity = 100;
    static const int MinIntensity = -100;

    enum Status {
        StatusNotAllowed = 0,
        StatusOff,
        StatusOn
    };

    XQVibra(QObject *parent = 0);
    ~XQVibra();

    XQVibra::Status currentStatus() const;

Q_SIGNALS:
    void statusChanged(XQVibra::Status status);

    // User defined
    void enabledChanged(bool enabled);
    void durationChanged(int duration);
    void pauseChanged(int pause);
    void repeatTimesChanged(int repeatTimes);

public:
    // User defined
    bool enabled() const;
    int  duration() const;

public Q_SLOTS:
    bool start(int duration = InfiniteDuration);
    // Start user defined
    bool startDuration();
    void startRepeat();
    // End user defined
    bool stop();
    bool setIntensity(int intensity);

    // User defined
    void setEnabled(bool enabled);
    void setDuration(int duration = InfiniteDuration);
    void setPause(int pause = 100);
    void setRepeatTimes(int repeatTimes = 1);

private:
    friend class XQVibraPrivate;
    XQVibraPrivate *d;

    // User defined
    bool m_enabled;
    int  m_duration;
    int  m_pause;
    int  m_repeatTimes;
};

#endif // XQVIBRA_H

// End of file
