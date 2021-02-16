/////////////////////////////////////////////////////////////////
//  Author: Devon Adams (https://github.com/devonadams)
//  License : GPLv3
//  Language: C++
//  This file serves as the definitions for the user-end 2D renderer
////////////////////////////////
#pragma once

#include "DAGGer/Renderer/OrthographicCamera.h"

#include "DAGGer/Renderer/Texture.h"
#include "DAGGer/Renderer/SubTexture2D.h"

#include "DAGGer/Renderer/Camera.h"

namespace DAGGer
{
	class Renderer2D
	{
	public:
		struct RenderCamera
		{
			glm::mat4 Projection;
			glm::mat4 View;
		};

		static void Init();
		static void Shutdown();

		static void BeginScene(const Camera& camera, const glm::mat4& transform);
		static void BeginScene(const OrthographicCamera& camera);	//	TODO: Remove
		static void EndScene();
		static void Flush();

			//////////////////////////////////////////////////////////////////////
			//							Primitives								//
			//////////////////////////////////////////////////////////////////////
		//	Colored Quad
		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color = glm::vec4(1.0f, 0.0f, 1.0f, 1.0));	//	Position, Size, [Color]
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color = glm::vec4(1.0f, 0.0f, 1.0f, 1.0f));	//	Position, Size, [Color]
		// Textured Quads
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f));	//	Position, Size, Texture, [Tiling Factor] &| [Tint Color]
		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f));	//	Position, Size, Texture, [Tiling Factor] &| [Tint Color]
		// Subtextured Quads
		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<SubTexture2D>& SubTexture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f));	//	Position, Size, SubTexture, [Tiling Factor] &| [Tint Color]
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<SubTexture2D>& SubTexture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f));	//	Position, Size, SubTexture, [Tiling Factor] &| [Tint Color]

		//	Rotated Colored Quads [rotation is in radians]
		static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float rotation, const glm::vec4& color = glm::vec4(1.0f, 0.0f, 1.0f, 1.0f));	//	Position, Size, Rotation, [Color]
		static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float rotation, const glm::vec4& color = glm::vec4(1.0f, 0.0f, 1.0f, 1.0f));	//	Position, Size, Rotation, [Color]
		//	Rotated Textured Quads
		static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float rotation, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f));	//	Position, Size, Rotation, Texture, [Tiling Factor] &| [Tint Color]
		static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float rotation, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f));	//	Position, Size, Rotation, Texture, [Tiling Factor] &| [Tint Color]
		// Subtextured Rotated Quad
		static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float rotation, const Ref<SubTexture2D>& SubTexture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f));	//	Position, Size, Rotation, SubTexture, [Tiling Factor] &| [Tint Color]
		static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float rotation, const Ref<SubTexture2D>& SubTexture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f));	//	Position, Size, Rotation, SubTexture, [Tiling Factor] &| [Tint Color]

		// Matrix Transform Quads - Parent functions
		static void DrawQuad(const glm::mat4& transform, const glm::vec4& color = glm::vec4(1.0f, 0.0f, 1.0f, 1.0));	//	Transform, color
		static void DrawQuad(const glm::mat4& transform, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f));	//	Transform, [Tiling Factor] &| [Tint Color]
		static void DrawQuad(const glm::mat4& transform, const Ref<SubTexture2D>& SubTexture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f));	//	Transform, [Tiling Factor] &| [Tint Color]

		// Stats
		struct Statistics
		{
			uint32_t DrawCalls = 0;
			uint32_t QuadCount = 0;
			uint32_t TextureCount = 1;

			uint32_t GetTotalVertexCount() { return QuadCount * 4; }
			uint32_t GetTotalIndexCount() { return QuadCount * 6; }
		};
		static void ResetStats();
		static Statistics GetStats();

	private:
		static void FlushAndReset();
	};

}	//	END namespace DAGGer