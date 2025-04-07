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

## 🧩 Tech Stack
Language: C
Target: VLC plugin API
Audio Format: float32 (VLC_CODEC_FL32)
Tools: make, pkg-config, GCC

## 📦 Requirements

Before building, make sure the following are installed:

```bash
sudo apt update
sudo apt install libvlc-dev vlc-plugin-base build-essential pkg-config
