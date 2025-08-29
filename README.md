# 🎨 Paint Beats

**Paint Beats** is a creative, fullscreen paint application developed in **C++** using **SFML (Simple and Fast Multimedia Library)** and **OpenCV**. It provides a dynamic digital canvas for users to sketch, draw, and paint — all while enjoying relaxing background music. With an intuitive graphical interface, customizable tools, and multimedia integration, this app brings digital art and music together in a delightful experience.

---

## 🚀 Features

- 🎨 **Drawing Tools**  
  Use your mouse to draw various shapes and lines on a 1320x620 canvas. Drawing behavior is intuitive — click and drag to sketch.

- 🛠️ **Customization**  
  Modify drawing parameters like color and line thickness using built-in input fields. RGB and thickness values are entered through the keyboard.

- 🖼️ **Canvas Controls**  
  - **🧼 Clear Button**: Wipe the canvas clean for a fresh start.  
  - **💾 Save Button**: Instantly export your artwork as a `.png` file (`Output Image.png`).

- 🎵 **Built-in Music Player**  
  Switch to a dedicated music screen to play, pause, and toggle through a selection of background music tracks. Enhance your creativity with relaxing tunes as you draw!

- 🧭 **Simple & Clean UI**  
  The user interface includes:
  - A top toolbar with buttons for tools, customization, save/clear actions, and music player.
  - A separate music screen with track controls and playback options.
  - Hover effects and intuitive visuals for interaction.

---

## 🧰 Technologies Used

- **SFML**: For GUI, rendering, audio playback, and input handling.
- **OpenCV**: For shape drawing on a pixel matrix (`cv::Mat`), converted to SFML textures for rendering.
- **C++**: Event-driven application logic and backend structure.

---

## 🧱 Project Structure

- `main.cpp` – Entry point launching the main application.
- `screens.h` – Manages paint and music screens.
- `shapes.h` – Includes functions for drawing various shapes using OpenCV.
- `musics.h` – Handles background music management and playback logic.

---

## 🎮 How to Use

1. **Build the Application**  
   - Install [SFML](https://www.sfml-dev.org/download.php) and [OpenCV](https://opencv.org/releases/), and configure your compiler to link them properly.
   - Compile `main.cpp` using your preferred IDE or compiler.

2. **Run the Executable**  
   - Launch the app in fullscreen mode.
   - Use mouse to select tools, draw on the canvas, or interact with the toolbar.
   - Use keyboard to enter line thickness or RGB values.
   - Click on the 🎵 **Music** icon to switch to the music player screen.

3. **Draw, Clear, and Save**  
   - 🎨 Draw freely within the canvas area (safe zone to avoid toolbar overlap).
   - 💾 Click the **Save** button to export your artwork.
   - 🧼 Click **Clear** to reset the canvas.

---

## 🖱️ Controls

| Action                | Input Type   | Description                                   |
|-----------------------|--------------|-----------------------------------------------|
| Select Tool/Button    | Mouse Click  | Click toolbar buttons to choose tools/music   |
| Draw on Canvas        | Mouse Drag   | Click and drag to sketch shapes/lines         |
| Enter RGB/Thickness   | Keyboard     | Type values into text fields                  |
| Play/Pause Music      | Mouse Click  | Toggle tracks in the music screen             |
| Return to Paint Screen| Mouse Click  | Use Back button in music screen               |
| Exit Application      | `Esc` Key    | Close the program                             |

---

## 💡 Notes

- Drawing is restricted to a specific canvas region (to prevent drawing over toolbar).
- Only one music track plays at a time.
- RGB and thickness fields accept limited numerical input to avoid overflow.
- Saved images are exported in `.png` format with the canvas as content.
- App launches in fullscreen for immersive experience.

---

## 📦 One-Click Run

Want to try Paint Beats **without compiling**?

- [**Download the ZIP release**](https://github.com/Musab-Farooq/Paint_Beats/blob/main/Executable_paint.zip)  


- Extract the folder.
- Run the provided `.exe` file inside to launch Paint Beats instantly!

---

