static const u32 sFieldMugshotGfx_TestNormal[] = INCBIN_U32("graphics/field_mugshots/test/normal.4bpp.lz");
static const u32 sFieldMugshotGfx_TestAlt[] = INCBIN_U32("graphics/field_mugshots/test/alt.4bpp.lz");
static const u16 sFieldMugshotPal_TestNormal[] = INCBIN_U16("graphics/field_mugshots/test/normal.gbapal");
static const u16 sFieldMugshotPal_TestAlt[] = INCBIN_U16("graphics/field_mugshots/test/alt.gbapal");

// actual mugshot gfx data
static const u32 sFieldMugshotGfx_SunkernNormal[] = INCBIN_U32("graphics/field_mugshots/sunkern_normal.4bpp.lz");
static const u16 sFieldMugshotPal_SunkernNormal[] = INCBIN_U16("graphics/field_mugshots/sunkern_normal.gbapal");
static const u32 sFieldMugshotGfx_SunkernAlt[] = INCBIN_U32("graphics/field_mugshots/sunkern_normal.4bpp.lz");
static const u16 sFieldMugshotPal_SunkernAlt[] = INCBIN_U16("graphics/field_mugshots/sunkern_normal.gbapal");

static const u32 sFieldMugshotGfx_WooperNormal[] = INCBIN_U32("graphics/field_mugshots/wooper_normal.4bpp.lz");
static const u16 sFieldMugshotPal_WooperNormal[] = INCBIN_U16("graphics/field_mugshots/wooper_normal.gbapal");
static const u32 sFieldMugshotGfx_WooperAlt[] = INCBIN_U32("graphics/field_mugshots/wooper_alt.4bpp.lz");
static const u16 sFieldMugshotPal_WooperAlt[] = INCBIN_U16("graphics/field_mugshots/wooper_alt.gbapal");

static const u32 sFieldMugshotGfx_TorkoalNormal[] = INCBIN_U32("graphics/field_mugshots/torkoal_normal.4bpp.lz");
static const u16 sFieldMugshotPal_TorkoalNormal[] = INCBIN_U16("graphics/field_mugshots/torkoal_normal.gbapal");
static const u32 sFieldMugshotGfx_TorkoalAlt[] = INCBIN_U32("graphics/field_mugshots/torkoal_alt.4bpp.lz");
static const u16 sFieldMugshotPal_TorkoalAlt[] = INCBIN_U16("graphics/field_mugshots/torkoal_alt.gbapal");

static const u32 sFieldMugshotGfx_XatuNormal[] = INCBIN_U32("graphics/field_mugshots/xatu_normal.4bpp.lz");
static const u16 sFieldMugshotPal_XatuNormal[] = INCBIN_U16("graphics/field_mugshots/xatu_normal.gbapal");
static const u32 sFieldMugshotGfx_XatuAlt[] = INCBIN_U32("graphics/field_mugshots/xatu_alt.4bpp.lz");
static const u16 sFieldMugshotPal_XatuAlt[] = INCBIN_U16("graphics/field_mugshots/xatu_alt.gbapal");

static const u32 sFieldMugshotGfx_WhimsicottNormal[] = INCBIN_U32("graphics/field_mugshots/whimsicott_normal.4bpp.lz");
static const u16 sFieldMugshotPal_WhimsicottNormal[] = INCBIN_U16("graphics/field_mugshots/whimsicott_normal.gbapal");
static const u32 sFieldMugshotGfx_WhimsicottAlt[] = INCBIN_U32("graphics/field_mugshots/whimsicott_alt.4bpp.lz");
static const u16 sFieldMugshotPal_WhimsicottAlt[] = INCBIN_U16("graphics/field_mugshots/whimsicott_alt.gbapal");

struct MugshotGfx
{
    const u32 *gfx;
    const u16 *pal;
};

static const struct MugshotGfx sFieldMugshots[MUGSHOT_COUNT][EMOTE_COUNT] =
{
    [MUGSHOT_TEST] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_TestNormal,
            .pal = sFieldMugshotPal_TestNormal,
        },

        [EMOTE_ALT] =
        {
            .gfx = sFieldMugshotGfx_TestAlt,
            .pal = sFieldMugshotPal_TestAlt,
        },
    },
    [MUGSHOT_SUNKERN] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_SunkernNormal,
            .pal = sFieldMugshotPal_SunkernNormal,
        },

        [EMOTE_ALT] =
        {
            .gfx = NULL,
            .pal = NULL,
        },
    },
    [MUGSHOT_WOOPER] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_WooperNormal,
            .pal = sFieldMugshotPal_WooperNormal,
        },

        [EMOTE_ALT] =
        {
            .gfx = sFieldMugshotGfx_WooperAlt,
            .pal = sFieldMugshotPal_WooperAlt,
        },
    },
    [MUGSHOT_TORKOAL] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_TorkoalNormal,
            .pal = sFieldMugshotPal_TorkoalNormal,
        },
        [EMOTE_ALT] =
        {
            .gfx = sFieldMugshotGfx_TorkoalAlt,
            .pal = sFieldMugshotPal_TorkoalAlt,
        },
    },
    [MUGSHOT_XATU] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_XatuNormal,
            .pal = sFieldMugshotPal_XatuNormal,
        },

        [EMOTE_ALT] =
        {
            .gfx = sFieldMugshotGfx_XatuAlt,
            .pal = sFieldMugshotPal_XatuAlt,
        },
    },
    [MUGSHOT_WHIMSICOTT] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_WhimsicottNormal,
            .pal = sFieldMugshotPal_WhimsicottNormal,
        },
        [EMOTE_ALT] =
        {
            .gfx = sFieldMugshotGfx_WhimsicottAlt,
            .pal = sFieldMugshotPal_WhimsicottAlt,
        },
    },
};
