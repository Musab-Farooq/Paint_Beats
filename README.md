# Paint Application

A simple yet versatile paint application developed using C++, SFML (Simple and Fast Multimedia Library), and OpenCV. This fullscreen application allows users to draw shapes, lines, and arrows on a canvas, customize colors and thickness, save drawings, and play background music from a selection of tracks. The intuitive interface includes a toolbar with drawing tools, color selection, and a music player screen.

Features
Drawing Tools: Create shapes and lines on a 1320x620 pixel canvas:
Circle: Draw circles by clicking and dragging to set the radius.
Rectangle: Draw rectangles by clicking and dragging to define dimensions.
Line: Draw straight lines by clicking and dragging.
Arrowed Line: Draw lines with an arrowhead at the end.

Customization:
Color Selection: Choose from predefined colors (Red, Yellow, Black, Blue, Green) or input custom RGB values (0-255) via text fields.
Thickness: Adjust line thickness (0-9) via a text input field.

Canvas Management:
Clear: Reset the canvas to a blank white background.
Save: Save the current drawing as a PNG file (Output Image.png).

Music Player:
Access a music screen to play, pause, or switch between five background tracks (Idea 10, Autumn Waltz, Melancholic, Magical Overture, Gymnopedie no. 1).
Tracks are displayed with play/pause buttons and names.
Graphics: Clean interface with a toolbar (120,120,120 gray), canvas background (180,180,180 gray), and button icons for tools (Circle.png, Rectangle.png, Line.png, arrow.png, Music.png, save.png, clear.png, play.png, pause.png, back.png).
Audio: Background music playback with volume control (e.g., Gymnopedie at 120, others at 80).

Controls:
Mouse: Click buttons to select tools, colors, or music options; click and drag to draw on the canvas.

Keyboard:
Enter numbers (0-9) for thickness when the thickness button is active.
Enter RGB values (0-255) when RGB buttons are active.
Escape: Close the application.

Screens:
Paint Screen: Main drawing interface with toolbar, canvas, and buttons for tools, colors, thickness, clear, save, and music.
Music Screen: Displays music tracks with play/pause buttons and a back button to return to the paint screen.
Technical Details

Libraries:
SFML: Handles window management, rendering sprites, handling mouse/keyboard events, and playing audio.
OpenCV: Processes drawing operations (circles, rectangles, lines, arrowed lines) on a Mat object, which is converted to an SFML texture for display.
Classes/Structures:
screens (in screens.h): Manages paint and music screens, including background images and button arrays. Handles button interactions and screen toggling.
buttons (in screens.h): Defines interactive buttons with hover effects, textures, and toggle states.
Drawing functions (in shapes.h): draw_circle, draw_rectangle, draw_line, draw_arrow_line use OpenCV to render shapes on a Mat, updated to an SFML texture. clear resets the canvas, and write handles text input for thickness/RGB.
Music functions (in musics.h): activate manages music playback, Musics_names sets up track names, and manage_buttons toggles play/pause button visibility.

Canvas Workflow:
Initializes a white 1320x620 canvas via texture_mat.
Mouse events (press, move, release) trigger OpenCV drawing on a temporary Mat, which is converted to RGBA and updated to an SFML sprite.
File Output: Drawings are saved as Output Image.png using SFML’s RenderTexture.
This project showcases integration of SFML and OpenCV, event-driven programming, GUI design, and multimedia handling. It’s ideal for learning graphics programming or creating simple digital art!

Requirements
SFML library
OpenCV library
C++ compiler
Texture files (Textures/ folder: Circle.png, Rectangle.png, Line.png, arrow.png, Music.png, save.png, clear.png, play.png, pause.png, back.png, music_bg.jpg)
Audio files (Music/ folder: idea_10.mp3, autumn_waltz.mp3, melancholic.mp3, magical_overture.mp3, gymnopedie.mp3)
Font file (Fonts/ folder: arial.ttf)

How to Run
Install and configure SFML and OpenCV in your development environment.
Place all texture, audio, and font files in the respective Textures/, Music/, and Fonts/ directories relative to the executable.
Compile and run main.cpp to launch the application in fullscreen mode.
Use the mouse to select tools, draw on the canvas, choose colors, and manage music. Use the keyboard to input thickness or RGB values.

NOTE: To run the paint application without setting up SFML
Save drawings or clear the canvas as needed, and toggle to the music screen to play background tracks.
Notes
Drawing is restricted to the canvas area (20,120 to 1340,740) to prevent toolbar overlap.
RGB input is limited to three digits per field to avoid overflow.
Music playback requires manual play/pause toggling per track; only one track plays at a time.
The canvas is initialized as white, and saved images include the canvas content only (transparent background).
Enjoy creating art and relaxing to music with this SFML and OpenCV-powered paint application!

Note: To use this paint beats application without setting up SFML and opencv in your system just download the zip file and hit to exe file
