# 2026-08-04

## Completed

- Implemented Transform class.
- Added Position, Rotation and Scale support.
- Implemented model matrix generation using GLM.
- Added uniform upload functions to Shader.
- Added model matrix uniform to vertex shader.
- Integrated Transform with Renderer.
- Verified translation, rotation and scaling on the rendered triangle.

## Problems

- Understanding GLM's role in the renderer.
- Learning matrix multiplication order.
- Connecting CPU-side transforms to GPU shader uniforms.

## Lessons Learned

- GLM is a mathematics library, not a rendering library.
- Objects are transformed using matrices rather than modifying vertex data.
- The model matrix combines translation, rotation and scale.
- Shader uniforms are used to send CPU data to the GPU.
- Vertex shaders transform every vertex using the uploaded model matrix.

## Next Session

- Camera class.
- View matrix.
- Projection matrix.
- Perspective projection.
- First movable camera.



# 2026-07-26

## Completed

- Implemented Mesh class
- Added VertexArray wrapper
- Added VertexBuffer wrapper
- Rendered first triangle
- Created documentation

## Problems

- Shader paths were incorrect.
- Fragment shader missing.
- Program linking bug.

## Lessons Learned

- VAOs remember vertex attribute state.
- VBOs only contain vertex data.
- glDrawArrays only requires the VAO once configured.

## Next Session

- Transform class
- Model matrix
- Uniform upload