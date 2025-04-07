/*****************************************************************************
 * volume_filter.c : Simple volume adjustment audio filter for VLC
 *****************************************************************************/

#include <vlc_common.h>
#include <vlc_plugin.h>
#include <vlc_filter.h>

#define VOL_FACTOR_DEFAULT 1.0
#define VOL_FACTOR_TEXT N_("Volume factor")
#define VOL_FACTOR_LONGTEXT N_("Adjust the volume (1.0 = original volume)")

static int Open(vlc_object_t *);
static void Close(vlc_object_t *);

vlc_module_begin()
    set_description("Simple Volume Filter (Ported from MPlayer)")
    set_capability("audio filter", 0)
    set_category(CAT_AUDIO)
    set_subcategory(SUBCAT_AUDIO_AFILTER)
    add_float("volume-factor", VOL_FACTOR_DEFAULT, VOL_FACTOR_TEXT, VOL_FACTOR_LONGTEXT, false)
    set_callbacks(Open, Close)
vlc_module_end()

typedef struct
{
    float volume_factor;
} filter_sys_t;

static block_t *Filter(filter_t *p_filter, block_t *p_block)
{
    if (!p_block)
        return NULL;

    filter_sys_t *p_sys = p_filter->p_sys;
    float *samples = (float *)p_block->p_buffer;
    size_t samples_count = p_block->i_buffer / sizeof(float);

    for (size_t i = 0; i < samples_count; i++)
    {
        samples[i] *= p_sys->volume_factor;
    }

    return p_block;
}

static int Open(vlc_object_t *obj)
{
    filter_t *filter = (filter_t *)obj;

    if (filter->fmt_in.audio.i_format != VLC_CODEC_FL32)
    {
        msg_Err(filter, "Volume filter only supports float32 audio format.");
        return VLC_EGENERIC;
    }

    filter_sys_t *sys = malloc(sizeof(*sys));
    if (!sys)
        return VLC_ENOMEM;

    sys->volume_factor = var_InheritFloat(filter, "volume-factor");
    filter->p_sys = sys;
    filter->pf_audio_filter = Filter;

    msg_Info(filter, "Volume filter loaded. Factor: %.2f", sys->volume_factor);
    return VLC_SUCCESS;
}

static void Close(vlc_object_t *obj)
{
    filter_t *filter = (filter_t *)obj;
    free(filter->p_sys);
}
