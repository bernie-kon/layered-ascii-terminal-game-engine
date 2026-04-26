## What's New (Fork Additions)

- **Layer System**: Sprites are Sprites are drawn in order (e.g. BG → Game → UI) and composited into a single framebuffer.

- **Per-Cell Alpha**: Each cell in a sprite can be transparent (show layer below) or opaque (render as solid space).

- **Diff Renderer**: Only changed cells are redrawn each frame, eliminating flicker and reducing terminal writes.
