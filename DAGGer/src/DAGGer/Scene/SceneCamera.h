#pragma once

#include "DAGGer/Renderer/Camera.h"

namespace DAGGer
{
	class SceneCamera : public Camera
	{
	public:
		enum class ProjectionType { Perspective = 0, Orthographic = 1 };
	public:
		SceneCamera();
		virtual ~SceneCamera() = default;

		void SetPerspective(float fov, float nearClip, float farClip);
		void SetOrthographic(float verticalFOV, float nearClip, float farClip);

		void SetViewportSize(uint32_t width, uint32_t height);
		//	Perspective
		float GetPerspectiveVerticalFOV() const { return m_PerspectiveFOV; }
		void  SetPerspectiveVerticalFOV(float verticalFOV){ (verticalFOV <= 0) ? m_PerspectiveFOV = 0.001f : m_PerspectiveFOV = verticalFOV; RecalculateProjection(); }
		float GetPerspectiveNearClip() const { return m_PerspectiveNear; }
		void  SetPerspectiveNearClip(float nearClip) { m_PerspectiveNear = nearClip; RecalculateProjection(); }
		float GetPerspectiveFarClip() const { return m_PerspectiveFar; }
		void  SetPerspectiveFarClip(float farClip) { m_PerspectiveFar = farClip; RecalculateProjection(); }
		//	Orthographic
		float GetOrthographicSize() const { return m_OrthographicSize; }
		void  SetOrthographicSize(float size) { (size <= 0) ? m_OrthographicSize = 0.001 : m_OrthographicSize = size; RecalculateProjection(); }
		float GetOrthographicNearClip() const { return m_OrthographicNear; }
		void  SetOrthographicNearClip(float nearClip) { m_OrthographicNear = nearClip; RecalculateProjection(); }
		float GetOrthographicFarClip() const { return m_OrthographicFar; }
		void  SetOrthographicFarClip(float farClip) { m_OrthographicFar = farClip; RecalculateProjection(); }

		void SetProjectionType(ProjectionType type) { m_ProjectionType = type; RecalculateProjection(); };
		ProjectionType GetProjectionType() const { return m_ProjectionType; };
	private:
		void RecalculateProjection();
	private:
		ProjectionType m_ProjectionType = ProjectionType::Orthographic;

		float m_PerspectiveFOV = glm::radians(45.0f);
		float m_PerspectiveNear = 0.01f, m_PerspectiveFar = 1000.0f;

		float m_OrthographicSize = 10.0f;
		float m_OrthographicNear = -1.0f, m_OrthographicFar = 1.0f;


		float m_AspectRatio = 0.0f;
	};

}	//	END namespace DAGGer