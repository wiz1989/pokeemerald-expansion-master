#include "global.h"
#include "play_time.h"

enum
{
    STOPPED,
    RUNNING,
    MAXED_OUT
};

static u8 sPlayTimeCounterState;

void PlayTimeCounter_Reset(void)
{
    sPlayTimeCounterState = STOPPED;

    gSaveBlock2Ptr->playTimeHours = 0;
    gSaveBlock2Ptr->playTimeMinutes = 0;
    gSaveBlock2Ptr->playTimeSeconds = 0;
    gSaveBlock2Ptr->playTimeVBlanks = 0;
}

void PlayTimeCounter_Start(void)
{
    sPlayTimeCounterState = RUNNING;

    if (gSaveBlock2Ptr->playTimeHours > 999)
        PlayTimeCounter_SetToMax();
}

void PlayTimeCounter_Stop(void)
{
    sPlayTimeCounterState = STOPPED;
}

void PlayTimeCounter_Update(void)
{
    if (sPlayTimeCounterState != RUNNING)
        return;

    gSaveBlock2Ptr->playTimeVBlanks++;

    if (gSaveBlock2Ptr->playTimeVBlanks < 60)
        return;

    gSaveBlock2Ptr->playTimeVBlanks = 0;
    gSaveBlock2Ptr->playTimeSeconds++;

    if (gSaveBlock2Ptr->playTimeSeconds < 60)
        return;

    gSaveBlock2Ptr->playTimeSeconds = 0;
    gSaveBlock2Ptr->playTimeMinutes++;

    if (gSaveBlock2Ptr->playTimeMinutes < 60)
        return;

    gSaveBlock2Ptr->playTimeMinutes = 0;
    gSaveBlock2Ptr->playTimeHours++;

    if (gSaveBlock2Ptr->playTimeHours > 999)
        PlayTimeCounter_SetToMax();
}

void PlayTimeCounter_SetToMax(void)
{
    sPlayTimeCounterState = MAXED_OUT;

    gSaveBlock2Ptr->playTimeHours = 999;
    gSaveBlock2Ptr->playTimeMinutes = 59;
    gSaveBlock2Ptr->playTimeSeconds = 59;
    gSaveBlock2Ptr->playTimeVBlanks = 59;
}

void PlayTimeCounter_AddMin(s16 minutes)
{
    DebugPrintf("%d:%d", gSaveBlock2Ptr->playTimeHours, gSaveBlock2Ptr->playTimeMinutes);
    DebugPrintf("current hours = %d", gSaveBlock2Ptr->playTimeHours);
    DebugPrintf("minutes+ = %d", minutes);
    if (gSaveBlock2Ptr->playTimeMinutes + minutes < 60) {
        gSaveBlock2Ptr->playTimeMinutes = gSaveBlock2Ptr->playTimeMinutes + minutes;
    }
    else {
        gSaveBlock2Ptr->playTimeHours = gSaveBlock2Ptr->playTimeHours + 1 * ((gSaveBlock2Ptr->playTimeMinutes + minutes) / 60);
        gSaveBlock2Ptr->playTimeMinutes = (gSaveBlock2Ptr->playTimeMinutes + minutes) % 60;
    }
    PlayTimeCounter_Update();
    DebugPrintf("%d:%d", gSaveBlock2Ptr->playTimeHours, gSaveBlock2Ptr->playTimeMinutes);
    DebugPrintf("-------------------");
}

void PlayTimeCounter_AddHrs(s16 hours)
{
    DebugPrintf("%d:%d", gSaveBlock2Ptr->playTimeHours, gSaveBlock2Ptr->playTimeMinutes);
    DebugPrintf("current hours = %d", gSaveBlock2Ptr->playTimeHours);
    DebugPrintf("hours+ = %d", hours);
    if (gSaveBlock2Ptr->playTimeHours + hours > 999) {
        PlayTimeCounter_SetToMax();
    }
    else {
        gSaveBlock2Ptr->playTimeHours = gSaveBlock2Ptr->playTimeHours + hours;
    }
    PlayTimeCounter_Update();
    DebugPrintf("%d:%d", gSaveBlock2Ptr->playTimeHours, gSaveBlock2Ptr->playTimeMinutes);
    DebugPrintf("-------------------");
}

void PlayTimeCounter_SubMin(s16 minutes)
{
    DebugPrintf("%d:%d", gSaveBlock2Ptr->playTimeHours, gSaveBlock2Ptr->playTimeMinutes);
    DebugPrintf("current hours = %d", gSaveBlock2Ptr->playTimeHours);
    DebugPrintf("minutes- = %d", minutes);
    if (gSaveBlock2Ptr->playTimeMinutes - minutes >= 0) {
        gSaveBlock2Ptr->playTimeMinutes = gSaveBlock2Ptr->playTimeMinutes - minutes;
    }
    else {
        DebugPrintf("calc1 = %d", (60 - gSaveBlock2Ptr->playTimeMinutes + minutes) / 60);
        DebugPrintf("calc hours rem = %d", gSaveBlock2Ptr->playTimeHours - 1 * ((60 - gSaveBlock2Ptr->playTimeMinutes + minutes) / 60));
        if (gSaveBlock2Ptr->playTimeHours - 1 * ((60 - gSaveBlock2Ptr->playTimeMinutes + minutes) / 60) >= 0) {
            gSaveBlock2Ptr->playTimeHours = gSaveBlock2Ptr->playTimeHours - 1 * ((60 - gSaveBlock2Ptr->playTimeMinutes + minutes) / 60);
            if (((gSaveBlock2Ptr->playTimeMinutes - minutes) * -1) < 60) {
                gSaveBlock2Ptr->playTimeMinutes = 60 - ((gSaveBlock2Ptr->playTimeMinutes - minutes) * -1);
            }
            else {
                gSaveBlock2Ptr->playTimeMinutes = 60 - ((gSaveBlock2Ptr->playTimeMinutes - minutes) * -1) % 60;
            }
        }
        else {
            PlayTimeCounter_Reset();
            PlayTimeCounter_Start();
        }
    }
    PlayTimeCounter_Update();
    DebugPrintf("%d:%d", gSaveBlock2Ptr->playTimeHours, gSaveBlock2Ptr->playTimeMinutes);
    DebugPrintf("-------------------");
}

void PlayTimeCounter_SubHrs(s16 hours)
{
    DebugPrintf("%d:%d", gSaveBlock2Ptr->playTimeHours, gSaveBlock2Ptr->playTimeMinutes);
    DebugPrintf("current hours = %d", gSaveBlock2Ptr->playTimeHours);
    DebugPrintf("hours- = %d", hours);
    if (gSaveBlock2Ptr->playTimeHours - hours < 0) {
        PlayTimeCounter_Reset();
        PlayTimeCounter_Start();
    }
    else {
        gSaveBlock2Ptr->playTimeHours = gSaveBlock2Ptr->playTimeHours - hours;
        PlayTimeCounter_Update();
    }
    DebugPrintf("%d:%d", gSaveBlock2Ptr->playTimeHours, gSaveBlock2Ptr->playTimeMinutes);
    DebugPrintf("-------------------");
}
