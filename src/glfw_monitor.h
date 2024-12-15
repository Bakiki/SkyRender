#pragma once

struct GLFWmonitor;
struct GLFWwindow;

namespace sreng {

	gsl::span<GLFWmonitor*> GetMonitors();
	glm::ivec2 GetMonitorPosition(gsl::not_null<GLFWmonitor*> monitor);
	glm::ivec2 GetMonitorWorkAreaSize(gsl::not_null<GLFWmonitor*> monitor);
	void MoveMonitorToWindow(gsl::not_null<GLFWwindow*> window, gsl::not_null<GLFWmonitor*> monitor);

}