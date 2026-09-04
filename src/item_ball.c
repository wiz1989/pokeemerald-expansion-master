#include "global.h"
#include "item_ball.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "constants/event_objects.h"
#include "constants/items.h"

static u32 GetItemBallAmountFromTemplate(u32);
static u32 GetItemBallIdFromTemplate(u32);

static u32 GetItemBallAmountFromTemplate(u32 itemBallId)
{
    u32 amount = gMapHeader.events->objectEvents[itemBallId].movementRangeX;

    if (amount > MAX_BAG_ITEM_CAPACITY)
        return MAX_BAG_ITEM_CAPACITY;

    return (amount == 0) ? 1 : amount;
}

static u32 GetItemBallIdFromTemplate(u32 itemBallId)
{
    enum Item itemId = gMapHeader.events->objectEvents[itemBallId].trainerRange_berryTreeId;

    return (itemId >= ITEMS_COUNT) ? (ITEM_NONE + 1) : itemId;
}

void GetItemBallIdAndAmountFromTemplate(void)
{
    u32 itemBallId = (gSpecialVar_LastTalked - 1);
    gSpecialVar_Result = GetItemBallIdFromTemplate(itemBallId);
    gSpecialVar_0x8009 = GetItemBallAmountFromTemplate(itemBallId);
}

void GetObjectEventSpecies(void)
{
    u8 objectEventId = GetObjectEventIdByLocalId(gSpecialVar_LastTalked);

    // reset VAR_SPECIAL in case the object does not return a species
    gSpecialVar_Result = SPECIES_NONE;

    if (gObjectEvents[objectEventId].active && IS_OW_MON_OBJ(&gObjectEvents[objectEventId]))
        gSpecialVar_Result = OW_SPECIES(&gObjectEvents[objectEventId]);
}
