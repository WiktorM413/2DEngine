# ✅ Game Engine Core Checklist (Linux, SFML, Solo Dev – 2D)
## 📦 Dependencies
- rapidjson (for JSON parsing)
## 🏗️ Phase 1: Foundation & Tooling

✅ Initialize GitHub repo and push initial commit  
✅ Set up CMake with targets for engine and tests  
✅ Define directory structure:
- ✅ /engine/include for headers  
- ✅ /engine/src for source files  
- ✅ /tests for test code  

✅ Install SFML via package manager or build from source  
✅ Configure CMake to find SFML libraries correctly  
✅ Write code to open a resizable 800×600 window  
✅ Handle window close and resize events  
✅ Implement fixed timestep game loop skeleton  
✅ Add basic logging system:
- ✅ Support INFO, WARN, ERROR levels  
- ✅ Log window creation and shutdown events  

✅ Load engine settings from a JSON config file:
- ✅ Parse window width, height, and title  
- ✅ Handle missing or invalid config with fallbacks  
- [ ] Add reloadable config feature (optional)

---

## 🎮 Phase 2: Input & 2D Rendering

### 🎮 Input
- ✅ Poll keyboard state each frame  
- ✅ Detect key press and release events  
- ✅ Poll mouse position and button states  
- ✅ Fire callbacks or push internal input events  
- ✅ Track key state per frame (for "just pressed", "just released")  
- ✅ Add simple input map or key binding abstraction  
- [ ] Optional: Gamepad detection and button polling

---

### 🎨 2D Rendering
- ✅ Render colored rectangles using `sf::RectangleShape`  
- ✅ Load `.png` textures using `sf::Texture::loadFromFile`  
- ✅ Create a basic `SpriteComponent` class:
  - ✅ Holds a texture reference  
  - ✅ Position, scale, and rotation in 2D space  

- ✅ Draw sprites using SFML's `sf::RenderWindow::draw()`  
- ✅ Sort by layer/z-index to control render order  

#### Camera (`sf::View`)
- ✅ Center view on a target (e.g. player position)  
- ✅ Implement view panning (keyboard/mouse)  
- ✅ Support view zoom in/out (mouse wheel or key)  
- ✅ Draw text using `sf::Text` (HUDs, debugging)

---

## 🧱 Phase 3: 2D Physics & Collision

- ✅ Create `TransformComponent` with position and velocity  
- ✅ Create `PhysicsBodyComponent` with size, flags, and mass (if needed)  
- ✅ Integrate simple gravity into motion  
- ✅ Apply movement using Euler integration (`pos += vel * dt`)  
- [ ] Implement AABB (axis-aligned bounding box) vs AABB checks  
- [ ] Broad-phase culling:
  - [ ] Simple spatial grid or coarse pass  
- [ ] Narrow-phase:
  - [ ] Resolve overlaps by pushing objects apart  
  - [ ] Clamp velocity or cancel movement when hitting a wall  

### Debugging Tools
- [ ] Draw AABBs around entities  
- [ ] Color colliding objects differently  
- [ ] Toggle physics debug draw on/off with a key

---

## 🔊 Phase 4: Audio, ECS, and Scripting

### 🔊 Audio (2D)
- [ ] Load short SFX (`sf::SoundBuffer` + `sf::Sound`)  
- [ ] Load and stream background music (`sf::Music`)  
- [ ] Set per-channel or global volume levels  
- [ ] Add basic audio manager to queue or stop sounds  
- [ ] Optional: Add 2D positional audio with stereo panning

---
## 🧱 Entity Structure (Simplified, No ECS)

- [ ] Represent entities as plain structs or classes containing:
  - [ ] `Transform`: position, velocity, scale
  - [ ] `Sprite`: texture, z-index
  - [ ] `Physics`: size, static/dynamic flag, optional collider info
  - [ ] `Input`: movement direction or input flags
- [ ] Store entities in a single container (e.g. `std::vector<Entity>`)
- [ ] Implement modular systems as functions or modules:
  - [ ] `InputSystem`: updates input-related fields on player entities
  - [ ] `MovementSystem`: applies velocity to position using deltaTime
  - [ ] `CollisionSystem`: checks and resolves overlaps between entities
  - [ ] `RenderSystem`: draws sprites using current transform data
- [ ] Run systems in a fixed order each frame:
  - [ ] Input
  - [ ] Physics/Movement
  - [ ] Collision
  - [ ] Rendering
- [ ] Use simple flags, enums, or type fields to categorize or tag entities (e.g. "Player", "Obstacle", "Enemy")
---

### 📜 Lua Scripting
- [ ] Embed Lua interpreter (`sol2` or `LuaBridge`)  
- [ ] Expose key engine functions:
  - [ ] Create/destroy entities  
  - [ ] Set position or velocity  
  - [ ] Play sound or music  
- [ ] Allow `.lua` scripts per scene or entity  
- [ ] Call script-defined `onUpdate()` or `onCollision()` functions  
- [ ] Expose basic math utilities and component access to scripts

---

## 🧪 Sample Game: "Boxworld"
- [ ] Create player box entity
  - [ ] Uses keyboard input to move  
  - [ ] Has a visible sprite  

- [ ] Create wall/obstacle boxes  
- [ ] Collisions prevent movement through walls  
- [ ] Camera smoothly follows the player  
- [ ] Play jump SFX when spacebar is pressed  
- [ ] Loop background music  
- [ ] Add text showing current FPS (use `sf::Text`)  
- [ ] Add pause menu and resume functionality (esc key)

---

## 🚀 Stretch Goals
- [ ] Scene saving/loading from JSON  
- [ ] Editor mode toggle for entity placement (in-engine)  
- [ ] Tilemap support with sprite atlas (Tiled map loader or own format)  
- [ ] Particle system:
  - [ ] Emit on collisions or explosions  
  - [ ] Fade out and die over time  

- [ ] Multithreading (load textures/audio in background)  
- [ ] GUI overlay with ImGui:
  - [ ] Inspect and edit entities/components live  
  - [ ] Toggle debug flags and camera view

