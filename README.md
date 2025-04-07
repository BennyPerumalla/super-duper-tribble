# super-duper-tribble
Ported Filter: Volume Control
# 🔊 VLC Volume Filter (Ported from MPlayer)

This project is a **simple audio filter plugin for VLC Media Player** that allows you to adjust the volume of playback audio by applying a user-defined gain factor. It’s a direct port of a volume filter originally implemented in **MPlayer**, adapted for VLC's audio filtering system.

---

## 🚀 Features

- 🎛️ Amplify or reduce volume using a floating-point factor (e.g. `1.0` = 100%, `0.5` = 50%)
- 🧠 Lightweight DSP logic using float32 sample manipulation
- 🔌 Loadable VLC plugin written in pure C

---

## 📦 Requirements

Before building, make sure the following are installed:

```bash
sudo apt update
sudo apt install libvlc-dev vlc-plugin-base build-essential pkg-config
```
## 📥 Installation Instructions
### 📂 User-Level (Recommended)
```bash
mkdir -p ~/.local/lib/vlc/plugins/audio_filter/
cp libvolume_filter_plugin.so ~/.local/lib/vlc/plugins/audio_filter/
```
### 🔐 System-Wide (Optional)
```bash
sudo cp libvolume_filter_plugin.so /usr/lib/vlc/plugins/audio_filter/
```
### 🔄 Refresh VLC Plugin Cache
```bash
vlc --reset-plugins-cache
```
## ▶️ Usage Instructions
- Run VLC with audio filter enabled
```bash
vlc --audio-filter=volume_filter --volume-factor=1.5 your-audio-file.mp3
```
### 💡 Volume Factor Examples
Factor	Effect
- 0.5 =	50% volume
- 1.0	= Original volume
- 1.5	= 150% volume
- 2.0	= 200% volume

You can also set this in VLC's preferences under:
```
Tools → Preferences → Audio → Effects → Audio Filters
```

## 🧩 Tech Stack

- Language: C
- Target: VLC plugin API
- Audio Format: float32 (VLC_CODEC_FL32)
- Tools: make, pkg-config, GCC

## 🧠 How It Works

- VLC reads PCM float32 audio samples into a buffer
- The plugin multiplies each sample by the volume factor
- The modified audio is played back or passed downstream

## 📚 Credits

- 🔄 Based on `af_volume.c` from the MPlayer project
- ✨ Ported to VLC by `Benny`
