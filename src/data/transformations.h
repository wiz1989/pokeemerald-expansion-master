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
        .ability = ABILITY_NONE,
        .moves = {
            MOVE_WEATHER_BALL,
            MOVE_NONE,
            MOVE_NONE,
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
        // .ability = ABILITY_SWIFT_SWIM,
        .moves = {
            MOVE_WEATHER_BALL,
            MOVE_NONE,
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
        // .ability = ABILITY_CHLOROPHYLL,
        .moves = {
            MOVE_WEATHER_BALL,
            MOVE_NONE,
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
        // .ability = ABILITY_SNOW_CLOAK,
        .moves = {
            MOVE_WEATHER_BALL,
            MOVE_NONE,
            MOVE_NONE,
            MOVE_NONE,
        },
        .targetMap = MAP_TARC3_SNOWY,
    },
};
