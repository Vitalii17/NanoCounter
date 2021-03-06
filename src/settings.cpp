#include "settings.h"

Settings::Settings(QObject *parent) :
    QObject(parent), m_pSettings(new QSettings(this))
{
    m_counterValue      = m_pSettings->value("CounterValue", 0   ).toInt();
    m_vibraEnabled      = m_pSettings->value("VibraEnabled", true).toBool();
    m_backlightAlwaysOn = m_pSettings->value("BacklightAlwaysOn", false).toBool();
    m_volumeKeysEnabled = m_pSettings->value("VolumKeysEnabled", false).toBool();
    m_reversed          = m_pSettings->value("Reversed", false).toBool();
    m_orientation       = m_pSettings->value("Orientation",
                                             Qt::WA_AutoOrientation).toInt();
}

Settings::~Settings()
{
    if(m_counterValue != m_pSettings->value("CounterValue", 0).toInt())
    {
        m_pSettings->setValue("CounterValue", m_counterValue);
    }
    if(m_vibraEnabled != m_pSettings->value("VibraEnabled", true).toBool())
    {
        m_pSettings->setValue("VibraEnabled", m_vibraEnabled);
    }
    if(m_backlightAlwaysOn != m_pSettings->value("BacklightAlwaysOn", false).toBool())
    {
        m_pSettings->setValue("BacklightAlwaysOn", m_backlightAlwaysOn);
    }
    if(m_volumeKeysEnabled != m_pSettings->value("VolumKeysEnabled", false).toBool())
    {
        m_pSettings->setValue("VolumKeysEnabled", m_volumeKeysEnabled);
    }
    if(m_reversed != m_pSettings->value("Reversed", false).toBool())
    {
        m_pSettings->setValue("Reversed", m_reversed);
    }
    if(m_orientation != m_pSettings->value("Orientation",
                                           Qt::WA_AutoOrientation).toInt())
    {
        m_pSettings->setValue("Orientation", m_orientation);
    }
}

void Settings::setCounterValue(int arg)
{
    if(m_counterValue != arg)
    {
        m_counterValue = arg;
        emit counterValueChanged(m_counterValue);
    }
}

void Settings::setVibraEnabled(bool arg)
{
    if(m_vibraEnabled != arg)
    {
        m_vibraEnabled = arg;
        emit vibraEnabledChanged(m_vibraEnabled);
    }
}

void Settings::setBacklightAlwaysOn(bool arg)
{
    if(m_backlightAlwaysOn != arg)
    {
        m_backlightAlwaysOn = arg;
        emit backlightAlwaysOnChanged(m_backlightAlwaysOn);
    }
}

void Settings::setVolumKeysEnabled(bool arg)
{
    if(m_volumeKeysEnabled != arg)
    {
        m_volumeKeysEnabled = arg;
        emit volumKeysEnabledChanged(m_volumeKeysEnabled);
    }
}

void Settings::setReversed(bool arg)
{
    if(m_reversed != arg)
    {
        m_reversed = arg;
        emit reversedChanged(m_reversed);
    }
}

void Settings::setOrientation(int arg)
{
    if(m_orientation != arg)
    {
        m_orientation = arg;
        emit orientationChanged(m_orientation);
    }
}

int Settings::counterValue() const
{
    return m_counterValue;
}

bool Settings::vibraEnabled() const
{
    return m_vibraEnabled;
}

bool Settings::backlightAlwaysOn() const
{
    return m_backlightAlwaysOn;
}

bool Settings::volumeKeysEnabled() const
{
    return m_volumeKeysEnabled;
}

bool Settings::reversed() const
{
    return m_reversed;
}

int Settings::orientation() const
{
    return m_orientation;
}

