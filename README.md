# 2DEngine

# ✅ Game Engine Core Checklist (Linux, SFML, Solo Dev)

## 🏗️ Phase 1: Foundation & Tooling
- ✅ Initialize GitHub repo and push initial commit
- ✅ Set up CMake with targets for engine and tests
- ✅ Define directory structure:
  - ✅ `/engine/include` for headers
  - ✅ `/engine/src` for source files
  - ✅ `/tests` for test code
- ✅ Install SFML via package manager or build from source
- ✅ Configure CMake to find SFML libraries correctly
- ✅ Write code to open a resizable window (800×600 default)
- ✅ Handle window close event gracefully
- ✅ Implement fixed timestep game loop skeleton
- ✅ Add basic logging system:
  - ✅ Support INFO, WARN, ERROR levels
  - ✅ Log window creation and shutdown events
- ✅ Load engine settings from a JSON config file:
  - ✅ Parse window size and title
  - ✅ Handle missing or invalid config with defaults

---

## 🎮 Phase 2: Input & Rendering
### Input
- [ ] Poll keyboard state each frame
- [ ] Detect key press and release events
- [ ] Poll mouse position and buttons
- [ ] Fire callbacks or post events on input
- [ ] Optional: Add basic gamepad support (connect, read buttons)
  
### Rendering
- [ ] Render simple colored rectangles as sprites
- [ ] Load textures from PNG files using SFML
- [ ] Create sprite class that supports:
  - [ ] Positioning
  - [ ] Rotation
  - [ ] Scaling
- [ ] Implement drawing order (e.g. by layer or z-index)
- [ ] Set up orthographic camera (`sf::View`)
  - [ ] Implement camera pan
  - [ ] Implement camera zoom
  - [ ] Adjust viewport on window resize
- [ ] Optimize draw calls by grouping sprites sharing textures (basic batching)

---

## 🧱 Phase 3: Physics & Collision
- [ ] Define `Transform` and `PhysicsBody` components with:
  - [ ] Position and velocity
  - [ ] Axis-aligned bounding box (AABB) size
- [ ] Update positions using simple Euler integration
- [ ] Implement broad-phase collision culling:
  - [ ] Simple spatial grid or sweep-and-prune by axis
- [ ] Detect narrow-phase collisions (AABB vs AABB overlap)
- [ ] Resolve collisions by adjusting positions to remove penetration
- [ ] Prevent objects from moving inside static obstacles
- [ ] Visual debugging:
  - [ ] Draw bounding boxes for physics bodies
  - [ ] Highlight collisions

---

## 🔊 Phase 4: Audio, ECS, and Scripting
### Audio
- [ ] Load sound effect files (WAV/OGG)
- [ ] Play sound effects on demand
- [ ] Load and play looping background music
- [ ] Add volume controls:
  - [ ] Global volume
  - [ ] Separate SFX and music volumes

### ECS
- [ ] Implement entity ID management (create, destroy)
- [ ] Design component storage with arrays or maps
- [ ] Implement core components:
  - [ ] Transform (position, rotation, scale)
  - [ ] Sprite (texture reference)
  - [ ] PhysicsBody (velocity, collider)
  - [ ] Input (current input state)
- [ ] Implement systems:
  - [ ] InputSystem (update input components)
  - [ ] PhysicsSystem (update positions, handle collisions)
  - [ ] RenderSystem (draw sprites with transforms)
- [ ] Manage system update order (input → physics → rendering)

### Scripting
- [ ] Embed Lua interpreter (sol2 or LuaBridge)
- [ ] Expose engine API to Lua scripts:
  - [ ] Entity creation/destruction
  - [ ] Component manipulation
  - [ ] Play sounds
- [ ] Load and run Lua scripts per scene
- [ ] Support calling Lua update functions each frame

---

## 🧪 Sample Game
- [ ] Create a player entity with:
  - [ ] Sprite and transform
  - [ ] Physics body with velocity
  - [ ] Input component to move the player
- [ ] Create static obstacle entities
- [ ] Implement collision response so player stops on obstacles
- [ ] Make camera follow the player smoothly
- [ ] Add background music and jump sound effect
- [ ] Test player movement with keyboard input
- [ ] Add pause/resume game state (optional)

---

## 🚀 Stretch Goals
- [ ] Scene serialization and deserialization (JSON or XML)
- [ ] Tilemap renderer with texture atlas and batching
- [ ] Particle system with emitters and lifetime
- [ ] Multithreading for physics update or asset loading
- [ ] Debug GUI overlay using Dear ImGui:
  - [ ] Inspect entities and components
  - [ ] Toggle debug draw features

