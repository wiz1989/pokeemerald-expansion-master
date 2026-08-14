#include "pokemon_animation.h"

const u32 gItemIcon_CastformBase[] = INCBIN_U32("graphics/items/icons/castform_base.4bpp.lz");
const u16 gItemIconPalette_CastformBase[] = INCBIN_U16("graphics/items/icon_palettes/castform.gbapal");
const u32 gItemIcon_CastformRainy[] = INCBIN_U32("graphics/items/icons/castform_rainy.4bpp.lz");
const u16 gItemIconPalette_CastformRainy[] = INCBIN_U16("graphics/items/icon_palettes/castform.gbapal");
const u32 gItemIcon_CastformSunny[] = INCBIN_U32("graphics/items/icons/castform_sunny.4bpp.lz");
const u16 gItemIconPalette_CastformSunny[] = INCBIN_U16("graphics/items/icon_palettes/castform.gbapal");
const u32 gItemIcon_CastformSnowy[] = INCBIN_U32("graphics/items/icons/castform_snowy.4bpp.lz");
const u16 gItemIconPalette_CastformSnowy[] = INCBIN_U16("graphics/items/icon_palettes/castform.gbapal");

const struct Transformation gTransformations[] =
{
    [SPECIES_CASTFORM_NORMAL] =
    {
        .name = _("Castform"),
        .fieldUseFunc = ItemUseOutOfBattle_TransformBase,
        .iconPic = gItemIcon_CastformBase,
        .iconPalette = gItemIconPalette_CastformBase,
        .battleSpecies = SPECIES_CASTFORM_NORMAL,
        .targetMap = MAP_TARC3_BASE,
        .ability = ABILITY_LEVITATE,
        .moves = {
            MOVE_WEATHER_BALL,
            MOVE_PROTECT,
            MOVE_DISABLE,
            MOVE_NONE,
        },
    },

    [SPECIES_CASTFORM_RAINY] =
    {
        .name = _("Rainy Form"),
        .fieldUseFunc = ItemUseOutOfBattle_TransformRainy,
        .iconPic = gItemIcon_CastformRainy,
        .iconPalette = gItemIconPalette_CastformRainy,
        .battleSpecies = SPECIES_CASTFORM_RAINY,
        .targetMap = MAP_TARC3_RAINY,
        .ability = ABILITY_HYDRATION,
        .moves = {
            MOVE_SURF,
            MOVE_AQUA_RING,
            MOVE_NONE,
            MOVE_NONE,
        },
    },

    [SPECIES_CASTFORM_SUNNY] =
    {
        .name = _("Sunny Form"),
        .fieldUseFunc = ItemUseOutOfBattle_TransformSunny,
        .iconPic = gItemIcon_CastformSunny,
        .iconPalette = gItemIconPalette_CastformSunny,
        .battleSpecies = SPECIES_CASTFORM_SUNNY,
        .targetMap = MAP_TARC3_SUNNY,
        .ability = ABILITY_CHLOROPHYLL,
        .moves = {
            MOVE_INCINERATE,
            MOVE_SIMPLE_BEAM,
            MOVE_NONE,
            MOVE_NONE,
        },
    },

    [SPECIES_CASTFORM_SNOWY] =
    {
        .name = _("Snowy Form"),
        .fieldUseFunc = ItemUseOutOfBattle_TransformSnowy,
        .iconPic = gItemIcon_CastformSnowy,
        .iconPalette = gItemIconPalette_CastformSnowy,
        .battleSpecies = SPECIES_CASTFORM_SNOWY,
        .ability = ABILITY_ICE_BODY,
        .moves = {
            MOVE_AVALANCHE,
            MOVE_ICY_WIND,
            MOVE_AURORA_VEIL,
            MOVE_NONE,
        },
        .targetMap = MAP_TARC3_SNOWY,
    },
};

#define NUMBER_OF_CHARACTERS ARRAY_COUNT(gCharacters)
const struct Character gCharacters[] =
{
    [SPECIES_FOMANTIS] =
    {
        .name = _("Fomantis"),
        .battleSpecies = SPECIES_FOMANTIS,
        .ability = ABILITY_LEAF_GUARD,
        .item = ITEM_NONE,
        .moves = {
            MOVE_GROWTH,
            MOVE_RAZOR_LEAF,
            MOVE_NONE,
            MOVE_NONE,
        },
    },
};
